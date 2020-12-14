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
#include <unistd.h>

//Librerias Locales
#include "libreria.h"
#include "menus.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 1F");
    int opcion, N = 0;
    usuario user;
    char apnom[60];

    do
    {
        opcion = menuAsist();
        switch (opcion)
        {
        case 1:
            loginuser(user);
            getch();
            break;
        case 2:
            regispet();
            getch();
            break;
        case 3:
            registurn();
            getch();
            break;
        case 4:
            listatencionvetfec();
            getch();
            break;
        case 5:
            system("CLS");
            printf("\n\n\n\n\n\n\t\t\tF i n   d e l   P r o g r a m a");
            printf("\n\n\n\n\n\n\n");
            // getch();
            break;
        default:
            system("CLS");
            printf("Ha ingresado una opcion no valida");
            printf("\n");
            system("pause");
            break;
        } //Fin del switch().

    } while (opcion != 5); //Fin del Ciclo Do

    // printf("\n");
	getch();
}
