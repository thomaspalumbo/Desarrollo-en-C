/*
 ============================================================================
 Name        : Calculadora.c
 Author      : Palumbo Thomas
 ============================================================================
 */

#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	setbuf(stdout, NULL);

	char seguir = 's';
	float a;
	float b;
	float resSuma;
	float resResta;
	float resDivision;
	float resMultiplicacion;
	double resFactorialUno;
    double resFactorialDos;
    int seHizoFuno;
    int seHizoFdos;
    int divExitosa;

    int flagPrimerOperando = 0;
    int flagSegundoOperando = 0;
    int flagCalcularOper = 0;
    int flagInformarRes = 0;

	do
	{
		switch(menu(&a, &b, flagPrimerOperando, flagSegundoOperando))
		{
		case 1:
			pedirNumero(&a);
			flagPrimerOperando = 1;
			break;
		case 2:
			pedirNumero(&b);
			flagSegundoOperando = 1;
			break;
		case 3:

			if(flagPrimerOperando == 1 && flagSegundoOperando == 1 && flagCalcularOper == 0)
			{
				calcularOperaciones(&a,  &b, &resSuma,  &resResta, &resDivision, &divExitosa, &resMultiplicacion, &resFactorialUno, &resFactorialDos, &seHizoFuno, &seHizoFdos);
				flagCalcularOper = 1;
				flagInformarRes = 1;
				printf("Operaciones calculadas, seleccione la opcion 4 para mostrar los resultados.\n");
			}
			else if(flagCalcularOper == 1)
			{
				printf("Error. Ya se calcularon las operaciones\n");
			}
			else if(flagPrimerOperando == 1 && flagSegundoOperando == 0)
			{
				printf("Error. Falta ingresar el segundo operando\n");
			}
			else if(flagPrimerOperando == 0 && flagSegundoOperando == 1)
			{
				printf("Error. Falta ingresar el primer operando\n");
			}
			else
			{
				printf("Error. no ingreso ningun operando\n");
			}
			break;
		case 4:
			if(flagCalcularOper == 1 && flagInformarRes == 1)
			{
			informarResultado(&resSuma, &resResta, &resDivision, &divExitosa, &resMultiplicacion, &resFactorialUno, &resFactorialDos, &seHizoFuno, &seHizoFdos);
			flagInformarRes = 0;
			flagPrimerOperando = 0;
			flagSegundoOperando = 0;
			flagCalcularOper = 0;
			}
			else if(flagCalcularOper == 0)
			{
				printf("Error. Primero debe calcular.\n");
			}
			break;
		case 5:
			printf("Eligio salir\n");
			seguir = 'n';
			break;
		default:
			printf("Opcion erronea, reintente nuevamente\n");
			break;
		}

		system("pause");

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
