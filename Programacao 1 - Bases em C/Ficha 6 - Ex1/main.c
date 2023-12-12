#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXSTRING 50
#define MAXIMOESTUDANTES 100


typedef struct
{
    int ano, mes, dia;
} data;

typedef struct
{
    int numero;
    char nome[MAXSTRING];
    float nota;
    data dataAvaliacao;
} tipoEstudante;

typedef struct{
char codigo[50];
tipoEstudante numero;
data dataRefeicao;
int refeicao;

}TipoReserva;


char menu(int totalAlunos, int NAvaliados, float  percentagem);
void limparBufferStdin();
int lerInteiro(int minimo, int maximo);
float lerFloat(float minimo, float maximo);
void lerString(char text[], int max);
data lerData();
int lerQuantidadeEstudantes();
tipoEstudante lerDadosEstudante(tipoEstudante estudantes[], int indiceMax);
void lerNotas(tipoEstudante estudantes[], int numEstudantes);
void mostrarDados(tipoEstudante estudantes[], int numEstudantes);
int acrescentaAvaliado(tipoEstudante estudantes[], int numEstudantes);
int procuraEstudante(tipoEstudante estudantes[],int numEstudante, int num);
int contas(tipoEstudante estudantes[],float *MPositivos, int numEstu);
void gravaFicheiroBinario(tipoEstudante estudantes[MAXIMOESTUDANTES], int totalEstu);
int leFicheiroBinario(tipoEstudante estudantes[MAXIMOESTUDANTES]);

int main()
{
    tipoEstudante estudantes[MAXIMOESTUDANTES];
    int totalEstudantes, nAvaliados = 0, i = 0;
    int numReservas =0;
    float Mpositivos = 0.00;
    char opcao;

    do
    {
        nAvaliados = contas(estudantes, &Mpositivos, totalEstudantes);
        opcao = menu(totalEstudantes, nAvaliados, Mpositivos);
        switch(opcao)
        {
        case 'A':
            totalEstudantes = acrescentaAvaliado(estudantes, totalEstudantes);
            break;
        case 'I':
            if(nAvaliados < totalEstudantes)
            {
                lerNotas(estudantes, totalEstudantes);
            }
            else
            {
                printf("\nTodos os alunos tem notas introduzidas\n");
            }
            break;
        case 'M':
            mostrarDados(estudantes, totalEstudantes);
            break;
        case 'G':
            gravaFicheiroBinario(estudantes,totalEstudantes);
            //gravaFicheiroTexto(estudantes,totalEstudantes);
            break;
        case 'L':
            totalEstudantes = leFicheiroBinario(estudantes);
            break;
        case 'F':
            break;
        default:
            printf("\nOpcao invalida");
        }
    }
    while(opcao != 'F');
    return 0;
}
/*TipoReserva lerDadosReserva(tipoEstudante estudantes[], int indiceMax)
{
    TipoReserva dadosreserva;
    tipoEstudante dados;
    int controlo;

    do
    {
        printf("\nIndique o numero estudante\n");
        dados.numero = lerInteiro(1,9999);
        controlo = procuraEstudante(estudantes, indiceMax, dados.numero);

        if(controlo != -1)
        {
        printf("\nIndique o codigo da reserva\n");
        lerString(dadosreserva.codigo,MAXSTRING);
        lerData();

        }else{
        printf("Estudante não existe");
        }
    }
    while(controlo != -1);


    return dados;
/

int acrescentaReserva(tipoEstudante estudantes[], int numEstudantes)
{
    if(numEstudantes < 100)
    {
        estudantes[numEstudantes] = lerDadosReserva(estudantes,numEstudantes);

        numEstudantes += 1;
    }
    else
    {
        printf("\nTotal de estudantes atingido.\n");
    }
    return numEstudantes;
}
*/

char menu(int totalAlunos, int NAvaliados, float  percentagem)
{
    char opcao;
    do
    {
        printf("\n************************ Menu Principal ************************\n");
        printf("\nEstudantes Inseridos: %3d\n",totalAlunos);
        printf("Estudantes Avaliados: %3d   \t       Notas Positivas (%%): %3.2f\n", NAvaliados, percentagem);
        printf("\nA - Acrescenta Estudante");
        printf("\nI - Introducao Notas");
        printf("\nM - Mostrar Dados");
        printf("\nG - Gravar dados em ficheiros");
        printf("\nL - Ler dados de ficheiro");
        printf("\nR - Criar reserva");
        printf("\nO - Eliminar reserva");
        printf("\nL - Ler dados de ficheiro");
        printf("\nF - Fim");
        printf("\n\t\t\tOpcao--> ");
        scanf(" %c",&opcao);
        opcao = toupper(opcao);
        if(opcao != 'A' && opcao != 'I' && opcao != 'M' && opcao != 'F' && opcao != 'G' && opcao != 'L')
        {
            printf("\nOpcao invalida\n");
        }
    }
    while(opcao != 'A' && opcao != 'I' && opcao != 'M' && opcao != 'F' && opcao != 'G' && opcao != 'L');
    return opcao;
}

