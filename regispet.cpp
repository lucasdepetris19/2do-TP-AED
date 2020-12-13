
struct fecha
{
	int dd,mm,aa;
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

void regispet()
{
	FILE *p = fopen("mascotas.dat", "a+b");
	char op;
	mascota datos;
	
	if (p == NULL)
	{
 		printf ("\n\nEl archivo no existe");
	}
	else
	{
		do
		{
			printf("\n\n	BIENVENDO AL REGISTRO DE MASCOTAS!		");
			printf("\n Ingresar datos de la mascota a registrar por favor:");
			
			_flushall();
			printf("Ingrese Apellido y Nombre de la mascota: ");
			gets(datos.ApeNom);
			printf("Ingrese domicilio de la mascota: ");
			gets(datos.Dom);
			printf("Ingrese DNI del dueño: ");
			scanf("%d",&datos.DNI);
			printf("Ingrese localidad de la mascota: ");
			gets(datos.Loc);
			printf("\nIngrese Fecha de nacimiento \n");
			printf("Dia: ");
			scanf("%d",&datos.fec.dd);
			printf("Mes: ");
			scanf("%d",&datos.fec.mm);
			printf("Anio (En 4 digitos): ");
			scanf("%d",&datos.fec.aa);
			printf("Ingresar peso de la mascota: ");
			scanf("%f",&datos.peso);
			printf("Ingrese telefono del dueño de la mascota: ");
			gets(datos.telef);
			
			
			fwrite(&datos,sizeof(mascota),1,p);
			
			_flushall();
			printf("\n\n¿Continuar Registrando Ventas? (S/N): ");
			scanf("%c", &op);
			
		}while(op == 'S' || op == 's');
	
	
		fclose(p);
	}
}
