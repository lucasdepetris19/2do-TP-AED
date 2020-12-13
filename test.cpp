#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstring>
#include <ctype.h>
#include <wchar.h>
// #include<string.h>
// #include<time.h>
// #include<cmath>

#include "libreria.h"
#include "menus.h"

//Main Veterinario
// int main()
// {
//     int n;

//     printf("Ingrese la cantidad de veterinarios a registrar: ");
//     scanf("%d",&n);

//     for (int i = 0; i < n; i++)
//     {
//         regisvet();
//     }

//     getch();
// }

int verifdni(turnos &turn);
int verifmatric(int buscamat);
void registurn();
void regispet();
void listurn(int matridein,char aux[60]);

//Main Registurn
int main()
{
    int mat;
    char palabra[60];
    setlocale(LC_ALL, "");

    // regisvet();

    // regispet();

    // registurn();
    
    menuVet();

    getch();

    printf("Ingrese una matricula");
    scanf("%d", &mat);

    listurn(mat,palabra);
    getch();
}

void registurn()
{
    turnos turno;
    int b = 0;
    char op;

    FILE *fp = fopen("turnos.dat", "a+b");
    do
    {
        printf("\n\t--------------------");
        printf("\n         Registro de Turnos");
        printf("\n\t--------------------\n");

        b = 0;
        do
        {
            printf("Matricula de Veterinario: ");
            scanf("%06d", &turno.matri);

            if (turno.matri <= 0 || turno.matri > 999999)
            {
                printf("Ingrese una matricula de hasta 6 dígitos!");
                getch();
                b = 1;
            }

        } while (b == 1 || verifmatric(turno.matri) == 0);

        b = 0;
        do
        {
            printf("DNI del Dueño (8 dígitos): ");
            scanf("%06d", &turno.DNI_dueno);

            // if (turno.DNI_dueno < 10000000 || turno.DNI_dueno > 99999999)
            // {
            //     printf("Ingrese un DNI de 8 dígitos!");
            //     getch();
            //     b = 1;
            // }

        } while (b == 1 || verifdni(turno) == 0);

        printf("\n\tFecha del Turno: \n");
        printf("\n\tDia: ");
        scanf("%02d", &turno.fec.dd);
        printf("\n\tMes: ");
        scanf("%02d", &turno.fec.mm);
        printf("\n\tAño: ");
        scanf("%04d", &turno.fec.aa);

        // fwrite(fp, "%s;%06d;%08d;%s;\n",vet.ApeNom,vet.matri,vet.DNI_vet,vet.telef);

        fwrite(&turno, sizeof(turno), 1, fp);

        _flushall();
        printf("\n\n¿Registrar otro Turno? (S/N): ");
        scanf("%c", &op);

    } while (op == 'S' || op == 's');

    fclose(fp);
    system("CLS");
}

int verifmatric(int buscamat)
{
    FILE *fp = fopen("veterinarios.dat", "rb");
    veterinario vet;

    fread(&vet, sizeof(vet), 1, fp);
    while (!feof(fp))
    {
        if (vet.matri == buscamat)
        {
            fclose(fp);
            return (vet.matri == buscamat);
        }
        fread(&vet, sizeof(vet), 1, fp);
    };
    printf("No se encontro un Veterinario con la Matricula '%d'. Vuelva a Intentarlo\n", buscamat);
    // getch();
    fclose(fp);
    return 0;
}

int verifdni(turnos &turn)
{
    FILE *fp = fopen("mascotas.dat", "rb");
    mascota masc;

    fread(&masc, sizeof(masc), 1, fp);
    while (!feof(fp))
    {
        if (masc.DNI == turn.DNI_dueno)
        {
            fclose(fp);
            turn.masc = masc;
            return (masc.DNI == turn.DNI_dueno);
        }
        fread(&masc, sizeof(masc), 1, fp);
    };
    printf("No se encontro una Mascota con el DNI de Dueño '%d'. Vuelva a Intentarlo\n", turn.DNI_dueno);
    // getch();
    fclose(fp);
    return 0;
}

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
            printf("Ingrese Apellido y Nombre de la mascota: ");
            gets(datos.ApeNom);
            printf("Ingrese domicilio de la mascota: ");
            gets(datos.Dom);
            printf("Ingrese DNI del dueño: ");
            scanf("%d", &datos.DNI);
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
            printf("Ingrese telefono del dueño de la mascota: ");
            gets(datos.telef);

            fwrite(&datos, sizeof(mascota), 1, p);

            _flushall();
            printf("\n\n¿Continuar Registrando Ventas? (S/N): ");
            scanf("%c", &op);

        } while (op == 'S' || op == 's');

        fclose(p);
    }
}

void listurn(int matridein, char aux[60])
{
    FILE *p = fopen("Turnos.dat", "rb+");
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
                printf("\tDNI del dueño: %d", datos.masc.DNI);
                printf("\tLocalidad de la mascota: %s", datos.masc.Loc);
                printf("\nEdad de la mascota: %d\n", (2020 - datos.masc.fec.aa));
                printf("Peso de la mascota: %f", datos.masc.peso);
                printf("Estado: ");
                if(datos.borrado){
                    printf("Atendido");
                }
                else{
                    printf("En espera");
                }
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
                printf("\n¿Desea llamar a %s? (1-Si/0-No):", datos.masc.ApeNom);
                scanf("%d", &op);

                if (op == 1)
                {
                    datos.borrado = true;
                    fseek(p, -sizeof(turnos), SEEK_CUR);
                    fwrite(&datos, sizeof(turnos), 1, p);
                    printf("¡Atención confirmada!\n\n");
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