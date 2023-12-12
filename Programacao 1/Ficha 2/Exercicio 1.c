#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    int aux=1;
    int somaW=0;
    int somaDW=0;
    int somaF=0;
    do{
          if(num<=0){
            printf("Numero negativo, porfavor voltar a introduzir\n");

          }

    printf("Escreva um numero\n");
    scanf("%d",&num);



        while(aux<=num)
        {
            somaW=somaW+aux;
            aux=aux+1;
        }
        printf("%d\n",somaW);
        aux=0;


        do
        {
            somaDW=somaDW+aux;
            aux=aux+1;

        }
        while(aux<=num);



        printf("%d\n",somaDW);

        for(aux=1; aux<=num; aux++)
        {

            somaF=somaF+aux;
        }
        printf("%d\n\n",somaF);

}while(num<=0);


    return 0;
}

