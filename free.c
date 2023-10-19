#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: the stack to be freed
 * Return: Nothing.
 */
void free_stack(stack_t **stack)
{
	while (*stack != NULL)
	{
		stack_t *temp;

		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
