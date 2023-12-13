#pragma once
#define MAX_RESERVA 50

enum refeicao {
  Almoco,
  Jantar
};

typedef struct{
  int dia, mes, ano;
}tipoData;

typedef struct{
  int codigo;
  int num_estudante;
  tipoData data;
  enum refeicao tipo;  
}Reserva;

tipoData lerData();
enum refeicao ler_tipo_refeicao();
void log_criacao(Reserva reserva);
void log_eliminacao(Reserva reserva);
void adicionar_reserva(Reserva* reservas, int* num_reservas, int* tamanho, int num_estudante);
void remover_reserva(Reserva* reservas, int* num_reservas, int codigo);
Reserva* reservar_espaco(Reserva* reservas, int tamanho);