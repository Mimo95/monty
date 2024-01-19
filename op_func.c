#include "monty.h"

/*
 * opcode_push - Pushes an integer onto the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_push(stack_t **stack, unsigned int line_number)
{
    char *value;
    int n;
    struct stack_s *newNode;

    value = strtok (0, " \n");
    if (value == 0 || !isdigit(*value))
    {
        dprintf(STDERR_FILENO,"L%u: usage: push integer\n",line_number);
        exit(EXIT_FAILURE);
    }
    n = atoi(value);
    newNode = malloc(sizeof(struct stack_s));
    if (newNode == 0)
    {
        dprintf(STDERR_FILENO,"Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    newNode->prev = 0;
    newNode->n = n;
    newNode->next = 0;
    newNode->next = *stack;

    if (*stack != 0)
    {
        (*stack)->prev = newNode;
    }
    *stack = newNode;
}

/*
 * opcode_pall - Prints all the elements on the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_pall(stack_t **stack, unsigned int line_number)
{
    size_t i;
    stack_t *pTop = *stack;
    (void)(line_number);
    i = 0;

    while (pTop != 0)
    {
        printf("%d\n",pTop->n);
        pTop = pTop->next;
        i++;
    }
}

/*
 * opcode_pint - Prints the value at the top of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_pint(stack_t **stack, unsigned int line_number)
{
    stack_t *pTop = *stack;
    if (*stack == 0)
    {
        dprintf(STDERR_FILENO,"L%u: can't pint, stack empty\n",line_number);
        exit(EXIT_FAILURE);
    }
    printf("%d\n",pTop->n);
}

/*
 * opcode_pop - Removes the top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *pTemp;

	if (*stack == 0)
	{
		dprintf(STDERR_FILENO,"L%u: can't pop an empty stack\n",line_number);
        	exit(EXIT_FAILURE);
	}

	pTemp = *stack;
    *stack = (*stack)->next;
    if (*stack != 0)
    {
        (*stack)->prev = 0;
    }
	free(pTemp);
	pTemp = 0;

}
