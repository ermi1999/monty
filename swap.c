#include "monty.h"
/**
 * swap - handles the pall in monty code
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	*stack = top->next;
	top->next = (*stack)->next;
	top->prev = *stack;
	(*stack)->next = top;
	(*stack)->prev = NULL;
}
