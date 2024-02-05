#ifndef declaracoes_H_INCLUDED
#define declaracoes_H_INCLUDED

#define TAM_NOME 25
#define MAX_FUNCIONARIOS 50

typedef struct{

int dia;
int mes;
int ano;

}tipoData;

typedef struct{

int numero;
char nome[TAM_NOME];
float vencimento;
tipoData dataAdmissao;


}tipoFuncionario;




#endif