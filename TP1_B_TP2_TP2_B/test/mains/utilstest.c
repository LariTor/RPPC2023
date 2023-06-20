/**
 * @file iotest.c
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se testea  Utilities.c
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "../../src/mains/Matrix.h"

int main(int argc, const char * argv[]) {

  if (argc != 1){
    fprintf(stderr, "La cantidad de archivos no corresponde.\n");
    printf("La forma correcta es: \n opstest.c (...).txt  (...).txt");
    exit(1);
  }

  Matrix mat = CreateMatrix(100, 32);
  DestroyMatrix(&mat);

  printf("\nIdentity\n");
  Matrix A = IdentityMatrix(5);
  PrintMatrix(&A);

  printf("\nDuplicate\n");

  Matrix mat4 = ReadMatrix("../txt/matrix4.txt");
  Matrix dupd = DuplicateMatrix(&mat4);
  PrintMatrix(&dupd);

  return 0;
}