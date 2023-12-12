
#include <stdlib.h>

#include <stdio.h>

#include <ctype.h>

#define PI 3.1415

    int menu();

int areaRetangulo(int altura, int base);

float areaCirculo(int raio);

float areaTriangulo(int altura, int base);

int areaQuadrado(int base);

void leDados(int *a, int *b);

int leNumero();

int main()

{

    int base, altura;

    float area;

    float areaDoTriangulo;

    int areaDoQuadrado;

    int contadorQ = 0, contadort = 0, contadorC = 0, contadorR = 0;

    char opcao;

    float areaDoCirculo;

    int areaDoRetangulo;

    do

    {

        opcao = menu(contadorC, contadorQ, contadort, contadorR);

        opcao = toupper(opcao);

        switch (opcao)

        {

        case 'T':

            leDados(&altura, &base);

            areaDoTriangulo = areaTriangulo(base, altura);

            contadort++;

            printf("\n\nArea do triangulo e : %.2f\n\n", areaDoTriangulo);

            break;

        case 'Q':

            base = leNumero();

            areaDoQuadrado = areaQuadrado(base);

            contadorQ++;

            printf("\n\nArea do quadrado e : %d\n\n", areaDoQuadrado);

            break;

        case 'C':

            altura = leNumero();

            areaDoCirculo = areaCirculo(altura);

            contadorC++;

            printf("\n\nArea do Circulo e : %.2f\n\n", areaDoCirculo);

            break;

        case 'R':

            altura = leNumero();

            base = leNumero();

            areaDoRetangulo = areaRetangulo(base, altura);

            contadorR++;

            printf("\n\nArea do Circulo e : %d\n\n", areaDoRetangulo);

            break;

        case 'F':

            printf("\n\nSair do programa");

            break;

        default:

            printf("Caracter Invalido");
        }

    }

    while (opcao != 'F');

    return 0;
}

int menu(int c, int q, int t, int r)

{

    char opcao;

    printf("\n\n\t\t\t\tCalculo de areas\n\n");

    printf("Triangulo N: %d \t\t\t\t\t\t Retangulo N: %d\n\n", t, r);

    printf("Circulo N: %d \t\t\t\t\t\t Quadrado N: %d\n", c, q);

    printf("\n\tOPCOES:\n\n");

    printf("\t (T)riangulo\n");

    printf("\t (R)etangulo\n");

    printf("\t (Q)uadrado\n");

    printf("\t (C)irculo\n");

    printf("\t F)im\n");

    printf("\nSelecione opcao: ");

    scanf(" %c", &opcao);

    return opcao;
}

int areaRetangulo(int altura, int base)

{

    float area = base * altura;

    return area;
}

float areaCirculo(int raio)

{

    float area = ((float)PI * raio) * (PI * raio);

    return area;
}

float areaTriangulo(int altura, int base)

{

    float area = ((float)base * altura) / 2;

    return area;
}

int areaQuadrado(int base)

{

    float area = base * base;

    return area;
}

void leDados(int *a, int *b)
    {

        printf("Indique valor da altura\n");

        *a = leNumero();

        printf("Indique valor da base\n");

        *b = leNumero();
    }

int leNumero()

{


    int num;

    do

    {

        printf("\nEscreva um numero: ");

        scanf("%d", &num);

        if (num <= 0)

        {

            printf("coloque um numero acima de 0");
        }

    }

    while (num <= 0);

    return num;
}
