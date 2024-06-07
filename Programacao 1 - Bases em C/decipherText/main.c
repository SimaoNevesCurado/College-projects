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
#include <ctype.h>


int main(int argc, char *argv[]) {
    struct gengetopt_args_info args_info;
    if(cmdline_parser(argc,argv, &args_info) < 0){
        ERROR(1,"Misinputed, Example Usage: %s: -e <encryptedText>", argv[0]);
    }

    char *encryptedText = args_info.encryptedText_arg;

    char *word1 = malloc(strlen(encryptedText));
    char *word2 = malloc(strlen(encryptedText));
    char *word3 = malloc(strlen(encryptedText));

    int indice = 1;

    //Verifica se o caractere atual é uma letra 
    for (int i=0; i<strlen(encryptedText); i++){
        if(isalpha(encryptedText[i])){
            if (indice % 2 == 0){
                word1[i] = encryptedText[i] - 2;
                word2[i] = encryptedText[i] - 3;
                word3[i] = encryptedText[i] - 4;
            }else{
                word1[i] = encryptedText[i] - 1;
                word2[i] = encryptedText[i] - 2;
                word3[i] = encryptedText[i] - 3;
            }

            if(!isalpha(word1[i])){
                word1[i] = word1[i] + 26;
            }
            if(!isalpha(word2[i])){
                word2[i] = word2[i] + 26;
            }
            if(!isalpha(word3[i])){
                word3[i] = word3[i] + 26;
            }
            indice++;
        }else{
            word1[i] = encryptedText[i];
            word2[i] = encryptedText[i];
            word3[i] = encryptedText[i];
        }
    }

    DEBUG("User Input: %s",encryptedText);
    
    printf("Deslocamento 1: %s\n", word1);
    printf("Deslocamento 2: %s\n", word2);
    printf("Deslocamento 3: %s\n", word3);
    
    free(word1);
    free(word2);
    free(word3);
    cmdline_parser_free(&args_info);
    return 0;
}