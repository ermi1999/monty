#include "monty.h"
/**
 * push - pushs a value to the stack
 * @line: the line number
 * @stack: pointer to pointer to the stack
 * @num: the value to be added
 * Return: Nothing
 */
void push(stack_t **stack, int num)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}
