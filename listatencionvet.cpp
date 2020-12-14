struct turnos
{
	int matri;
	fecha fec;
	int DNI_dueno;
	char DetA[380];
	mascota masc;
	bool borrado;
};


void listatencionvet()
{
    FILE *p = fopen("Turnos.dat", "rb");
    turnos datos;
    int i,op,aux1,aux2,aux3,b1=0,b2=0;
    bool band;
    
    printf("	ATENCIONES POR VETERINARIO"); 
    printf("\n\nIngresar la matricula del veterinario del cual desea saber las atenciones realizadas: "); 
	scanf("%d",&aux1);
	printf("\n Ingresar mes de las atenciones a visualizar: ");
	scanf("%d",&aux2);
	printf("\n Ingresar ano de las atenciones a visualizar: ");
	scanf("%d",&aux3);
	

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
            if (datos.borrado == true && aux1==datos.matri)
            {
            	b1=1;
            	if (aux2==datos.fec.mm && aux3==datos.fec.aa)
            	{
            		b2=1;
            		printf("\n------------------------------------------------\n");
	                printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd,datos.fec.mm,datos.fec.aa);
	                printf("Apellido y Nombre de la mascota: %s", datos.masc.ApeNom);
	                printf("DNI del dueño: %d", datos.masc.DNI);
	                printf("Localidad de la mascota: %s", datos.masc.Loc);
	                printf("\nEdad de la mascota: %d\n", (2020 - datos.masc.fec.aa));
	                printf("Peso de la mascota: %f", datos.masc.peso);
	                i++;
				}   
            }

            fread(&datos, sizeof(turnos), 1, p);
        }

        printf("\n------------------------------------------------\n");

        if (b1==0)
        {
            printf("\n\nNo se encontro la matricula del veterinario");
        }
        else
        {
        	if (b2==0)
	        {
	            printf("\n\nNo realizo atenciones en ese mes y ese ano");
	        }
		}

        fclose(p);
    }
}
