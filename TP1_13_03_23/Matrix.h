/*TORLETTI LARA AGOSTINA - RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - IMPLEMENTANDO FUNCIONES CON MATRICES - 13/03/2023*/
//LLAMADO A .H Y DECLARACIÓN DE FUNCIONES:

#ifndef Matrix_h
#define Matrix_h

#include "ConstantsAndLibraries.h"

//FUNCTIONS

void FillMatrixManually(int m[DIM][DIM]);

void FillMatrixAutomatically(int m[DIM][DIM]);

void ShowMatrix(int m[DIM][DIM]);

void ScalarProductMatrix(int m[DIM][DIM], int res[DIM][DIM]);

void SumMatrix(int m[DIM][DIM], int m1[DIM][DIM], int res[DIM][DIM]);

void ProductMatrix(int m[DIM][DIM], int m1[DIM][DIM], int res[DIM][DIM]);

void TransposeMatrix(int m[DIM][DIM], int res[DIM][DIM]);


#endif
