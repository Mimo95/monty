#include "monty.h"

/*
 * opcode_rotl - Rotates the stack to the top.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_rotl(stack_t **stack, unsigned int line_number)
{

    struct stack_s *firstTop ;
    struct stack_s *secondTop ;
    struct stack_s *last ;
    (void)line_number;

    if (*stack == 0)
    {
	return;
    }
    firstTop = *stack;
    secondTop = firstTop->next;
    last = *stack;

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
    struct stack_s *last ;
    struct stack_s *secondLast;
    (void)line_number;

    if (*stack == 0)
    {
	return;
    }
    last = *stack;
    secondLast = 0;

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
