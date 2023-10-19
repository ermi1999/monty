#include "monty.h"
/**
 * nop - doesn't do anything
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line_number)
{
	*stack = *stack;
	line_number = line_number;
}
