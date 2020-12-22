/*TODO:
* Agregar funciones listados santiago ?
* Agregar verifuser ?
* Agregar loginuser ?
* Agregar loginvet(veterinario &vet); ?
*
*
*/

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
	int rank = 0;
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
struct usuario
{
	char user[10];
	char contra[10];
	char ApeNom[60];
};

//Aux regisvet/regiusuario - Verificar cond contraseña
bool verifpass(char pass[33])
{
	char aux[33];
	int cantidad = 0, min = 0, num = 0, may = 0, n = 27;
	bool verif = false;

	cantidad = strlen(pass);

	strcpy(aux, pass);
	strlwr(aux); //convertimos en minuscula

	if (cantidad > 5 && cantidad < 33)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (pass[i] == ' ' || pass[i] == ',' || pass[i] == '!' || pass[i] == '?' || pass[i] == '¿' || pass[i] == '.')
			{
				printf("\nContraseña Incorrecta");
				printf("\nRazón: No se permiten caracteres especiales");
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
				printf("\nContraseña Incorrecta");
				printf("\nRazón: No se permite el ingreso de caracteres consecutivos alfanúmericos");
				printf("\nVuelva a intentarlo");

				// printf("forma ascendente");
				return verif;
			}
		}
	}
	else
	{
		printf("\nContraseña Incorrecta");
		printf("\nRazón: Ingrese una contraseña de entre 6 y 32 caracteres");
		printf("\nVuelva a intentarlo");
		return verif;
	}

	if (num > 0 && min > 0 && may > 0)
	{
		printf("\nContraseña valida");
		verif = true;
		return verif;
	}
	else
	{
		printf("\nContraseña Incorrecta");
		printf("\nRazón: Ingrese al menos una mayuscula, una minuscula y un número");
		printf("\nVuelva a intentarlo");
		return verif;
	}

	system("PAUSE");
	// return verif;
}

//Aux regisvet/regiusuario - Verificar cond usuario
bool verifuser(char usuario[10])
{
	int i, cantidad = 0, min = 0, num = 0, may = 0, mayus = 0;
	bool verificacion = true;

	cantidad = strlen(usuario);

	if (cantidad <= 6 || cantidad >= 10)
	{
		printf("\nIngrese un nombre de usuario de entre 6 y 10 caracteres\n\n");
		getch();
		return false;
	}

	if (usuario[0] < 'a' || usuario[0] > 'z')
	{
		printf("\nError. El nombre debe comenzar con minusculas\n\n");
		getch();
		return false;
	}

	// printf("%s", usuario);
	for (i = 0; i < cantidad; i++)
	{
		if (usuario[i] > 64 && usuario[i] < 91) //letras mayusculas
		{
			mayus++;
		}

		if (usuario[i] >= 97 && usuario[i] < 122) //letras minusculas
		{
			min++;
		}

		if (usuario[i] > 47 && usuario[i] < 58) //Numeros
		{
			num++;
		}
	}

	if (num > 3)
	{
		printf("Supero el limite de digitos en el nombre\n");
		getch();
		return false;
	}

	if (mayus > 2)
	{
		printf("Supero el limite de mayusculas en el nombre\n");
		getch();
		return false;
	}

	printf("\nUsuario valido");
	getch();
	return true;
}

//Aux registurn
int buscamatri(int buscamat)
{
	FILE *fp = fopen("Veterinarios.dat", "rb");
	veterinario vet;

	fread(&vet, sizeof(vet), 1, fp);
	while (!feof(fp))
	{
		if (vet.matri == buscamat)
		{
			fclose(fp);
			printf("Matricula '%d' encontrada", vet.matri);
			return 1;
		}
		fread(&vet, sizeof(vet), 1, fp);
	};
	printf("No se encontro un Veterinario con la Matricula '%d'. Vuelva a Intentarlo\n", buscamat);
	getch();
	fclose(fp);
	return 0;
}

