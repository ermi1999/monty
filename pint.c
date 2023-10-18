#include "monty.h"
/**
 * pint - prints the value at the top of the stack.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	}
	printf("%d\n", (*stack)->n);
}
