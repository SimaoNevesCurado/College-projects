/**
 * @file main.c
 * @brief Description
 * @date 2018-1-1
 * @author name of author
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "debug.h"
#include "memory.h"

#include "args.h"
#include <fcntl.h>

#include "debug.h"

#define EVENFILENAME "even_file.bin"
#define ODDFILENAME "odd_file.bin"

int main(int argc, char *argv[]) {

    struct gengetopt_args_info args_info;

    if(cmdline_parser(argc,argv,&args_info) != 0){
        exit(1);
    }

    if (argc != 3){
        ERROR(1, "Número de Elementos inválido, exemplo: %s -f <nomeFich.txt>", argv[0]);
    }

    char *nomeFichUser = args_info.file_arg;

    int fd = open(nomeFichUser, O_RDONLY); // O_* precisa do #include <fcntl.h>
    
    if( fd == -1 ){
        ERROR(1, "Error opening file: %s", nomeFichUser);
    }

    if(lseek(fd,0,SEEK_END) == 0){
        ERROR(1, "Empty File");
    }
    
    lseek(fd, 0, SEEK_SET);

    ssize_t bytesLidos;
    int oddNumber = 0, evenNumber = 0;

    char buffer[1];

    int pos = 1;
  
    char odd_filename[256];
    char even_filename[256];
    snprintf(odd_filename, sizeof(odd_filename), "odd_%s", nomeFichUser);  
    snprintf(even_filename, sizeof(even_filename), "even_%s", nomeFichUser); 

    
    int evenFile = open(even_filename, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
    int oddFile = open(odd_filename, O_CREAT | O_WRONLY | O_TRUNC| O_APPEND,0644);

    while ((bytesLidos = read(fd, buffer, sizeof(buffer))) > 0) {
        // Process the read data, for example, print it
        if(pos % 2 == 0){
            if(evenFile != -1){
                write(evenFile,buffer,bytesLidos);
            }
            evenNumber++;
        }else{
            
            if(evenFile != -1){
                write(oddFile,buffer,bytesLidos);
            }
            oddNumber++;
        }
        pos += 1;
    }

    printf("%d Total Bytes Written\n", evenNumber+oddNumber);
    printf("%d Even Bytes Written - %s\n", evenNumber, even_filename);
    printf("%d Odd Bytes Written - %s\n", oddNumber, odd_filename);
    
    close(evenFile);
    close(oddFile);
    close(fd);
    return 0;
}