#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliares.h"
#include "funcoes.h"
#include "declaracoes.h"

int menuPrincipal(int quantFuncionarios,float mediaVencimentos, int admissao);
int main()
{
  int quantFuncionarios = 0;
  int opcao;
  float vencimentos=0.0;
  int admissao=0;


  tipoFuncionario vetorFuncionarios[MAX_FUNCIONARIOS];

  do
  {

    admissao= AdmissaoNovembro(vetorFuncionarios,quantFuncionarios);
  vencimentos=mediaVencimentos(vetorFuncionarios,quantFuncionarios);

    opcao = menuPrincipal(quantFuncionarios,vencimentos,admissao);

   
    switch (opcao)
    {
    case 1:
    quantFuncionarios=inserirNovoFuncionario(vetorFuncionarios,quantFuncionarios);

      break;

    case 2:
    listarUmFuncionario(vetorFuncionarios,quantFuncionarios);

      break;
    case 3:
    listarDadosFuncionario(vetorFuncionarios,quantFuncionarios);

      break;
    case 4:
    vencimentoSuperior(vetorFuncionarios,quantFuncionarios);


      break;
      case 0:

      break;
    default:
    printf("Nao existe");
      break;
    }
  } while (opcao != 0);

  return 0;
}

int menuPrincipal(int quantFuncionarios,float mediaVencimentos, int admissao)
{

  int opcao;

  printf("\n\n---------------- MENU PRINCIPAL ----------------\n");
  printf("\nNum Funcionarios: %d \n\n", quantFuncionarios);
  printf("\nMedia Vencimentos: %.2f \n\n", mediaVencimentos);
  printf("\nFuncionario Admitidos no mes de novembro:  %d \n\n",admissao);

  printf("\t1  - Novo Funcionario \n\t2  - Listar Dados de um Funcionario \n");
  printf("\t3  - Mostrar dados dos funcionarios\n\t4  - Percentagem de funcionarios(Salario > 1000€)\n");
  printf("\t5  -  \n\t6  - \n");
  printf("\t7  -   \n");

  printf("\n\t0  - Sair\n\n");

  opcao = lerInteiro("\t\tIndique a opcao:", 0, 9);

  return opcao;
}