#include "monty.h"
/**
 * pall - handles the pall in monty code
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	line_number = line_number;
	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
