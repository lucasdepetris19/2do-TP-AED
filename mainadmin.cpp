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
    setlocale(LC_ALL, "");
    system("color 3F");
    int inicio = 0, opcion, ea = 0;
    //ea = easter egg
    do
    {
        opcion = menuAdmin(inicio);
        inicio++;
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
            listatencionvet(); //Atencion por Veterinario- Opcion 3 ADMIN
            getch();
            break;
        case 4:
            ranking(); // Ranking de Veterinarios- Opcion 4 ADMIN
            getch();
            break;
        case 5:
            system("CLS");
            printf("\n\n\n\n\n\n\t\t\tF i n   d e l   P r o g r a m a");
            printf("\n\n\n\n\n\n\n");
            // getch();
            break;
        case 2077:
            easteregg(ea);
            ea++;
            break;
        default:
            system("CLS");
            printf("Ha ingresado una opcion no valida");
            printf("\n");
            system("pause");
            break;
        }
        //Fin del switch().
    } while (opcion != 5); //Fin del Ciclo Do

    getch();
}