//Aux registurn
int verifdni(turnos &turn)
{
	FILE *fp = fopen("Mascotas.dat", "rb");
	mascota masc;

	fread(&masc, sizeof(masc), 1, fp);
	while (!feof(fp))
	{
		if (masc.DNI == turn.DNI_dueno)
		{
			turn.masc = masc;
			fclose(fp);
			return 1;
		}
		fread(&masc, sizeof(masc), 1, fp);
	};
	printf("No se encontro una Mascota con el DNI de Dueño '%d'. Vuelva a Intentarlo\n", turn.DNI_dueno);
	getch();
	fclose(fp);
	return 0;
}

//********************ADMIN********************
//Admin - Opc 1 - Registrar Veterinario
void regisvet()
{
	int b = 0, i;
	char op;
	veterinario vet;

	FILE *fp = fopen("Veterinarios.dat", "a+b");

	do
	{
		system("cls");

		printf("\n\t---------------------------");
		printf("\n         Registro de Veterinarios");
		printf("\n\t---------------------------\n");

		_flushall();

		do
		{
			printf("\nApellido y Nombre: ");
			gets(vet.ApeNom);
		} while (strlen(vet.ApeNom) == 0);

		_flushall();

		do
		{
			printf("Matricula (6 dígitos): ");
			scanf("%d", &vet.matri);

			if (vet.matri <= 0 || vet.matri > 999999)
			{
				printf("La matricula debe ser de 6 digitos.\nVuelva a intentarlo.");
			}

		} while (vet.matri <= 0 || vet.matri > 999999);

		do
		{
			_flushall();
			printf("\nCreación de Contraseña\n");
			printf("La contraseña debe respetar los siguientes terminos:\n");
			printf("1-Debe contener al menos una letra mayúscula, una letra minúscula y un número\n");
			printf("2-No puede tener un caracter de puntuación\n");
			printf("3-Debe contener entre 6 y 32 caractares\n");
			printf("4-No debe contener 2 letras consecutivas\n");
			printf("Ingrese una contrasena: ");
			gets(vet.contravet);

		} while (verifpass(vet.contravet) == 0);

		do
		{
			printf("\nDNI: ");
			scanf("%d", &vet.DNI_vet);
			b = 0;
			if (vet.DNI_vet < 10000000 || vet.DNI_vet > 99999999 || vet.DNI_vet == INT_MAX)
			{
				printf("¡Ingrese un DNI de 8 dígitos!");
				getch();
				b = 1;
			}

		} while (b == 1);

		_flushall();
		do
		{
			printf("\nTelefono: ");
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

		vet.rank = 0;
		fwrite(&vet, sizeof(vet), 1, fp);

		_flushall();
		printf("\n-----------------------\n¿Registrar otro Veterinario? (S/N): ");
		scanf("%c", &op);

	} while (op == 'S' || op == 's');

	fclose(fp);

	printf("\nVeterinarios Creados Satisfactoriamente");
	getch();
	system("CLS");
}

//Admin - Opc 2 - Registrar Usuario
void regiusuario()
{
	usuario us;
	int ban;
	char s;

	FILE *arch;
	arch = fopen("Usuarios.dat", "a+b");

	do
	{
		ban = 0;

		system("cls");

		printf("\n\t---------------------------------");
		printf("\n         Registro de Usuarios Asistentes");
		printf("\n\t---------------------------------\n");

		printf("Ingrese Apellido y Nombre del usuario: ");
		_flushall();
		gets(us.ApeNom);

		do
		{
			_flushall();
			printf("\nCreación de Usuario\n");
			printf("El nombre de usuario debe tener las siguientes condiciones:\n");
			printf("1-Debe comenzar con una letra minuscula\n");
			printf("2-Debe tener al menos 2 letras mayusculas\n");
			printf("3-Debe contener entre 6 y 10 caractEres\n");
			printf("4-Debe contener como maximo 3 numeros\n");
			printf("Ingrese un nombre de Usuario: ");
			gets(us.user);

		} while (verifuser(us.user) == 0);

		do
		{
			_flushall();
			printf("\n\nCreación de Contraseña\n");
			printf("La contraseña debe respetar los siguientes terminos:\n");
			printf("1-Debe contener al menos una letra mayúscula, una letra minúscula y un número\n");
			printf("2-No puede tener un caracter de puntuación\n");
			printf("3-Debe contener entre 6 y 32 caractares\n");
			printf("4-No debe contener 2 letras consecutivas\n");
			printf("Ingrese una contraseña: ");
			gets(us.contra);

		} while (verifpass(us.contra) == 0);

		fwrite(&us, sizeof(us), 1, arch);

		_flushall();
		printf("\n\n¿Desea Registrar otro Usuario? (S/N): ");
		scanf("%c", &s);

	} while (s == 'S' || s == 's');

	fclose(arch);
}

//Admin - Opc 3 - Listar Atencion x vet
void listatencionvet()
{
	FILE *p = fopen("Turnos.dat", "rb");
	turnos datos;
	int i, op, aux1, aux2, aux3, b1 = 0, b2 = 0, b3 = 0;
	bool band;

	if (p == NULL)
	{
		printf("\nNo se han realizado Atenciones.");
	}
	else
	{
		system("cls");
		printf("\n\t---------------------------");
		printf("\n         Atenciones por Veterinario");
		printf("\n\t---------------------------\n");
		printf("\nSe buscaran las atenciones realizadas por un Veterinario en cierto mes y año.\n");

		printf("\nIngresar la matricula del Veterinario: ");
		scanf("%d", &aux1);
		printf("\nIngresar mes de las atenciones a visualizar: ");
		scanf("%d", &aux2);
		printf("\nIngresar año de las atenciones a visualizar: ");
		scanf("%d", &aux3);
		fread(&datos, sizeof(turnos), 1, p);

		i = 0;
		while (!feof(p))
		{
			if (datos.borrado == true)
			{
				b1 = 1;

				if (aux1 == datos.matri)
				{
					b2 = 1;

					if (aux2 == datos.fec.mm && aux3 == datos.fec.aa)
					{
						b3 = 1;
						printf("\n------------------------------------------------\n");
						printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd, datos.fec.mm, datos.fec.aa);
						printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
						printf("\tDNI del dueño: %d", datos.masc.DNI);
						printf("\nLocalidad: %s", datos.masc.Loc);
						printf("\nEdad: %d años", (2020 - datos.masc.fec.aa));
						printf("\tPeso: %.2fkg", datos.masc.peso);
						printf("\n------------------------------------------------\n");
					}
				}
			}
			fread(&datos, sizeof(turnos), 1, p);
		}

		if (b1 == 0)
		{
			printf("\n\nNo se realizaron atenciones por el veterinario de matricula: %d.", aux1);
		}
		else if (b2 == 0)
		{
			printf("\n\nNo existe el veterinario de matricula: %d.", aux1);
		}
		else if (b3 == 0)
		{
			printf("\n\nNo se realizaron atenciones en esa fecha.");
		}

		fclose(p);
	}
}

