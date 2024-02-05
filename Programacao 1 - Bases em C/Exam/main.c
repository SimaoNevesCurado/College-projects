/*
 * @folder numeroNome_ExameP1
 * @brief Gest�o da inspecao de veiculos
 * @date 09-01-2024
 * @author (COLOCAR O NUMERO, NOME E EMAIL)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funcoesGenericas.h"
#include "veiculo.h"

// FUNCOES DO EXAME
#include "exame.h"

int menu(int quantVeiculos);

/** ------------------------------ main ------------------------------ **/

int main()
{
    tipoVeiculo vetorVeiculos[MAX_VEICULOS];

    // vetor dinamico
    tipoInspecao *vetorInspecoes = NULL;

    int quantInspecoes = 0;

    int quantVeiculos, opcao, opcaoGravar;

    quantVeiculos = 0;

    lerFicheiroBinarioVeiculos(vetorVeiculos, &quantVeiculos);

    do
    {
        opcao = menu(quantVeiculos);
        switch (opcao)
        {
        case 1: // inserir novo Veiculos
            quantVeiculos = inserirNovoVeiculo(vetorVeiculos, quantVeiculos);
            break;
        case 2: // Listar Veiculos
            listarVeiculos(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 3: // listar veiculos pesados -------------------------------------------------- FEITO
            listarVeiculosPesados(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 4:
            listarVeiculosPorMarca(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 5:
            atualizarKms(vetorVeiculos, quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 6:
            vetorInspecoes=inserirNovaInspecao(vetorInspecoes,&quantInspecoes,vetorVeiculos, quantVeiculos);
            printf("\n\n.%d.",quantInspecoes);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 7:
 
            listarDadosInspecoes(vetorInspecoes,quantInspecoes,vetorVeiculos,quantVeiculos);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 8:
            escreverFicheiroTextoInspecoes(vetorInspecoes,vetorVeiculos,quantVeiculos,quantInspecoes);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 9:
            VeiculosInfiaveis(vetorVeiculos,vetorInspecoes,quantVeiculos,quantInspecoes);
            printf("\n\nPressione ENTER para avancar\n\n");
            getchar();
            break;
        case 0:
            printf("\n\n Saida!");
            break;
        }
    } while (opcao != 0);

    printf("\n\n Deseja armazenar no ficheiro os dados dos veiculos (1-Sim  2-Nao) \n ");
    opcaoGravar = lerInteiro("\t\t Indique a opcao:", 1, 2);
    if (opcaoGravar == 1)
    {
        escreverFicheiroBinarioVeiculos(vetorVeiculos, quantVeiculos);
    }

free(vetorInspecoes);
    return 0;
}

/** ------------------------------ Menu Principal ------------------------------ **/

int menu(int quantVeiculos)
{
    int opcao;

    printf("\n\n---------------- INSPECAO DE VEICULOS DE FROTA ----------------\n");
    printf("\nTOTAL VEICULOS: %d\n\n", quantVeiculos);

    printf("\n- VEICULOS -\n");
    printf("\t1  - Adicionar novo Veiculos\n\t2  - Listar Veiculos\n");

    printf(" - EXAME -\n");
    printf("\t3  - Funcionalidade A -Listar pesados \n\t4  - Funcionalidade B -Listar por marca\n");
    printf("\t5  - Funcionalidade C - Atualizar kms\n\t6  - Funcionalidade D - inserir inspecao\n");
    printf("\t7  - Funcionalidade E - listar inspecao \n\t8  - Funcionalidade F - Escrever no ficheiro\n");
    printf("\t9  - Funcionalidade G - Veiculos Infiaveis  \n");

    printf("\n\t0  - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 9);

  

    return opcao;
}
