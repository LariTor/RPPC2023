/**
 * @file Operations.c
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se implementan las siguientes funciones:
          -> Determinant: Calcula el determinante de la matriz.
          -> Transpose: Transpone la matriz.
          -> RREF: Convierte la matriz a su forma escalonada reducida por filas.
          -> row: Devuelve la i-ésima fila de la matriz.
          -> Add: Suma dos matrices (si es posible, sino muestra un error).
          -> Exchange: Intercambia las filas i y j en la matriz.
          -> Multiply: Multiplica dos matrices (si es posible, sino muestra un error).
          -> Scale: Escala una matriz por un factor lambda.
          -> ScaleRow: Escala una fila por un factor lambda.
          -> AddRow: Agrega una fila r en la i-ésima posición de la matriz.
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "Operations.h"

Value Determinant(Matrix *mat) {
  assert(mat->rows == mat->cols);

  Index exs;
  Value coeffs;
  Matrix dp = DuplicateMatrix(mat);

  GaussElim(&dp, &coeffs, &exs);

  Value det = pow(-1, exs) * coeffs;

  return EqualZero(det) ? 0.0 : det;
}

Value MultipliedValue(Index i, Index j, Matrix *mat1, Matrix *mat2) {
  Index k, l;
  Value v = 0;

  for (k = 0; k < mat1->cols; ++k)
    v += mat1->vals[i][k] * mat2->vals[k][j];

  return v;
}

Matrix Add(Matrix *mat1, Matrix *mat2) {
  assert(mat1->rows == mat2->rows && mat1->cols == mat2->cols);

  Matrix sum = CreateMatrix(mat1->rows, mat1->cols);
  Index i, j;

  for (i = 0; i < sum.rows; ++i)
    for (j = 0; j < sum.cols; ++j)
      sum.vals[i][j] = mat1->vals[i][j] + mat2->vals[i][j];

  return sum;
}

void Scale(Matrix *mat, Value lambda) {
  Index i, j;

  for (i = 0; i < mat->rows; ++i)
    for (j = 0; j < mat->cols; ++j)
      mat->vals[i][j] *= lambda;
}

Matrix Multiply(Matrix *mat1, Matrix *mat2) {
  assert(mat1->cols == mat2->rows);

  Matrix mult = CreateMatrix(mat1->rows, mat2->cols);
  Index i, j;

  for (i = 0; i < mult.rows; ++i)
    for (j = 0; j < mult.cols; ++j)
      mult.vals[i][j] = MultipliedValue(i, j, mat1, mat2);

  return mult;
}

void Exchange(Matrix *mat, Index ith, Index jth) {
  assert(ith < mat->rows && jth < mat->rows);

  Index i, j;
  Value tmp;

  for (i = 0; i < mat->cols; ++i) {
    tmp = mat->vals[ith][i];
    mat->vals[ith][i] = mat->vals[jth][i];
    mat->vals[jth][i] = tmp;
  }
}

Row row(Matrix *mat, Index i) {
  assert(i < mat->rows);

  Row r;
  r.row = mat->cols;
  r.val = malloc(r.row * sizeof(Value));
  HandleAllocError(r.val);

  memcpy(r.val, mat->vals[i], r.row * sizeof(Value));

  return r;
}

void ScaleRow(Row *r, double lambda) {
  Index i;

  for (i = 0; i < r->row; ++i)
    r->val[i] *= lambda;
}

void ScaleMatrixRow(Matrix *mat, Index ith, Value lambda) {
  Index i;

  for (i = 0; i < mat->cols; ++i)
    mat->vals[ith][i] *= lambda;
}

void AddRow(Row *r, Index i, Matrix *mat) {
  assert(i < mat->rows && r->row == mat->cols);
  Index j;

  for (j = 0; j < mat->cols; ++j)
    mat->vals[i][j] += r->val[j];
}

Index FixPivot(Matrix *mat, Index ith, Index *col) {
  if (ith == mat->rows - 1 || mat->vals[ith][*col] != 0) return 0;

  Index i, ith_ = ith, exs = 0;

  for (i = ith_ + 1; i < mat->rows; ++i) {
    if (mat->vals[i][*col] != 0) {
      Exchange(mat, i, ith_);
      exs++;
      ith_++;

      if (mat->vals[ith_][*col] != 0) break;
    }
  }

  for (i = *col; i < mat->cols && EqualZero(mat->vals[ith][i]); ++i);

  *col = i;

  return exs;
}

void CleanDown(Matrix *mat, Index ith, Index jth) {
  if (ith == mat->rows - 1) return;

  Index i;
  Value prev = 1;

  for (i = ith + 1; i < mat->rows; ++i) {
    Row r = row(mat, ith);
    ScaleRow(&r, prev * -1 * mat->vals[i][jth]);
    AddRow(&r, i, mat);
  }
}

void CleanUpZeros(Matrix *mat) {
  Index i, j;

  for (i = 0; i < mat->rows; ++i)
    for (j = 0; j < mat->cols; ++j)
      if (EqualZero(mat->vals[i][j])) mat->vals[i][j] = 0;
}

void GaussElim(Matrix *mat, Value *coeffs, Index *exs) {
  Index i;
  Values v = mat->vals;
  *coeffs = 1;
  *exs = 0;

  for (i = 0; i < mat->rows; ++i) {
    Index col = i;

    *exs += FixPivot(mat, i, &col);

    if (col == mat->cols || EqualZero(v[i][col])) {
      *coeffs = 0;
      break;
    }

    *coeffs *= v[i][col];
    ScaleMatrixRow(mat, i, 1 / v[i][col]);

    CleanDown(mat, i, col);
  }

  CleanUpZeros(mat);

  mat->inrref = 1;
}

void RREF(Matrix *mat) {
  Index a;
  Value b;
  GaussElim(mat, &b, &a);
}

Index Rank(Matrix *mat) {
  if (!mat->inrref) {
    Matrix m_ = DuplicateMatrix(mat);
    mat = &m_;
    RREF(mat);
  }

  Index i, j, rk = 0;

  for (i = 0; i < mat->rows; ++i) {
    for (j = 0; j < mat->cols && EqualZero(mat->vals[i][j]); ++j);
    if (j < mat->cols) rk++;
  }

  return rk;
}

Index Dim(Matrix *mat) {
  return Rank(mat);
}

Matrix Transpose(Matrix *mat) {
  Matrix tp = CreateMatrix(mat->cols, mat->rows);
  Index i, j;

  for (i = 0; i < mat->rows; ++i)
    for (j = 0; j < mat->cols; ++j)
      tp.vals[j][i] = mat->vals[i][j];

  return tp;
}
