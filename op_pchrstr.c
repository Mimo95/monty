#include "monty.h"

/*
 * opcode_pchar - Prints the ASCII character at the top of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_pchar(stack_t **stack, unsigned int line_number)
{
    struct stack_s *top = *stack;

    if (*stack == 0)
    {
        dprintf(STDERR_FILENO,"L%u: can't pchar, stack empty",line_number);
        exit(EXIT_FAILURE);
    }
    if (top->n < 0 || top->n > 127)
    {
        dprintf(STDERR_FILENO,"L%u: can't pchar, value out of range",line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n",(char)top->n);

    *stack = top->next;
    if (*stack != 0)
    {
        (*stack)->prev = 0;
    }

    free(top);
}

/*
 * opcode_pstr - Prints the ASCII characters from the stack until a 0 or non-ASCII value.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_pstr(stack_t **stack, unsigned int line_number)
{
    struct stack_s *move = *stack;
    (void)line_number;

    if (*stack == 0)
    {
        printf("\n");
    }
    while (move != 0 && move->n != 0 && move->n >= 0 && move->n <= 127)
    {
        printf("%c",(char)move->n);
        move = move->next;
    }
    printf("\n");
}
