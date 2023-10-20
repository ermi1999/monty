#include "monty.h"
/**
 * to_queue - process the queue opcode
 * @stack: double pointer to the top of the stack
 * @line_number: current line number
 * Return: Nothing
 */
void to_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *bottom,*temp = *stack;

	line_number = line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->next = *stack;
	(*stack)->prev = bottom;

	*stack = (*stack)->next;
	(*stack)->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = NULL;
}
