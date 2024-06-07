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
#include <fcntl.h>
#include "debug.h"
#include "memory.h"
#include "args.h"

int main(int argc, char *argv[])
{
    struct gengetopt_args_info args_info;
 
    if (cmdline_parser(argc, argv, &args_info) != 0)
    {
        return 1;
    }
    // Assuming args_info has members input_file
    char *input_filename = args_info.filename_arg;
    char *output_filename = args_info.outfile_arg;
    int file = open(input_filename, O_RDONLY); // O_* precisa do #include <fcntl.h>
    if (file == -1)
    {
        ERROR(1, " Opening file: %s\n", input_filename);
        close(file);
    }
    int bufSize = 4096;
    if (args_info.buffsize_given)
    {
        bufSize = args_info.buffsize_arg;
        if (bufSize <= 0)
        {
            printf("Tamanho buffer invalido");
            bufSize = 4096;
        }
    }
    ssize_t bytes_lidos;
    ssize_t bytes_escritos;

    int outFile = open(output_filename, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
    
    unsigned *buffer = MALLOC(bufSize);
    while (1)
    {
        bytes_lidos = read(file, &buffer, sizeof(&buffer));
        if (bytes_lidos == -1)
        {
            ERROR(3, "Can't read from input file");
        }

        bytes_escritos = write(outFile, &buffer, bytes_lidos);
        if (bytes_escritos == -1)
        {
            ERROR(4, "Cant write to output file");
        }
    }

    printf("%s Copied to %s\n", input_filename, output_filename);
    close(file);
    close(outFile);

    cmdline_parser_free(&args_info);
    return 0;
}
