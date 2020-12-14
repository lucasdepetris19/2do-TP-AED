struct fecha
{
	int dd;
	int mm;
	int aa;
};
struct veterinario
{
	char ApeNom[60];
	char contravet[10];
	int matri;
	int DNI_vet;
	char telef[25];
	int rank;
};
struct turnos
{
	int matri;
	fecha fec;
	int DNI_dueno;
	char DetA[380];
	mascota masc;
	bool borrado;
};

void ranking()
{
  	FILE *p,*s;
	p=fopen("Turnos.dat", "rb");
	s=fopen("veterinarios.dat","rb+");
	turnos datos;
	veterinario dat;
	bool x=false;
	int v[50],n=0,b,aux;

	fread(datos,sizeof(turnos),1,p);
	
	while(!feof(p))
	{
		if (datos.borrado == true)
	    {	
	    	rewind(s);
	    	x=false;
	    	fread(dat,sizeof(veterinario),1,s);
	    	while(!feof(s) && x==false)
	    	{
	    		if(datos.matri==dat.matri)
	    		{
	    			dat.rank++;
	    			fseek(s, -sizeof(veterinario), SEEK_CUR);
	        		fwrite(dat,sizeof(veterinario),1,s);	        
					x=true;
	    		}
	    		fread(dat,sizeof(veterinario),1,s);
	    	}
	    }
	
		fread(datos,sizeof(turnos),1,p);
	}
	
	rewind(s);
	
	fread(dat,sizeof(veterinario),1,s);
	while(!feof(s))
	{
		v[n]=dat.rank;
		fread(dat,sizeof(veterinario),1,s);
		if(!feof(s))
		{
			n++;
		}
	}
	do
	{
		b=0;
		for(int i=0;i<n-1;i++)
		{
			if(v[i]<v[i+1])
			{
				aux=v[i];
				v[i]=v[i+1];
				v[i+1]=aux;	
				b=1;		
			}
		}
	}while(b==1);
	
	
	fclose(p);
	fclose(s);
}
