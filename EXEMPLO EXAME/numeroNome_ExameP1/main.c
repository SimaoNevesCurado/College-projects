

#include <stdio.h>
#include <stdlib.h>

#include "declaracoes.h"
#include "funcoesAuxiliares.h"

/** ------------------------ Fun��es dos menus ----------------------- **/
int menu(int totalClientes);
int menuClientes(void);
int menuAgendamentos(void);
int menuEstatisticas(void);
int menuFicheiros(void);

/** ------------------- Fun��es das Funcionalidades ------------------- **/

void inserirNovoCliente(tipoCliente vetorClientes[MAX], int *quantClientes);
int procurarCliente(tipoCliente vetorClientes[MAX], int quantCliente, int numContribuinte);
void escreverCliente(tipoCliente cliente);
void listarClientes(tipoCliente vetorClientes[MAX], int quantClientes);

void escreverFicheiroBinario(tipoCliente vetorClientes[MAX], int quantClientes);
void lerFicheiroBinario(tipoCliente vetorClientes[MAX], int *quantClientes);

tipoAgendamento *AgendarAgendamento(tipoAgendamento *Agendamentos, int *num_Agendamentos, tipoCliente *vetorCliente, int quantCliente);
int procurarAgendamento(tipoAgendamento *Agendamentos, int num_Agendamentos, int numProcurar);
void registarVisita(tipoAgendamento *Agendamentos, int num_Agendamentos);
void ConsultarAgendamentos(tipoAgendamento *Agendamentos,int num_Agendamentos);
void PertagemGrau(tipoAgendamento *Agendamentos, int num_Agendamentos);
void escreverFicheiroBinarioAgendamento(tipoAgendamento *Agendamentos, int num_Agendamentos);
tipoAgendamento *lerFicheiroBinarioAgendamentos(tipoAgendamento *Agendamentos, int *num_agendamentos);

/** ------------------------------ main ------------------------------ **/

int main(void)
{
    tipoCliente vetorClientes[MAX];

    tipoAgendamento *Agendamentos = NULL;
    int num_Agendamentos = 0;

    int quantClientes, opcao, opcao2;

    quantClientes = 0;

    do
    {
        opcao = menu(quantClientes);
        switch (opcao)
        {
        case 1: // menu CLIENTES
            do
            {
                opcao2 = menuClientes();
                switch (opcao2)
                {
                case 1: // inserir novo cliente
                    inserirNovoCliente(vetorClientes, &quantClientes);
                    break;
                case 2: // Listar Clientes
                    listarClientes(vetorClientes, quantClientes);
                    break;
                case 3: // Listar Clientes e respetivas marcacoes
                    ConsultarAgendamentos(Agendamentos,num_Agendamentos);
                    break;
                }
            }
            while (opcao2 != 0);
            break;

        case 2: // menu AGENDAMENTOS
            do
            {
                opcao2 = menuAgendamentos();
                switch (opcao2)
                {
                case 1: // Adicionar novo agendamento

                    Agendamentos = AgendarAgendamento(Agendamentos, &num_Agendamentos, vetorClientes, quantClientes);
                    printf("\n\nIMPLEMENTADA\n\n");
                    break;
                case 2: // Registar Visita
                    registarVisita(Agendamentos,num_Agendamentos);
                    printf("\n\nATENCAO: opcao para implementar no exame\n\n");
                    break;
                case 3: // Consultar Agendamentos (por data)
                    ConsultarAgendamentos(Agendamentos,num_Agendamentos);
                    printf("\n\nATENCAO: opcao para implementar no exame\n\n");
                    break;
                }
            }
            while (opcao2 != 0);
            break;

        case 3: // menu ESTATISTICA
            do
            {
                opcao2 = menuEstatisticas();
                switch (opcao2)
                {
                case 1: // Melhor(es) Cliente(s) - os que t�m mais agendamentos
                    menhoresClientes(vetorClientes,Agendamentos,quantClientes,num_Agendamentos);
                    printf("\n\nATENCAO: opcao para implementar no exame\n\n");
                    break;
                case 2: // �ndice/Percentagens por graus de satisfacao dos clientes
                    PertagemGrau(Agendamentos,num_Agendamentos);
                    printf("\n\nATENCAO: opcao para implementar no exame\n\n");
                    break;
                }
            }
            while (opcao2 != 0);
            break;

        case 4: // menu FICHEIROS
            do
            {
                opcao2 = menuFicheiros();
                switch (opcao2)
                {
                case 1: // Guardar no ficheiro
                    escreverFicheiroBinario(vetorClientes, quantClientes);
                    escreverFicheiroBinarioAgendamento(Agendamentos,num_Agendamentos);
                    break;
                case 2: // Ler do ficheiro
                    lerFicheiroBinario(vetorClientes, &quantClientes);
                    Agendamentos = lerFicheiroBinarioAgendamentos(Agendamentos,&num_Agendamentos);
                    break;
                }
            }
            while (opcao2 != 0);
            break;
        }

    }
    while (opcao != 0);

    free(Agendamentos);
    return 0;
}

