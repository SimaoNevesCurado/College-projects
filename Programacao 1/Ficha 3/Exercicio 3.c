#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
int binomioDiscriminante(int a, int b, int c);
int numDeZerosReais(int a, int b, int c, float *x1, float *x2);
int lerNumeros();

int main()
{

    int a, b, c, binomio, resultado, B;
    float x1, x2;

    printf("Determinação  dos  zeros  reais  de  um  polinómio  do  2º  grau\n\n");

    a = lerNumeros();
    printf("Indique um numero\n");
    scanf("%d", &b);
    printf("Indique um numero\n");
    scanf("%d", &c);

   // binomio = binomioDiscriminante(a, b, c);
   // printf("Com a=%d , b=%d  c=%d, o binomio = %d \n\n", a, b, c, binomio);

    resultado = numDeZerosReais(a, b, c, &x1, &x2);
    if (resultado == 0)
    {
        printf("Nao ha zeros reais\n\n");
    }
    else
    {
        if (resultado == 1)
        {
            // x1=-b/(float)(2*a);
            printf("R= %2.f\n\n", x1);
        }
        else
        {

            // B=binomioDiscriminante(a,b,c);
            // x1=(-b + (float) sqrt(b*b-4*a*c))/2*a;
            // x2=(-b - (float) sqrt(b*b-4*a*c))/2*a;

            printf("Raizes do polinomio\n R1= %2.f \n R2= %2.f ", x1, x2);
        }
    }
    return 0;
}

int lerNumeros()
{

    int num;

    do
    {

        printf("Indique um valor\n\n");
        scanf("%d", &num);

        if (num == 0)
        {

            printf("Valor do a = 0 , tente novamente\n\n");
        }

    } while (num == 0);

    return num;
}

int binomioDiscriminante(int a, int b, int c)
{

    int binomio;
    binomio = b * b - 4 * a * c;

    return binomio;
}
int numDeZerosReais(int a, int b, int c, float *x1, float *x2)
{

    int binomio, resultado;
    binomio = binomioDiscriminante(a, b, c);
    if (binomio < 0)
    {

        resultado = 0;
    }
    else
    {
        if (binomio == 0)
        {

            resultado = 1;
            *x1 = -b / (float)(2 * a);
        }
        else
        {

            resultado = 2;

            int B = binomioDiscriminante(a, b, c);
            *x1 = (-b + (float)sqrt(B)) / 2 * a;
            *x2 = (-b - (float)sqrt(B)) / 2 * a;
        }
    }

    return resultado;
}