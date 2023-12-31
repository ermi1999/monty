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
	stack_t *current = *stack;

	line_number = line_number;

	while (current != NULL && current->n != 0 &&
			current->n > 0 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
