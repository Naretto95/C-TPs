#ifndef __TP4_H_
#define __TP4_H_

#include <stdio.h> /*Autorise l'emploi de printf et de scanf.*/
#include <time.h>
#include <stdlib.h>
#include <math.h>

/*! float approximation(int n)
\param int n
\brief donne une approximation de pi à l'aide de la methode de quadrillage*/
float approximation(int n);

/*! float Madhava(int n)
\param int n
\brief donne une approximation de pi à l'aide de la methode de Madhava*/
float Madhava(int n);

/*! float wallis(int n)
\param int n
\brief donne une approximation de pi à l'aide de la methode de jhon wallis*/
float wallis(int n);

/*! float float newton(int n)
\param int n
\brief donne une approximation de sqrt(2) à l'aide de la methode de newton*/
float newton(int n);

/*! float float newton(int n)
\param int n
\brief donne une approximation de sqrt(2) à l'aide de la methode de edmund halley*/
float halley(int n);

/*! float float newton(int n)
\param int n
\brief donne une approximation de sqrt(2) à l'aide de la methode de theon de smyrne*/
float theon(int n);
#endif