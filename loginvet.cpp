#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	s=buscar(aux);
	
	if(s)
	{	
		_flushall();
		printf("Ingrese la contrasenia: ");
		printf("%s",aux2);
		busqueda(aux2);
	}

}


bool buscar(int busqueda)
{
	FILE *p;
	p=fopen("Turnos.dat","r");
	turnos datos;
	bool bus=false;
	
	fread(datos,sizeof(turnos),1,p);
	
	while(!feof(p))
	{
		if(busqueda==datos.matri)
		{
			bus=true;
				
		}	
		
	}
	
	
	if(bus)
	{
		printf("Matricula encontrada");
		
	}
	else
	{
		printf("No se encontro la matricula del veterinario");
		
	}
	
	return bus;
}


void busqueda(char contrasena)
{
	FILE *f;
	f = fopen("Usuarios.dat", "r");
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


