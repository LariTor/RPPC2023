/**
 * @file polinomialstest.cpp
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se testea Polinomials.cpp
 *          con criterion
 * @version 0.1
 * @date 2023-07-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "../../Polinomials.hpp"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>

Test(comparator, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    std::vector<float> vec_p2({1,-3});
    Polinomials second_polinomial(vec_p2);

    cr_assert_neq(first_polinomial,second_polinomial);
}

Test(negative,test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    Polinomials neg = -first_polinomial;

    std::vector<float> vec_expected({-6,-4,2});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(neg,expected_polinomial);
}

Test(degree, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    int deg = first_polinomial.degree(); 

    int expected_degree = 2;

    cr_assert_eq(deg,expected_degree);
}

Test(sumation, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    std::vector<float> vec_p2({1,-3});
    Polinomials second_polinomial(vec_p2);

    Polinomials sum = first_polinomial+second_polinomial;

    std::vector<float> vec_expected({6,5,-5});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(sum,expected_polinomial);
}

Test(substraction, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    std::vector<float> vec_p2({1,-3});
    Polinomials second_polinomial(vec_p2);

    Polinomials sub = first_polinomial-second_polinomial;

    std::vector<float> vec_expected({6,3,1});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(sub,expected_polinomial);
}

Test(float_multiplication,test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);
    float a = 2;

    Polinomials mult_float = first_polinomial*a;

    std::vector<float> vec_expected({12,8,-4});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(mult_float,expected_polinomial);
}

Test(polinomial_multiplication,test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    std::vector<float> vec_p2({1,-3});
    Polinomials second_polinomial(vec_p2);

    Polinomials mult_pol = first_polinomial*second_polinomial; 

    std::vector<float> vec_expected({6,-14,-14,6});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(mult_pol,expected_polinomial);
}

Test(division, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    std::vector<float> vec_p2({1,-3});
    Polinomials second_polinomial(vec_p2);

    Polinomials div = first_polinomial/second_polinomial; 

    std::vector<float> vec_expected({6,22});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(div,expected_polinomial);
}

Test(remainder, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    std::vector<float> vec_p2({1,-3});
    Polinomials second_polinomial(vec_p2);

    Polinomials rem = first_polinomial%second_polinomial; 

    std::vector<float> vec_expected({64});
    Polinomials expected_polinomial(vec_expected);

    cr_assert_eq(rem,expected_polinomial);
}

Test(evaluate, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    float x = 2;

    float eval = first_polinomial(x);

    float expected_val = 30;

    cr_assert_eq(eval,expected_val);
}

Test(derivate, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    Polinomials deriv_polinomial = *first_polinomial;

    std::vector<float> vec_exp({12,4});
    Polinomials expected_polinomial(vec_exp);

    cr_assert_eq(deriv_polinomial,expected_polinomial);
}

Test(real_roots, test){
    std::vector<float> vec_p1({6,4, -2});
    Polinomials first_polinomial(vec_p1);

    float tolerance = 1e-3;

    float real_root = first_polinomial.real_root(0,2, 100, tolerance);

    float value_at_root = first_polinomial(real_root);
    value_at_root = value_at_root<0?-value_at_root:value_at_root;

    cr_assert(value_at_root < tolerance);
}