tipoAgendamento *lerFicheiroBinarioAgendamentos(tipoAgendamento *Agendamentos, int *num_agendamentos)
{
    FILE *ficheiro;
    int quantValoresLidos, erro = 0;

    ficheiro = fopen("dadosAgendamentos.dat", "rb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresLidos = fread(num_agendamentos, sizeof(int), 1, ficheiro);
        if (quantValoresLidos != 1)
        {
            printf("\n\nERRO: falha na leitura da quantidade de clientes\n\n");
            erro = 1;
        }
        else
        {
            Agendamentos = realloc(Agendamentos,(*num_agendamentos)*sizeof(tipoAgendamento));
            quantValoresLidos = fread(Agendamentos, sizeof(tipoAgendamento),*num_agendamentos, ficheiro);
            if (quantValoresLidos != *num_agendamentos)
            {
                printf("\n\nERRO: falha na leitura dos dados dos clientes\n\n");
                erro = 1;
            }
        }

        if (erro == 1)
        {
            *num_agendamentos = 0;
        }

        fclose(ficheiro);
    }
}

tipoAgendamento *AgendarAgendamento(tipoAgendamento *Agendamentos, int *num_Agendamentos, tipoCliente *vetorCliente, int quantCliente)
{
    int controlo;
    int num;
    num = lerInteiro("Qual é o num contribuinte do cliente?", 111111111, 999999999);
    controlo = procurarCliente(vetorCliente, quantCliente, num);
    if (controlo == -1)
    {
        printf("NAO EXISTE");
    }
    else
    {

        Agendamentos = realloc(Agendamentos, (*num_Agendamentos + 1) * sizeof(tipoAgendamento));

        Agendamentos[*num_Agendamentos].codigo = *num_Agendamentos;
        Agendamentos[*num_Agendamentos].numContribuinte = vetorCliente[controlo].numContribuinte;
        Agendamentos[*num_Agendamentos].data = lerData();

        lerString("Insira a descricao", Agendamentos[*num_Agendamentos].descricao, TEXTO_LONGO);

        (*num_Agendamentos)++;
    }

    return Agendamentos;
}

void registarVisita(tipoAgendamento *Agendamentos, int num_Agendamentos)
{
    int num, controlo;
    num = lerInteiro("Qual é o Codigo agendamento?", 0, num_Agendamentos);
    controlo = procurarAgendamento(Agendamentos, num_Agendamentos, num);
    if (controlo == -1)
    {
        printf("NAO EXISTE");
    }
    else
    {
        Agendamentos[controlo].custo = lerInteiro("Defina um custo", 0, 9999);
        Agendamentos[controlo].grauSatisfacao = lerInteiro("Defina o grau de satisfacao\n\n[1]-fraco\n[2]-bom \n [3]- Excelente", 1, 3);
    }
}

int procurarAgendamento(tipoAgendamento *Agendamentos, int num_Agendamentos, int numProcurar)
{
    int posicao = -1, i;

    for (i = 0; i < num_Agendamentos; i++)
    {
        if (Agendamentos[i].codigo == numProcurar)
        {
            posicao = i;
            i = num_Agendamentos;
        }
    }

    return posicao;
}

void ConsultarAgendamentos(tipoAgendamento *Agendamentos,int num_Agendamentos)
{
    tipoData data=lerData();
    int total = 0, i = 0;

    for (i = 0; i < num_Agendamentos; i++)
    {
        if (Agendamentos[i].data.ano == data.ano && Agendamentos[i].data.mes == data.mes && Agendamentos[i].data.dia == data.dia)
        {
            printf("\n\nCodigo: %d\t\tContribuinte: %9d\n", Agendamentos[i].codigo, Agendamentos[i].numContribuinte);
            printf("Data: %d/%d/%d\nMorada: %s\n", Agendamentos[i].data.dia,Agendamentos[i].data.mes,Agendamentos[i].data.ano, Agendamentos[i].descricao);
            printf("\n\nCusto: %d\t\tSatisfacao: %d\n", Agendamentos[i].custo, Agendamentos[i].grauSatisfacao);
            total ++;
        }
    }
    printf("\n Total de agendamentos para a data: %d\n", total);

}

