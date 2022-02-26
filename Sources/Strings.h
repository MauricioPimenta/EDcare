#ifndef _STRINGS_H
#define _STRINGS_H

#include <float.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>


/*
 * Our own data type for string variables.
 */

typedef char* string;
typedef struct strings Strings;

//#define 


/* newString - Inicializa a estrutura da String
 *   - cria uma cópia, caracter a caracter, do vetor de char de entrada
 * Recebe um vetor de caracteres
 * Retorna um ponteiro pro TAD String
 * 
 * 
 */
Strings *newString(string s);

/*
 * Reads a line of text from standard input and returns it as a
 * string (char *), sans trailing newline character.  (Ergo, if
 * user inputs only "\n", returns "" not NULL.)  Returns NULL
 * upon error or no input whatsoever (i.e., just EOF).  Leading
 * and trailing whitespace is not ignored.  Stores string on heap
 * (via malloc); memory must be freed by caller to avoid leak.
 */

Strings* getLine(string fileIn);



#endif