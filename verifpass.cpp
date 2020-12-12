#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>

bool verifpass();

main()
{
	for (int i = 0; i < 10; i++)
	{
		printf("\nEstado: %d\n", verifpass());
		system("PAUSE");
	}
}

bool verifpass()
{
	setlocale(LC_ALL, "Spanish");
	char pass[33], aux[33];
	int i, cantidad = 0, min = 0, num = 0, may = 0, n = 27;
	bool verif = false;

	printf("Creaci�n de contrase�a");
	printf("La contrase�a debe respetar los siguientes terminos:\n");
	printf("1-Debe contener al menos una letra may�scula, una letra min�scula y un n�mero\n");
	printf("2-No puede tener un caracter de puntuaci�n\n");
	printf("3-Debe contener entre 6 y 32 caractares\n");
	printf("4-No debe contener 2 letras consecutivas\n");

	_flushall();
	printf("Contrase�a: ");
	gets(pass);
	cantidad = strlen(pass);

	strcpy(aux, pass);
	strlwr(aux); //convertimos en minuscula

	if (cantidad > 5 && cantidad < 33)
	{
		for (i = 0; i < cantidad; i++)
		{
			if (pass[i] == ' ' || pass[i] == ',' || pass[i] == '!' || pass[i] == '?' || pass[i] == '�' || pass[i] == '.')
			{
				printf("\nContrase�a Incorrecta");
				printf("\nRazon: No se permiten caracteres especiales");
				printf("\nVuelva a intentarlo");
				// verif = false;
				return verif;
			}

			if (pass[i] > 64 && pass[i] < 91) //letras mayusculas
			{
				may++;
			}
			if (pass[i] > 97 && pass[i] < 122) //letras minusculas
			{
				min++;
			}
			if (pass[i] > 47 && pass[i] < 58) //Numeros
			{
				num++;
			}

			if (aux[i] == (aux[i + 1] - 1) && isalpha(aux[i]) && isalpha(aux[i + 1]))
			{
				printf("\nContrase�a Incorrecta");
				printf("\nRazon: No se permite el ingreso de caracteres consecutivos alfan�mericos");
				printf("\nVuelva a intentarlo");

				// printf("forma ascendente");
				return verif;
			}
		}
	}
	else
	{
		printf("\nContrase�a Incorrecta");
		printf("\nRazon: Ingrese una contrase�a de entre 6 y 32 caracteres");
		printf("\nVuelva a intentarlo");
		return verif;
	}

	if (num > 0 && min > 0 && may > 0)
	{
		printf("Contrase�a valida");
		verif = true;
		return verif;
	}
	else
	{
		// printf("Num: %d  Mayus: %d  Minus: %d", num, may, min);
		printf("\nContrase�a Incorrecta");
		printf("\nRazon: Ingrese al menos una mayuscula, una minuscula y un n�mero");
		printf("\nVuelva a intentarlo");
		return verif;
	}

	// if (num > 0 && min > 0 && may > 0)
	// {

	// }

	system("PAUSE");
	// return verif;
}