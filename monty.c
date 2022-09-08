#include "lists.h"

stack_t *g_stack = NULL;

/**
 * main - simple monty compiler
 * @argc: count of command line args provided
 * @argv: list of arguments
 * Return: status 0
 */
int main(int argc, char **argv)
{
	char *fname, *line, *linecp, *content, *toFree, *command, *arg;
	FILE *fptr;
	char c;
	int lnum = 1, i = 0, iarg;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fname = argv[1];
	fptr = fopen(fname, "r");
	toFree = content = malloc(sizeof(char) * 1000);

	while ((c = getc(fptr)) != EOF)
	{
		content[i] = c;
		i++;
	}

	while ((line = strsep((char **)&content, "\n")) != NULL)
	{
		linecp = line;
		command = strtok(linecp, " ");
		arg = strtok(NULL, " ");
		if (command == NULL)
			break;
		if (arg != NULL)
		{
			iarg = atoi(arg);
			invoke(command, (unsigned int *)&iarg);
		}
		else
		{
			invoke(command, (unsigned int *)&iarg);
		}
	};

	free(toFree);
	return (0);
}
