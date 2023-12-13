#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"
#include "funcoes_reservas.h"
#define MAX 100
#define MAXSTRING 64
#define MIN_NUM 1
#define MAX_NUM 9999

typedef struct{
  int numero;  
  char nome[MAXSTRING];
  tipoData dataAval;
  float nota;
}tipoEstudante;

void limpaBufferStdin();
int lerQuantidadeEstudantes();
void lerDadosEstudante(tipoEstudante *estudante, tipoEstudante estudantes[MAX], int quantidade);
int lerNotas(tipoEstudante estudantes[MAX], int quantidade);
void mostrarDados(tipoEstudante estudantes[MAX], int quantidade);

void acrescentaEstudante(tipoEstudante estudantes[MAX], int *quantidade);
int obterNumEstudanteExistente(tipoEstudante estudantes[MAX], int quantidade);
int procuraEstudante(tipoEstudante estudantes[MAX], int quantidade);
char menu(tipoEstudante estudantes[MAX], int quantidade);
void contas(tipoEstudante estudantes[MAX], int quantidade, int *num_avaliados, float *per_notas_positivas);
void gravaFicheiroBinario(tipoEstudante estudantes[MAX], int quantidade);
void lerFicheiroBinario(tipoEstudante estudantes[MAX], int *quantidade);
void gravaFicheiroTexto(tipoEstudante estudantes[MAX], int quantidade);

int main(){
  tipoEstudante estudantes[MAX];
  int quantidade = 0;
  Reserva* reservas = NULL;
  int num_reservas = 0;
  int tamanho = MAX_RESERVA;
  reservas = reservar_espaco(reservas, tamanho);
  char op; 
  do{
    op = menu(estudantes, quantidade);
    switch(op) {
      case 'A':
        printf("Ok\n");
        acrescentaEstudante(estudantes, &quantidade);
        break;
      case 'I':
        lerNotas(estudantes, quantidade);
        break;
      case 'M':
        mostrarDados(estudantes, quantidade);
        break;
      case 'G':
        gravaFicheiroBinario(estudantes, quantidade);
        gravaFicheiroTexto(estudantes, quantidade);
        break;
      case 'L':
        lerFicheiroBinario(estudantes, &quantidade);
        break;
      case 'R':
        if(quantidade == 0) {
          printf("Nao existe estudantes para reservar refeicao.\n");
          break;
        }
        adicionar_reserva(reservas, &num_reservas, &tamanho, obterNumEstudanteExistente(estudantes, quantidade));
        break;
      case 'E':
        break;
      default:
        printf("Opcao invalida\n");
    }
  }while(op != 'F');

  free(reservas);

  return 0;
}

int lerInteiro(int min, int max) {
  int op, controlo;
  do{
    printf("Introduza um inteiro entre %d e %d\n", min, max);
    controlo = scanf("%d", &op);
    limpaBufferStdin();
  }while(controlo == 0 || op < min || op > max);
  return op;
}

float lerFloat(float min, float max){
  int controlo;
  float op;
  do{
    printf("Introduza um inteiro entre %.1f e %.1f\n", min, max);
    controlo = scanf("%f", &op);
    limpaBufferStdin();
  }while(controlo == 0 || op < min || op > max);
  return op;
}

void limpaBufferStdin(){
  char chr;
  do{
    chr = getchar();
  }while(chr != '\n' && chr != EOF);
}

void lerString(char string[MAXSTRING]) {
  fgets(string, MAXSTRING, stdin);
  limpaBufferStdin();
}

int lerQuantidadeEstudantes() {
  int quantidade = 0;
  quantidade = lerInteiro(0, MAX);
  
  return quantidade;
}

void lerDadosEstudante(tipoEstudante *estudante, tipoEstudante estudantes[MAX], int quantidade){
  printf("Introduza o numero do estudante:\n");
  estudante->numero = procuraEstudante(estudantes, quantidade);
  
  printf("Introduza o nome do estudante:\n");
  lerString(estudante->nome);
}

int lerNotas(tipoEstudante estudantes[MAX], int quantidade){
  int num_avaliados = 0;
  for(int i = 0; i < quantidade; i++){
    printf("Introduza a nota do estudante n%d\n", i);
    estudantes[i].nota = lerFloat(0, 20);
    num_avaliados++;
  }
  return num_avaliados;
}

void mostrarDados(tipoEstudante estudantes[MAX], int quantidade){
  for(int i = 0; i < quantidade; i++){
    printf("Numero: %d\n", estudantes[i].numero);
    printf("Nome: %s\n", estudantes[i].nome);
    printf("Data: %d/%d/%d\n",
       estudantes[i].dataAval.dia, estudantes[i].dataAval.mes, estudantes[i].dataAval.ano);
    printf("Nota: %.1f\n", estudantes[i].nota);
  }
}

