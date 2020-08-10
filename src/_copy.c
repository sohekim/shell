#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/copy.h"

#define BUFFER_SIZE 64

int copy(char *input)
{
    char *files_p;
    input[strlen(input) - 1] = '\0';
    files_p = strtok(input, " ");
    char *files[100];

    int count = 0;

    while (files_p != NULL)
    {
        files_p = strtok(NULL, " ");
        files[count] = files_p;
        count++;
        if (count > 3)
        {
            printf("Error: Please provide $copy <source_file> <target_file>\n");
            return 1;
        }
    }
    if (count < 3)
    {
        printf("Error: Please provide $copy <source_file> <target_file>\n");
        return 1;
    }
    else if (count == 3)
    {
        FILE *source_file, *target_file, *check_file;
        char *source = files[0];
        char *target = files[1];

        if (!(source_file = fopen(source, "r")))
        {
            printf("Error: %s doesn't exist\n", source);
            return 1;
        }

        if ((target_file = fopen(target, "r")))
        {
            printf("Error: %s already exist\n", target);
            fclose(target_file);
            return 1;
        }

        target_file = fopen(target, "w");

        char *buffer = (char *)malloc(BUFFER_SIZE);
        int total_read;

        while ((total_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0)
        {
            fwrite(buffer, 1, total_read, target_file);
        }

        free(buffer);
        fclose(source_file);
        fclose(target_file);

        // when the size of the two files are equal
        printf("Copied Successfully\n");
    }
    return 1;
}