#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcoesGenericas.h"
#include "veiculo.h"


/** ------------------- Fun��es dos VEICULOS ------------------- **/

// Fun��o que permite inserir um novo Veiculo no vetorVeiculos
int inserirNovoVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int posicao;
    tipoVeiculo novoVeiculo;

    if (quantVeiculos < MAX_VEICULOS)
    {
        printf("\n\n*********** NOVO Veiculo ***********\n\n");
        lerString("Matricula: ", novoVeiculo.matricula, TAM_MATRICULA);
        converteMaiuscula(novoVeiculo.matricula);
        posicao = procurarVeiculo(vetorVeiculos, quantVeiculos, novoVeiculo.matricula);

        if (posicao != -1)
        {
            printf("\n\nATENCAO: Ja existe veiculo com a matricula inserida.\n");
            escreverVeiculo(vetorVeiculos[posicao]);
        }
        else
        {
            lerString("\nMarca: ", novoVeiculo.marca, TEXTO_CURTO);
            converteMaiuscula(novoVeiculo.marca);
            lerString("\nModelo: ", novoVeiculo.modelo, TEXTO_CURTO);
            novoVeiculo.anoRegisto = lerInteiro("Ano Registo: ", MIN_ANO, MAX_ANO);
            novoVeiculo.tipo = lerInteiro("Tipo Veiculo (1-ligeiro, 2-pesado, 3-reboque) ", TIPO_LIGEIRO, TIPO_REBOQUE);
            novoVeiculo.totalKms = lerInteiro("Total Kms ", 0, MAX_TOTAL_KMS);

            vetorVeiculos[quantVeiculos]=novoVeiculo;
            quantVeiculos++;
            printf("\nVeiculo inserido com sucesso\n");
        }
    }
    else
    {
        printf("\n\nATENCAO: o limite maximo de Veiculos ja foi atingido\n\n");
    }
    return quantVeiculos;
}


// Fun��o que procura um Veiculo pela matricula.
// A fun��o devolve -1 se n�o encontrar o Veiculo ou devolve a posi��o(indice) do Veiculo no vetor
int procurarVeiculo(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, char matricula[])
{
   
    int posicao, i;

    posicao = -1;

   
    for (i=0; i < quantVeiculos;  i++)
    {
    

        if (strcmp(vetorVeiculos[i].matricula, matricula) == 0)
        {
             
            posicao = i;
            i = quantVeiculos;
        }
    }

    return posicao;
}

// Fun��o que lista no ecra os dados de todos os Veiculos inseridos no vetor
void listarVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    int i;

    if (quantVeiculos > 0)
    {
        printf("\n\n*********** LISTAGEM dos VEICULOS ***********\n\n");
        for (i=0; i < quantVeiculos; i++)
        {
            escreverVeiculo(vetorVeiculos[i]);
        }
    }
    else
    {
        printf("\n\nATENCAO: Nao existem Veiculos inseridos.\n\n");
    }
}


// Fun��o que escreve no ecra os dados de um Veiculo
void escreverVeiculo (tipoVeiculo dados)
{
    printf("\nMatricula: %s\t\t", dados.matricula);
    printf("Marca: %s \t\t\tModelo: %s \n", dados.marca, dados.modelo);
    printf("Ano Registo: %d\n",  dados.anoRegisto);
    switch (dados.tipo)
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

    printf("Total Kms: %d\n",  dados.totalKms);
}


/** ------------------- Fun��es dos FICHEIROS ------------------- **/

void escreverFicheiroBinarioVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos)
{
    FILE *ficheiro;
    int quantValoresEscritos;

    ficheiro = fopen("veiculos.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresEscritos = fwrite(&quantVeiculos, sizeof(int), 1, ficheiro);
        if (quantValoresEscritos != 1)
        {
            printf("\n\nERRO: falha na escrita da quantidade de Veiculos\n\n");
        }
        else
        {
            quantValoresEscritos = fwrite(vetorVeiculos, sizeof(tipoVeiculo), quantVeiculos, ficheiro);
            if (quantValoresEscritos != quantVeiculos)
            {
                printf("\n\nERRO: falha na escrita dos dados dos Veiculos\n\n");
            }
        }

        fclose(ficheiro);
    }
}



void lerFicheiroBinarioVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos)
{
    FILE *ficheiro;
    int quantValoresLidos, erro;

    erro = 0;

    ficheiro = fopen("veiculos.dat", "rb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresLidos = fread(quantVeiculos, sizeof(int), 1, ficheiro);
        if (quantValoresLidos != 1)
        {
            printf("\n\nERRO: falha na leitura da quantidade de Veiculos\n\n");
            erro = 1;
        }
        else
        {
            quantValoresLidos = fread(vetorVeiculos, sizeof(tipoVeiculo), *quantVeiculos, ficheiro);
            if (quantValoresLidos != *quantVeiculos)
            {
                printf("\n\nERRO: falha na leitura dos dados dos Veiculos\n\n");
                erro = 1;
            }
        }
        if (erro == 1)
        {
            *quantVeiculos = 0;
        }
        fclose(ficheiro);
    }
}
