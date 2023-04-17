// ALUMNA: TORLETTI LARA AGOSTINA
// CATEDRA: RESOLUCIÓN DE PROBLEMAS POR COMPUTADORA - UNRN 
// TEMA: IMPLEMENTANDO FUNCIONES CON MATRICES DINAMICAS Y MANEJO DE ARCHIVOS
// FECHA: 17/03/23 -> Ultima modificación 22/03/23
// ARCHIVO: INPUTOUTPUT.C
/*BREVE DESCRIPCIÓN: En este archivo se implementan las funciones:
	-> ReadMatrix: La cual se encarga de extraer y leer del archivo la matriz.
	-> WriteMatrix: La cual se encarga de escribir la matriz en un archivo. 
*/

#include "InputOutput.h" //Incluyo mi librería donde tengo declaraciones

Matrix ReadMatrix (char *filename){

	FILE *fp = fopen(filename, "rt");

	if(fp == NULL){
        fprintf(stderr, "Could not open %s: %s !!╚(•⌂•)╝\n", filename, strerror(errno));
        exit(1);
    }

	char c; 
	Value n;
	Index row_size=1, col_size=1, col_size_=0;

	while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    	if (c == ';') {
      		col_size_ = col_size;
      		col_size = 1;
      		row_size++;
    	}
    	if (c == ' ') col_size++;
  	}

	Matrix mat = CreateMatrix(row_size, col_size); //Leer el archivo denuevo para obtener los valores
  	Index i = 0;
  	Index j = 0;

  	fseek(fp, 0, SEEK_SET); //volvemos al inicio del file
  	fscanf(fp, "%c%lf", &c, &n);
  	mat.vals[i][j] = n;
  	while (fscanf(fp, "%c%lf", &c, &n) != EOF) {
    	if (c == ';') mat.vals[++i][j = 0] = n;
    	if (c == ' ') mat.vals[i][++j] = n;
  	}

  	fclose(fp);

  	return mat;
}

int WriteMatrix (Matrix *mat, char *filename){

	FILE *fp = fopen(filename, "wt");

	if(fp == NULL){
        fprintf(stderr, "Could not open %s: %s !!╚(•⌂•)╝\n", filename, strerror(errno));
        exit(1);
    }

	fprintf(fp, "[");

	for (int i = 0; i < mat->rows; ++i) {
    for (int j = 0; j < mat->cols; ++j)
      if (j < mat->rows - 1) fprintf(fp, "%f ", mat->vals[i][j]);
      else fprintf(fp, "%f", mat->vals[i][j]);
    if (i < mat->rows - 1) fprintf(fp, "; ");
  }
	
	fprintf(fp, "]");

	fclose(fp);
  	return 1;

}