//Admin - Opc 4 - Ranking
void ranking()
{
	FILE *p, *s;
	p = fopen("Turnos.dat", "rb");
	s = fopen("Veterinarios.dat", "r+b");
	turnos datos;
	veterinario dat, v[50], aux;
	bool x = false;
	int n = 0, b, c = 0;

	if (p == NULL)
	{
		printf("\nNo se han cargado Turnos.");
	}
	else
	{

		fread(&dat, sizeof(veterinario), 1, s);
		while (!feof(s))
		{
			v[n] = dat;
			v[n].rank = 0;
			fread(&dat, sizeof(veterinario), 1, s);
			n++;
		}

		fread(&datos, sizeof(turnos), 1, p);

		while (!feof(p))
		{
			if (datos.borrado == true)
			{
				for (int i = 0; i < n; i++)
				{
					if (v[i].matri == datos.matri)
					{
						v[i].rank++;
					}
				}
			}

			fread(&datos, sizeof(turnos), 1, p);
		}

		rewind(s);

		do
		{
			b = 0;
			for (int i = 0; i < n - 1; i++)
			{
				if (v[i].rank < v[i + 1].rank)
				{
					aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					b = 1;
				}
			}
		} while (b == 1);

		printf("\nRANKING DE VETERINARIOS\n------------------");
		for (int i = 0; i < n; i++)
		{
			printf("\nPUESTO N° %d para %s con: %d atenciones", i + 1, v[i].ApeNom, v[i].rank);
		}

		printf("\nRecibira el bono: '%s'.", v[0].ApeNom);

		fclose(p);
		fclose(s);
	}
}

