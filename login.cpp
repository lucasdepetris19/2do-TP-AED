void login()
{
	char nombre[20];
	char contrasena[20];

	printf("Ingrese el nombre de usuario: ");
	gets(nombre);

	buscauser(nombre);
	//Agregar condicion en caso que nombre no se encuentre
	//Lo mismo para pass

	printf("Ingrese la contraseña");
	gets(contrasena);

	buscapass(contrasena);
}

int buscauser(char nombre[20])
{
	FILE *f;
	f = fopen("Usuarios.dat", "r");
	int b;

	fread(nombre, sizeof(usuario), f);

	while (!feof(f))
	{
		if (strcmp(nombre, usuario.user) == 0)
		{
			b++;
		}

		fread(nombre,  sizeof(usuario), f);
	}

	if (b > 0)
	{
		printf("Usuario correcto\n");
		return b;
	}
	else
	{
		printf("Usuario Incorrecto\n");
		return b;
	}

	fclose(f);
}

int buscapass(char contrasena)
{
	FILE *f;
	f = fopen("Usuarios.dat", "r");

	fread(contrasena, 20, f);

	while (!feof(f))
	{
		fread(contrasena, 20, f);

		if (strcmp(contrasena, usuario.contra) == 0)
		{
			printf("Contraseña Correcta\n");
		}
		else
		{
			printf("Contraseña Incorrecta\n");
		}
	}

	fclose(f);
}