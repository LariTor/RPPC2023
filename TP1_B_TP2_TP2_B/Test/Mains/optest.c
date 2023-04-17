// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: OPTEST.C
/*BREVE DESCRIPCIÓN: En este archivo se testea OPERATIONS.C*/

#include <stdio.h>
#include "src/Matrix.h"

int main(int argc, const char * argv[]) {

  if (argc != 9){
    printf(stderr, "La cantidad de archivos no corresponde.\n");
    printf("La forma correcta es: \n opstest.c (...).txt  (...).txt");
    exit(1);
  }

  Matrix a = ReadMatrix("./matrix2.txt");
  Matrix b = ReadMatrix("./matrix3.txt");
  Matrix c = ReadMatrix("./matrix4.txt");
  Matrix d = ReadMatrix("./matrix5.txt");
  Matrix e = ReadMatrix("./matrix6.txt");
  Matrix f = ReadMatrix("./matrix7.txt");
  Matrix g = ReadMatrix("./matrix8.txt");
  Matrix h = ReadMatrix("./matrix9.txt");

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
  RowScale(&r, -5);
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