//********************USUARIO********************
//Asist - Opc 1 - Iniciar sesion Usuario
void loginuser(usuario &user, bool &login)
{
	FILE *f;
	f = fopen("Usuarios.dat", "r+b");
	usuario aux;
	int b = 0, userenc = 0;
	char username[10];
	char contra[10];

	if (f == NULL)
	{
		printf("\nNo hay usuarios registrados.");
	}
	else
	{
		_flushall();
		printf("\nIngrese el nombre de usuario: ");
		gets(username);

		_flushall();
		printf("Ingrese la contraseña: ");
		gets(contra);

		fread(&aux, sizeof(usuario), 1, f);

		while (!feof(f) && b == 0)
		{
			if (strcmp(username, aux.user) == 0)
			{
				userenc = 1;
				if (strcmp(contra, aux.contra) == 0)
				{
					user = aux;
					login = true;
					b = 1;
				}
			}
			fread(&aux, sizeof(usuario), 1, f);
		}

		if (userenc)
		{
			printf("\nUsuario encontrado");
			if (b)
			{
				printf("\nContraseña encontrada");
			}
			else
			{
				printf("\nContraseña incorrecta.\nVuelva a intentarlo");
			}
		}
		else
		{
			printf("\nNo se encontro un Asistente con el nombre de usuario '%s'.\nVuelva a Intentarlo\n", username);
		}

		if (userenc && b)
		{
			login = true;
			printf("\n --- Logueo exitoso --- \n");
		}
	}
	fclose(f);
	system("pause");
}

//Asist - Opc 2 - Registrar Mascota
void regispet()
{
	FILE *p = fopen("Mascotas.dat", "a+b");
	int b = 0, i = 0;
	char op;
	mascota datos;

	if (p == NULL)
	{
		printf("\n\nEl archivo no existe");
	}
	else
	{
		do
		{
			system("cls");
			printf("\n\t----------------------------------");
			printf("\n	BIENVENDO AL REGISTRO DE MASCOTAS!		");
			printf("\n\t----------------------------------\n");
			printf("\nCargue los datos de la mascota a registrar:");

			_flushall();
			printf("\n\nApellido y Nombre de la mascota: ");
			gets(datos.ApeNom);
			printf("Domicilio de la mascota: ");
			gets(datos.Dom);

			do
			{
				printf("DNI del dueño: ");
				scanf("%08d", &datos.DNI);

				b = 0;
				if (datos.DNI < 10000000 || datos.DNI > 99999999)
				{
					printf("¡Ingrese un DNI de 8 dígitos!");
					getch();
					b = 1;
				}

			} while (b == 1);

			_flushall();
			printf("Localidad de la mascota: ");
			gets(datos.Loc);

			printf("\nFecha de nacimiento \n");
			printf("\tDia: ");
			scanf("%d", &datos.fec.dd);
			printf("\tMes: ");
			scanf("%d", &datos.fec.mm);
			printf("\tAño (En 4 digitos): ");
			scanf("%d", &datos.fec.aa);

			printf("Peso de la mascota: ");
			scanf("%f", &datos.peso);

			_flushall();
			do
			{
				printf("Telefono del dueño de la mascota: ");
				gets(datos.telef);
				i = 0;
				b = 0;
				while (datos.telef[i] != '\0')
				{
					if (isdigit(datos.telef[i]) == false && datos.telef[i] != '+')
						b = 1;
					i++;
				}

			} while (strlen(datos.telef) == 0 || b == 1);

			fwrite(&datos, sizeof(mascota), 1, p);

			_flushall();
			printf("\n\n¿Continuar Registrando Mascotas? (S/N): ");
			scanf("%c", &op);

		} while (op == 'S' || op == 's');

		fclose(p);
	}
}

