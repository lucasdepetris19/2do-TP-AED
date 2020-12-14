#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

bool buscar(int busqueda);
void busqueda(char contrasena[33]);

// FUNCION PARA VERIFICAR LA MATRICULA DEL VETERINARIO Y LA CONTRASENIA

main()
{
	int aux;
	char aux2[33];
	bool s;
	
	printf("Ingrese el numero de matricula: ");
	scanf("%d",&aux);
	
	s=buscamatri(aux);
	
	if(s)
	{	
		_flushall();
		printf("Ingrese la contrasenia: ");
		printf("%s",aux2);
		busqueda(aux2);
	}
}

void busqueda(char contrasena)
{
	FILE *f;
	f = fopen("Usuarios.dat", "rb");
	bool bus=false;
	fread(contrasena, 20, f);

	while (!feof(f))
	{
		fread(contrasena, 20, f);

		if (strcmp(contrasena, usuario.contra) == 0)
		{
			bus=true;
		}
	}
	
		if(bus)
	{
		printf("Contrasenia encontrada");
	}
	else
	{
		printf("Contrasenia incorrecta");
		
	}
	
	
	fclose(f);
}


