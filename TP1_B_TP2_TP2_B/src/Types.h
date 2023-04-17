// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: TYPES.H
// BREVE DESCRIPCIÓN: En este archivo se declaran las estructuras matriz y fila

//Indice de la matriz
typedef unsigned int Index;

//Valores de la matriz
typedef double Value;

//Arreglo dinamico 2D 
typedef Value **Values;

typedef Value *RowValues;

//STRUCT MATRIX
typedef struct{
    Index rows; // Numero de Filas 
    Index cols; // Numero de Columnas
    Values vals; // Valores de la matriz
    int inrref; // TRUE si la matriz tiene la forma RREF (reduce row echelon form) (es invertible)
}Matrix;

typedef struct {
  Index row;           // Tamaño fila
  RowValues val;       // Valores en fila 
} Row;