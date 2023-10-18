#include "monty.h"
#define MAX_LENGTH 1024

/**
 * process_push - process the "push" opcode
 * @stack: double pointer to the top of the stack
 * @arg: argument string of the push opcode
 * @line_number: current line number
 * Return: Nothing
 */
void process_push(stack_t **stack, char *arg, unsigned int line_number)
{
	unsigned int i;

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
			continue;
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	push(stack, atoi(arg));
}

/**
 * execute - executes each line in the file
 * @file: the file to be looped
 * Return: Nothing
 */
void execute(FILE *file)
{
	stack_t *stack = NULL;
	char line[MAX_LENGTH];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *opcode;

		line_number++;
		opcode = strtok(line, " \t\n$");
		if (opcode != NULL)
		{
			if (strncmp(opcode, "push", 4) == 0)
			{
				char *arg = strtok(NULL, " \t\n$");

				if (arg == NULL)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
				process_push(&stack, arg, line_number);
			}
			else if (strncmp(opcode, "pall", 4) == 0)
			{
				pall(&stack);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
}

/**
 * main - monty bytecode interpreter
 * @argc: argument count
 * @argv: the arguments array
 * Return: 0 if success or exit with EXIT_FAILURE
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	execute(file);

	return (0);
}
