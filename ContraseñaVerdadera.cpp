#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <ctype.h>

main()
//bool verifpass(char pass[33]))
{	


	setlocale(LC_ALL, "Spanish");
	char pass[33],aux1[33],aux2[33];
	int i,cantidad=0,min=0,num=0,may=0,n=27,j;
	bool verificacion=true;
	
	
	printf("Ingrese la contraseña");
	printf("La contraseña debe respetar los siguientes terminos\n");
	printf("1-Debe contener al menos una letra mayúscula,un letra minúscula y un número\n");
	printf("2-No puede tener caracter de puntuacion\n");
	printf("3-Debe contener entre 6 y 32 caractares\n");
	printf("4-No debe contener 2 caracteries conseutivos alfanumericos\n");
	
	
		_flushall();
		printf("Contraseña: ");
		gets(pass);
		cantidad=strlen(pass);
		
		strcpy(aux1,pass);			
		strlwr(aux1);               //convertimos en minuscula
      
		
		if(cantidad > 5 && cantidad <33)
		{
			
			for(i=0;i<cantidad && verificacion ;i++)
			{
				if(pass[i]==' '|| pass[i]==',' || pass[i]=='!' || pass[i]=='?' || pass[i]=='¿' || pass[i]=='.')
				{ 
				
					printf("\nTiene un caracter especial\n");
					printf("Apartado B\n");
					printf("Porfavor ingrese una contraseña valida\n");
					verificacion=false;
					
				}
				if(pass[i] > 64 && pass[i] < 91 ) //letras mayusculas
				{
					
					may=1;
					
				}
				if(pass[i] > 97 && pass[i] < 122 ) //letras minusculas
				{
					
					min=1;
					
				}
				if(pass[i] > 47 && pass[i] < 58 ) //Numeros
				{
					
					num=1;
					
				}
				
				for(j=0;j<n && verificacion ;j++)
				{
					if(aux1[j]==aux1[j+1]-1 && isalpha(aux1[j]) && isalpha(aux1[i+1]))
					{
						
						printf("forma ascendente");
						verificacion=false;
						
					}
				
				}							
					
			}
				
		}
		
		else
		{
			
			printf("No esta en el rango de caracteres");
			printf("Ingrese un formato invalido para la contraseña");
			printf("Porfavor ingrese otra contraseña");	
				
		}
		
		if(num==0 || min==0 || may==0)
		{
			
			printf("\nNo ingreso un numero/Letra minuscula/letra Mayuscula\n");
			printf("Apartado 1\n");
			printf("Porfavor ingrese una contraseña valida\n");
					
		}
		
		if(num==1 && min==1 && may==1)
		{
			
			printf("Contraseña valida");
			
		}	
		
		// return verificación; 
}
