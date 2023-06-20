/**
 * @file Types.h
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se declaran las estructuras matriz y fila
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef TYPES_H
#define TYPES_H

// Indice de la matriz
typedef unsigned int Index;

// Valores de la matriz
typedef double Value;

// Arreglo dinámico 2D 
typedef Value **Values;

typedef Value *RowValues;

// ESTRUCTURA MATRIX
typedef struct {
    Index rows;   // Número de filas 
    Index cols;   // Número de columnas
    Values vals;  // Valores de la matriz
    int inrref;   // TRUE si la matriz tiene la forma RREF (reduce row echelon form) (es invertible)
} Matrix;

typedef struct {
    Index row;         // Tamaño de fila
    RowValues val;     // Valores en fila 
} Row;

#endif //TYPES_H