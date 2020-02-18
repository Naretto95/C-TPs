#ifndef __TP8_H_
#define __TP8_H_

#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
/*! void error()
\brief envoi une erreur par raport à l'argument*/
void error();
/*! void error2()
\brief envoi une erreur pas rapport au mot donné*/
void error2();
/*! void cesar()
\brief execute le cryptage par la methode cesar*/
void cesar();
/*! void vigenere()
\brief execute le cryptage par la methode vigenere*/
void vigenere();
/*! void scytale()
\brief execute le cryptage par la methode scytale*/
void scytale();

#endif
