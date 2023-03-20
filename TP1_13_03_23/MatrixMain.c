/*TORLETTI LARA AGOSTINA - RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - IMPLEMENTANDO FUNCIONES CON MATRICES - 13/03/2023*/
//MAIN:

#include "Matrix.h" //Incluyo mi librería donde tengo declaraciones

int main(int argc, const char * argv[]) {

	int matrix1[DIM][DIM],res[DIM][DIM],matrix2[DIM][DIM];
    printf("Llenado manual de matriz 1\n");
    FillMatrixManually(matrix1);
    printf("La matriz 1 es:\n");
    ShowMatrix(matrix1);

    printf("Llenado automatico de matriz 2\n");
    FillMatrixManually(matrix2);
    printf("La matriz 2 es:\n");
    ShowMatrix(matrix2);
    
    printf("Operaciones con 1 matriz\n");

    printf("Producto escalar de matriz 1\n");    
    ScalarProductMatrix(matrix1,res);
    ShowMatrix(res);

    printf("Transpuesta de matriz 2\n");  
	TransposeMatrix(matrix2, res);
    ShowMatrix(res);

    printf("Operaciones con 2 matrices\n");
    
    printf("Suma de matriz 1 y matriz 2\n");   
    SumMatrix(matrix1,matrix2,res);
    ShowMatrix(res);

    printf("Producto de matriz 1 y matriz 2\n");  
    ProductMatrix(matrix1,matrix2,res);
    ShowMatrix(res);

	return 0;
}