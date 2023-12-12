#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
int TipoCombustivel(int Combustivel);
float LitrosConsumidos(float valorCombustivel, float litros);
char Menu();
int leValores();
int main()
{

    float km, valor, valorCombustivel, litrosTotal, consumomedio;
    int combustivel;
    char opcao;

   

   // valorCombustivel = TipoCombustivel(combustivel);
    //litrosTotal = LitrosConsumidos(valorCombustivel, valor);
    // printf("%.2f\n %.2f\n", km, valor);

    do{    

    opcao= Menu();

    switch(opcao){

        case 'I':

    printf("Indique a distancia percurrida em km\n");
    km = leValores();
    printf("Indique o montante de combustivel em Euros\n");
    valor = leValores();

    printf("Qual o tipo de combustivel\n\n(1)\n(2)\n(3)\n\nOPCAO");
    combustivel = leValores();


break;  

case 'C':
    valorCombustivel = TipoCombustivel(combustivel);
    litrosTotal = LitrosConsumidos(valorCombustivel, valor);
    consumomedio=(litrosTotal*100)/km;

    printf("CONSUMO MEDIO: %f\n\n",consumomedio);    

break;

case 'T':

    printf("SAIU DO PROGRAMA\n\n");

break;

default:
printf("Opcao invalida\n");

    }
    }while(opcao != 'T');

    return 0;
}

int leValores()
{

    float valor;

    scanf("%f", &valor);

    return valor;
}

int TipoCombustivel(int Combustivel)
{

    float valorCombustivel;
    switch (Combustivel)
    {

    case 1:

        printf("Preco por litro: 1,55 Euros \n");

        break;
    case 2:

        printf("Preco por litro: 1,65 Euros \n");

        valorCombustivel = 1.65;
        break;

    case 3:

        printf("Preco por litro: 1,80 Euros \n");

        valorCombustivel = 1.80;
        break;

    default:
        printf("OPCAO NAO EXIXSTE");
    }

    return valorCombustivel;
}

float LitrosConsumidos(float valorCombustivel, float litros)

{

    float litrostotal = litros / valorCombustivel;


    return litrostotal;
}


char Menu(){

char opcao;
    
    do{    
     printf("(I)ntroduzir percuso\n");
    printf("(C)onsumo medio\n");
    printf("(T)erminar\n");
    printf("Opcao: ");
    scanf(" %c",&opcao);
    opcao=toupper(opcao);
    }while(opcao !=  'I' && opcao != 'C' && opcao != 'T');
   return opcao; 
}