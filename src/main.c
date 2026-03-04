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
