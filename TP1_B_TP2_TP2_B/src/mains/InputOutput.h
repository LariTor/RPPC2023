/**
 * @file InputOutput.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se declaran las funciones implementadas en InputOutput.c
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef INPUTOUTPUT_H
#define INPUTOUTPUT_H

#include "Matrix.h" // Incluyo mi archivo de encabezado de Matrix donde tengo las declaraciones

// Funciones de entrada y salida
Matrix ReadMatrix(char *filename);
int WriteMatrix(Matrix *mat, char *filename);

#endif // INPUTOUTPUT_H

