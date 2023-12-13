#include <stdio.h>
#include <stdlib.h>
#include "funcoes_reservas.h"
#include "funcoes_auxiliares.h"

Reserva* reservar_espaco(Reserva* reservas, int tamanho){
  reservas = (Reserva*)realloc(reservas, sizeof(Reserva) * tamanho);  
  return reservas;
}

void adicionar_reserva(Reserva* reservas, int* num_reservas, int* tamanho, int num_estudante) {
  Reserva reserva; 
  reserva.num_estudante = num_estudante;
  reserva.codigo = lerInteiro(0, 1000);
  reserva.data = lerData();
  reserva.tipo = ler_tipo_refeicao();
  printf("\nOk1\n");
  reservas[*num_reservas] = reserva;
  printf("\nOk2\n");
  log_criacao(reserva);
  printf("\nOk3\n");
  *num_reservas += 1;
  if(*num_reservas == *tamanho) {
    *tamanho += MAX_RESERVA;
    reservar_espaco(reservas, *tamanho);
  }
}

void remover_reserva(Reserva* reservas, int* num_reservas, int codigo) {
  for(int i = 0; i < *num_reservas; i++){
    if (reservas[i].codigo == codigo) {
      log_eliminacao(reservas[i]);
      reservas[i] = reservas[*num_reservas - 1];
      *num_reservas -= 1;
      return;
    }
  }

  printf("O codigo fornecido nao existe!\n");
}

enum refeicao ler_tipo_refeicao(){
  int op = -1;
  do{
    printf("Qual o tipo de refeicao?\n");
    scanf("%d", &op);
  }while(op != Almoco && op != Jantar);

  return (enum refeicao)op;
}

void log_criacao(Reserva reserva){
  FILE* ficheiro;
  ficheiro = fopen("logs.txt", "a");
  if (ficheiro == NULL){
    printf("Erro a abrir ficheiro!\n");
    return;
  }
  
  fprintf(ficheiro, "Foi criada uma reserva para o estudante n: %d\n", reserva.num_estudante);
  fprintf(ficheiro, "Codigo reserva: %d\n", reserva.codigo);
  fprintf(ficheiro, "Tipo de refeicao:");
  if(reserva.tipo == Almoco) {
    fprintf(ficheiro, "Almoco\n");  
  } else {
    fprintf(ficheiro, "Jantar\n");
  }
  fprintf(ficheiro, "Data: Dia: %d Mes: %d Ano %d\n", reserva.data.dia, reserva.data.mes, reserva.data.ano); 
  
  fclose(ficheiro);
  
}

void log_eliminacao(Reserva reserva){
  FILE* ficheiro;
  ficheiro = fopen("logs.txt", "a");
  if (ficheiro == NULL){
    printf("Erro a abrir ficheiro!\n");
    return;
  }
  
  fprintf(ficheiro, "Foi eliminada uma reserva para o estudante n: %d\n", reserva.num_estudante);
  fprintf(ficheiro, "Codigo reserva: %d\n", reserva.codigo);
  
  fclose(ficheiro);
  
}
