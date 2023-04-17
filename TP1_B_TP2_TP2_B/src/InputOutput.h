// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: INPUTOUTPUT.H
// BREVE DESCRIPCIÓN: En este archivo se declaran las funciones implementadas en INPUTOUTPUT.C

#include "Matrix.h" //incluyo libreria 

//OUTPUT
Matrix ReadMatrix(char *filename);

//INPUT
int WriteMatrix(Matrix *mat, char *filename);