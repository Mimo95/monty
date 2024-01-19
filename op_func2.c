#include "monty.h"

/*
 * dlistint_len - Returns the number of elements in a doubly linked list.
 * @h: A pointer to the head of the doubly linked list.
 *
 * Return: The number of elements in the doubly linked list.
 */

size_t dlistint_len(stack_t *h)
{
	size_t i = 0;

	while (h != 0)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/*
 * opcode_swap - Swaps the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_swap(stack_t **stack, unsigned int line_number)
{
    struct  stack_s *first ;
    struct  stack_s *second ;
    
    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO,"L%u: can't swap, stack too short\n",line_number);
        exit(EXIT_FAILURE);
    }
    first = *stack;
    second = first->next;

    first->next = second->next;
    first->prev = second;

    second->next = first;
    second->prev = 0;

    *stack = second;
}

/*
 * opcode_add - Adds the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_add(stack_t **stack, unsigned int line_number)
{
    int sum;
    struct  stack_s *first ;
    struct  stack_s *second ;

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO,"L%u: can't add, stack too short\n",line_number);
        exit(EXIT_FAILURE);
    }
	first = *stack;
	second = first->next;

    sum = first->n + second->n;
    second->n = sum;

    *stack = second;
    if (second->next != NULL) 
    {
        second->next->prev = NULL;
    }
    free(first);
}

/*
 * opcode_nop - Does nothing.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_nop(stack_t **stack, unsigned int line_number)
{
    	(void)stack;
	(void)line_number;
}
