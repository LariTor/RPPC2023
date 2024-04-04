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
	GiNaC::ex e = sin(x);
	Spline spline(e, x, -1, 1, 20);
	std::vector<float> puntos;
	puntos.reserve(198);
    std::vector<float> puntos_spline;
    GiNaC::exmap x_eval;
	puntos_spline.reserve(198);
    for (float i = -9.9; i<9.9; i+=0.1) {
        x_eval[x] = i;
        GiNaC::ex exp_eval = e.subs(x_eval);
        float y = GiNaC::ex_to<GiNaC::numeric>(exp_eval).to_double();
        puntos.push_back(y);
		puntos_spline.push_back(0.0);
	}
	for (float i = -0.9; i<0.9; i+=0.1) {
		puntos_spline[(i+9.9)*10] = spline(i);
	}
	plt::plot(puntos);
    plt::hold(plt::on);
    plt::plot(puntos_spline);
	plt::show();        
	return 0;
}