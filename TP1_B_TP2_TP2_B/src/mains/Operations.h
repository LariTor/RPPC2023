/**
 * @file  Operations.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se declaran las funciones implementadas en Operations.c
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "Matrix.h"

Value Determinant(Matrix *mat);

Value MultipliedValue (Index i, Index j, Matrix *mat1, Matrix *mat2);

Matrix Add (Matrix *mat1, Matrix *mat2);

void Scale (Matrix *mat, Value lambda);

Matrix Multiply (Matrix *mat1, Matrix *mat2);

void Exchange (Matrix *mat, Index ith, Index jth);

Row row (Matrix *mat, Index i);

void ScaleRow (Row *r, double lambda);

void ScaleMatrixRow (Matrix *mat, Index ith, Value lambda);

void AddRow (Row *r, Index i, Matrix *mat);

Index FixPivot (Matrix *mat, Index ith, Index *col);

void CleanDown (Matrix *mat, Index ith, Index jth);

void CleanUpZeros (Matrix *mat);

void GaussElim (Matrix *mat, Value *coeffs, Index *exs);

void RREF (Matrix *mat);

Index Rank (Matrix *mat);

Index Dim (Matrix *mat);

Matrix Transpose(Matrix *mat);

#endif //OPerations.h



