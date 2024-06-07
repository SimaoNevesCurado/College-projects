#include <matrix.h>
#include <memory.h>


float **matrix_new(int n_row,n_cols ){

  if(n_rows <= 0 || n_cols <=0)
  return NULL;


  float **matrix = MALLOC(sizeof(float *) *n_rows);
  float *data = MALLOC(sizeof(float) *n_cols * n_rows);

  for(i=0; i<n_rows;i++){
    matrix[i]=&data[i*n_cols];
  }

  return matrix;
}

void matrix_delete(float **matrix){
  if(matrix ==NULL)
  return;
FREE(matrix[0]);
FREE(matrix);
}

void matrix_fill(float **matrix, int n_rows, int n_cols, float init_value){

int i,j;

for(i=0;i<n_rows; i++){
  for(j=0; j<n_cols; i++){
    matrix[i][j]= init_value;
  }
}
}

void matrix_print(float **matrix, int n_rows, int n_cols){
  int i,j;

  for(i=0;i<n_rows;i++){
    for(j=0;j<n_cols;j++){
      printf("%10.2f",matrix[i][j]);
    }
    printf("\n");
  }
  printf("-----------------------------\n");
}
