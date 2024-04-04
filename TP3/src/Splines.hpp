/**
 * @file Splines.hpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Usamos https://en.wikipedia.org/wiki/Spline_interpolation ^ https://www.ginac.de/tutorial/
 * @version 0.1
 * @date 2024-04-03
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#pragma once
#include "Polinomials.hpp"

#include <ginac/symbol.h>
#include <ginac/ginac.h>

//struct para predefined points
typedef struct {
    float pt_k; //pendiente 
	float pt_x; //punto x
	float pt_y; //punto y
} point;

class Spline{
    public:

        /**
         * @brief Construct a new Spline object
         *      sin inicializar
         * 
         */
        Spline() = default;

        /**
         * @brief Construct a new Spline object
         *  por copia
         */
        Spline(Spline&&) = default;
        Spline(const Spline&) = default;
        
        /**
         * @brief por copia
         * 
         * @return Spline& 
         */
        Spline &operator= (Spline&&) = default; 
        Spline &operator= (const Spline&) = default;
        
        /**
         * @brief Construct a new Spline object
         * 
         */
        Spline(
            //GiNaC ejemplo => 3x²+ 4y --> expression = ex .... symbol = x; y 
			GiNaC::ex,  //expression
			GiNaC::symbol, //symbol
			float, //first point of interval
			float, //last point of interval
			int //number of points in interval
        ); 
        
        /**
         * @brief Destroy the Spline object
         * 
         */
        ~Spline();

        /**
         * @brief implementación de las no expection aprendidas en clase
         *        
         * 
         */
        class spline_undifined: public std::exception {
            public:
            /**
             * @brief Construct a new out of range object default
             *          Construct a new obket of range por copia
             *          Destroy a out of range object
             * 
             */
            spline_undifined()=default;

            spline_undifined(spline_undifined &&) = default;
            spline_undifined(const spline_undifined &) = default;

            ~spline_undifined()=default;
            /**
             * @brief member function named what() that provides a way to retrieve the error message associated with an out_of_range exception
             * @return const char*, 
             */
            const char * what() const noexcept(true) override;

            /**
             * @brief para que no se pueda modificar el mensaje, lo ponemos en private
             * msg= Entrada no válida: La spline no esta definida para la entrada dada.
             */
            private:
            const char * msg = "Invalid input: Spline is no defined for the given input.";
        };
        
        float operator()(float) const noexcept(false);


    private:

        typedef struct {
            Polinomials pol;
            float init;
        } SplinePolinomial;
        
        float end;

        std::vector<SplinePolinomial> q_pols; //polinomias cubic = splines vector

        Polinomials t(point pf_points[2]);

        float a(point pf_points[2]);

        float b(point pf_points[2]);

        Polinomials q_generator(point pf_points[2]);

};

