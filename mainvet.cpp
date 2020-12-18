/*TODO:
* 
* 
* 
* 
*
*
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstring>
#include <ctype.h>
#include <wchar.h>
#include <stdbool.h>
// #include<string.h>
// #include<time.h>
// #include<cmath>

//Librerias Locales
#include "libreria.h"
#include "menus.h"

int main()
{
    setlocale(LC_ALL, "");
    system("color 5F");
    int opcion;
    veterinario vet;
    turnos aux;
    bool login = false, band = false;

    do
    {
        opcion = menuVet(login);
        switch (opcion)
        {
        case 1:
            login = false;
            loginvet(vet, login);
            getch();
            break;
        case 2:
            // if (band == false)
            {
                listurn(vet.matri, aux, band);
            }
            // else
            {
                printf("\nRegistre la evolución de la ultima mascota atendida para continuar.");
            }
            getch();
            break;
        case 3:
            // if (band == true)
            {
                band = false;
                evolucion(aux);
            }
            // else
            {
                printf("\nSe requiere llamar a una mascota para acceder a esta opción.");
            }
            getch();
            break;
        case 4:
            system("CLS");
            printf("\n\n\n\n\n\n\t\t\tF i n   d e l   P r o g r a m a");
            printf("\n\n\n\n\n\n\n");
            // getch();
            break;
        case 5:
            printf("\nModo Desarrollador\n-------------\n");
        	printf("\nFecha del Turno: %d/%d/%d\n", aux.fec.dd, aux.fec.mm, aux.fec.aa);
        	printf("Matricula %d",aux.matri);
        	system("pause");
        	break;
        default:
            system("CLS");
            printf("Ha ingresado una opcion no valida");
            printf("\n");
            system("pause");
            break;
        } //Fin del switch().

    } while (opcion != 4); //Fin del Ciclo Do

    // printf("\n");
    getch();
}
