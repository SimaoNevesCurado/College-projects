#include <stdlib.h>
#include <stdio.h>

int leNumero();
int areaRetangulo(int altura,int base);
void leDadosRetangulo(int *altura, int *base);
int main()
{

    int area, base, altura;

   leDadosRetangulo(&base,&altura);

    area=areaRetangulo(base,altura);

    printf(" \n\narea e de : %d", area);

    return 0;
}

int leNumero()
{

    int num;
    do
    {
        scanf("%d", &num);

        if (num <= 0)
        {

            printf("coloque um numero acima de 0");
        }

    } while (num <= 0);

    return num;
}

int areaRetangulo(int altura,int base){

int res= base*altura;

return res;
}

void leDadosRetangulo(int *altura, int *base){

printf("Indique valor da altura\n");
*altura=leNumero();


printf("Indique valor da base\n");
*base=leNumero();
}