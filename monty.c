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
	check_file_error(fptr, fname);
	toFree = content = malloc(sizeof(char) * 1000);
	check_malloc(toFree);
	while ((c = getc(fptr)) != EOF)
	{
		content[i] = c;
		if (!((c == '\n' || c == ' ') && content[i - 1] == '\n'))
			i++;
	}
	while ((line = strsep((char **)&content, "\n")))
	{
		linecp = line;
		command = strtok(linecp, " ");
		arg = strtok(NULL, " ");
		if (command == NULL)
			break;
		if (arg != NULL)
			iarg = atoi(arg);
		invoke(command, arg, iarg, lnum);
		lnum++;
	};
	free(toFree);
	return (0);
}

/**
 * check_file_error - check if file opening failed
 *
 * @fptr: point to file
 * @fname: name of file
 */
void check_file_error(FILE *fptr, char *fname)
{
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", fname);
		exit(EXIT_FAILURE);
	}
}
