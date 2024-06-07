#include <stdio.h>
#include <stdlib.h>
// #include <sys/wait.h>
#include <unistd.h>
// #include <signal.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// #include <assert.h>

#include "debug.h"

int main(int argc, char *argv[]) {
    /* Disable warnings */
    (void)argc;
    (void)argv;

    char *fich = "dev/full";

    int numeros[] = {0,1,2,3};
    int fd;

    fd= open(fich, O_WRONLY);
    if(fd == -1){
        ERROR(1,"Não é possivel abrir o ficheiro: %s",fich);
    }

    ssize_t bytes_escritos;
    bytes_escritos = write(fd, numeros, sizeof(numeros));
    if(bytes_escritos!= sizeof(numeros)){
        ERROR(2,"Nao e possivel escrever %d bytes no ficheiro %s", sizeof(numeros),fich);
    }
    close(fd);
    /* Insira o seu código aqui */

    return 0;
}