int lerInteiro(int minimo, int maximo)
{
    int num, controlo;

    do
    {
        printf("\nIndique valor %d - %d\n",minimo,maximo);
        controlo = scanf("%d", &num);
        limparBufferStdin();

        if (num < minimo || num > maximo || controlo == 0)
        {
            printf("\nOpcao invalida, o numero tem de ser inteiro e estar no intervalo\n");
        }
    }
    while(num < minimo || num > maximo || controlo == 0);
    return num;
}

float lerFloat(float minimo, float maximo)
{
    float num;
    int controlo;

    do
    {
        printf("\nIndique valor %.2f - %.2f\n",minimo,maximo);
        controlo = scanf("%f", &num);
        limparBufferStdin();
        if (num < minimo || num > maximo || controlo == 0)
        {
            printf("\nOpcao invalida, o numero tem de estar no intervalo\n");
        }
    }
    while(num < minimo || num > maximo || controlo == 0);
    return num;
}

void lerString(char text[], int max)
{
    int tamanhoString;
    do  /*Repete leitura caso sejam introduzidas strings apenas com o \n (tamanhoString == 1) */
    {
        fgets(text, max, stdin);
        tamanhoString = strlen(text);
    }
    while(tamanhoString == 1);
    if (text[tamanhoString-1] != '\n')
    {
        /* armazenados no vetor todos os caracteres */
        limparBufferStdin(); /* elimina caracteres que ficaram no buffer stdin */
    }
    else
    {
        text[tamanhoString-1] ='\0'; /*substitui \n da string armazenada em vetor por \0 */
    }
}

