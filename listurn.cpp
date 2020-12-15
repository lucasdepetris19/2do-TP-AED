struct turnos
{
	int matri;
	fecha fec;
	int DNI_dueno;
	char DetA[380];
	mascota masc;
	bool borrado;
};


void listurn(int matridein, char aux[60])
{
    FILE *p = fopen("Turnos.dat", "rb+");
    turnos datos;
    int i;
    int op;
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
                printf("DNI del dueño: %d", datos.masc.DNI);
                printf("Localidad de la mascota: %s", datos.masc.Loc);
                printf("\nEdad de la mascota: %d\n", (2020 - datos.masc.fec.aa));
                printf("Peso de la mascota: %f", datos.masc.peso);
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
                printf("Desea llamar a %s? (1-Si/0-No):", datos.masc.ApeNom);
                scanf("%d", &op);

                if (op == 1)
                {
                    datos.borrado = true;
                    fseek(p, -sizeof(turnos), SEEK_CUR);
                    fwrite(&datos, sizeof(turnos), 1, p);
                    printf("Atencion confirmada!\n\n");
                    strcpy(aux,datos.masc.ApeNom);
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
