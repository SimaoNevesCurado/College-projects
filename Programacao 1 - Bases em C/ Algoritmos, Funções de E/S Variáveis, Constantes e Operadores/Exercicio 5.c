#include <stdio.h>
#include <stdlib.h>

int main()


{
    int ValorCompras,ValorPagar, desconto;
    printf("Indique o valor as compras\n");
    scanf("%d",&ValorCompras);

    if(ValorCompras<=500)
    {
        system("cls");
        printf("Valor a Pagar %d EUROS\n\n",ValorCompras);
    }
    if(ValorCompras>500 && ValorCompras<=1250)
    {
        desconto=ValorCompras*0.04;
        ValorPagar = ValorCompras-desconto;
        system("cls");
        printf("Valor a pagar %d EUROS\n\n",ValorPagar);
    }

    if(ValorCompras>1250 && ValorCompras<=2000)
    {
        desconto=ValorCompras*0.06;
        ValorPagar = ValorCompras-desconto;
        system("cls");
        printf("Valor a pagar %d EUROS\n\n",ValorPagar);
    }
    if(ValorCompras>2000)
    {
        desconto=ValorCompras*0.08;
        ValorPagar = ValorCompras-desconto;
        system("cls");
        printf("Valor a pagar %d EUROS\n\n",ValorPagar);
    }


return 0;
}