//Asist - Opc 3 - Registrar Turno
void registurn()
{
	turnos turno;
	int b = 0;
	char op;

	FILE *fp = fopen("Turnos.dat", "a+b");
	do
	{
		system("cls");
		printf("\n\t--------------------------\n");
		printf("\t    Registro de Turnos");
		printf("\n\t--------------------------\n");

		do
		{
			b = 0;
			printf("Matricula de Veterinario: ");
			scanf("%d", &turno.matri);

			if (turno.matri <= 0 || turno.matri > 999999)
			{
				printf("Ingrese una matricula de hasta 6 dígitos!");
				getch();
				b = 1;
			}

		} while (b == 1 || buscamatri(turno.matri) == 0);

		do
		{
			b = 0;
			printf("\nDNI del Dueño (8 dígitos): ");
			scanf("%d", &turno.DNI_dueno);
			if (turno.DNI_dueno < 10000000 || turno.DNI_dueno > 99999999)
			{
				printf("¡Ingrese un DNI de 8 dígitos!");
				getch();
				b = 1;
			}

		} while (b == 1 || verifdni(turno) == 0);

		printf("\n\tFecha del Turno: \n");
		printf("\n\tDia: ");
		scanf("%02d", &turno.fec.dd);
		printf("\n\tMes: ");
		scanf("%02d", &turno.fec.mm);
		printf("\n\tAño: ");
		scanf("%04d", &turno.fec.aa);

		turno.borrado = false;

		// fwrite(fp, "%s;%06d;%08d;%s;\n",vet.ApeNom,vet.matri,vet.DNI_vet,vet.telef);

		fwrite(&turno, sizeof(turno), 1, fp);

		_flushall();
		printf("\n\n¿Registrar otro Turno? (S/N): ");
		scanf("%c", &op);

	} while (op == 'S' || op == 's');

	fclose(fp);
}

//Asist - Opc 4 - Listar Atencion x vet y fecha
void listatencionvetfec()
{
	FILE *p = fopen("Turnos.dat", "rb");
	turnos datos;
	int i, op, aux1, aux2, aux3, aux4, b1 = 0, b2 = 0, b3 = 0;
	bool band;

	if (p == NULL)
	{
		printf("\n\nEl archivo no existe");
	}
	else
	{
		printf("\n\t---------------------------");
		printf("\n         Atenciones por Veterinario y Fecha");
		printf("\n\t---------------------------\n");

		printf("\n\nIngresar la matricula del veterinario del cual desea saber las atenciones realizadas: ");
		scanf("%d", &aux1);
		printf("\nFecha de las Atenciones a visualizar");

		printf("\n\tIngresar día de las atenciones: ");
		scanf("%d", &aux2);
		printf("\n\tIngresar mes de las atenciones: ");
		scanf("%d", &aux3);
		printf("\n\tIngresar año de las atenciones: ");
		scanf("%d", &aux4);

		fread(&datos, sizeof(turnos), 1, p);

		i = 0;
		while (!feof(p))
		{
			if (datos.borrado == true)
			{
				b1 = 1;

				if (aux1 == datos.matri)
				{
					b3 = 1;
					if (aux2 == datos.fec.dd && aux3 == datos.fec.mm && aux4 == datos.fec.aa)
					{
						b2 = 1;
						printf("\n------------------------------------------------\n");
						printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd, datos.fec.mm, datos.fec.aa);
						printf("MASCOTA %d\n", i + 1);
						printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
						printf("\tDNI del dueño: %d", datos.masc.DNI);
						printf("\nLocalidad de la mascota: %s", datos.masc.Loc);
						printf("\nEdad de la mascota: %d años", (2020 - datos.masc.fec.aa));
						printf("\tPeso de la mascota: %.2fkg", datos.masc.peso);
						i++;
					}
				}
			}

			fread(&datos, sizeof(turnos), 1, p);
		}

		printf("\n------------------------------------------------\n");

		if (b1 == 0)
		{
			printf("\n\nNo se realizaron atenciones por el veterinario de matricula: %d.", aux1);
		}
		else if (b2 == 0)
		{
			printf("\n\nNo existe el veterinario de matricula: %d.", aux1);
		}
		else if (b3 == 0)
		{
			printf("\n\nNo se realizaron atenciones en esa fecha.");
		}
	}

	fclose(p);
}

