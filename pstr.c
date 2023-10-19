#include "monty.h"

/**
 * pstr - prints the string starting at the top of
 * the stack, followed by a new line.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	line_number = line_number;

	if (*stack == NULL)
	{
		printf("\n");
		return;
	}

	while (*stack != NULL && (*stack)->n != 0)
	{
		if ((*stack)->n >= 0 && (*stack)->n <= 255)
		{
			printf("%c", (*stack)->n);
		}
		*stack = (*stack)->next;
	}

	printf("\n");
}
