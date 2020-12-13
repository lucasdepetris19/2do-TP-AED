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

//Librerias Locales
#include "libreria.h"
#include "menus.h"

int main()
{
    setlocale(LC_CTYPE,"Spanish");

    int opcion, N = 0;
    veterinario vet;
    char apnom[20];

    do
    {
        opcion = menuAdmin();
        switch (opcion)
        {
        case 1:
            regisvet();
            getch();
            break;
        case 2:
            regiusuario();
            getch();
            break;
        case 3:
            //Atencion por Veterinario- Opcion 3 ADMIN


            getch();
            break;
        case 4:
            // Ranking de Veterinarios- Opcion 4 ADMIN
            
            getch();
            break;
        case 5:
            system("CLS");
            printf("\nS a l i r   d e l   S i s t e m a");
            printf("\n");
            system("pause");
            break;      
        default:
            system("CLS");
            printf("Ha ingresado una opcion no valida");
            printf("\n");
            system("pause");
            break;
        } //Fin del switch().

    } while (opcion != 5); //Fin del Ciclo Do

    printf("\n");
	getch();
}
