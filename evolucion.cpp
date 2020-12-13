void evolucion(aux)
{	
  	FILE *p,*s;
	p = fopen("Turnos.dat", "rb+");
	s=fopen("veterinarios.dat","rb");
	turnos datos;
	veterinario dat;
		
	bool x=false;

	
	fread(datos,sizeof(turnos),1,p);
	
	while(!feof(p) && band==false)
	{

		if (datos.borrado == true && aux==datos.masc.ApeNom)
	    {	
	    	fread(dat,sizeof(veterinario),1,s);
	    	while(!feof(s) && x==false)
	    	{
	    		if(datos.matri==dat.matri)
	    		{
	    			printf("\n\nMatricula del veterinario %s",datos.matri); 
	    			printf("\nApellido y nombre del veterinario %s",dat.ApeNom);
					x=true;
	    		}
	    		
	    		
	    		fread(dat,sizeof(veterinario),1,s);
	    	}
	        printf("FECHA DEL TURNO: %d/%d/%d\n", datos.fec.dd,datos.fec.mm,datos.fec.aa); 	
	        
	        printf("La evolucion del paciente: ");
	        gets(datos.DetA);
	        fseek(p, -sizeof(turnos), SEEK_CUR);
	        
	        fwrite(datos,sizeof(turnos),1,p);
	        
	        band=true;
	    }
	
		fread(datos,sizeof(turnos),1,p);
	}
	fclose(p);	
}
