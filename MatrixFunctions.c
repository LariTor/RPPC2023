/*TORLETTI LARA AGOSTINA - RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - IMPLEMENTANDO FUNCIONES CON MATRICES - 13/03/2023*/
//IMPLEMENTACIÓN DE FUNCIONES

#include "Matrix.h" //Incluyo mi librería donde tengo declaraciones

//OPERACIONES CON UNA SOLA MATRIZ

void FillMatrixManually(int m[DIM][DIM]){

    int i ,j, c;

    for (i=0; i<DIM; i++){
        for (j=0; j<DIM; j++){
            printf("Ingrese un número\n");
            scanf("%d", &m[i][j]);
        }
    }

}

void FillMatrixAutomatically(int m[DIM][DIM]){
	for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			m[i][j] = pow(i,j);
		}
	}
}

void ShowMatrix(int m[DIM][DIM]){
    
    int i ,j;
    for (i=0; i<DIM; i++){ 
        for (j=0; j<DIM; j++){
            printf("%10d", m[i][j]);   
        }
        printf("\n");
    }    

}

void ScalarProductMatrix(int m[DIM][DIM], int res[DIM][DIM]){

    int n, i, j; 

    printf("Ingrese el escalar que desea multiplicar: \n");

    scanf("%i", &n);

    for (i=0; i<DIM; i++){ 
        for (j=0; j<DIM; j++){
            res[i][j]=n*m[i][j];
        }
    }

}

void TransposeMatrix(int m[DIM][DIM], int res[DIM][DIM]){
    for(int i=0;i<DIM;i++){
		for(int j=0;j<DIM;j++){
			res[i][j] = m[j][i];
		}
	}
}

//OPERACIONES CON DOS MATRICES

void SumMatrix(int m[DIM][DIM], int y[DIM][DIM], int res[DIM][DIM]){
    int  i, j; 

    for (i=0; i<DIM; i++){ 
        for (j=0; j<DIM; j++){
            res[i][j]=m[i][j]+y[i][j];
        }
    }
    
}

//FUNCION AUXILIAR PARA PODER HACER PRODUCT DE MATRICES, producto punto
int FuncAux(int *v1, int *v2){
    int k=0;
    for (int i = 0; i < DIM; i++){
        k += v1[i]*v2[i];
    }
    return k;
}

void ProductMatrix(int m[DIM][DIM], int y[DIM][DIM], int res[DIM][DIM]){
    int  i, j;
    int aux[DIM][DIM];
    TransposeMatrix(y,aux);
    for (i=0; i<DIM; i++){ 
        for (j=0; j<DIM; j++){
            res[i][j] = FuncAux(m[i], aux[j]);
        }
    }    
}
