#include "monty.h"

/**
 * main - simple monty compiler
 * @argc: count of command line args provided
 * @argv: list of arguments
 * Return: status 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
	}
	printf("%s", argv[0]);

	return (0);
}
