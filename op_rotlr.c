#include "monty.h"

/*
 * opcode_rotl - Rotates the stack to the top.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_rotl(stack_t **stack, unsigned int line_number)
{

    struct stack_s *firstTop = *stack;
    struct stack_s *secondTop = firstTop->next;
    struct stack_s *last = *stack;
    (void)line_number;

    while (last->next != 0)
    {
        last = last->next;
    }
    last->next = firstTop;
    firstTop->prev = last;
    firstTop->next = 0;
    secondTop->prev = 0;
    *stack = secondTop;

}

/*
 * opcode_rotr - Rotates the stack to the bottom.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_rotr(stack_t **stack, unsigned int line_number)
{
    struct stack_s *last = *stack;
    struct stack_s *secondLast = 0;
    (void)line_number;

    while (last->next != 0)
    {
        secondLast = last;
        last = last->next;
    }
    last->next = *stack;
    (*stack)->prev = last;
    secondLast->next = 0;
    last->prev = 0;
    *stack = last;
}
