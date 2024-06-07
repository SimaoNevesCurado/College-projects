#include <stdlib.h>
#include "memory.h"
#include "debug.h"
#include "matrix.h"
#include <unistd.h>
#include "args.h"
#include <stdin.h>

int main(){

struct gengeopt_args_info args;

if(cmdline_parser(argc,&argv)!= 0){
  exit(EXIT_INVALID_ARGS);

}


int r1 = args.r1_arg;
int c1 = args.c1_arg;
int r2 = args.r2_arg;
int c2 = args.c2_arg;

float **m1 =matrix_new(args.r1_arg, args.c1_arg);
float **m2 = matrix_new(args.r2_arg,args.c2_arg);


 
matrix_delete(m1);
matrix_delete(m2);

  return 0;
}
