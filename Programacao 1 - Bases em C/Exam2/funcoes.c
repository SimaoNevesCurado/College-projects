#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"
#include "funcoes.h"
#include "declaracoes.h"

int inserirNovoFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios)
{
  int i;

  tipoFuncionario novoFuncionario;
  if (quantFuncionarios < MAX_FUNCIONARIOS)
  {
    printf("\n\n****************NOVO FUNCIONARIO*****************");
    novoFuncionario.numero = lerInteiro("\nNumero: \n", 0, 50);
    i = procurarFuncionario(vetorFuncionarios, quantFuncionarios, novoFuncionario.numero);

    if (i != -1)
    {
      printf("\nJá existe \n");
    }
    else
    {

      lerString("\nNome: ", novoFuncionario.nome, TAM_NOME);
      novoFuncionario.vencimento = lerFloat("\nVencimento: ", 0, 99999);
      novoFuncionario.dataAdmissao = lerData("\nData: ");

      vetorFuncionarios[quantFuncionarios] = novoFuncionario;

      quantFuncionarios++;
    }
  }
  else
  {
    printf("Atingiu o maximo de funcionarios");
  }

  return quantFuncionarios;
}

void listarUmFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios)
{

  int numero;
  int posicao;

  numero = lerInteiro("Numero: ", 1, 50);
  posicao = procurarFuncionario(vetorFuncionarios, quantFuncionarios, numero);
  printf("\n.%d.", posicao);
  if (posicao == -1)
  {
    printf("Funcionario nao existe");
  }
  else
  {
    escreverFuncionario(vetorFuncionarios, posicao);
  }
}

void escreverFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int posicao)
{

  printf("\n Numero: %d", vetorFuncionarios[posicao].numero);
  printf(" Nome: %s\n", vetorFuncionarios[posicao].nome);
  printf(" Vencimento: %.2f\n", vetorFuncionarios[posicao].vencimento);
  printf(" Data: %d/%d/%d\n", vetorFuncionarios[posicao].dataAdmissao.dia, vetorFuncionarios[posicao].dataAdmissao.mes, vetorFuncionarios[posicao].dataAdmissao.ano);
}

void listarDadosFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios)
{

  int i;

  printf("\n.%d.", quantFuncionarios);
  if (quantFuncionarios > 0)
  {

    for (i = 0; i < quantFuncionarios; i++)
    {

      printf("\n Numero: %d", vetorFuncionarios[i].numero);
      printf(" Nome: %s\n", vetorFuncionarios[i].nome);
      printf(" Vencimento: %.2f\n", vetorFuncionarios[i].vencimento);
      printf(" Data: %d/%d/%d\n", vetorFuncionarios[i].dataAdmissao.dia, vetorFuncionarios[i].dataAdmissao.mes, vetorFuncionarios[i].dataAdmissao.ano);
    }
  }
  else
  {

    printf("\nNao há funcionarios");
  }
}

int procurarFuncionario(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios, int numero)
{

  int posicao, i;

  posicao = -1;

  for (i = 0; i < quantFuncionarios; i++)
  {

    if (vetorFuncionarios[i].numero == numero)
    {
      posicao = i;
      i = quantFuncionarios;
    }
  }
  return posicao;
}

float mediaVencimentos(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios)
{

  float total=0.0;
  
  int i;
  float mediaVencimentos=0.0;

  if (quantFuncionarios > 0)
  {

    for (i = 0; i < quantFuncionarios; i++)
    {
      total = total + vetorFuncionarios[i].vencimento;
      
    }
    mediaVencimentos = (total / ((float)quantFuncionarios));
  }else{

    mediaVencimentos= 0.0;
  }

  return mediaVencimentos;
}

void vencimentoSuperior(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS], int quantFuncionarios){

int i;
int contador =0;
float percentagem=0.0;

  if(quantFuncionarios > 0){

    for(i=0; i < quantFuncionarios;i ++){

        if(vetorFuncionarios[i].vencimento > 1000.0){
          contador++;
        }
    }

    percentagem=((float)contador*100)/(float)quantFuncionarios;

    printf("Percentagem: %.2f\n",percentagem);

  }else{
    printf("Nao ha funcionarios");
  }
}

int AdmissaoNovembro(tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS],int quantFuncionarios){


int i;
int contador = 0;

if(quantFuncionarios >0 ){

for(i=0;i < quantFuncionarios ; i++){

if( vetorFuncionarios[i].dataAdmissao.mes == 11){
  contador++;
}
}

}else{
  printf("Nao ha funcionarios\n");
}




  return contador;
}