data lerData()
{
    int maxDias;
    data dataAvaliacao;
    printf("\nIntroduza o ano:");
    dataAvaliacao.ano = lerInteiro(2023,2100);
    printf("\nIntroduza o mes:");
    dataAvaliacao.mes = lerInteiro(1,12);
    printf("\nIntroduza o dia:");

    switch(dataAvaliacao.mes)
    {
    case 2:
        if(dataAvaliacao.ano%4 == 0 && dataAvaliacao.ano%100 != 0)
        {
            maxDias = 29;
        }
        else
        {
            maxDias = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDias = 30;
        break;
    default:
        maxDias = 31;
    }

    dataAvaliacao.dia = lerInteiro(1,maxDias);

    return dataAvaliacao;
}

int lerQuantidadeEstudantes()
{
    int totalEstudantes;
    printf("\nIntroduza a quantidade de estudantes.\n");
    totalEstudantes = lerInteiro(1,MAXIMOESTUDANTES);

    return totalEstudantes;
}

tipoEstudante lerDadosEstudante(tipoEstudante estudantes[], int indiceMax)
{
    tipoEstudante dados;
    int controlo;

    do
    {
        printf("\nIndique o numero estudante\n");
        dados.numero = lerInteiro(1,9999);
        controlo = procuraEstudante(estudantes, indiceMax, dados.numero);

        if(controlo != -1)
        {
            printf("\nO estudante ja esta inserido\n");
        }
    }
    while(controlo != -1);
    printf("\nIndique o nome do estudante\n");
    lerString(dados.nome, MAXSTRING);
    dados.nota = -1;
    dados.dataAvaliacao.ano = 0000;
    dados.dataAvaliacao.mes = 0;
    dados.dataAvaliacao.dia = 0;

    return dados;
}

void lerNotas(tipoEstudante estudantes[], int numEstudantes)
{
    int i = 0;
    for(i = 0 ; i < numEstudantes ; i++)
    {
        if(estudantes[i].nota < 0)
        {
            printf("\nNumero: %d",estudantes[i].numero);
            printf("\nNome: %s",estudantes[i].nome);
            printf("\nIntroduza a data da avaliacao:");
            estudantes[i].dataAvaliacao = lerData();
            printf("\nIntroduza a nota final");
            estudantes[i].nota = lerFloat(0.00,20.00);
        }

    }
}

void mostrarDados(tipoEstudante estudantes[], int numEstudantes)
{
    int i;

    for(i = 0 ; i < numEstudantes ; i ++)
    {
        printf("\n\n\nNumero: %d",estudantes[i].numero);
        printf("\nNome: %s",estudantes[i].nome);
        if(estudantes[i].nota >= 0)
        {
            printf("\nData avaliacao: %d/%d/%d",estudantes[i].dataAvaliacao.ano, estudantes[i].dataAvaliacao.mes, estudantes[i].dataAvaliacao.dia);
            printf("\nNota: %.2f",estudantes[i].nota);
        }
    }
}

int acrescentaAvaliado(tipoEstudante estudantes[], int numEstudantes)
{
    if(numEstudantes < 100)
    {
        estudantes[numEstudantes] = lerDadosEstudante(estudantes,numEstudantes);

        numEstudantes += 1;
    }
    else
    {
        printf("\nTotal de estudantes atingido.\n");
    }
    return numEstudantes;
}

int procuraEstudante(tipoEstudante estudantes[],int numEstudante, int num)
{
    int i, indice = -1;

    for(i = 0 ; i < numEstudante ; i ++)
    {
        if (num == estudantes[i].numero)
        {
            indice = i;
            i = numEstudante;
        }
    }

    return indice;
}

void limparBufferStdin()
{
    char chr;
    do
    {
        chr = getchar();
    }
    while(chr != '\n' && chr != EOF);
}

int contas(tipoEstudante estudantes[],float *MPositivos, int numEstu)
{
    int i = 0, numN = 0, totalP = 0;
    for(i = 0 ; i < numEstu ; i ++)
    {
        if(estudantes[i].nota != -1)
        {
            if(estudantes[i].nota >= 9.5)
            {
                totalP ++;
            }
            numN ++;
        }
    }
    if (numN != 0)
    {
        *MPositivos  = ((float)totalP * 100)/numN;
    }
    else
    {
        *MPositivos = 0.00;
        numN = 0;
    }
    return numN;
}

void gravaFicheiroBinario(tipoEstudante estudantes[MAXIMOESTUDANTES], int totalEstu)
{
    int controlo;
    FILE *dados;
    dados = fopen("dados.dat","wb");

    if (dados != NULL)
    {
        controlo = fwrite(&totalEstu,sizeof(int),1,dados);
        if (controlo != 1)
        {
            printf("\nErro ao gravar ficheiro\n");
        }
        else
        {
            controlo = fwrite(estudantes, sizeof(tipoEstudante),totalEstu,dados);
            if (controlo != totalEstu)
            {
                printf("\nErro ao gravar ficheiro\n");
            }
        }
        fclose(dados);
    }
    else
    {
        printf("\nAbertura do ficheiro falhou.");
    }

}

int leFicheiroBinario(tipoEstudante estudantes[MAXIMOESTUDANTES])
{
    int controlo, totalEstu;
    FILE *dados;
    dados = fopen("dados.dat","rb");

    if (dados != NULL)
    {
        controlo = fread(&totalEstu,sizeof(int),1,dados);
        if (controlo != 1)
        {
            printf("\nErro ao gravar ficheiro\n");
        }
        else
        {
            controlo = fread(estudantes, sizeof(tipoEstudante),totalEstu,dados);
            if (controlo != totalEstu)
            {
                printf("\nErro ao gravar ficheiro\n");
            }
        }
        fclose(dados);
    }
    else
    {
        printf("\nAbertura do ficheiro falhou.");
    }


    return totalEstu;
}

void gravaFicheiroTexto(tipoEstudante estudantes[MAXIMOESTUDANTES], int totalEstu)
{
    int controlo[7], i = 0, y = 0;
    FILE *dados;
    dados = fopen("dados.txt","w");

    if (dados != NULL)
    {
        controlo[0] = fprintf(dados,"%d\n",totalEstu);
        for(i = 0 ; i < totalEstu ; i ++ )
        {
            controlo[1] = fprintf(dados,"Numero: %d\n",estudantes[i].numero);
            controlo[2] = fprintf(dados,"Nome: %s\n",estudantes[i].nome);
            controlo[3] = fprintf(dados,"Nota: %2.2f\n",estudantes[i].nota);
            controlo[4] = fprintf(dados,"Data: %d/",estudantes[i].dataAvaliacao.ano);
            controlo[5] = fprintf(dados,"%d/",estudantes[i].dataAvaliacao.mes);
            controlo[6] = fprintf(dados,"%d\n",estudantes[i].dataAvaliacao.dia);

            for (y = 0 ; y < 7 ; y++)
            {
                if(controlo[y] <= 1)
                {
                    printf("\nErro ao guardar dados \n");
                    y = 7;
                    i = totalEstu;
                }
            }
        }
        fclose(dados);
    }
    else
    {
        printf("\nAbertura do ficheiro falhou.");
    }
}
