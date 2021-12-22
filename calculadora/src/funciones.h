#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int menu(float* x, float* y, int flagPrimerOperando, int flagSegundoOperando);
float pedirNumero(float* entradaV);
float sumarNumeros(float numeroUno,float numeroDos);
float restarNumeros(float numeroUno,float numeroDos);
int dividirNumeros(float numeroUno,float numeroDos, float* divFinal);
float multiplicarNumeros(float numeroUno,float numeroDos);
int calcularFactorial(float numeroACalcular, double* resultado);
int calcularOperaciones(float* x, float* y, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, int* divExitosa, float* resultadoMultiplicacion, double* resultadoFactorialUno, double* resultadoFactorialDos, int* seHizoFactUno, int* seHizoFactDos);
int informarResultado(float* resultadoSuma, float* resultadoResta, float* resultadoDivision, int* divExitosa, float* resultadoMultiplicacion, double* resultadoFactorialUno, double* resultadoFactorialDos, int* seHizoFactUno, int* seHizoFactDos);
float validarEntrada(float *);

#endif /* FUNCIONES_H_ */
