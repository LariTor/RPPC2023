/**
 * @file polinomialstest.cpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se testea Splines.cpp
 *          con matplot++
 * @version 0.1
 * @date 2024-04-04
 * 
 */

#include "../../Splines.hpp"
#include <matplot/matplot.h>

namespace plt = matplot;

int main (int argc, char *argv[]) {
	GiNaC::symbol x;
	GiNaC::ex exp = -pow(x,4)+2*pow(x,2)+sin(10*x);
	Spline spline(exp, x, -2, 2, 20);
	std::vector<float> puntos;
	puntos.reserve(380);
    std::vector<float> puntos_spline;
    GiNaC::exmap x_eval;
	puntos_spline.reserve(380);
    for (float i = -1.9; i<1.9; i+=0.01) {
        x_eval[x] = i;
        GiNaC::ex exp_eval = exp.subs(x_eval);
        float y = GiNaC::ex_to<GiNaC::numeric>(exp_eval).to_double();
        puntos.push_back(y);
		puntos_spline.push_back(spline(i));
	}
	plt::plot(puntos);
    plt::hold(plt::on);
    plt::plot(puntos_spline);
	plt::show();        
	return 0;
}
