#include "monty.h"
/**
 * pall - handles the pall in monty code
 * @stack: pointer to pointer to the stack
 * @line: the line number
 * Return: Nothing
 */
void pall(stack_t **stack)
{
	stack_t *current;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
