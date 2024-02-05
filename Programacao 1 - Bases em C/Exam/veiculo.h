#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED

#define TAM_MATRICULA 9
#define TEXTO_LONGO 80
#define TEXTO_CURTO 15

#define TIPO_LIGEIRO 1
#define TIPO_PESADO 2
#define TIPO_REBOQUE 3

#define MAX_VEICULOS 30

#define MAX_TOTAL_KMS 900000

typedef struct{
    char matricula[TAM_MATRICULA];
    char marca[TEXTO_CURTO];
    char modelo[TEXTO_CURTO];
    int anoRegisto;
    int tipo;
    int totalKms;
} tipoVeiculo;


int procurarVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos, char matricula[]);
int inserirNovoVeiculo (tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

void escreverVeiculo (tipoVeiculo dados);
void listarVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);

void escreverFicheiroBinarioVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int quantVeiculos);
void lerFicheiroBinarioVeiculos(tipoVeiculo vetorVeiculos[MAX_VEICULOS], int *quantVeiculos);

#endif // VEICULO_H_INCLUDED
