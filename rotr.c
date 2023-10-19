#include "monty.h"
/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *last;

	line_number = line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;
	last = *stack;

	while (last->next != NULL)
		last = last->next;
	last->next = temp;
	temp->prev = last;
	*stack = temp->next;
	(*stack)->prev = NULL;
	temp->next = NULL;
}
