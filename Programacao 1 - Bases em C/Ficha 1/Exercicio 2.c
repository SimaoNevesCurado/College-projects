#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
    printf("Escreva 3 valores inteiros\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);

    if(num1 != num2 && num1 != num3 && num2 != num3)
    {

        printf("\n\nOs numeros %d, %d e %d SAO todos diferentes\n\n", num1,num2,num3);

    }
    else
    {

        printf("\n\nOs numeros %d, %d e %d NAO SAO todos diferentes\n\n", num1,num2,num3);
    }

    return 0;
}
