/*TODO:
* Agregar funciones listados santiago
* Agregar verifuser
* Agregar loginuser
* Agregar loginvet(veterinario &vet);
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
	int rank;
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

//Aux regisvet/regiusuario - Verificar cond contrase�a
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
		printf("\nContrase�a Incorrecta");
		printf("\nRazon: Ingrese al menos una mayuscula, una minuscula y un n�mero");
		printf("\nVuelva a intentarlo");
		return verif;
	}

	system("PAUSE");
	// return verif;
}

//Aux regisvet/regiusuario - Verificar cond usuario
//bool verifuser()
//{
//}

//Aux registurn
int buscamatri(int buscamat)
{
	FILE *fp = fopen("veterinarios.dat", "rb");
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
	FILE *fp = fopen("mascotas.dat", "rb");
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
	printf("No se encontro una Mascota con el DNI de Due�o '%d'. Vuelva a Intentarlo\n", turn.DNI_dueno);
	getch();
	fclose(fp);
	return 0;
}

//********************ADMIN********************
//Admin - Opc 1 - Registrar Veterinario
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
			printf("Matricula (6 di�gitos): ");
			scanf("%06d", &vet.matri);
			system("cls");
		} while (vet.matri <= 0 || vet.matri > 999999);

		do
		{
			_flushall();
			printf("Contrase�a\n");
			printf("La contrase�a debe respetar los siguientes terminos:\n");
			printf("1-Debe contener al menos una letra may�scula, una letra min�scula y un n�mero\n");
			printf("2-No puede tener un caracter de puntuaci�n\n");
			printf("3-Debe contener entre 6 y 32 caractares\n");
			printf("4-No debe contener 2 letras consecutivas\n");
			printf("Ingrese una contrasena: ");
			gets(vet.contravet);
			system("cls");
		} while (verifpass(vet.contravet) == 0);

		do
		{
			printf("DNI: ");
			scanf("%08d", &vet.DNI_vet);
			system("cls");
		} while (vet.DNI_vet < 10000000 || vet.DNI_vet > 99999999);

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
			system("cls");

		} while (strlen(vet.telef) == 0 || b == 1);

		_flushall();
		printf("\n\n�Registrar otro Veterinario? (S/N): ");
		scanf("%c", &op);
		system("cls");

	} while (op == 'S' || op == 's');

	fwrite(&vet, sizeof(vet), 1, fp);

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
		printf("\tRegistrar Usuario Asistente\n");

		printf("Ingrese Apellido y Nombre del usuario: ");
		_flushall();
		gets(us.ApeNom);
		system("cls");

		// do
		// {
		_flushall();
		printf("Nombre de usuario\n");
		printf("El nombre de usuario debe tener las siguientes condiciones\n");
		printf("1-Debe comenzar con una letra minuscula\n");
		printf("2-Debe tener al menos 2 letras mayusculas\n");
		printf("3-Debe contener entre 6 y 10 caractares\n");
		printf("4-Debe contener como maximo 3 numeros\n");
		printf("Ingrese un nombre de Usuario: ");
		gets(us.user);
		system("cls");
		// } while (verifuser(us.user) == 0);

		do
		{
			_flushall();
			printf("Contrase�a\n");
			printf("La contrase�a debe respetar los siguientes terminos:\n");
			printf("1-Debe contener al menos una letra may�scula, una letra min�scula y un n�mero\n");
			printf("2-No puede tener un caracter de puntuaci�n\n");
			printf("3-Debe contener entre 6 y 32 caractares\n");
			printf("4-No debe contener 2 letras consecutivas\n");
			printf("Ingrese una contrasena: ");
			gets(us.contra);
			system("cls");
		} while (verifpass(us.contra) == 0);

		fwrite(&us, sizeof(us), 1, arch);

		_flushall();
		printf("\n\n�Desea Registrar otro Usuario? (S/N): ");
		scanf("%c", &s);

	} while (s == 'S' || s == 's');

	fclose(arch);
}

//Admin - Opc 3 - Listar Atencion x vet
void listatencionvet()
{
	FILE *p = fopen("Turnos.dat", "rb");
	turnos datos;
	int i, op, aux1, aux2, aux3, b1 = 0, b2 = 0;
	bool band;

	printf("	ATENCIONES POR VETERINARIO");
	printf("\n\nIngresar la matricula del veterinario del cual desea saber las atenciones realizadas: ");
	scanf("%d", &aux1);
	printf("\n Ingresar mes de las atenciones a visualizar: ");
	scanf("%d", &aux2);
	printf("\n Ingresar ano de las atenciones a visualizar: ");
	scanf("%d", &aux3);

	if (p == NULL)
	{
		printf("\n\nEl archivo no existe");
	}
	else
	{
		fread(&datos, sizeof(turnos), 1, p);

		i = 0;
		while (!feof(p))
		{
			if (datos.borrado == true && aux1 == datos.matri)
			{
				b1 = 1;
				if (aux2 == datos.fec.mm && aux3 == datos.fec.aa)
				{
					b2 = 1;
					printf("\n------------------------------------------------\n");
					printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd, datos.fec.mm, datos.fec.aa);
					printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
					printf("DNI del due�o: %d", datos.masc.DNI);
					printf("Localidad de la mascota: %s", datos.masc.Loc);
					printf("\nEdad de la mascota: %d\n", (2020 - datos.masc.fec.aa));
					printf("Peso de la mascota: %f", datos.masc.peso);
					i++;
				}
			}

			fread(&datos, sizeof(turnos), 1, p);
		}

		printf("\n------------------------------------------------\n");

		if (b1 == 0)
		{
			printf("\n\nNo se encontro la matricula del veterinario");
		}
		else
		{
			if (b2 == 0)
			{
				printf("\n\nNo realizo atenciones en ese mes y ese ano");
			}
		}

		fclose(p);
	}
}

//********************USUARIO********************
//Asist - Opc 1 - Iniciar sesion Usuario
void loginuser(usuario &user)
{
	FILE *f;
	f = fopen("Usuarios.dat", "r+b");
	usuario aux;
	int b = 0;
	char username[10];
	char contra[10];

	_flushall();
	printf("Ingrese el nombre de usuario: ");
	gets(username);

	_flushall();
	printf("Ingrese la contrasena: ");
	gets(contra);

	fread(&aux, sizeof(usuario), 1, f);

	while (!feof(f) && b == 0)
	{
		if (strcmp(username, aux.user) == 0 && strcmp(contra, aux.contra) == 0)
		{
			user = aux;
			b = 1;
		}
		fread(&aux, sizeof(usuario), 1, f);
	}

	fclose(f);

	if (b == 1)
	{
		printf("Usuario y Contrase�a Correctos\n\n");
	}
	else
	{
		printf("Datos Incorrectos\n\n");
	}

	system("pause");
}

//Asist - Opc 2 - Registrar Mascota
void regispet()
{
	FILE *p = fopen("mascotas.dat", "a+b");
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
			printf("\n\n	BIENVENDO AL REGISTRO DE MASCOTAS!		");
			printf("\n Ingresar datos de la mascota a registrar por favor:");

			_flushall();
			printf("\n\nIngrese Apellido y Nombre de la mascota: ");
			gets(datos.ApeNom);
			printf("Ingrese domicilio de la mascota: ");
			gets(datos.Dom);
			printf("Ingrese DNI del due�o: ");
			scanf("%d", &datos.DNI);
			_flushall();
			printf("Ingrese localidad de la mascota: ");
			gets(datos.Loc);
			printf("\nIngrese Fecha de nacimiento \n");
			printf("Dia: ");
			scanf("%d", &datos.fec.dd);
			printf("Mes: ");
			scanf("%d", &datos.fec.mm);
			printf("Anio (En 4 digitos): ");
			scanf("%d", &datos.fec.aa);
			printf("Ingresar peso de la mascota: ");
			scanf("%f", &datos.peso);
			_flushall();
			printf("Ingrese telefono del due�o de la mascota: ");
			gets(datos.telef);

			fwrite(&datos, sizeof(mascota), 1, p);

			_flushall();
			printf("\n\n�Continuar Registrando Ventas? (S/N): ");
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

	FILE *fp = fopen("turnos.dat", "a+b");
	do
	{
		printf("\n\t-----------------------------\n");
		printf("\tRegistro de Turnos");
		printf("\n\t-----------------------------\n");

		b = 0;
		do
		{
			printf("Matricula de Veterinario: ");
			scanf("%06d", &turno.matri);

			if (turno.matri <= 0 || turno.matri > 999999)
			{
				printf("Ingrese una matricula de hasta 6 d�gitos!");
				getch();
				b = 1;
			}

		} while (b == 1 || buscamatri(turno.matri) == 0);

		b = 0;
		do
		{
			printf("DNI del Due�o (8 d�gitos): ");
			scanf("%08d", &turno.DNI_dueno);
			// printf("Dni ingresado: %d",turno.DNI_dueno);
			if (turno.DNI_dueno < 10000000 || turno.DNI_dueno > 99999999)
			{
				printf("Ingrese un DNI de 8 d�gitos!");
				getch();
				b = 1;
			}

		} while (b == 1 || verifdni(turno) == 0);

		printf("\n\tFecha del Turno: \n");
		printf("\n\tDia: ");
		scanf("%02d", &turno.fec.dd);
		printf("\n\tMes: ");
		scanf("%02d", &turno.fec.mm);
		printf("\n\tA�o: ");
		scanf("%04d", &turno.fec.aa);

		// fwrite(fp, "%s;%06d;%08d;%s;\n",vet.ApeNom,vet.matri,vet.DNI_vet,vet.telef);

		fwrite(&turno, sizeof(turno), 1, fp);

		_flushall();
		printf("\n\n�Registrar otro Turno? (S/N): ");
		scanf("%c", &op);

	} while (op == 'S' || op == 's');

	fclose(fp);
	system("CLS");
}

//Asist - Opc 4 - Listar Atencion x vet y fecha
void listatencionvetfec()
{
	FILE *p = fopen("Turnos.dat", "rb");
	turnos datos;
	int i, op, aux1, aux2, aux3, aux4, b1 = 0, b2 = 0;
	bool band;

	printf("	ATENCIONES POR VETERINARIO Y FECHA");
	printf("\n\nIngresar la matricula del veterinario del cual desea saber las atenciones realizadas: ");
	scanf("%d", &aux1);
	printf("\n Fecha de las Atenciones a visualizar");
	printf("\n Ingresar dia de las atenciones: ");
	scanf("%d", &aux2);
	printf("\n Ingresar mes de las atenciones: ");
	scanf("%d", &aux3);
	printf("\n Ingresar ano de las atenciones: ");
	scanf("%d", &aux4);

	if (p == NULL)
	{
		printf("\n\nEl archivo no existe");
	}
	else
	{
		fread(&datos, sizeof(turnos), 1, p);

		i = 0;
		while (!feof(p))
		{
			if (datos.borrado == true && aux1 == datos.matri)
			{
				b1 = 1;
				if (aux2 == datos.fec.dd && aux3 == datos.fec.mm && aux4 == datos.fec.aa)
				{
					b2 = 1;
					printf("\n------------------------------------------------\n");
					printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd, datos.fec.mm, datos.fec.aa);
					printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
					printf("DNI del due�o: %d", datos.masc.DNI);
					printf("Localidad de la mascota: %s", datos.masc.Loc);
					printf("\nEdad de la mascota: %d\n", (2020 - datos.masc.fec.aa));
					printf("Peso de la mascota: %f", datos.masc.peso);
					i++;
				}
			}

			fread(&datos, sizeof(turnos), 1, p);
		}

		printf("\n------------------------------------------------\n");

		if (b1 == 0)
		{
			printf("\n\nNo se encontro la matricula del veterinario");
		}
		else
		{
			if (b2 == 0)
			{
				printf("\n\nNo realizo atenciones en ese mes y ese ano");
			}
		}

		fclose(p);
	}
}

//********************VETERINARIO********************
//Vet - Opc 1 - Iniciar Sesion Vet
// void loginvet()

//Vet - Opc 2 - Listar Turnos y atender
void listurn(int matridein, char aux[60])
{
	FILE *p = fopen("Turnos.dat", "r+b");
	turnos datos;
	int i, op;
	bool band;

	if (p == NULL)
	{
		printf("\n\nEl archivo no existe");
	}
	else
	{
		fread(&datos, sizeof(turnos), 1, p);
		i = 0;
		while (!feof(p))
		{
			if (datos.borrado == false && matridein == datos.matri)
			{
				printf("\n------------------------------------------------\n");
				printf("MASCOTA %d\n", i + 1);
				printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
				printf("\tDNI del due�o: %d", datos.masc.DNI);
				printf("\nLocalidad de la mascota: %s", datos.masc.Loc);
				printf("\nEdad de la mascota: %d a�os", (2020 - datos.masc.fec.aa));
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
				printf("\n�Desea llamar a %s? (1-Si/0-No):", datos.masc.ApeNom);
				scanf("%d", &op);

				if (op == 1)
				{
					datos.borrado = true;
					fseek(p, -sizeof(turnos), SEEK_CUR);
					fwrite(&datos, sizeof(turnos), 1, p);
					printf("�Atenci�n confirmada!\n\n");
					strcpy(aux, datos.masc.ApeNom);
				}
				band = true;
				getch();
			}
			else
			{
				fread(&datos, sizeof(turnos), 1, p);
			}
		}

		fclose(p);
	}
}

//Vet - Opc 3 - Evolucion del paciente
void evolucion(char aux[60])
{
	FILE *p, *s;
	p = fopen("Turnos.dat", "rb+");
	s = fopen("veterinarios.dat", "rb");
	turnos datos;
	veterinario dat;

	bool x = false, band = false;

	fread(&datos, sizeof(turnos), 1, p);

	while (!feof(p) && band == false)
	{
		if (datos.borrado == true && strcpy(aux,datos.masc.ApeNom))
		{
			fread(&dat, sizeof(veterinario), 1, s);
			while (!feof(s) && x == false)
			{
				if (datos.matri == dat.matri)
				{
					printf("\nApellido y nombre del veterinario %s", dat.ApeNom);
					x = true;
				}

				fread(&dat, sizeof(veterinario), 1, s);
			}
			printf("\nFECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd, datos.fec.mm, datos.fec.aa);
			
			
			printf("La evolucion del paciente: ");
			scanf("%s",datos.DetA);
			fseek(p, -sizeof(turnos), SEEK_CUR);

			fwrite(&datos, sizeof(turnos), 1, p);

			band = true;
		}

		fread(&datos, sizeof(turnos), 1, p);
	}
	fclose(p);
}

void ranking()
{
  	FILE *p,*s;
	p=fopen("Turnos.dat", "rb");
	s=fopen("veterinarios.dat","rb+");
	turnos datos;
	veterinario dat;
	bool x=false;
	int v[50],n=0,b,aux;

	fread(&datos,sizeof(turnos),1,p);
	
	while(!feof(p))
	{
		
		if (datos.borrado == true)
	    {	
	    	rewind(s);
	    	x=false;
	    	fread(&dat,sizeof(veterinario),1,s);
	    	dat.rank=0;
	    	while(!feof(s) && x==false)
	    	{
	    		
	    		if(datos.matri==dat.matri)
	    		{
	    			dat.rank++;
	    			fseek(s, -sizeof(veterinario), SEEK_CUR);
	        		fwrite(&dat,sizeof(veterinario),1,s);	        
					x=true;
	    		}
	    		fread(&dat,sizeof(veterinario),1,s);
	    	}
	    }
	
		fread(&datos,sizeof(turnos),1,p);
	}
	
	rewind(s);
	
	fread(&dat,sizeof(veterinario),1,s);
	while(!feof(s))
	{
		v[n]=dat.rank;
		fread(&dat,sizeof(veterinario),1,s);
		if(!feof(s))
		{
			n++;
		}
	}
	do
	{
		b=0;
		for(int i=0;i<n-1;i++)
		{
			if(v[i]<v[i+1])
			{
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;	
				b=1;		
			}
		}
	}while(b==1);
	
	
	printf("RANKING DE VETERINARIOS");
	for(int i=0;i<n;i++)
	{
		printf("\nPUESTO N� %d: %d",i+1,v[i]);
	}
	
	fclose(p);
	fclose(s);
}
