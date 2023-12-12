#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3;
    printf("Escreva 3 numeros inteiros de modo a construir um triangulo\n\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    scanf("%d",&num3);

    if(abs(num1-num2<num3 && num3<num1+num2))
    {
        printf("Pode ser um triangulo\n");

        if(num1 == num2 && num1 == num3 && num2 == num3)
        {

            printf(" Lado 1: %d\n Lado 2: %d\n Lado 3: %d",num1,num2,num3);
            printf("\n\nO Triangulo e EQUILATERO\n\n");
        }
        else
        {
            if(num1 != num2 && num1 != num3 && num2 != num3)
            {

                printf("Lado 1: %d\n Lado 2: %d\n Lado 3: %d",num1,num2,num3);
                printf("\n\nO Triangulo e ESCALENO\n\n");
            }

            else
            {
                if(num1== num2 || num2 == num3 || num3==num1)
                {
                    printf("Lado 1: %d\n Lado 2: %d\n Lado 3: %d",num1,num2,num3);
                    printf("\n\nO Triangulo e ISOSCELES\n");
                }

            }
        }



    }
    else
    {
        printf("nao pode ser um triangulo");
    }

    return 0;
}
