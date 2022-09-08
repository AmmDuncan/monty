#include "monty.h"

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

	printf("%d: ", lnum);
	while ((c=getc(fptr)) != EOF)
	{
		content[i] = c;
		i++;
	}

	while ((line = strsep((char **)&content, "\n")) != NULL)
	{
		linecp = line;
		command = strsep(&linecp, " \t");
		arg = strsep(&linecp, " \t");
	       	/*iarg = atoi(arg);*/

		printf("Command: %s, Arg: %s\n", command, arg);
	};
	free(toFree);
	return (0);
}

