#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void lerNotas(int notas[25], int QtdAlunos);
int letQuantidadeAvaliados();
void mostrarDados(int QtdAlunos,int notas[25]);
int calculamedia(int notas[25],int QtdAlunos);

int main()
{

    int notas[25] = {0};

    return 0;
}

int letQuantidadeAvaliados()
{
    int QtdAlunos;

    do
    {

        printf("indique o numero de Estudantes avaliados");
        scanf("%d", &QtdAlunos);
        if (QtdAlunos > 25 || QtdAlunos < 0)
        {
            printf("tente denovo");
        }

    } while (QtdAlunos > 25 || QtdAlunos < 0);
}

void lerNotas(int notas[25], int QtdAlunos)
{

    int i;
    int num;
    for (i = 0; i < QtdAlunos; i++)
    {
        do
        {
            printf("Escreva a nota do estudante n %d",num+1);
            scanf("%d",&notas[i]);

    


            if (notas[i] < 0 || notas[i] > 20)
            {

                printf("Nota invalida");
            }

        } while (notas[i] < 0 || notas[i] > 20);
    }
}

void mostrarDados(int QtdAlunos,int notas[25]){
int num,i;
    for ( i = 0; i < QtdAlunos; i++)
    {
        printf("Aluno %d: %d",num+1,notas[i]);
    }
    

}

int calculamedia(int notas[25],int QtdAlunos){
 int i,total;
 float media;

      for ( i = 0; i < QtdAlunos; i++)
    {
    total+=notas[i];
    }

    media=total/QtdAlunos;

    return media;
}

void alteraNota(int QtdAlunos,int notas[25]){

int notaalterada,posicao,i;

printf("Posicao alterar\n 0 - %d",QtdAlunos);
scanf("%d",&posicao);
printf("Nota a alterar");
scanf("%d",&notaalterada);

notas[posicao]=notaalterada;


}