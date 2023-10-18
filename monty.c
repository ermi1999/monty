#include "monty.h"
#define MAX_LENGTH 1024

/**
 * process_push - process the "push" opcode
 * @stack: double pointer to the top of the stack
 * @line_number: current line number
 * Return: Nothing
 */
void process_push(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \t\n$");
	unsigned int i;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

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
void execute(FILE *file, instruction_t *instructions)
{
	stack_t *stack = NULL;
	char line[1024];
	unsigned int line_number = 0;

	while (fgets(line, sizeof(line), file) != NULL)
	{
		char *opcode;

		line_number++;
		opcode = strtok(line, " \t\n$");
		if (opcode != NULL)
		{
			int i;
			int found = 0;

			for (i = 0; instructions[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(&stack, line_number);
					found = 1;
					break;
				}
			}
			if (found == 0)
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
	instruction_t instructions[] = {
		{"push", process_push},
		{"pall", pall},
		{NULL, NULL}
	};

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

	execute(file, instructions);

	return (0);
}
