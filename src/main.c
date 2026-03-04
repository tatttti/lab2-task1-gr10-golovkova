/* main.c */
/* Author: Tanya Golovkova */

/*
 * This file implements variant 40:
 * reverse the order of words in a string separated by spaces and commas.
 */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* Constants */
#define MAX_WORDS 200

/* Function prototypes */ 
int split_words (char *str, char **words); 
void print_reversed (char **words, int count);

/*
 * Split string into words separated by spaces and commas.
 * Returns number of words.
 */
int
split_words (char *str, char **words)
{
	int count = 0;
	char *token = strtok (str, " ,");

	while (token != NULL)
		{
			words[count++] = token;
			token = strtok (NULL, " ,");
		}

	return count;
}

/*
 * Print words in reverse order.
 */
void
print_reversed (char **words, int count)
{
	for (int i = count - 1; i >= 0; i--)
		{
			printf ("%s", words[i]);
			if (i > 0)
				printf (" ");
		}
	printf ("\n");
}

/*
 * Entry point: reads string from command line and prints reversed words.
 */
int
main (int argc, char *argv[])
{
	if (argc < 2)
	{
		printf ("Usage: %s \"string\"\n", argv[0]); 
		return 1;
	}

	char *input = strdup (argv[1]);
	char *words[MAX_WORDS];

	printf ("Исходная строка: %s\n", argv[1]);

	int count = split_words (input, words);

	printf ("Результат: ");
	print_reversed (words, count);

	free (input); 
	return 0;
}