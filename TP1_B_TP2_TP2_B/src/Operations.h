// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: OPERATIONS.H
// BREVE DESCRIPCIÓN: En este archivo se declaran las funciones implementadas en OPERATIONS.C

#include "Matrix.h"

Value Determinant(Matrix *mat);
Matrix Transpose(Matrix *mat);
Index Dim (Matrix *mat);
Index Rank (Matrix *mat);
void GaussElim (Matrix *mat, Value *coeffs, Index *exs);
Row row (Matrix *mat, Index i);
void Exchange (Matrix *mat, Index ith, Index jth);
Matrix Multiply (Matrix *mat1, Matrix *mat2);
Matrix Add(Matrix *mat1, Matrix *mat2);
Value MultipliedValue (Index i, Index j, Matrix *mat1, Matrix *mat2);
void Scale(Matrix *mat1, double lambda);
void ScaleRow (Row *r, double lambda);
void AddRow(Row *r, Index i, Matrix *mat);
Index FixPivot (Matrix *mat, Index ith, Index *col);
void RREF(Matrix *mat);