//********************VETERINARIO********************
//Vet - Opc 1 - Iniciar Sesion Vet
void loginvet(veterinario &vet, bool &login)
{
	FILE *p;
	p = fopen("Veterinarios.dat", "r+");

	veterinario datos;
	int busqueda;
	bool bus = false, contra = false;
	char aux2[33];

	if (p == NULL)
	{
		printf("No hay veterinarios registrados.");
	}
	else
	{
		printf("\n\t\tIngrese el número de matricula: ");
		scanf("%d", &busqueda);

		_flushall();
		printf("\t\tIngrese la contraseña: ");
		gets(aux2);

		fread(&datos, sizeof(veterinario), 1, p);

		while (!feof(p) && contra == false)
		{
			if (busqueda == datos.matri)
			{
				bus = true;
				if (strcmp(aux2, datos.contravet) == 0)
				{
					vet = datos;
					contra = true;
				}
			}
			fread(&datos, sizeof(veterinario), 1, p);
		}
		if (bus)
		{
			printf("\n\t\tMatricula encontrada\n");
			if (contra)
			{
				printf("\t\tContraseña encontrada");
			}
			else
			{
				printf("\t\tContraseñaa incorrecta.\n Por favor vuelva a ingresar la contraseña");
			}
		}
		else
		{
			printf("\t\tNo se encontro un Veterinario con la Matricula '%d'. Vuelva a Intentarlo\n", busqueda);
		}

		if (bus && contra)
		{
			login = true;
			printf("\n\t -- Logueo exitoso -- \n");

			// printf("Veterinario '%s' ingreso al sistema",datos.ApeNom);
		}
	}
	system("pause");
	fclose(p);
}

//Vet - Opc 2 - Listar Turnos y atender
void listurn(int matridein, turnos &aux, bool &band1)
{
	FILE *p = fopen("Turnos.dat", "r+b");
	turnos datos;
	int i = 0, op;
	bool band = false;

	rewind(p);
	if (p == NULL)
	{
		printf("\n\n\t\tEl archivo no existe");
	}
	else
	{
		fread(&datos, sizeof(turnos), 1, p);
		i = 0;
		while (!feof(p))
		{
			if (datos.borrado == false && matridein == datos.matri)
			{
				// printf("Aquie esta el valor de datos de la matricula: %d", datos.matri);
				printf("\n------------------------------------------------\n");
				printf("MASCOTA %d\n", i + 1);
				printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
				printf("\tDNI del dueño: %d", datos.masc.DNI);
				printf("\nLocalidad de la mascota: %s", datos.masc.Loc);
				printf("\nEdad de la mascota: %d años", (2020 - datos.masc.fec.aa));
				printf("\tPeso de la mascota: %.2fkg", datos.masc.peso);
				i++;
			}
			fread(&datos, sizeof(turnos), 1, p);
		}

		printf("\n------------------------------------------------\n");

		if (i == 0)
		{
			printf("No posee turnos para atender ");
		}

		rewind(p);

		fread(&datos, sizeof(turnos), 1, p);
		band = false;

		while (!feof(p) && band == false)
		{
			if (datos.borrado == false && matridein == datos.matri)
			{
				printf("\n¿Desea llamar a %s? (1-Si/0-No): ", datos.masc.ApeNom);
				scanf("%d", &op);

				if (op == 1)
				{
					datos.borrado = true;
					fseek(p, -sizeof(turnos), SEEK_CUR);
					fwrite(&datos, sizeof(turnos), 1, p);
					printf("¡Atención confirmada!\n\n");
					aux = datos;
					band1 = true;
				}
				band = true;
				getch();
			}
			else
			{
				fread(&datos, sizeof(turnos), 1, p);
			}
		}
	}
	fclose(p);
}

