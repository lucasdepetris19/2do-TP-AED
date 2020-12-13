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
void listurn(int matridein, char aux[60]);

//Main Registurn
int main()
{
    int mat;
    char aux[60];
    setlocale(LC_ALL, "");

    // regisvet();

    // regispet();

    registurn();

    // menuVet();

    // getch();

    // printf("Ingrese una matricula");
    // scanf("%d", &mat);

    // listurn(mat, aux);
    getch();
}