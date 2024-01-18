#include "monty.h"

/**
 * main - performs simple operations
 * @argc: number of arguments passed
 * @argv: array of pointers to arguments
 *
 * Return: always 0
 */

stack_t *stack;

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        stack_t *temp;
        FILE *file;
        char *instruction = NULL;
        char *opcode = 0;
        size_t len = 0;
        unsigned int line_number = 0;

        file = fopen(argv[1],"r");

        stack = NULL;

        if (file != 0)
        {
            while (getline(&instruction, &len, file) != -1)
            {
                line_number++;
                opcode = strtok(instruction, " \n");
                if (opcode != 0 && opcode[0] != '#')
                {
                    valide_opcode(opcode, &stack, line_number);
                }
            }
            free(instruction);
        }
        else
        {
            dprintf(STDERR_FILENO,"Error: Can't open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        fclose(file);
        while (stack != NULL)
        {
            temp = stack;
            stack = stack->next;
            free(temp);
        }
    }
    else
    {
        dprintf(STDERR_FILENO,"USAGE: monty file");
        exit(EXIT_FAILURE);
    }
return (0);
}
