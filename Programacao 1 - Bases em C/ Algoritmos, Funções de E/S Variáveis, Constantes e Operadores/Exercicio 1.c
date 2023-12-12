#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    printf("Introduza um numero inteiro\n");
    scanf("%d",&numero);
    if (numero==0)
    {
        printf("O numero %d e um numero nulo\n",numero);
    }
    else
    {
        if(numero > 0)
        {
            printf("O numero %d e um numero positivo\n",numero);
            if(numero%2==0)
            {
                printf("O numero %d e um numero par\n",numero);
            }
            else
            {
                printf("O numero %d e um numero impar\n",numero);
            }
        }
        else
        {
            if(numero <0)
            {
                printf("O numero %d e um numero negativo\n",numero);
                if(numero%2==0)
                {
                    printf("O numero %d e um numero par\n",numero);
                }
                else
                {
                    printf("O numero %d e um numero impar\n",numero);
                }
            }
        }
    }

    return 0;
}
