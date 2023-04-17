// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: UTILSTEST.C
/*BREVE DESCRIPCIÓN: En este archivo se testea UTILITIES.C*/

#include <stdio.h>
#include "src/Matrix.h"

int main(int argc, const char * argv[]) {

  if (argc != 1){
    printf(stderr, "La cantidad de archivos no corresponde.\n");
    printf("La forma correcta es: \n opstest.c (...).txt  (...).txt");
    exit(1);
  }

  Matrix mat = CreateMatrix(100, 32);

  Destroy(&mat);

  printf("\nIdentity\n");
  Matrix A = IdentityMatrix(5);
  PrintMatrix(&A);

  printf("\nDuplicate\n");
  Matrix dupd = DuplicateMatrix(&A);
  PrintMatrix(&dupd);

  return 0;
}