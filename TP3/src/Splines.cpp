/**
 * @file Splines.cpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se implementan las funciones declaradas en Splines.hpp
 * 
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "Splines.hpp"

Spline::~Spline(){}
 
//auxiliar Functions

	Polinomials Spline::t(point pf_points[2]){
		std::vector<float> vec_t({(1/(pf_points[1].pt_x - pf_points[0].pt_x)),-(pf_points[0].pt_x/(pf_points[1].pt_x - pf_points[0].pt_x))});
		Polinomials t(vec_t);
		return t;
	}

    float Spline::a(point pf_points[2]){
		return ((pf_points[0].pt_k)*(pf_points[1].pt_x - pf_points[0].pt_x)-(pf_points[1].pt_y - pf_points[0].pt_y));
    }

    float Spline::b(point pf_points[2]){
		return (-(pf_points[1].pt_k)*(pf_points[1].pt_x - pf_points[0].pt_x)+(pf_points[1].pt_y - pf_points[0].pt_y));
    }

	Polinomials Spline::q_generator(point pf_points[2]){

		Polinomials t = this->t(pf_points);
		float a = this->a(pf_points);
		float b = this->b(pf_points);

		Polinomials one({1});
		//q(x)=(1-t(x))*y_1 + t(x)*y_2 + t(x)*(1-t(x)) * ((1-t(x))*a + t(x)*b)
		//q(x)= term_a      + term_b   + (term_c       *       term_d )

		Polinomials term_a = (one-t)*pf_points[0].pt_y;
		Polinomials term_b = t*pf_points[1].pt_y;
		Polinomials term_c = t*(one-t);
		Polinomials term_d = (one-t)*a + t*b;

		return (term_a + term_b + (term_c * term_d)); 
	}


/**
 * @brief Construct a new Spline:: Spline object
 *  -exp = expression
 *  -sym = symbol
 *  -xi = first number of interval
 *  -xf = las number of interval
 *  -n_pi = number of points in interal
 * 
 */
Spline::Spline(GiNaC::ex exp, GiNaC::symbol sym, float xi, float xf, int n_pi){

	//for y: evaluate exp in symbol
	GiNaC::exmap x_eval;
	x_eval[sym] = xi;
	GiNaC::ex exp_eval = exp.subs(x_eval);
	float y = GiNaC::ex_to<GiNaC::numeric>(exp_eval).to_double();

	// for k: evaluate exp' in symbol
	GiNaC::ex diff_exp = exp.diff(sym);
	GiNaC::ex diff_exp_eval = diff_exp.subs(x_eval);
	float k = GiNaC::ex_to<GiNaC::numeric>(diff_exp_eval).to_double();
	
	point pf_points[2];
	pf_points[1] = point{.pt_k = k, .pt_x = xi, .pt_y = y};

	//initialize segment q
	q_pols.resize(n_pi-1);

	// genero el equiespaciado
	float xd = (xf-xi)/n_pi;

	for (int i = 0; i < q_pols.size(); i++){

		float x_i=xd*(i+1)+xi;
		x_eval[sym] = x_i;

		exp_eval = exp.subs(x_eval);
		y = GiNaC::ex_to<GiNaC::numeric>(exp_eval).to_double();

		diff_exp_eval = diff_exp.subs(x_eval);
		k = GiNaC::ex_to<GiNaC::numeric>(diff_exp_eval).to_double();

		pf_points[0]=pf_points[1];
		pf_points[1]=point{.pt_k = k, .pt_x = x_i, .pt_y = y};
		q_pols[i] = SplinePolinomial{.pol=q_generator(pf_points), .init=pf_points[0].pt_x};
	}

}

const char *Spline::out_of_range::what() const noexcept(true) { return msg; }

float Spline::operator()(float xe) const noexcept(false){
	
	for (int i = 0; i < q_pols.size()-1; i++){
		if (xe > q_pols[i].init && xe < q_pols[i+1].init){
			return q_pols[i].pol(xe);
		}		
	}

	return q_pols[q_pols.size()-1].pol(xe);
}