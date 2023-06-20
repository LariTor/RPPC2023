/**
 * @file InputOutput.c
 * @author Lara Torletti (lara.a.torletti@gmail.com)
 * @brief En este archivo se implementan las funciones:
		-> ReadMatrix: La cual se encarga de extraer y leer del archivo la matriz.
		-> WriteMatrix: La cual se encarga de escribir la matriz en un archivo. 
 * @version 0.1
 * @date 2023-06-19
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "InputOutput.h" //Incluyo mi librería donde tengo declaraciones

Matrix ReadMatrix(char *filename) {
    FILE *fp = fopen(filename, "rt");

    if (fp == NULL) {
        fprintf(stderr, "Could not open %s: %s !!╚(•⌂•)╝\n", filename, strerror(errno));
        exit(1);
    }

    char c;
    Value n;
    Index row_size = 1, col_size = 1, col_size_ = 0;

    while (fscanf(fp, "%lf%c", &n, &c) != EOF) {
        if (c == ';') {
            col_size_ = col_size;
            col_size = 1;
            row_size++;
        }
        if (c == ' ') col_size++;
    }

    Matrix mat = CreateMatrix(row_size, col_size); // Leer el archivo de nuevo para obtener los valores
    Index i = 0;

    fseek(fp, 0, SEEK_SET); // Volver al inicio del archivo

    while (fscanf(fp, "%lf%c", &n, &c) != EOF) {
        mat.vals[i / col_size][i % col_size] = n;
        i++;
    }

    fclose(fp);

    return mat;
}

int WriteMatrix(Matrix *mat, char *filename) {
    FILE *fp = fopen(filename, "wt");

    if (fp == NULL) {
        fprintf(stderr, "Could not open %s: %s !!╚(•⌂•)╝\n", filename, strerror(errno));
        exit(1);
    }

    fprintf(fp, "[");

    for (int i = 0; i < mat->rows; ++i) {
        for (int j = 0; j < mat->cols; ++j) {
            if (j < mat->cols - 1)
                fprintf(fp, "%f ", mat->vals[i][j]);
            else
                fprintf(fp, "%f", mat->vals[i][j]);
        }
        if (i < mat->rows - 1)
            fprintf(fp, "; ");
    }

    fprintf(fp, "]");

    fclose(fp);
    return 1;
}