void menhoresClientes(tipoCliente *vetorClientes, tipoAgendamento *Agendamentos, int quantClientes, int num_Agendamentos)
{
    int maxAgendamentos = 0, i = 0, j = 0, totalAux = 0;

    if (quantClientes > 0)
    {
        for (i = 0; i < quantClientes; i++)
        {
            for (j = 0; j < num_Agendamentos; j++)
            {

                if (vetorClientes[i].numContribuinte == Agendamentos[j].numContribuinte)
                {
                    totalAux ++;
                }
            }
            if (totalAux > maxAgendamentos)
            {
                maxAgendamentos = totalAux;
            }
            totalAux = 0;
        }

        for (i = 0; i < quantClientes; i++)
        {
            for (j = 0; j < num_Agendamentos; j++)
            {

                if (vetorClientes[i].numContribuinte == Agendamentos[j].numContribuinte)
                {
                    totalAux ++;
                }
            }
            if (totalAux == maxAgendamentos)
            {
                escreverCliente(vetorClientes[i]);
            }
            totalAux = 0;
        }
    }
    else
    {
        printf("\n\nATENCAO: Nao existem clientes inseridos.\n\n");
    }
}

void PertagemGrau(tipoAgendamento *Agendamentos, int num_Agendamentos)
{

    int contagem, contagem2, contagem3;
    float percentagem1, percentagem2, percentagem3;
    int j;
    for (j = 0; j < num_Agendamentos; j++)
    {

        if (Agendamentos[j].grauSatisfacao == 1)
        {
            contagem++;
        }
        else
        {
            if (Agendamentos[j].grauSatisfacao == 2)
            {
                contagem2++;
            }
            else
            {
                if (Agendamentos[j].grauSatisfacao == 3)
                {
                    contagem3++;
                }
            }
        }
    }
    percentagem1 = ((float)contagem * 100) / num_Agendamentos;
    percentagem2 = ((float)contagem2 * 100) / num_Agendamentos;
    percentagem3 = ((float)contagem3 * 100) / num_Agendamentos;

    printf("Percentagem de grau fraco: %f", percentagem1);
    printf("Percentagem de grau fraco: %f", percentagem2);
    printf("Percentagem de grau fraco: %f", percentagem3);
}

void escreverFicheiroBinarioAgendamento(tipoAgendamento *Agendamentos, int num_Agendamentos)
{
    FILE *ficheiro;
    int quantValoresEscritos;

    ficheiro = fopen("dadosAgendamentos.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresEscritos = fwrite(&num_Agendamentos, sizeof(int), 1, ficheiro);

        if (quantValoresEscritos != 1)
        {
            printf("\n\nERRO: falha na escrita da quantidade de clientes\n\n");
        }
        else
        {

            quantValoresEscritos = fwrite(Agendamentos, sizeof(tipoAgendamento), num_Agendamentos, ficheiro);
            if (quantValoresEscritos != num_Agendamentos)
            {
                printf("\n\nERRO: falha na escrita dos dados dos clientes\n\n");
            }
        }

        fclose(ficheiro);
    }
}
/** ------------------- Fun��es dos CLIENTES ------------------- **/

// Fun��o que permite inserir um novo cliente no vetorClientes
void inserirNovoCliente(tipoCliente vetorClientes[MAX], int *quantClientes)
{
    int posicao, numContribuinte;

    if (*quantClientes < MAX)
    {
        printf("\n\n*********** NOVO CLIENTE ***********\n\n");
        numContribuinte = lerInteiro("\nNumero de contribuinte: ", CONTRIBUITE_MIN, CONTRIBUITE_MAX);
        posicao = procurarCliente(vetorClientes, *quantClientes, numContribuinte);

        if (posicao > -1)
        {
            printf("\n\nATENCAO: o nr. contribuinte inserido ja existe.\n");
            escreverCliente(vetorClientes[posicao]);
        }
        else
        {
            vetorClientes[*quantClientes].numContribuinte = numContribuinte;
            lerString("\nNome: ", vetorClientes[*quantClientes].nome, TEXTO_BREVE);
            lerString("\nMorada: ", vetorClientes[*quantClientes].morada, TEXTO_LONGO);
            vetorClientes[*quantClientes].telefone = lerInteiro("\nTelefone: ", TELEFONE_MIN, TELEFONE_MAX);
            (*quantClientes)++;
        }
    }
    else
    {
        printf("\n\nATENCAO: o limite maximo de clientes ja foi atingido\n\n");
    }
}

// Fun��o que procura um cliente pelo n� de contribuinte. A fun��o devolve -1 se n�o encontrar o cliente ou devolve a posi��o do cliente no vetor
int procurarCliente(tipoCliente vetorClientes[MAX], int quantCliente, int numContribuinte)
{
    int posicao = -1, i;

    for (i = 0; i < quantCliente; i++)
    {
        if (vetorClientes[i].numContribuinte == numContribuinte)
        {
            posicao = i;
            i = quantCliente;
        }
    }

    return posicao;
}

