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
	
	fread(&datos,sizeof(turnos),1,p);
	
	while(!feof(p) && bus==false)
	{
		
		if(busqueda == datos.matri)
		{
			bus=true;
			
		}
		fread(&datos,sizeof(turnos),1,p);
	}
	if(!bus)
	{
		printf("Matricula encontrada");
		
	}
	else
	{
		printf("No se encontro un Veterinario con la Matricula '%d'. Vuelva a Intentarlo\n", busqueda);
	}
	
	system("pause");
	
	fclose(p);
	
	return bus;
}


void busqueda(char aux2[33])
{
	FILE *f;
	f = fopen("Veterinarios.dat", "r");
	veterinario vet;
	
	int comp=0;
	bool bus=false;
	
	
	fread(&vet,sizeof(veterinario),1,f);
	
	while(!feof(f) && bus == false)
	{
		comp=strcmp(aux2,dat.contrasena);
		
		if(comp == 0)
		{
		
			bus=true;
			
		}
		
		fread(&vet,sizeof(veterinario),1,f);
	}
	
		if(bus)
	{
		printf("Contrasenia correcta");
		
	}
	else
	{
		printf("Contrasenia incorrecta.\n Porfavor vuelva a ingresar la contrasenia");
		
	}
	
	system("Pause")
	
	fclose(f);
	
}


