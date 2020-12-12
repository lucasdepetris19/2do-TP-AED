struct fecha
{
	int dd;
	int mm;
	int aa;
};
struct veterinario
{
	char ApeNom[60];
	char contravet[10];
	int matri;
	int DNI_vet;
	char telef[25];
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

struct turnos
{
	int matri;
	fecha fec;
	int DNI_dueno;
	char DetA[380];
	mascota masc;
	bool borrado;
};

void regiusuario()
{
	printf("Registre el usuario %s\n");
}

void regisvet()
{
	// char nom[20], ape[20], carrera[30];
	// int cantf = 0, b = 0;
	// float prom = 0;
	int b = 0, i;
	char op;
	veterinario vet;

	FILE *fp = fopen("Veterinarios.dat", "a+b");

	printf("\n\t---------------------------");
	printf("\n         Registro de Veterinarios");
	printf("\n\t---------------------------\n");

	do
	{
		_flushall();

		do
		{
			printf("\nApellido y Nombre: ");
			gets(vet.ApeNom);
		} while (strlen(vet.ApeNom) == 0);
		
		_flushall();

		/*Dependiente de funcion verifpass*/
		// do
		// {
		// 	printf("Contraseña: ");
		// 	gets(vet.contravet);
		// } while (verifpass(vet.contravet));
		// _flushall();

		do
		{
			printf("Matricula (6 dígitos): ");
			scanf("%06d", &vet.matri);
		} while (vet.matri <= 0 || vet.matri > 999999);

		do
		{
			printf("DNI: ");
			scanf("%08d", &vet.DNI_vet);
		} while (vet.DNI_vet < 10000000 || vet.DNI_vet > 99999999);

		_flushall();
		do
		{
			printf("\nTélefono: ");
			gets(vet.telef);
			i = 0;
			b = 0;
			while (vet.telef[i] != '\0')
			{
				if (isdigit(vet.telef[i]) == false && vet.telef[i] != '+')
					b = 1;
				i++;
			}

		} while (strlen(vet.telef) == 0 || b == 1);
		_flushall();

		_flushall();
		printf("\n\n¿Registrar otro Veterinario? (S/N): ");
		scanf("%c", &op);

	} while (op == 'S' || op == 's');
	// fwrite(fp, "%s;%06d;%08d;%s;\n",vet.ApeNom,vet.matri,vet.DNI_vet,vet.telef);

	fwrite(&vet, sizeof(vet), 1, fp);

	fclose(fp);
	system("CLS");
}

// int menuPrincipal()
// {
// }