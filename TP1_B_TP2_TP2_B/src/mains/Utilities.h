/**
 * @file ConstantsAndLibraries.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se declaran las funciones implementadas en Utilities.c
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Matrix.h"

void HandleAllocError(void *ptr);

int EqualZero (Value v);

Matrix CreateMatrix(Index row_size, Index col_size);

void DestroyMatrix (Matrix *mat);

Matrix IdentityMatrix (Index n);

Matrix DuplicateMatrix (Matrix *mat);

void PrintMatrix (Matrix *mat);

void PrintRow (Row *r);

//void PrettyPrintMatrix(Matrix *mat);

//int GetMaxDigitsPP(Matrix *mat);
