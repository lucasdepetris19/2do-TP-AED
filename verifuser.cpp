/*TODO:
* Revisar entradas y salidas => coherencia con regiusuario
* Revisar textos
* Revisar verifpass.cpp y copiar de ahi
* Push cuando compile correctamente
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>

main()
//bool verifpass(char pass[33]))
{
    char usuario[10], aux1[10], aux2[10];
    int i, cantidad = 0, min = 0, num = 0, may = 0, n = 27, j, x = 0, mayus = 0, ;
    bool verificacion = true;

    printf("Nombre de usuario");
    printf("El nombre de usuario debe tener las siguientes condiciones\n");
    printf("1-Debe comenzar con una letra minuscula\n");
    printf("2-Debe tener al menos 2 letras mayusculas\n");
    printf("3-Debe contener entre 6 y 10 caractares\n");
    printf("4-Debe contener como maximo 3 numeros\n");

    _flushall();
    printf("Usuario: ");
    gets(usuario);
    cantidad = strlen(pass);

    strcpy(aux1, pass);
    strlwr(aux1); //convertimos en minuscula

    if (cantidad >= 6 && cantidad <= 10)
    {
        if (usuario[0] <= 'a' && usuario[0] >= 'z')
        {
            printf("Error. El nombre debe comenzar con minusculas");
        }
        else
        {

            for (i = 0; i < cantidad && verificacion; i++)
            {
                if (usuario[i] > 64 && usuario[i] < 91) //letras mayusculas
                {
                    mayus++;
                }
                if (usuario[i] > 97 && usuario[i] < 122) //letras minusculas
                {

                    min = 1;
                }
                if (usuario[i] > 47 && usuario[i] < 58) //Numeros
                {
                    x++;
                }
            }
        }
        if (x > 3)
        {
            printf("NO DEBE TENER MAS DE 3 DIGITOS\n");
            verificacion = false;
        }
        else
        {
            num = 1;
        }
        if (mayus > 2)
        {
            printf("NO DEBE TENER MAS DE 2 MAYUSCULAS\n");
            verificacion = false;
        }
        else
        {
            may = 1;
        }
    }
}
else
{

    printf("No esta en el rango de caracteres");
    printf("Ingrese un formato invalido para el usuario");
    printf("Porfavor ingrese otro usuario");
}

if (num == 0 || min == 0 || may == 0)
{
    printf("\nNo ingreso un numero/Letra minuscula/letra Mayuscula\n");
    printf("Apartado 1\n");
    printf("Porfavor ingrese un usuario valida\n");
}

if (num == 1 && min == 1 && may == 1)
{
    printf("Usuario valida");
}

// return verificación;
}