//Vet - Opc 3 - Evolucion del paciente
void evolucion(turnos aux)
{
	FILE *p, *s;
	p = fopen("Turnos.dat", "rb+");
	s = fopen("Veterinarios.dat", "rb");
	turnos datos;
	veterinario dat;

	bool x = false, band = false;

	fread(&datos, sizeof(turnos), 1, p);

	while (!feof(p) && band == false)
	{
		// printf("Aca1");
		// printf("datos.borrado: %d",datos.borrado);
		// printf("aux.fec: %d/%d/%d",aux.fec.dd);
		if (datos.borrado == true && strcmp(aux.masc.ApeNom, datos.masc.ApeNom) == 0 && aux.fec.dd == datos.fec.dd && aux.fec.mm == datos.fec.mm && aux.fec.aa == datos.fec.aa)
		{
			// printf("Aca2");
			fread(&dat, sizeof(veterinario), 1, s);

			while (!feof(s) && x == false)
			{
				// printf("Aca3");
				if (aux.matri == dat.matri)
				{
					printf("\nVeterinario: %s", dat.ApeNom);
					x = true;
				}
				fread(&dat, sizeof(veterinario), 1, s);
			}
			printf("\nFECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd, datos.fec.mm, datos.fec.aa);

			printf("La evolución del paciente: ");
			scanf(" %[^\n]", datos.DetA);
			fseek(p, -sizeof(turnos), SEEK_CUR);
			fwrite(&datos, sizeof(turnos), 1, p);
			band = true;
		}
		else
		{
			fread(&datos, sizeof(turnos), 1, p);
		}
	}

	fclose(s);
	fclose(p);
	_flushall();
}

void mododev(turnos aux)
{
	FILE *p, *s;
	p = fopen("Turnos.dat", "rb+");
	s = fopen("Veterinarios.dat", "rb");
	int i = 1;
	int des;
	turnos datos;
	veterinario dat;
	_flushall();
	printf("\nModo Desarrollador\n-------------------\n");
	printf("Para ingresar debe confirmar que sabe lo que esta haciendo.\n");
	printf("¿En qué lenguaje esta escrito este programa?\nSu respuesta: ");
	scanf("%c", &des);
	if (des == 'c' || des == 'C')
	{
		printf("Acceso concedido.\n");
		getch();
		system("CLS");
		printf("Se mostraran los datos de la variable Aux\n");
		printf("\nFecha del Turno: %d/%d/%d\n", aux.fec.dd, aux.fec.mm, aux.fec.aa);
		printf("Matricula %d", aux.matri);
		getch();

		printf("Se listaran todos los turnos de los veterinarios\n");

		fread(&datos, sizeof(turnos), 1, p);
		while (!feof(p))
		{
			// printf("Aquie esta el valor de datos de la matricula: %d", datos.matri);
			printf("\n------------------------------------------------\n");
			printf("MASCOTA %d\n", i);
			printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
			printf("\nFecha %d/%d/%d", datos.fec.dd, datos.fec.mm, datos.fec.aa);
			printf("\tDNI del dueño: %d", datos.masc.DNI);
			printf("\nLocalidad de la mascota: %s", datos.masc.Loc);
			printf("\nEdad de la mascota: %d años", (2020 - datos.masc.fec.aa));
			printf("\tPeso de la mascota: %.2fkg", datos.masc.peso);
			printf("\tEstado: %d", datos.borrado);
			i++;

			fread(&datos, sizeof(turnos), 1, p);
		}
		printf("\n-----------------------------------\n");
	}
	else
	{
		printf("Acceso denegado.\n");
		printf("No vuelva a ingresar\n");
	}
}

void easteregg(int ea)
{
	system("CLS");
	printf("No sigas haciendo eso porfa\n");
	getch();

	switch (ea)
	{
	case 1:
		printf("\nPara");
		break;
	case 2:
		printf("\nEn serio deja de intentarlo");
		break;
	case 3:
		printf("\nDeja de hacer eso");
		getch();
		printf("\nEstas muy aburrido verdad?");
		break;
	case 4:
		printf("\nBueno esta bien...\n");
		printf("\n¡Encontraste una sección secreta!\n");
		printf("¡Presiona una tecla para jugar al nuevo CyberPunk 2077!\n\n");
		getch();
		printf("\nParece ser que no tenes el juego, proba en otro momento :/\n");
		getch();
		break;
	}
	printf("\n");
	getch();
}