
// FUNCION PARA VERIFICAR LA MATRICULA DEL VETERINARIO Y LA CONTRASENIA

void loginvet()
{
	FILE *p;
	p = fopen("Veterinario.dat", "r");

	veterinario datos;

	bool bus = false, contra = false;
	char aux[33];

	printf("Ingrese el numero de matricula: ");
	scanf("%d", &busqueda);

	_flushall();
	printf("Ingrese la contraseña: ");
	gets(aux2);

	fread(&datos, sizeof(veterinario), 1, p);

	while (!feof(p) && contra == false)
	{
		if (busqueda == datos.matri)
		{
			bus = true;
			if (aux2 == datos.contravet)
			{
				contra = true;
			}
		}
		fread(&datos, sizeof(turnos), 1, p);
	}

	if (bus)
	{
		printf("\nMatricula encontrada\n");
		if (contra)
		{
			printf("Contrasenia encontrada");
		}
		else
		{
			printf("Contrasenia incorrecta.\n Porfavor vuelva a ingresar la contrasenia");
		}
		system("Pause")
	}
	else
	{
		printf("No se encontro un Veterinario con la Matricula '%d'. Vuelva a Intentarlo\n", busqueda);
	}

	if(bus && contra)
	{
		printf("\n Logueo exitoso \n");
	}

	system("pause");
	fclose(p);
}
