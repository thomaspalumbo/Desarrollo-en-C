#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * @fn int menu(float*, float*, int, int)
 * @brief Muestra al usuario las opciones disponibles y lo va actualizando
 *
 * @param x recibe el primer operando
 * @param y recibe el segundo operando
 * @param flagPrimerOperando bandera para mostrar los operandos cargados
 * @param flagSegundoOperando bandera para mostrar los operandos cargados
 * @return la opcion elegida
 */
int menu(float* x, float* y, int flagPrimerOperando, int flagSegundoOperando)
{
	int opcion;
	system("cls");
	if(x != NULL && y != NULL)
	{
		if(flagPrimerOperando == 0 && flagSegundoOperando == 0)
		{
			printf("1: Ingrese el primer operando (A=X)\n");
			printf("2: Ingrese el segundo operando (B=Y)\n");
		}
		else if(flagPrimerOperando == 1 && flagSegundoOperando == 0)
		{
			printf("1: Ingrese el primer operando (A=%.2f)\n", *x);
			printf("2: Ingrese el segundo operando (B=Y)\n");
		}
		else if(flagPrimerOperando == 0 && flagSegundoOperando == 1)
		{
			printf("1: Ingrese el primer operando (A=X)\n");
			printf("2: Ingrese el segundo operando (B=%.2f)\n", *y);
		}
		else if (flagPrimerOperando == 1 && flagSegundoOperando == 1)
		{
			printf("1: Ingrese el primer operando (A=%.2f)\n", *x);
			printf("2: Ingrese el segundo operando (B=%.2f)\n", *y);
		}
			printf("3: Calcular todas las operaciones\n");
			printf("4: Informar resultados\n");
			printf("5: Salir\n\n");

			printf("Ingrese una opcion: ");
			fflush(stdin);
			scanf("%d", &opcion);
	}
		return opcion;
}
/**
 * @fn float pedirNumero(float*)
 * @brief le pide al usuario un numero para recibir y dentro se llama a otra funcion para validar
 *
 * @param numero numero ingresado por el usuario (direccion de memoria)
 * @return el correcto funcionamiento
 */
float pedirNumero(float* numero)
{
	int resOk = 0;
	if(numero != NULL)
	{
		validarEntrada(numero);
		resOk = 1;
	}
	return resOk;
}
/**
 * @fn float validarEntrada(float*)
 * @brief valida que el dato ingresado sea un numero
 *
 * @param entradaV recibe el numero pedido
 * @return el numero validado
 */
float validarEntrada(float* entradaV)
{
	int esUnNumero;
		if(entradaV != NULL)
		{
			printf("Ingrese un numero: ");
			fflush(stdin);
			esUnNumero = scanf("%f", entradaV);

			while(!esUnNumero)
			{
				printf("Error. Ingrese un numero: ");
				fflush(stdin);
				esUnNumero = scanf("%f", entradaV);
			}
		}
	return *entradaV;
}
/**
 * @fn float sumarNumeros(float, float)
 * @brief suma dos numeros
 *
 * @param numeroUno  primer operando a sumar
 * @param numeroDos  segundo operando a sumar
 * @return numeros sumados
 */
float sumarNumeros(float numeroUno, float numeroDos)
{
	float sumar;
	sumar = numeroUno + numeroDos;
	return sumar;
}
/**
 * @fn float restarNumeros(float, float)
 * @brief resta dos numeros
 *
 * @param numeroUno primer operando a restar
 * @param numeroDos segundo operando a restar
 * @return el resultado de la resta
 */
float restarNumeros(float numeroUno, float numeroDos)
{
	float restar;
	restar = numeroUno - numeroDos;
	return restar;
}
/**
 * @fn int dividirNumeros(float, float, float*)
 * @brief divide dos numeros
 *
 * @param numeroUno primer operando
 * @param numeroDos primer operando
 * @param divFinal resultado
 * @return el correcto funcionamiento
 */
int dividirNumeros(float numeroUno, float numeroDos, float* divFinal)
{
	int resOk = 0;
	if(divFinal != NULL)
	{
		if(numeroDos != 0)
		{
			*divFinal = numeroUno / numeroDos;
			resOk = 1;
		}
	}
	return resOk;
}
/**
 * @fn float multiplicarNumeros(float, float)
 * @brief multiplica dos numeros
 *
 * @param numeroUno primer operando a multiplicar
 * @param numeroDos segundo operando a multiplicar
 * @return el producto de la multiplicacion
 */
float multiplicarNumeros(float numeroUno, float numeroDos)
{
	float multiplicar;
	multiplicar = numeroUno * numeroDos;
	return multiplicar;
}
/**
 * @fn int calcularFactorial(float, int*)
 * @brief calcula el factorial de un numero ingresado, adaptandolo a las posibilidades de validacion
 *
 * @param numeroACalcular el numero a efectuar su factorial
 * @param resultado el resultado del factorial
 * @return si es óptimo, se llevan a cabo los siguientes pasos para poder continuar con el programa
 */
