/**
 * @file Polinomials.cpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se implementan las funciones:
 *    -> declaradas en hpp
 * @version 0.1
 * @date 2023-06-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "Polinomials.hpp"

void Polinomials::trim_zeros(){
    int new_size = this->polinomial.size();
    while (new_size != 0){
        if (this->polinomial[new_size-1]!=0){
            break;
        }
        new_size--;
    }
    this->polinomial.resize(new_size);
}

Polinomials::Polinomials(std::vector<float> vector){
    this->polinomial.resize(vector.size());
    
    for (int i = (vector.size()-1); i >= 0; i--){
        this->polinomial[i]=vector[vector.size()-i-1];
    }
    this->trim_zeros();
    
} //constructor de polinomio

Polinomials::Polinomials(std::vector<float> vector, char _): polinomial(vector){
    this->trim_zeros();
}

Polinomials::~Polinomials(){}

Polinomials &Polinomials::operator= (Polinomials&& pol){
    this->polinomial = pol.polinomial;
    return *this;
    //a = b
    //*this = pol
}

Polinomials &Polinomials::operator= (const Polinomials& pol){
    this->polinomial = pol.polinomial;
    return *this;
}

bool Polinomials::operator== (const Polinomials& pol) const{

    if (this->polinomial.size() != pol.polinomial.size()){
        return false;
    }
    for (int i = 0; i < pol.polinomial.size(); i++){
       if (this->polinomial[i] != pol.polinomial[i]){
            return false;
        }
    } 
    return true;  
}

bool Polinomials::operator!= (const Polinomials& pol) const{
    return !(*this==pol);
}

std::ostream & operator << (std::ostream &out, const Polinomials &pol){
    for (int i = pol.polinomial.size()-1; i >=0; i--){
        if (pol.polinomial[i]==0){
           continue;
        }
        if (pol.polinomial[i]>0 && i != pol.polinomial.size()-1){
            out<<"+";
        }   
        if ((pol.polinomial[i]!=1 && pol.polinomial[i]!=-1) || i == 0){
            out<<pol.polinomial[i];
        }
        if (pol.polinomial[i] == -1 && i!=0 ){
            out<<"-";
        }
        if (i==1){
            out<<"x"<<" ";
        } else 
        if (i!=0){
            out<<"x^"<<i<<" ";
        }
    }
    return out;
}

std::istream & operator >> (std::istream &in, Polinomials &pol){ //grado 4x²+0x+3 grado mayor a menor
    int size;
    in>>size;

    pol.polinomial.resize(size);

    for (int i = size-1; i >= 0; i--){
        in >> pol.polinomial[i];    
    }

    return in;
}

Polinomials Polinomials::operator+(const Polinomials& another_polinomial) const{
    
    std::vector<float> vec;

    int size_p1 =  this->polinomial.size();
    int size_p2 = another_polinomial.polinomial.size();
    
    const Polinomials* minor = size_p1 < size_p2? this:&another_polinomial;
    const Polinomials* mayor = size_p1 < size_p2? &another_polinomial:this;
    
    vec.resize(mayor->polinomial.size());

    for (int i = 0; i < minor->polinomial.size(); i++){
        vec[i]=minor->polinomial[i]+mayor->polinomial[i];
    }
    
    for (int i = minor->polinomial.size(); i < mayor->polinomial.size(); i++){
        vec[i]=mayor->polinomial[i];
    }

    Polinomials result(vec, '\0');

    return result;

}

Polinomials Polinomials::operator+=(const Polinomials& another_polinomial){
    *this = *this + another_polinomial;
    return *this;
}

Polinomials Polinomials::operator-() const{
    
    std::vector<float> vec;
    vec.resize(this->polinomial.size());

    for (int i = 0; i < this->polinomial.size(); i++){
        vec[i]= - this->polinomial[i];
    }
    
    Polinomials result(vec, '\0');

    return result;

}

Polinomials Polinomials::operator-(const Polinomials& another_polinomial) const{
    return *this+(-another_polinomial);
}

Polinomials Polinomials::operator-=(const Polinomials& another_polinomial){
    *this = *this - another_polinomial;
    return *this;
}

Polinomials Polinomials::operator*(const float a) const{
    
    std::vector<float> vec;
    vec.resize(this->polinomial.size());

    for (int i = 0; i < this->polinomial.size(); i++){
        vec[i]= a*(this->polinomial[i]);
    }
    
    Polinomials result(vec, '\0');

    return result;
}

Polinomials operator*(const float a, const Polinomials& pol){
    return pol*a;
}

Polinomials Polinomials::operator*=(const float a){
    *this = *this * a;
    return *this;
}

Polinomials Polinomials::operator*(const Polinomials& another_polinomial) const {

  if (this->polinomial.empty() || another_polinomial.polinomial.empty()) {
    return Polinomials(std::vector<float>(1, 0.0f), '\0'); // Result: 0
  } //por si son 0 los polinomios

  //calculo del tamaño del polinomio resutante
  int result_degree = this->degree() + another_polinomial.degree();

  // inicializo el polinomio resultante con ceros
  std::vector<float> result_coefficients(result_degree + 1, 0.0f);

  for (int i = 0; i <= this->degree() ; i++) {
    for (int j = 0; j <= another_polinomial.degree(); j++) {
      int result_index = i + j;
      result_coefficients[result_index] += this->polinomial[i] * another_polinomial.polinomial[j];
    }
  }

  return Polinomials(result_coefficients, '\0');
}

Polinomials Polinomials::operator*=(const Polinomials& another_polinomial){
    *this = *this * another_polinomial;
    return *this;
}

int Polinomials::degree() const{
    return((this->polinomial.size()-1));
}

Polinomials Polinomials::operator/(const Polinomials& another_polinomial) const{

    Polinomials dividendo = *this;
    const Polinomials divisor = another_polinomial;
    
    if (another_polinomial.polinomial.empty()) {
        throw std::runtime_error("Division by zero polynomial is not allowed.");
    }

    Polinomials result;

	while (dividendo.polinomial.size() > 0 && dividendo.polinomial.size() >= divisor.polinomial.size()){
        float coeff = dividendo.polinomial[dividendo.degree()]/divisor.polinomial[divisor.degree()];
        int exp = dividendo.degree()-divisor.degree();
        std::vector<float> vec;
        vec.resize(exp+1,0);
        vec[exp]=coeff;
        Polinomials term(vec,'\0');
		result += term;
		dividendo -= term*divisor;
	}

    return result;
}

Polinomials Polinomials::operator/= (const Polinomials& another_polinomial){
    *this = *this / another_polinomial;
    return *this;
}

Polinomials Polinomials::operator%(const Polinomials& another_polinomial) const{

    Polinomials dividendo = *this;
    const Polinomials divisor = another_polinomial;
    
    if (another_polinomial.polinomial.empty()) {
        throw std::runtime_error("Division by zero polynomial is not allowed.");
    }

    Polinomials result;

	while (dividendo.polinomial.size() > 0 && dividendo.polinomial.size() >= divisor.polinomial.size()){
        float coeff = dividendo.polinomial[dividendo.degree()]/divisor.polinomial[divisor.degree()];
        int exp = dividendo.degree()-divisor.degree();
        std::vector<float> vec;
        vec.resize(exp+1,0);
        vec[exp]=coeff;
        Polinomials term(vec,'\0');
		result += term;
		dividendo -= term*divisor;
	}

    return dividendo;
    
}

Polinomials Polinomials::operator%= (const Polinomials& another_polinomial){
    *this = *this % another_polinomial;
    return *this;
}

float Polinomials::operator() (const float x) const{
    float ret = 0;
    for (int i = 0; i < this->polinomial.size(); i++){
        ret += this->polinomial[i]*pow(x,i);
    }
    return ret;
}

Polinomials Polinomials::operator*() const{

    Polinomials result = *this;

    for (int i = 0; i < result.polinomial.size()-1; i++){
        result.polinomial[i]= result.polinomial[i+1]*(i+1);
    }

    result.polinomial.resize(result.polinomial.size()-1);

    return result;
}

//https://es.wikipedia.org/wiki/Aislamiento_de_ra%C3%ADces_reales#M%C3%A9todo_de_bisecci%C3%B3n
float Polinomials::real_root(float xi, float xs, int max_iterations, float tolerance) const {
    float real_root;
    const Polinomials& pol = *this;
    for (int i = 0; i < max_iterations; i++){
        float xa = (xi+xs)/2;
        float pol_xi = pol(xi);
        float pol_xa = pol(xa);
        if (pol_xa * pol_xa < tolerance*tolerance){
            real_root=xa;
            break;
        }
        if (pol_xi*pol_xa > 0){
            xi=xa;
        }else {
            xs = xa;
        }
    }
    return real_root;
}