// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: IOTEST.C
/*BREVE DESCRIPCIÓN: En este archivo se testea INPUTOUTPUT.C*/

#include <stdio.h>
#include "src/Matrix.h"

int main(int argc, const char * argv[]) {

  if (argc != 3){
    printf(stderr, "La cantidad de archivos no corresponde.\n");
    printf("La forma correcta es: \n iotest.c (...).txt  (...).txt");
    exit(1);
  }

  FILE* res;
    if ((res = fopen(argv[2], "w+")) == NULL){
        printf(stderr, "Error abriendo el archivo %s: %s\n", argv[2], strerror(errno));
        exit(1);
    }

  Matrix mat1 = ReadMatrix("matrix1.txt");

  PrintMatrix(&mat1);

  int writed = WriteMatrix(&mat1, "resultado.txt");

  if (writed) printf("Print successful!\n");
  else printf("Print unsuccessful!\n");

	fclose(res);

  return 0;
}