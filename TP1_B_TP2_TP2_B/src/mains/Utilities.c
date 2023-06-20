/**
 * @file Utilities.c
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se implementan las funciones:
 *    ->HandleAllocError: Tira error si la alocación falló
 *    ->EqualZero: Hago todos los valores = 0
 *    ->CreateMatrix: Devuelve una row*col Matrix. Con data alocada dinámicamente en Heap
 *    ->DestroyMatrix: Elimina la matrix
 *    ->IdentityMatrix: Crea una matrix identidad n*n
 *    ->DuplicateMatrxi: Devuelve la matrix duplicada
 *    ->PrintMatrix: Imprime la matriz
 *    ->PrintROw: Imprime los elementos de la fila
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 */
 
#include "Utilities.h"

void HandleAllocError(void *ptr) {
  if (ptr != NULL) return;
  fprintf(stderr, "Some allocation failed!!! ╚(•⌂•)╝\n");
  exit(1);
}

int EqualZero (Value v) {
  return fabs(v) < 10e-8;
  //The fabs() function takes a single argument (in double) and returns the absolute value of that number (also in double)
}

Matrix CreateMatrix(Index row_size, Index col_size) {

  Matrix mat;

  mat.rows = row_size;
  mat.cols = col_size;
  mat.inrref = 0;
  mat.vals = malloc(mat.rows * sizeof(Value *));
  HandleAllocError(mat.vals);
  Index i;
  for (i = 0; i < mat.rows; ++i) {
    mat.vals[i] = malloc(mat.cols * sizeof(Value));
    HandleAllocError(mat.vals[i]);
  }

  return mat;
}

void DestroyMatrix (Matrix *mat) {
  Index i;
  for (i = 0; i < mat->rows; ++i)
    free(mat->vals[i]);
  free(mat->vals);
  //void free(void *ptr) deallocates the memory previously allocated by a call to malloc
  mat->rows = 0;
  mat->cols = 0;
  mat->vals = NULL;
}

Matrix IdentityMatrix (Index n) {
  Matrix idmat = CreateMatrix(n, n);

  Index i, j;
  for (i = 0; i < idmat.rows; ++i)
    for (j = 0; j < idmat.rows; ++j)
      idmat.vals[i][j] = i == j;

  return idmat;
}

Matrix DuplicateMatrix (Matrix *mat) {
  Matrix dmat = CreateMatrix(mat->rows, mat->cols);
  Index i, j;
  for (i = 0; i < mat->rows; ++i)
    for (j = 0; j < mat->cols; ++j)
      dmat.vals[i][j] = mat->vals[i][j];
  return dmat;
}

void PrintMatrix(Matrix *mat) {
  for (Index i = 0; i < mat->rows; ++i) {
    for (Index j = 0; j < mat->cols; ++j) {
      printf("%7.2f ", mat->vals[i][j]);
    }
    printf("\n");
  }
}


void PrintRow (Row *r) {
  printf("Elementos de la fila: %d\n", r->row);
  Index i;
  for (i = 0; i < r->row; ++i) {
    printf("%.f ", r->val[i]);
  }
  printf("\n");
}

/*
int GetMaxDigitsPP(Matrix *mat) {
  int maxDigits = 0;
  for (Index i = 0; i < mat->rows; ++i) {
    for (Index j = 0; j < mat->cols; ++j) {
      int digits = snprintf(NULL, 0, "%.2f", mat->vals[i][j]);
      if (digits > maxDigits) {
        maxDigits = digits;
      }
    }
  }
  return maxDigits;
}
void PrettyPrintMatrix(Matrix *mat) {
  int maxDigits = GetMaxDigitsPP(mat);  // Obtiene la cantidad máxima de dígitos en los elementos de la matriz
  for (Index i = 0; i < mat->rows; ++i) {
    for (Index j = 0; j < mat->cols; ++j) {
      printf("%*.*f ", maxDigits + 3, 2, mat->vals[i][j]);  // Añade un espacio adicional antes de cada elemento
    }
    printf("\n");
  }
}*/