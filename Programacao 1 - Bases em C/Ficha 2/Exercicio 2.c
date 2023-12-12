#include <stdio.h>
#include <stdlib.h>

int main()
{
    char opcao;
    int soma = 0;
    int aux = 1;
    int num;
    int sair = 0;

    printf("Escolha uma letra\n");
    scanf("%d", &opcao);
     while (sair == 0)
    {
        printf("************************\n");
        printf("*                      *\n");
        printf("*  [W]- Usar While     *\n");
        printf("*  [D]- Usar Do While  *\n");
        printf("*  [F]- Usar FOR       *\n");
        printf("*  [S]- Sair           *\n");
        printf("*                      *\n");
        printf("************************\n\n\n");
        scanf(" %c", &opcao);

        soma = 0;
        aux = 0;
        switch (opcao)
        {
        case 'W':
        case 'w':
            while (aux <= num)
            {
                soma = soma + aux;
                aux = aux + 1;
            }
            printf("%d\n", soma);
            break;
        case 'D':
        case 'd':
            do
            {
                soma = soma + aux;
                aux = aux + 1;
            } while (aux <= num);
            printf("%d\n", soma);
            break;
        case 'F':
        case 'f':
            for (aux = 1; aux <= num; aux++)
            {
                soma = soma + aux;
            }
            printf("%d", soma);
            break;
        case 'S':
        case 's':
            printf("Saiu do Programa");
            sair = 1;
            break;
        default:
            printf("Caracter inv�lido");
        }
    }
    return 0;
}
