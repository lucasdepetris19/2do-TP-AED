struct veterinario
{
	char ApeNom[60];
	int matri;
	int DNI;
	char telef[25];
};

struct fecha
{
	int dd;
	int mm;
	int aa;
};

struct mascota
{
	char ApeNom[60];
	char Dom[60];
	int DNI;
	char Loc[60];
	fecha fec;
	float peso;
	char telef[25];
};

int regiusuario() //Alpha (No Usar)
{
	char Usuario;
	int ban=0;
	do
	{
		printf("\tRegistrar Usuario Asistente\n");
		printf("Ingrese el nombre de Usuario: ");
		_flushall();
		gets(Usuario);
		strcmp ();

		Comprobar();
		
	}
	
	while(Comprobar!=0);

	if (Usuario>10 and Usuario<6)
	{
		printf("Error. El nombre de Usuario debe contener entre 6 y 10 caracteres\n");	
		ban++;
	}
	if ()
	{
		printf("Error. El nombre de Usuario debe contar con 2 letras mayusculas\n");
		ban++;
	}
	if ()
	{
		printf("Error. El nombre de Usuario debe tener como maximo 3 digitos");
		ban++;
	}
	if ()
	{
		printf("Error. El nombre debe comenzar con minusculas");
		ban++;
	}
	if ()
	{
		printf("Error. El nombre esta repetido, Ingrese otro diferente");
		ban++;
	}
	return
}
}

void regisvet(int i)
{
	// char nom[20], ape[20], carrera[30];
	// int cantf = 0, b = 0;
	// float prom = 0;
	int b = 0;
	veterinario vet;

	FILE *fp = fopen("Veterinarios.dat", "a+b");
		
	printf("Registro de Veterinario Nº%d", i + 1);
	printf("\n------------------------------\n");

	_flushall();
	
	do
	{
		printf("Apellido y Nombre: ");
		gets(vet.ApeNom);
	} while (strlen(vet.ApeNom) == 0);
	_flushall();

	do
	{
		printf("Matricula (6 dígitos): ");
		scanf("%06d", &vet.matri);
	} while (vet.matri <= 0 || vet.matri > 999999);

	do
	{
		printf("DNI: ");
		scanf("%08d", &vet.DNI);
	} while (vet.DNI < 10000000 || vet.DNI > 99999999);

	_flushall();
	do
	{
		printf("Télefono: ");
		gets(vet.telef);
		i = 0;
		b = 0;
		while (vet.telef[i] != '\0')
		{
			if (isdigit(vet.telef[i]) == false && vet.telef[i] != '+')
				b = 1;
			printf("\ncaracter = %c",vet.telef[i]);
			printf("\nbandera = %d",b);
			i++;
		}

	} while (strlen(vet.telef) == 0 || b == 1);
	_flushall();

	// fwrite(fp, "%s;%06d;%08d;%s;\n",vet.ApeNom,vet.matri,vet.DNI,vet.telef);
	
	fwrite(&vet, sizeof(vet), 1, fp);

	fclose(fp);
	system("CLS");
}

// int menuPrincipal()
// {
// }
