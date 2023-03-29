// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: BASICUTILITIES.H
// BREVE DESCRIPCIÓN: En este archivo se declaran las funciones implementadas en BASICUTILITIES.C

#include "Matrix.h"

Matrix CreateMatrix (Index row_size, Index col_size);

void DestroyMatrix (Matrix *mat);

Matrix IdentityMatrix (Index n);

Matrix DuplicateMatrix(Matrix *mat);

void HandleAllocError(void *ptr);