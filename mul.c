#include "monty.h"
/**
 * mul - multiplies the second top element of the stack with the top element of the stack.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	temp->next->n *= temp->n;
	temp->next->prev = NULL;
	*stack = temp->next;
	free(temp);
}
