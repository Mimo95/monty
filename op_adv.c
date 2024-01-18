#include "monty.h"
/*
 * opcode_sub - Subtracts the top element from the second top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_sub(stack_t **stack, unsigned int line_number)
{
    int sub;
    struct  stack_s *first = *stack;
    struct  stack_s *second = first->next;

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO,"L%u: can't sub, stack too short",line_number);
        exit(EXIT_FAILURE);
    }
    sub = second->n - first->n;
    second->n = sub;

    *stack = second;
    if (second->next != NULL) 
    {
        second->next->prev = NULL;
    }
    free(first);
}

/*
 * opcode_div - Divides the second top element by the top element of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_div(stack_t **stack, unsigned int line_number)
{
    int div;
    struct  stack_s *first = *stack;
    struct  stack_s *second = first->next;

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO,"L%u: can't div, stack too short",line_number);
        exit(EXIT_FAILURE);
    }
    if (first->n == 0)
    {
        dprintf(STDERR_FILENO,"L%u: division by zero",line_number);
        exit(EXIT_FAILURE);
    }
    div = second->n / first->n;
    second->n = div;

    *stack = second;
    if (second->next != NULL) 
    {
        second->next->prev = NULL;
    }
    free(first);
}

/*
 * opcode_mul - Multiplies the top two elements of the stack.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_mul(stack_t **stack, unsigned int line_number)
{
    int mul;
    struct  stack_s *first = *stack;
    struct  stack_s *second = first->next;

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO,"L%u: can't mul, stack too short",line_number);
        exit(EXIT_FAILURE);
    }
    mul = second->n * first->n;
    second->n = mul;

    *stack = second;
    if (second->next != NULL) 
    {
        second->next->prev = NULL;
    }
    free(first);
}

/*
 * opcode_mod - Computes the modulo of the second top element by the top element.
 * @stack: A double pointer to the top of the stack.
 * @line_number: The current line number in the Monty bytecode file.
 */

void opcode_mod(stack_t **stack, unsigned int line_number)
{
    int mod;
    struct  stack_s *first = *stack;
    struct  stack_s *second = first->next;

    if (dlistint_len(*stack) < 2)
    {
        dprintf(STDERR_FILENO,"L%u: can't mod, stack too short",line_number);
        exit(EXIT_FAILURE);
    }
    if (first->n == 0)
    {
        dprintf(STDERR_FILENO,"L%u: division by zero",line_number);
        exit(EXIT_FAILURE);
    }
    mod = second->n % first->n;
    second->n = mod;

    *stack = second;
    if (second->next != NULL) 
    {
        second->next->prev = NULL;
    }
    free(first);
}
