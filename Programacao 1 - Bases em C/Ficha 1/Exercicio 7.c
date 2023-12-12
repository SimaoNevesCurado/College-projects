#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num1,num2,resultado;
    char operacao;


    printf("Diga um  numero\n");
    scanf("%d",&num1);


    printf("Diga um numero\n");
    scanf("%d",&num2);

    printf("Diga a operacao\n");
    scanf(" %c",&operacao);



    switch(operacao)
    {
    case '+':
        resultado= num1+num2;
        printf("RESULTADO: %d",resultado);
        break;

    case '-':
        resultado= num1-num2;
        printf("RESULTADO: %d",resultado);
        break;
    case '*' ||'x' :
        resultado= num1*num2;
        printf("RESULTADO: %d",resultado);
    case '*':
    case 'x':
    case 'X':
        resultado= num1*num2;
        printf("RESULTADO: %d",resultado);

        break;

    case '/':
    case ':':

        if(num1 ==0 || num2==0)
        {
            resultado= num1/num2;
            printf("RESULTADO: %d",resultado);
        }
        else
        {
            printf("ERRO- DIVISAO POR ZERO");
        }
        break;
    case '%':
        resultado= num1%num2;
        printf("RESULTADO: %d",resultado);
        break;
    default:
        printf("OPERACAO INVALIDA");

    }
    return 0;
}
