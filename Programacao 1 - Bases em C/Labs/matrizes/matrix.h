#pragma once
float **matrix_new(int n_row,n_cols );
void matrix_print(float **matrix, int n_rows, int n_cols);
void matrix_delete(float **matrix);
void matrix_fill(float **matrix, int n_rows, int n_cols, float init_value);
