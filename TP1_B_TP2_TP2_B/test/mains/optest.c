/**
 * @file iotest.c
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se testea Operations.c
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "../../src/mains/Matrix.h"

int main(int argc, const char * argv[]) {

  if (argc != 9){
    fprintf(stderr, "La cantidad de archivos no corresponde.\n");
    printf("La forma correcta es: \n opstest.c (...).txt  (...).txt");
    exit(1);
  }

  Matrix a = ReadMatrix("../txt/matrix2.txt");
  Matrix b = ReadMatrix("../txt/matrix3.txt");
  Matrix c = ReadMatrix("../txt/matrix4.txt");
  Matrix d = ReadMatrix("../txt/matrix5.txt");
  Matrix e = ReadMatrix("../txt/matrix6.txt");
  Matrix f = ReadMatrix("../txt/matrix7.txt");
  Matrix g = ReadMatrix("../txt/matrix8.txt");
  Matrix h = ReadMatrix("../txt/matrix9.txt");

  printf("\nAdd\n");
  Matrix sum = Add(&a, &b);
  PrintMatrix(&sum);
  

  printf("\nScale\n");
  Value l = 2;
  Scale(&a, l);
  PrintMatrix(&a);


  printf("\nMultiply\n");
  Matrix mult = Multiply(&c, &d);
  PrintMatrix(&mult);


  printf("\nExchange\n");
  Exchange(&mult, 0, 1);
  PrintMatrix(&mult);


  printf("\nRow\n");
  Row r = row(&mult, 1);
  PrintRow(&r);


  printf("\nRow scale\n");
  ScaleRow(&r, -5);
  PrintRow(&r);


  printf("\nAddRow row\n");
  AddRow(&r, 0, &mult);
  PrintMatrix(&mult);


  printf("\nRREF\n");
  RREF(&e);
  PrintMatrix(&e);

  printf("\n");

  RREF(&g);
  PrintMatrix(&g);


  printf("\nRank\n");
  printf("rank of e: %d\n", Rank(&e));
  printf("rank of f: %d\n", Rank(&f));
  printf("rank of g: %d\n", Rank(&g));


  printf("\nTranspose\n");
  Matrix tr = Transpose(&mult);
  PrintMatrix(&tr);


  printf("\nDeterminant\n");
  printf("Determinant of h: %.2f\n", Determinant(&h));

  return 0;
}