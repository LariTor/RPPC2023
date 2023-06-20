/**
 * @file iotest.c
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se testea InputOutput.c
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "../../src/mains/Matrix.h"

int main(int argc, const char * argv[]) {

  Matrix mat1 = ReadMatrix("../txt/matrix1.txt");

  PrintMatrix(&mat1);

  int writed = WriteMatrix(&mat1, "../txt/resultado.txt");

  if (writed) printf("Print successful!\n");
  else printf("Print unsuccessful!\n");

  return 0;
}
