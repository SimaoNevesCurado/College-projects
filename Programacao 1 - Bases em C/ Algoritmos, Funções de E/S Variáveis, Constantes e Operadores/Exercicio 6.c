#include <stdio.h>
#include <stdlib.h>



int main()
{
    int num1,num2,resultado;
    char operacao;


    printf("Diga um  numero\n");
    scanf("%d",&num1);


    printf("Diga um numero\n");
    scanf("%d",&num1);

    printf("Diga a operacao\n");
    scanf(" %c",&operacao);



    if(operacao =='+')
    {

        resultado = num1+num2;

        printf("\n\n\n\n\nResultado: %d",resultado);
    }
    else
    {

        if(operacao=='-')
        {

            resultado= num1-num2;

            printf("\n\n\n\n\nResultado: %d",resultado);
        }
        else
        {
            if(operacao =='*' || operacao=='x')
            {

                resultado= num1*num2;

                printf("\n\n\n\n\nResultado: %d",resultado);
            }
            else
            {


                if(operacao == '/' || operacao==':')
                {
                    if(num1 ==0 || num2 ==0)
                    {
                        printf("\n\nErro - Divisao por zero\n");
                    }
                    resultado= num1/num2;

                    printf("\n\n\n\n\nResultado: %d",resultado);
                }
                else
                {

                    if(operacao == '%')
                    {
                        resultado= num1%num2;

                        printf("\n\n\n\n\nResultado: %d",resultado);
                    }
                    else
                    {

                        if(operacao != '+' && operacao != '-' && operacao != '*' && operacao!= 'x' && operacao != '/' && operacao!= ':' &&operacao != '%')
                        {

                            printf("\n\nOPERADOR DESCONHECIDO");
                        }
                    }
                }
            }




        }

    }

    return 0;
}