tipoData lerData(){
  tipoData data;
  printf("Introduza a data de avaliacao\n");
  printf("Introduza o dia:\n");
  data.dia = lerInteiro(1, 31);
  printf("Introduza o mes:\n");
  data.mes = lerInteiro(1, 12);
  printf("Introduza o ano:\n");
  data.ano = lerInteiro(1999, 2023);
  return data;
}

void acrescentaEstudante(tipoEstudante estudantes[MAX], int *quantidade) {
  if(*quantidade == MAX){
    printf("A quantidade maxima de estudantes ja foi atingida\n");
    return;
  }

  tipoEstudante estudante;
  lerDadosEstudante(&estudante, estudantes, *quantidade);
  estudante.dataAval = lerData();
  estudantes[*quantidade] = estudante;
  estudantes[*quantidade].nota = -1.0f;
  (*quantidade)++;
}

int obterNumEstudanteExistente(tipoEstudante estudantes[MAX], int quantidade){
  printf("Introduza um numero de estudante existente:\n");
  int num, count = 0; 
  do{
    num = lerInteiro(MIN_NUM, MAX_NUM);  
    for(int i = 0; i < quantidade; i++) {
      if(estudantes[i].numero == num){
        count++;
      }
    }
  }while(count == 0);
  return num;
}

int procuraEstudante(tipoEstudante estudantes[MAX], int quantidade){
  int num, count = 0; 
  do{
    num = lerInteiro(MIN_NUM, MAX_NUM);  
    for(int i = 0; i < quantidade; i++) {
      if(estudantes[i].numero == num){
        count++;
      }
    }
  }while(count > 0);
  return num;
}

char menu(tipoEstudante estudantes[MAX], int quantidade){
  char op;
  int num_avaliados = 0;
  float per_notas_positivas = 0.0f;
  contas(estudantes, quantidade, &num_avaliados, &per_notas_positivas);
  printf("****************** Menu Principal ******************\n");
  printf("Estudantes Inseridos: %d\n", quantidade); 
  printf("Estudantes Avaliados: %d\t Notas Positivas(%%): %.2f\n", num_avaliados, per_notas_positivas);
  printf("A - Acrescenta Estudante\n");
  printf("I - Introducao Notas\n");
  printf("M - Mostrar Dados\n");
  printf("G - Gravar dados em ficheiros\n");
  printf("L - Ler dados em ficheiro\n");
  printf("R - Reservar refeicao\n");
  printf("E - Eliminar reserva\n");
  printf("F - Fim\n");
  printf("\tOpcao-->");
  scanf(" %c", &op);
  return toupper(op);
}

void contas(tipoEstudante estudantes[MAX], int quantidade, int *num_avaliados, float *per_notas_positivas)
{
  for(int i = 0; i < quantidade; i++){
    if(estudantes[i].nota > 0.0f){
      (*num_avaliados)++;
      if(estudantes[i].nota >= 9.5) {
        *per_notas_positivas += 1.0f;
      }
    } 
  }
  *per_notas_positivas = (*per_notas_positivas * 100.0f) / *num_avaliados;  
}

void gravaFicheiroBinario(tipoEstudante estudantes[MAX], int quantidade) {
  FILE *ficheiro;

  ficheiro = fopen("dados.dat", "wb");
  if (ficheiro == NULL){
    printf("Erro a abrir ficheiro!\n");
    return;
  }
  
  fwrite(&quantidade, sizeof(int), 1, ficheiro);
  fwrite(estudantes, sizeof(tipoEstudante), quantidade, ficheiro);
  fclose(ficheiro);
}

void gravaFicheiroTexto(tipoEstudante estudantes[MAX], int quantidade) {
  FILE *ficheiro;

  ficheiro = fopen("dados.txt", "w");
  if (ficheiro == NULL){
    printf("Erro a abrir ficheiro!\n");
    return;
  }
  
  fprintf(ficheiro, "%d\n", quantidade);
  for(int i = 0; i < quantidade; i++){
    fprintf(ficheiro, "Numero: %d\n", estudantes[i].numero); 
    fprintf(ficheiro, "Nome: %s\n", estudantes[i].nome); 
    fprintf(ficheiro, "Nota: %.1f\n", estudantes[i].nota); 
    fprintf(ficheiro, "Data: Dia: %d Mes: %d Ano %d\n", estudantes[i].dataAval.dia, estudantes[i].dataAval.mes, estudantes[i].dataAval.ano); 
  }
  
  fclose(ficheiro);
}

void lerFicheiroBinario(tipoEstudante estudantes[MAX], int *quantidade) {
  FILE *ficheiro;

  ficheiro = fopen("dados.dat", "rb");
  if (ficheiro == NULL){
    printf("Erro a abrir ficheiro!\n");
    return;
  }
  
  fread(quantidade, sizeof(int), 1, ficheiro);
  fread(estudantes, sizeof(tipoEstudante), *quantidade, ficheiro);
  fclose(ficheiro);
}
