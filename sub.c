#include "monty.h"
/**
 * sub - subtracts the top two elements of the stack.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n -= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
