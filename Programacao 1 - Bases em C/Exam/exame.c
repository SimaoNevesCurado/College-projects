#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#include "funcoesGenericas.h"
#include "exame.h"
#include "veiculo.h"


void listarVeiculosPesados(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
  int i;

  if (quantVeiculos > 0)
  {
    printf("\n\n*********** LISTAGEM dos VEICULOS Pesados ***********\n\n");
    for (i = 0; i < quantVeiculos; i++)
    {
      if (vetorVeiculos[i].tipo == 2)
      {
        printf("\nMatricula: %s\t\t", vetorVeiculos[i].matricula);
        printf("Marca: %s \n", vetorVeiculos[i].marca);
        printf("Ano Registo: %d\n", vetorVeiculos[i].anoRegisto);
        printf("Total Kms: %d\n", vetorVeiculos[i].totalKms);
      }
    }
  }
  else
  {
    printf("\n\nATENCAO: Nao existem Veiculos inseridos.\n\n");
  }
}


void listarVeiculosPorMarca(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
  int i;

  if (quantVeiculos > 0)
  {
    printf("\n\n*********** LISTAGEM dos VEICULOS Por marca ***********\n\n\n");
    char marcaLida[TEXTO_CURTO];
    lerString("Qual é a marca do carro?\n", marcaLida, TEXTO_CURTO);

    for (i = 0; i < quantVeiculos; i++)
    {

      if (strcmp(vetorVeiculos[i].marca, marcaLida) == 0 && vetorVeiculos[i].anoRegisto > 2020)
      {

        printf("Marca: %s \t\t\tModelo: %s \n", vetorVeiculos[i].marca, vetorVeiculos[i].modelo);
        printf("Ano Registo: %d\n", vetorVeiculos[i].anoRegisto);
        printf("Tipo: %d\n", vetorVeiculos[i].tipo);
        printf("Total Kms: %d\n", vetorVeiculos[i].totalKms);
      }
    }
  }
  else
  {
    printf("\n\nATENCAO: Nao existem Veiculos inseridos.\n\n");
  }
}


