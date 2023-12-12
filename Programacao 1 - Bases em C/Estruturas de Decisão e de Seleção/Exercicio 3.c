#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num;
    int numtotal = 0;
    int numInt = 0;
    int neg = 0;
    int pos = 0;
    float media, percentPositivos, percentNegativos;

    do // FAZ
    {

        printf("indique um numero sem ser  0\n\n");
        scanf("%d", &num);

        if (num != 0)
        {

            numInt++;                  // Soma os numeros intruduzidos
            numtotal = numtotal + num; // Vai somandos todos os numeros

            if (num > 0)
            {
                pos++; // Soma os numeros intruduzidos NEGATIVOS
            }

            if (num < 0)
            {

                neg++; // Soma os numeros intruduzidos POSITIVOS
            }
        }

    } while (num != 0); // Enquanto numero introduzido for diferente de 0

    media = (float)numtotal / numInt; // Calcula a media

    percentPositivos = (float)(pos * 100) / numInt; // regra de 3 simples para calcular a percentagem
    percentNegativos = (float)(neg * 100) / numInt; // regra de 3 simples para calcular a percentagem

    // Escreve os resultados
    printf("Soma total: %d\n", numtotal);
    printf("Quantidade de numeros: %d\n", numInt);
    printf("Quantidade de Numeros Positivos: %d\n", pos);
    printf("Quantidade de Numeros Negativos: %d\n", neg);
    printf("Percentagem de numeros Positivos: %.2f\n", percentPositivos);
    printf("percentagem de numeros negativos: %.2f\n", percentNegativos);

    return 0;
}
