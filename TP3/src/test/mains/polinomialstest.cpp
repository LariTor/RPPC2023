/**
 * @file polinomialstest.cpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se testea Polinomials.cpp
 * @version 0.1
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../Polinomials.hpp"


int main(int argc, const char * argv[]) {

    std::vector<float> vec_p1({6,4, -2});

    Polinomials first_polinomial(vec_p1);

    std::cout<<"El primer polinomio es: "<<first_polinomial<<std::endl;

    std::cout<<"El primer polinomio invertido es: "<<-first_polinomial<<std::endl;

    int degree = first_polinomial.degree(); 

    std::cout<<"El grado del primer polinomio es: "<<degree<<std::endl;

    std::vector<float> vec_p2({1,-3});

    Polinomials second_polinomial(vec_p2);

    // TEST PARA VER SI FUNCIONA EL Cin:
    //std::cout<<"Ingrese el segundo polinomio de la forma: 'Grado' 'Termino' 'Termino' "<<std::endl;
    //std::cout<<"Ej. yo quiero el polinomio 4x^2+4 sería= 3 4 0 4"<<std::endl;

    //Polinomials second_polinomial;

    //std::cin>>second_polinomial;
    
    std::cout<<"El segundo polinomio es: "<<second_polinomial<<std::endl;

    Polinomials sum = first_polinomial+second_polinomial;

    std::cout<<"("<<first_polinomial<<")"<<"+"<<"("<<second_polinomial<<")"<<" da como resultado: "<<sum<<std::endl;

    Polinomials sub = first_polinomial-second_polinomial;

    std::cout<<"("<<first_polinomial<<")"<<"-"<<"("<<second_polinomial<<")"<<" da como resultado: "<<sub<<std::endl;
    
    float a = 2;
    
    Polinomials mult_float = first_polinomial*a; //tambien funciona a*first_polinomial

    std::cout<<"("<<first_polinomial<<")"<<"*"<<"("<<a<<")"<<" da como resultado: "<<mult_float<<std::endl;

    Polinomials mult_pol = first_polinomial*second_polinomial; 

    std::cout<<"("<<first_polinomial<<")"<<"*"<<"("<<second_polinomial<<")"<<" da como resultado: "<<mult_pol<<std::endl;

    Polinomials div = first_polinomial/second_polinomial; 

    std::cout<<"("<<first_polinomial<<")"<<"/"<<"("<<second_polinomial<<")"<<" da como resultado: "<<div<<std::endl;

    Polinomials div_rest = first_polinomial%second_polinomial; 

    std::cout<<"("<<first_polinomial<<")"<<"%"<<"("<<second_polinomial<<")"<<" da como resto: "<<div_rest<<std::endl;    
    
    return 0;
}
