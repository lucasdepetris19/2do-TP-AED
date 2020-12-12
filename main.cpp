#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <cstring>
#include <ctype.h>
// #include <wchar.h>
// #include<string.h>
// #include<time.h>
// #include<cmath>

#include "libreria.h"

int main()
{
    int n;

    printf("Ingrese la cantidad de veterinarios a registrar: ");
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
    {
        regisvet(i);
    }
    
    getch();
}