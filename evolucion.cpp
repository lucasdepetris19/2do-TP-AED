void evolucion(aux)
{	
  	FILE *p = fopen("Turnos.dat", "rb+");
	printf("\n\nMatricula del veterinario",datos.matri); 
	
	fread(datos,sizeof(mascotas),1,p);
	
	while(!feof(p))
	{

		if (datos.borrado == true && aux1==datos.matri)
	    {
	        printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd,datos.fec.mm,datos.fec.aa); 	
	        printf("La evolucion del paciente: ");
	        gets(datos.DetA);
	        fwrite(datos,sizeof(turnos),1,p);
	    }
	
		fread(datos,sizeof(mascotas),1,p);
	}
	fclose(p);	
}
