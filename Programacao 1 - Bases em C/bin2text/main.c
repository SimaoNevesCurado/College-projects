/**
 * @file main.c
 * @brief Description
 * @date 2018-1-1
 * author name of author
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ctype.h>

#include "args.h"
#include "debug.h"
#include "memory.h"

int main(int argc, char *argv[])
{
    struct gengetopt_args_info args_info;

    if (cmdline_parser(argc, argv, &args_info) != 0)
    {
        return 1;
    }

    char *input_filename = args_info.in_arg;
    char *output_filename = args_info.out_arg;
    char *type = args_info.type_arg;

    int show_text = 0;

    if (args_info.show_given)
    {
        show_text = args_info.show_arg;

        if (show_text != 0 && show_text != 1)
        {
            show_text = 0;
            ERROR(1, "Option '--show / -s ' should be 0 or 1. Example: ./prog -i <ficheiro> -o <output> -t <I/L> -s <0/1>\n");
        }
    }

    

    if (strcmp(type, "L") != 0 && strcmp(type, "I") != 0)
    {
        ERROR(2, "Option '--type / -t ' should be L  or I. Example: ./prog -i <ficheiro> -o <output> -t <I/L> -s <0/1>\n");
    }

    int file = open(input_filename, O_RDONLY);
    if (file == -1)
    {
        ERROR(3, "Opening file: %s\n", input_filename);
        return 1;
    }

    int output = open(output_filename, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);
    if (output == -1)
    {
        close(file);
        ERROR(3, "Opening file: %s\n", output_filename);
        return 1;
    }

    ssize_t bytes_read;
    int n_escrito = 0;

   
  
         

        if (strcmp(type, "L") == 0)
        {
            long value;
            while ((bytes_read = read(file, &value, sizeof(value))) > 0)
            {
                if (bytes_read != sizeof(value))
                {
                    ERROR(4, "file '%s' has insufficient bytes for selected data type.\n", input_filename);
                    close(file);
                    close(output);
                    return 1;
                }

                write(output, &value, bytes_read);
                n_escrito++;
                if (show_text == 1)
                {
                    printf("%ld\n", value);
                }
            }
        }
        else if (strcmp(type, "I") == 0)
        {
            int value;
            while ((bytes_read = read(file, &value, sizeof(value))) > 0)
            {
                  if (bytes_read != sizeof(value))
                {
                    ERROR(4, "file '%s' has insufficient bytes for selected data type.\n", input_filename);
                    close(file);
                    close(output);
                    return 1;
                }

                write(output, &value, bytes_read);
                n_escrito++;
                if (show_text == 1)
                {
                    printf("%d\n", value);
                }
            }
        }
     
    if (bytes_read == -1)
    {
        ERROR(4, "Reading file: %s\n", input_filename);
    }

    if (strcmp(type, "L") == 0)
    {
        printf("[INFO] %d LONG converted\n", n_escrito);
    }
    if (strcmp(type, "I") == 0)
    {
        printf("[INFO] %d INT converted\n", n_escrito);
    }

    printf("[INFO] Saving new file '%s'\n", output_filename);

    close(file);
    close(output);
    cmdline_parser_free(&args_info);

    return 0;
}
