#include "monty.h"
/**
 * pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @stack: pointer to pointer to the stack
 * @line_number: the line number
 * Return: Nothing
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	char result;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (((*stack)->n >= 65 && (*stack)->n <= 90)
		       || ((*stack)->n >= 97 && (*stack)->n <= 122))
	{
		result = (char)(*stack)->n;
		printf("%c\n", result);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}
