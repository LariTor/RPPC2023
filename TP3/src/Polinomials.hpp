/**
 * @file Polinomials.hpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief Este archivo contiene las declaraciones de constantes y bibliotecas utilizadas.
 * @version 0.1
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once 
#include <vector>
#include <complex>
#include <iostream>

class Polinomials {

    public:
        Polinomials()=default; 
        
        Polinomials(Polinomials&&) = default; //"copia" de polinomio, con otro
        Polinomials(const Polinomials&) = default;
        
        Polinomials &operator= (Polinomials&&); //por copia
        Polinomials &operator= (const Polinomials&);
        
        Polinomials(std::vector<float>); //constructor de polinomio
        
        ~Polinomials(); //destructor

        Polinomials operator+ (const Polinomials&) const; // c = a + b
        Polinomials operator+= (const Polinomials&); // a += b === a = a + b

        Polinomials operator- () const; // c = -a
        Polinomials operator- (const Polinomials&) const; // c = a - b
        Polinomials operator-= (const Polinomials&); // a = a - b

        Polinomials operator* (const Polinomials&) const; // c = a * b
        Polinomials operator* (const float) const; // c = a * b con b tipo float 
        Polinomials operator*= (const Polinomials&); // a = a * b
        Polinomials operator*= (const float); // a = a * b con b tipo float
       
        Polinomials operator/ (const Polinomials&) const; // c = a / b para div
        Polinomials operator/= (const Polinomials&); // a = a / b para div
        Polinomials operator% (const Polinomials&) const; // c = a % b para resto
        Polinomials operator%= (const Polinomials&); // a = a % b para resto

        float operator() (const float) const; //estructuras de funcion

        bool operator== (const Polinomials&) const; //paracomparar
        bool operator!= (const Polinomials&) const;

        friend std::ostream & operator<< (std::ostream&, const Polinomials&); 
        friend std::istream & operator>> (std::istream&, Polinomials&); 
        Polinomials operator*  () const;//operador dee desreferenciar para derivar el polinomio

        float real_root(float,float, int, float) const; //raices reales
        
        int degree() const; //func para ver el grado pedida
        
    private:
                   //                                    |-- grade
        std::vector<float> polinomial; // p[grade] = [coeff1, coeff2, coeffetc]
        Polinomials(std::vector<float>, char); //constructor de polinomio
        void trim_zeros();

};


