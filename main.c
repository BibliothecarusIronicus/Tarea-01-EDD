#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int anagramas(char **S, int n, char *str)
{
	int a,suma=0;
	FILE *fp;
	fopen("strings.txt","a");
	a = strlen(str);
	char aux[a];
	strcpy(aux,str);
	destildar(aux);
	
	for (int i = 0; i < n; i++)
	{
		if (comparar(destildar(S[i]),aux)) suma++;
	}
	
	fprintf(fp,"%d\n",suma);
}