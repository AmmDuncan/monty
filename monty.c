#include "lists.h"

data_t *data = NULL;

/**
 * main - simple monty compiler
 * @argc: count of command line args provided
 * @argv: list of arguments
 * Return: status 0
 */
int main(int argc, char **argv)
{
	char *fname, *content, *toFree;
	FILE *fptr;
	char c;
	int lnum = 1, i = 0;
	int j, n;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	data = malloc(sizeof(data_t));
	fname = argv[1];
	fptr = fopen(fname, "r");
	check_file_error(fptr, fname);
	toFree = content = malloc(sizeof(char) * 1000);
	check_malloc(toFree);
	while ((c = getc(fptr)) != EOF)
	{
		content[i] = c;
		/*if (!((c == '\n' || c == ' ') && content[i - 1] == '\n'))*/
		i++;
	}
	for (j = 0, n = 0; content[j]; j++)
		n += (content[j] == '\n');

	handle_lines(content, lnum, n);
	free(toFree);
	free(data);
	free_stack(data->stack);
	fclose(fptr);
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

/**
 * handle_lines - get lines from content and invoke commands
 * @content: content of bytescode file
 * @linenum: line number
 * @totallines: total number of lines
 */
void handle_lines(char *content, int linenum, int totallines)
{
	char *linecp, *command, *line;
	int lnum = linenum;

	while ((line = strsep((char **)&content, "\n")))
	{
		void (*f)(stack_t **, unsigned int);

		linecp = line;
		command = strtok(linecp, " ");
		data->arg = strtok(NULL, " ");
		if (command == NULL && lnum >= totallines)
			break;
		else if (command == NULL)
		{
			lnum++;
			continue;
		}
		f = get_func(command);
		if (f == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lnum, command);
			exit(EXIT_FAILURE);
		}
		(*f)(&data->stack, lnum);
		lnum++;
	};
}
