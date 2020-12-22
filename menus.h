#include <unistd.h>

int time = 50000;
int time1 = 500000;

void logo()
{
    FILE *p;
    p = fopen("logo.txt", "r");
    char linea[100];
    while (!feof(p))
    {
        fgets(linea, 100, p);
        printf("\t%s", linea);
        usleep(time);
    }
    fclose(p);
}

int menuVet(bool login, int inicio)
{
    int opc = 0;
    system("CLS");
    if (inicio == 0)
    {
        logo();
        usleep(time1);
    }
    system("CLS");
    printf("\n\n\n\n\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**     C O N S U L T O R I O  V E T E R I N A R I O  **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   1-> Iniciar Sesión                              **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   2-> Visualizar Lista de Espera de Turnos        **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   3-> Registrar Evolución de la Mascota           **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   4-> S A L I R  del  S I S T E M A               **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n\n");
    usleep(time);
    printf("\tSeleccione una Opción: ");
    scanf("%d", &opc);

    if (login == false && opc > 1 && opc < 5)
    {
        printf("\n\n\t\tSe requiere iniciar sesión para acceder a esta opción");
        printf("\n\t\tSera redirigido al área de inicio de sesión");
        opc = 1;
    }

    return opc; //retorna el número de opción seleccionada.
}

int menuAsist(bool login, int inicio)
{
    int opc = 0;
    system("CLS");
    if (inicio == 0)
    {
        logo();
        usleep(time1);
    }
    system("CLS");
    usleep(time);
    printf("\n\n\n\n\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**  A S I S T E N T E   D E  V E T E R I N A R I O   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   1-> Iniciar Sesión                              **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   2-> Registrar Mascota                           **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   3-> Registrar Turno                             **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   4-> List. de Atenciones por Veterinario y fecha **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   5-> S A L I R  del  S I S T E M A               **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n\n");
    usleep(time);
    printf("\t\tSeleccione una Opción: ");
    scanf("%d", &opc);

    if (login == false && opc > 1 && opc < 5)
    {
        printf("\n\n\t\tSe requiere iniciar sesión para acceder a esta opción");
        printf("\n\t\tSera redirigido al área de inicio de sesión");
        opc = 1;
    }

    return opc; //retorna el número de opción seleccionada.
}

int menuAdmin(int inicio)
{
    int opc = 0;
    system("CLS");
    if (inicio == 0)
    {
        logo();
        usleep(time1);
    }
    system("CLS");
    usleep(time);
    printf("\n\n\n\n\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**            A D M I N I S T R A C I Ó N            **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   1-> Registrar Veterinario                       **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   2-> Registrar Usuario Asistente                 **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   3-> Atenciones por Veterinarios                 **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   4-> Ranking de Veterinarios por Atenciones      **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t**   5-> S A L I R  del  S I S T E M A               **\n");
    usleep(time);
    printf("\t\t**                                                   **\n");
    usleep(time);
    printf("\t\t*******************************************************\n\n");
    usleep(time);
    printf("\t\tSeleccione una Opción: ");
    scanf("%d", &opc);

    return opc; //retorna el número de opción seleccionada.
}
