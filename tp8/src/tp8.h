#ifndef TP8_H
#define TP8_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Prints usage information listing the available ciphers. */
void print_usage(void);

/** Reads a word and a shift from stdin, then prints its Caesar cipher. */
void caesar_cipher(void);

/** Reads a word and a key from stdin, then prints its Vigenere cipher. */
void vigenere_cipher(void);

/** Reads a word from stdin, then prints it encoded with the scytale (columnar transposition) cipher. */
void scytale_cipher(void);

#endif
