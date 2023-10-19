#include "monty.h"
/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	line_number = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;
	*stack = temp->next;
	(*stack)->prev = NULL;
	last->next = temp;
	temp->prev = last;
	temp->next = NULL;
}
