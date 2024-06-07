#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "args.h"
#include "memory.h"
#include "debug.h"

void print_error(const char *message, const char *file_name)
{
    fprintf(stderr, "[ERROR] %s '%s': %s\n", message, file_name, strerror(errno));
}

int main(int argc, char *argv[])
{
    struct gengetopt_args_info args_info;

    if (cmdline_parser(argc, argv, &args_info) != 0)
    {
        return 1;
    }
    // Assuming args_info has members input_file1 and input_file2 for filenames
    char *input_filename1 = args_info.file1_arg;
    char *input_filename2 = args_info.file2_arg;
    char *input_filename_out = args_info.out_arg;

    int file1 = open(input_filename1, O_RDONLY); // O_* precisa do #include <fcntl.h>
    int file2 = open(input_filename2, O_RDONLY); // O_* precisa do #include <fcntl.h>

    if (file1 == -1)
    {
        ERROR(1, " Opening file: %s\n", input_filename1);
        close(file1);
    }
    if (file2 == -1)
    {
        ERROR(1, " Opening file: %s\n", input_filename2);
        close(file2);
    }

    if (lseek(file1, 0, SEEK_END) == 0 || lseek(file2, 0, SEEK_END) == 0)
    {
        ERROR(1, " Empty File");
        // Reset file offsets to the beginnin
        close(file1);
        close(file2);
    }

    // Volta a colocar o offset  no inicio do ficheiro
    lseek(file1, 0, SEEK_SET);
    lseek(file2, 0, SEEK_SET);

    ssize_t bytesLidos_F1;
    ssize_t bytesLidos_F2;

    int F1_B_number = 0, F2_B_number = 0;

    char bufferF1[1];
    char bufferF2[1];

    // char out_file[256];
    int outFile = open(input_filename_out, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0644);

    // Desta maneira nao sao imprimidos alternadamente
    /* while ((bytesLidos_F1 = read(file1, bufferF1, sizeof(bufferF1))) > 0     )
     {
         write(outFile, bufferF1, bytesLidos_F1);
         F1_B_number++;
         while ((bytesLidos_F2 = read(file2, bufferF2, sizeof(bufferF2))) > 0)
         {
             write(outFile, bufferF2, bytesLidos_F2);
             F2_B_number++;
         }
     }
 */

    while ((bytesLidos_F1 = read(file1, bufferF1, sizeof(bufferF1))) > 0 &&
           (bytesLidos_F2 = read(file2, bufferF2, sizeof(bufferF2))) > 0)
    {

        if (bytesLidos_F1 > 0)
        {
            write(outFile, bufferF1, bytesLidos_F1);
            F1_B_number++;
        }
        if (bytesLidos_F2 > 0)
        {
            write(outFile, bufferF2, bytesLidos_F2);
            F2_B_number++;
        }
    }

        while ((bytesLidos_F1 = read(file1, bufferF1, sizeof(bufferF1))) > 0)
        {

            write(outFile, bufferF1, bytesLidos_F1);
            F1_B_number++;
        }
        while ((bytesLidos_F2 = read(file2, bufferF2, sizeof(bufferF2))) > 0)
        {
           // printf("%lx\n", bytesLidos_F2);
            write(outFile, bufferF2, bytesLidos_F2);
            F2_B_number++;
        }


    printf("%d Total Bytes Written\n", F1_B_number + F2_B_number);
    printf("%d Bytes Written - %s\n", F1_B_number, input_filename1);
    printf("%d Bytes Written - %s\n", F2_B_number, input_filename2);

    close(file1);
    close(file2);

    cmdline_parser_free(&args_info);
    return 0;
}