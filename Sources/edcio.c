


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "edcio.h"

/*
 * Reads a line of text from standard input and returns it as a
 * string (char *), sans trailing newline character.  (Ergo, if
 * user inputs only "\n", returns "" not NULL.)  Returns NULL
 * upon error or no input whatsoever (i.e., just EOF).  Leading
 * and trailing whitespace is not ignored.  Stores string on heap
 * (via malloc); memory must be freed by caller to avoid leak.
 */

string getLine(string fileIn)
{
    // growable buffer for chars
    string buffer = NULL;

    // capacity of buffer
    unsigned int capacity = 0;

    // number of chars actually in buffer
    unsigned int n = 0;

    // character read or EOF
    int c;

	FILE *arquivo;
	// Se a string estiver vazia, define FILE como stdin
	if (fileIn == NULL)
		arquivo = stdin;
	else
		arquivo = fopen(fileIn, "r");	// Se for passado um arquivo, tenta abrir o arquivo
	
	if (arquivo == NULL){
		return NULL;	// Não foi possível abrir o arquivo
	}
	
	
    // iteratively get chars from the input
    while ((c = fgetc(arquivo)) != '\n' && c != EOF)
    {
        // grow buffer if necessary
        if (n + 1 > capacity)
        {
            // determine new capacity: start at 32 then double
            if (capacity == 0)
                capacity = 32;
            else if (capacity <= (UINT_MAX / 2))
                capacity *= 2;
            else
            {
                free(buffer);
                return NULL;
            }

            // extend buffer's capacity
            string temp = realloc(buffer, capacity * sizeof(char));
            if (temp == NULL)
            {
                free(buffer);
                return NULL;
            }
            buffer = temp;
        }

        // append current character to buffer
        buffer[n++] = c;
    }

    // return NULL if user provided no input
    if (n == 0 && c == EOF)
        return NULL;

    // minimize buffer
    string minimal = malloc((n + 1) * sizeof(char));
    strncpy(minimal, buffer, n);
    free(buffer);

    // terminate string
    minimal[n] = '\0';

	// Fecha o arquivo de leitura
	fclose(arquivo);

    // return string
    return minimal;
}