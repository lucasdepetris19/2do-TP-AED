int menuVet()
{
    int opc = 0;
    system("CLS");
    printf("\n\n\n\n\t\t*****************************************************\n");
    printf("\t\t**     C O N S U L T O R I O  V E T R I N A R I O  **\n");
    printf("\t\t*****************************************************\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t**   1-> Iniciar Sesion                            **\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t*****************************************************\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t**   2-> Visualizar Lista de Espera de Turnos      **\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t*****************************************************\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t**   3-> Registrar Evolucion de la Mascota         **\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t*****************************************************\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t**   4-> S A L I R  del  S I S T E M A             **\n");
    printf("\t\t**                                                 **\n");
    printf("\t\t*****************************************************\n\n");
    printf("\tSeleccione una Opción: ");
    scanf("%d", &opc);
 
    return opc; //retorna el número de opción seleccionada.
}

int menuAsist()
{
    int opc = 0;
    system("CLS");
    printf("\n\n\n\n\t\t*****************************************************\n");
    printf("\t\t**  A S I S T E N T E   D E  V E T E R I N A R I O   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   1-> Iniciar Sesion                              **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   2-> Registrar Mascota                           **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   3-> Registrar Turno                             **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   4-> List. de Atenciones por Veterinario y fecha **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   5-> S A L I R  del  S I S T E M A               **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n\n");
    printf("\t\tSeleccione una Opción: ");
    scanf("%d", &opc);
 
    return opc; //retorna el número de opción seleccionada.
}

int menuAdmin()
{
    int opc = 0;
    system("CLS");
    printf("\n\n\n\n\t\t*****************************************************\n");
    printf("\t\t**            A D M I N I S T R A C I O N            **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   1-> Registrar Veterinario                       **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   2-> Registrar Usuario Asistente                 **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   3-> Atenciones por Veterinarios                 **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   4-> Ranking de Veterinarios por Atenciones      **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t**   5-> S A L I R  del  S I S T E M A               **\n");
    printf("\t\t**                                                   **\n");
    printf("\t\t*******************************************************\n\n");
    printf("\t\tSeleccione una Opción: ");
    scanf("%d", &opc);
 
    return opc; //retorna el número de opción seleccionada.
}