int calcularFactorial(float numeroACalcular, double* resultado)
{
	int resOk = 0;

	double numeroFactor;
	numeroFactor = numeroACalcular;
	*resultado = 1;

	if(resultado != NULL)
	{
		if(numeroFactor > 0 && numeroFactor < 22)
		{
			if(numeroFactor == ceil(numeroFactor))
			{
				for(int i = *resultado; i <= numeroFactor; i++)
				{
					*resultado = *resultado * i;
				}
				resOk = 1;
			}
			else
			{
				resOk = 0;
			}
		}
		else if(numeroFactor == 0)
		{
			resOk = 1;
		}
	}
	return resOk;
}
/**
 * @fn int calcularOperaciones(float*, float*, float*, float*, float*, int*, float*, int*, int*, int*, int*)
 * @brief llama a todas las funciones para calcular las operaciones.
 *
 * @param x primer operando
 * @param y segundo operando
 * @param resultadoSuma la suma de los dos operandos
 * @param resultadoResta la resta de los dos operandos
 * @param resultadoDivision  el resultado de la division
 * @param divExitosa analiza si se pudo dividir
 * @param resultadoMultiplicacion el resultado de la multipliacion
 * @param resultadoFactorialUno el resultado del primer operando
 * @param resultadoFactorialDos el resultado del segundo operando
 * @param seHizoFactUno analiza si se hizo el factorial del primer operando
 * @param seHizoFactDos analiza si se realizo el factorial del segundo operando
 * @return el correcto funciomiento de la funcion
 */
int calcularOperaciones(float* x, float* y, float* resultadoSuma, float* resultadoResta, float* resultadoDivision, int* divExitosa, float* resultadoMultiplicacion, double* resultadoFactorialUno, double* resultadoFactorialDos, int* seHizoFactUno, int* seHizoFactDos)
{
	int resOk = 0;
	if(x != NULL && y != NULL && resultadoSuma != NULL && resultadoResta != NULL && resultadoDivision != NULL && divExitosa != NULL && resultadoFactorialUno != NULL && resultadoFactorialDos != NULL && seHizoFactUno != NULL && seHizoFactDos != NULL)
	{
		*resultadoSuma = sumarNumeros(*x, *y);
		*resultadoResta = restarNumeros(*x, *y);
		*divExitosa = dividirNumeros(*x, *y, resultadoDivision);
		*resultadoMultiplicacion = multiplicarNumeros(*x, *y);
		*seHizoFactUno = calcularFactorial(*x, resultadoFactorialUno);
		*seHizoFactDos = calcularFactorial(*y, resultadoFactorialDos);
	  resOk = 1;
	}
	return resOk;
}
/**
 * @fn int informarResultado(float*, float*, float*, int*, float*, int*, int*, int*, int*)
 * @brief informa los resultados de todas las operaciones calculadas anteriormente
 *
 * @param resultadoSuma el resultado de la suma
 * @param resultadoResta el resultado de la resta
 * @param resultadoDivision el resultado de la division
 * @param divExitosa la evaluacion de la posible division o no
 * @param resultadoMultiplicacion el resultado de la multiplicacion
 * @param resultadoFactorialUno el resultado del primer factorial
 * @param resultadoFactorialDos el resultado del segundo factorial
 * @param seHizoFactUno el analisis del primer operando posible o no
 * @param seHizoFactDos el analisis del segundo operando posible o no
 * @return el correcto funcionamiento
 */
int informarResultado(float* resultadoSuma, float* resultadoResta, float* resultadoDivision, int* divExitosa, float* resultadoMultiplicacion, double* resultadoFactorialUno, double* resultadoFactorialDos, int* seHizoFactUno, int* seHizoFactDos)
{
	int resOk = 0;
		if(resultadoSuma != NULL && resultadoResta != NULL && resultadoDivision != NULL && divExitosa != NULL && resultadoMultiplicacion != NULL && resultadoFactorialUno != NULL && resultadoFactorialDos != NULL && seHizoFactUno != NULL && seHizoFactDos != NULL)
		{
			printf("El resultado de la suma es: %.2f\n", *resultadoSuma);
			printf("El resultado de la resta es: %.2f\n", *resultadoResta);
			if(*divExitosa == 1)
			{
				printf("El resultado de la division es: %.2f\n", *resultadoDivision);
			}
			else
			{
				printf("Error. no se puede divivir por 0.\n");
			}
			printf("El resultado de la multiplicación es: %.2f\n", *resultadoMultiplicacion);
			if(*seHizoFactUno == 1 && *seHizoFactDos == 1)
			{
				printf("El factorial del primer operando es: %.0lf y el factorial del segundo operando es: %.0lf\n", *resultadoFactorialUno, *resultadoFactorialDos);
			}
			else if(*seHizoFactUno == 1 && *seHizoFactDos == 0)
			{
				printf("El factorial del primer operando es: %.0lf y el factorial del segundo no se pudo calcular.\n", *resultadoFactorialUno);
			}
			else if(*seHizoFactUno == 0 && *seHizoFactDos == 1)
			{
				printf("El factorial del primer operando no se pudo calcular y el factorial del segundo operando es: %.0lf\n",*resultadoFactorialDos);

			}
			else if(*seHizoFactUno == 0 && *seHizoFactDos == 0)
			{
				printf("No se pudo calcular el factorial de ningun operando.\n");
			}
		 resOk = 1;
		}
		return resOk;
}