// Fun��o que lista no ecra os dados de todos os clientes inseridos no vetor
void listarClientes(tipoCliente vetorClientes[MAX], int quantClientes)
{
    int i;

    if (quantClientes > 0)
    {
        printf("\n\n*********** LISTAGEM dos CLIENTES ***********\n\n");
        for (i = 0; i < quantClientes; i++)
        {
            escreverCliente(vetorClientes[i]);
        }
    }
    else
    {
        printf("\n\nATENCAO: Nao existem clientes inseridos.\n\n");
    }
}

// Fun��o que escreve no ecra os dados de um cliente
void escreverCliente(tipoCliente cliente)
{
    printf("\n\nContribuinte: %9d\t\tNome: %s\n", cliente.numContribuinte, cliente.nome);
    printf("Telefone: %13d\t\tMorada: %s\n", cliente.telefone, cliente.morada);
}

/** ------------------- Fun��es dos FICHEIROS ------------------- **/

void escreverFicheiroBinario(tipoCliente vetorClientes[MAX], int quantClientes)
{
    FILE *ficheiro;
    int quantValoresEscritos;

    ficheiro = fopen("dados.dat", "wb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresEscritos = fwrite(&quantClientes, sizeof(int), 1, ficheiro);
        if (quantValoresEscritos != 1)
        {
            printf("\n\nERRO: falha na escrita da quantidade de clientes\n\n");
        }
        else
        {
            quantValoresEscritos = fwrite(vetorClientes, sizeof(tipoCliente), quantClientes, ficheiro);
            if (quantValoresEscritos != quantClientes)
            {
                printf("\n\nERRO: falha na escrita dos dados dos clientes\n\n");
            }
        }

        fclose(ficheiro);
    }
}

void lerFicheiroBinario(tipoCliente vetorClientes[MAX], int *quantClientes)
{
    FILE *ficheiro;
    int quantValoresLidos, erro = 0;

    ficheiro = fopen("dados.dat", "rb");

    if (ficheiro == NULL)
    {
        printf("\n\nERRO: falha na abertura do ficheiro.\n\n");
    }
    else
    {
        quantValoresLidos = fread(quantClientes, sizeof(int), 1, ficheiro);
        if (quantValoresLidos != 1)
        {
            printf("\n\nERRO: falha na leitura da quantidade de clientes\n\n");
            erro = 1;
        }
        else
        {
            quantValoresLidos = fread(vetorClientes, sizeof(tipoCliente), *quantClientes, ficheiro);
            if (quantValoresLidos != *quantClientes)
            {
                printf("\n\nERRO: falha na leitura dos dados dos clientes\n\n");
                erro = 1;
            }
        }

        if (erro == 1)
        {
            *quantClientes = 0;
        }

        fclose(ficheiro);
    }
}

/** ----------------------- Fun��es dos MENUS ------------------------- **/

int menu(int totalClientes)
{
    int opcao;

    printf("\n\n---------------- TECNICO DE REPARACOES - AGENDA ----------------\n\n");
    printf("Total de Clientes: %d\n\n", totalClientes);
    printf("\t1 - Clientes\n\t2 - Agendamentos\n\t3 - Estatisticas\n\t4 - Ficheiros\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 4);

    return opcao;
}

int menuClientes(void)
{
    int opcao;

    printf("\n\n--------------------- MENU CLIENTES --------------------------\n\n");
    printf("\t1 - Adicionar novo cliente\n\t2 - Listar Clientes\n\t3 - Listar Clientes e respetivos agendamentos\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 3);

    return opcao;
}

int menuAgendamentos(void)
{
    int opcao;

    printf("\n\n------------------- MENU AGENDAMENTOS ------------------------\n\n");
    printf("\t1 - Adicionar novo agendamento\n\t2 - Registar Visita\n\t3 - Consultar Agendamentos (por data)\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 3);

    return opcao;
}

int menuEstatisticas(void)
{
    int opcao;

    printf("\n\n------------------- MENU ESTATISTICAS ------------------------\n\n");
    printf("\t1 - Melhor(es) Cliente(s)\n\t2 - Percentagens por grau de satisfacao dos clientes\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 2);

    return opcao;
}

int menuFicheiros(void)
{
    int opcao;

    printf("\n\n------------------- MENU FICHEIROS ------------------------\n\n");
    printf("\t1 - Guardar no ficheiro\n\t2 - Ler do ficheiro\n\n\t0 - Sair\n\n");

    opcao = lerInteiro("\t\tIndique a opcao:", 0, 2);

    return opcao;
}