void atualizarKms(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{

  char matriculaLida[TAM_MATRICULA];
  int i, kmsAtualizados = 0, kmsAntigos = 0, distancia = 0;

  lerString("\nIndique a matricula do veiculo: ", matriculaLida, TAM_MATRICULA);
  converteMaiuscula(matriculaLida);
  i = procurarVeiculo(vetorVeiculos, quantVeiculos, matriculaLida);

  if (i != -1)
  {
    // guarda o valor dos kms antigos
    kmsAntigos = vetorVeiculos[i].totalKms;
    printf("\nKMS atuais: %d\n\n", vetorVeiculos[i].totalKms);
    do
    {
      kmsAtualizados = lerInteiro("\nIndique os kms:\n", 0, MAX_TOTAL_KMS);
      if (kmsAtualizados < kmsAntigos)
      {
        printf("\nErro- Nao pode inserir menos kms\n");
      }
    } while (kmsAtualizados < kmsAntigos);
    vetorVeiculos[i].totalKms = kmsAtualizados;
    distancia = kmsAtualizados - kmsAntigos;

    printf("DISTANCIA PERCORRIDA: %d KM", distancia);
  }
  else
  {

    printf("nao existe matricula");
  }
}

tipoInspecao *inserirNovaInspecao(tipoInspecao *vetorInspecoes, int *quantInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
  int i;
  char matriculaLida[TAM_MATRICULA];

  if (quantVeiculos > 0)
  {
    printf("\n\n*********** NOVA Inspecao ***********\n\n");

    lerString("\nInsira a Matricula: \t", matriculaLida, TAM_MATRICULA);
    converteMaiuscula(matriculaLida);
    i = procurarVeiculo(vetorVeiculos, quantVeiculos, matriculaLida);

    if (i != -1)
    {
      vetorInspecoes = realloc(vetorInspecoes, (*quantInspecoes + 1) * sizeof(tipoInspecao));

      vetorInspecoes[*quantInspecoes].codigo = *quantInspecoes;
      strcpy(vetorInspecoes[*quantInspecoes].matricula, vetorVeiculos[i].matricula);
      vetorInspecoes[*quantInspecoes].totalKms = vetorVeiculos[i].totalKms;
      vetorInspecoes[*quantInspecoes].dataInspecao = lerData("\nInsira a data de inspecao\n");
      vetorInspecoes[*quantInspecoes].resultado = lerInteiro("\nInsira o resultado da inspecao:\n1- Aprovado\t 2- Reprovado\n", 1, 2);
      lerString("\nAnotacoes:\n", vetorInspecoes[*quantInspecoes].anotacoes, TEXTO_LONGO);
      vetorInspecoes[*quantInspecoes].custo = lerFloat("\nInsira um custo:", 0.0, 10000000.0);
      (*quantInspecoes)++;
    }
    else
    {
      printf("Carro nao existe");
    }
  }
  else
  {
    printf("nao ha inspecoes");
  }
  return vetorInspecoes;
}


void listarDadosInspecoes(tipoInspecao *vetorInspecoes, int quantInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
  char matriculaLida[TAM_MATRICULA];
  int i, j;
  int totalInspecoes = 0;

  for (i = 0; i < quantVeiculos; i++)
  {
    totalInspecoes = 0;
    printf("\n\nMatricula: %s \n", vetorVeiculos[i].matricula);
    switch (vetorVeiculos[i].tipo)
    {
    case TIPO_LIGEIRO:
      printf("Tipo: LIGEIRO \n");
      break;
    case TIPO_PESADO:
      printf("Tipo: PESADO \n");
      break;
    case TIPO_REBOQUE:
      printf("Tipo: REBOQUE \n");
      break;
    }
    printf("Total Kms: %d\n", vetorVeiculos[i].totalKms);

    for (j = 0; j < quantInspecoes; j++)
    {

      if (strcmp(vetorVeiculos[i].matricula, vetorInspecoes[j].matricula) == 0)
      {
        totalInspecoes++;

        printf("Codigo: %d\n", vetorInspecoes[j].codigo);
        printf("Data Inspecao: %d/%d/%d\n", vetorInspecoes[j].dataInspecao.dia, vetorInspecoes[j].dataInspecao.mes, vetorInspecoes[j].dataInspecao.ano);
        switch (vetorInspecoes[j].resultado)
        {
        case TIPO_APROVADO:
          printf("Tipo: APROVADO\n");
          break;
        case TIPO_REPROVADO:
          printf("Tipo: REPROVADO \n");
          break;
        }
        printf("Anotacoes:\n %s\n", vetorInspecoes[j].anotacoes);
        printf("Custo: %.2f\n", vetorInspecoes[j].custo);
      }
    }
    printf("Inspecoes: %d\n", totalInspecoes);
  }
}

void listarDadosInspecoesUnico(tipoInspecao *vetorInspecoes, int quantInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
  char matriculaLida[TAM_MATRICULA];
  int i, j;

  lerString("\nIndique a matricula:\n", matriculaLida, TAM_MATRICULA);
  converteMaiuscula(matriculaLida);

  i = procurarVeiculo(vetorVeiculos, quantVeiculos, matriculaLida);

  if (i == -1)
  {
    printf("Veiculo nao existe");
  }
  else
  {

    printf("\n\nMatricula: %s \n", vetorVeiculos[i].matricula);
    switch (vetorVeiculos[i].tipo)
    {
    case TIPO_LIGEIRO:
      printf("Tipo: LIGEIRO \n");
      break;
    case TIPO_PESADO:
      printf("Tipo: PESADO \n");
      break;
    case TIPO_REBOQUE:
      printf("Tipo: REBOQUE \n");
      break;
    }
    printf("Total Kms: %d\n", vetorVeiculos[i].totalKms);
  }

  j = procurarInspecao(vetorInspecoes, quantInspecoes, matriculaLida);

  if (j == -1)
  {
    printf("Este carro nao tem inspecoes\n");
  }
  else
  {
    printf("Codigo: %d\n", vetorInspecoes[j].codigo);
    printf("Data Inspecao: %d/%d/%d\n", vetorInspecoes[j].dataInspecao.dia, vetorInspecoes[j].dataInspecao.mes, vetorInspecoes[j].dataInspecao.ano);
    switch (vetorInspecoes[j].resultado)
    {
    case TIPO_APROVADO:
      printf("Tipo: APROVADO\n");
      break;
    case TIPO_REPROVADO:
      printf("Tipo: REPROVADO \n");
      break;
    }
    printf("Anotacoes:\n %s\n", vetorInspecoes[j].anotacoes);
    printf("Custo: %.2f\n", vetorInspecoes[j].custo);
  }
}

int procurarInspecao(tipoInspecao *vetorInspecoes, int quantInspecoes, char matricula[])
{
  int posicao = -1;

  for (int i = 0; i < quantInspecoes; i++)
  {

    if (strcmp(vetorInspecoes[i].matricula, matricula) == 0)
    {
      posicao = i;
      i = quantInspecoes;
    }
  }

  return posicao;
}

void escreverFicheiroTextoInspecoes(tipoInspecao *vetorInspecoes, tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, int quantInspecoes)
{
  FILE *ficheiro;

  int i, j;
  char matriculaLida[TAM_MATRICULA];
  lerString("\nIndique a matricula que quer guardar:\n", matriculaLida, TAM_MATRICULA);
  converteMaiuscula(matriculaLida);

  i = procurarVeiculo(vetorVeiculos, quantVeiculos, matriculaLida);
  j = procurarInspecao(vetorInspecoes, quantInspecoes, matriculaLida);

  ficheiro = fopen("InspecoesData.txt", "a");

  if (ficheiro == NULL)
  {
    printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
  }

  if (i != -1)
  {

    fprintf(ficheiro, "Marca: %s\n", vetorVeiculos[i].marca);
    switch (vetorVeiculos[i].tipo)
    {
    case TIPO_LIGEIRO:
      fprintf(ficheiro, "Resultado:  Ligeiro \n");
      break;
    case TIPO_PESADO:
      fprintf(ficheiro, "Resultado:  Pesado \n");
      break;
    case TIPO_REBOQUE:
      fprintf(ficheiro, "Resultado:  Reboque \n\n");
      break;
    }
  }
  else
  {
    printf("\n\nERRO: A GUARDAR OS DADOS DOS VEICULOS.\n\n");
  }

  if (j != -1)
  {

    fprintf(ficheiro, "Codigo: %d\n", vetorInspecoes[j].codigo);
    fprintf(ficheiro, "Matricula: %s\n", vetorInspecoes[j].matricula);
    fprintf(ficheiro, "Total Kms: %d\n", vetorInspecoes[j].totalKms);
    fprintf(ficheiro, "Data Inspecao: %d/%d/%d\n", vetorInspecoes[j].dataInspecao.dia, vetorInspecoes[j].dataInspecao.mes, vetorInspecoes[j].dataInspecao.ano);
    fprintf(ficheiro, "Resultado: %d\n", vetorInspecoes[j].resultado);
    switch (vetorInspecoes[j].resultado)
    {
    case TIPO_APROVADO:
      fprintf(ficheiro, "Resultado:  Aprovado \n");
      break;
    case TIPO_REPROVADO:
      fprintf(ficheiro, "Resultado:  Reprovado \n");
      break;
    }
    fprintf(ficheiro, "Anotacoes: %s\n", vetorInspecoes[j].anotacoes);
    fprintf(ficheiro, "Custo: %f", vetorInspecoes[j].custo);
  }
  else
  {
    printf("\n\nERRO: A GUARDAR OS DADOS DAS INSPECOES.\n\n");
  }

  fclose(ficheiro);
}

void VeiculosInfiaveis(tipoVeiculo vetorVeiculos[MAX_VEICULOS], tipoInspecao *vetorInspecoes, int quantVeiculos, int quantInspecoes)
{

  int i, j;
  int contador, totalcontador;
  float percentagem;
  float menorPercentagem=0.0;



  for (i = 0; i < quantVeiculos; i++)
  {
    contador = 0;
    totalcontador = 0;

    for (j = 0; j < quantInspecoes; j++)
    {

      if (strcmp(vetorVeiculos[i].matricula, vetorInspecoes[j].matricula) == 0)
      {

        if (vetorInspecoes[j].resultado == TIPO_REPROVADO)
        {
          contador++;
        }
        totalcontador++;
      }

      percentagem = ((float)contador * 100) / totalcontador;
    }
    if (percentagem > menorPercentagem)
    {
      menorPercentagem = percentagem;
    }
  }

  for (i = 0; i < quantVeiculos; i++)
  {
    contador = 0;
    totalcontador = 0;

    for (j = 0; j < quantInspecoes; j++)
    {

      if (strcmp(vetorVeiculos[i].matricula, vetorInspecoes[j].matricula) == 0)
      {

        if (vetorInspecoes[j].resultado == 2)
        {
          contador++;
        }
        totalcontador++;
      }

      percentagem = ((float)contador * 100) / totalcontador;
    }
    if (percentagem == menorPercentagem)
    {

      printf("Matricula: %s\n", vetorVeiculos[i].matricula);
      printf("Percentagem: %.2f\n", menorPercentagem);
    }
  }
}