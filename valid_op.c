#include "monty.h"

/**
 * valide_opcode - Validates and executes Monty bytecode instructions based
 *                 on a predefined instruction table. If the opcode is
 *                 recognized, the corresponding function is called; otherwise,
 *                 an error message is printed, and the program exits.
 *
 * @opcode: The opcode to be validated and executed.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void valide_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    size_t i;

    instruction_t instructions[] = {
        {"push",opcode_push},
        {"pall",opcode_pall},
        {"pint",opcode_pint},
        {"pop",opcode_pop},
        {"swap",opcode_swap},
        {"add",opcode_add},
        {"nop",opcode_nop},
        {"sub",opcode_sub},
        {"div",opcode_div},
        {"mul",opcode_mul},
        {"mod",opcode_mod},
        {"pchar",opcode_pchar},
        {"pstr",opcode_pstr},
        {"rotl",opcode_rotl},
        {"rotr",opcode_rotr},
        {NULL,NULL}
    };
    i = 0;

    while (i < 15)
    {
        if (strcmp(instructions[i].opcode, opcode) == 0)
        {
            instructions[i].f(stack, line_number);
            return ;
        }
        i++;
    }
    dprintf(STDERR_FILENO,"L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}
