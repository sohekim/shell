#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Header/copy.h"

#define QUIT_COMMAND "quit"
#define COPY_COMMAND "copy"

int command(char *input)
{
    char *input_p = strdup(input);
    char *command_p;

    input[strlen(input) - 1] = '\0';
    command_p = strtok(input, " ");

    if (strcmp(command_p, QUIT_COMMAND) == 0)
    {
        return 0;
    }
    else if (strcmp(command_p, COPY_COMMAND) == 0)
    {
        return copy(input_p);
    }
    else
    {
        printf("Error: Command not found\n");
        return 1;
    }

    // options 추가

    // find alternatives
    // hash the string and use switch statements
    // switch (*command)
    // {
    // case 'copy':
    //     return 1;
    // }
}

int main()
{
    char input[50];
    int result;

    while (1)
    {
        printf("\n> ");
        fgets(input, 100, stdin);
        result = command(input);
        if (result == 1)
        {
            continue;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
