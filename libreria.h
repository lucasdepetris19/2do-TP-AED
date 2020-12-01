struct veterinario
{
	char ApeNom[60];
	int matri;
	int DNI;
	char telef[25];
};

struct fecha
{
	int dd;
	int mm;
	int aa;
};

struct veterinario
{
	char ApeNom[60];
	char Dom[60];
	int DNI;
	char Loc[60];
	fecha fec;
	float peso;
	char telef[25];
};

struct fecha
{
	int dd;
	int mm;
	int aa;
};

struct veterinario
{
	int matri;
	fecha fec;
	int DNI;
	char DetA[380];
};

void regiusuario(){
	printf("Registre el usuario %s\n");
}