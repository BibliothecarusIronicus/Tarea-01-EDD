#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anagrama(char *str1, char *str2) 
{
	// Encuentra si str1 y str2 son anagramas en caso de ser así retorna 1 en caso contrario 0
	// Se deben primero cambiar las str para que no contengan tildes
	int largo1,largo2,indice=0,i=0;
	char *igual;
	
	largo1 = strlen(str1);
	printf("%d\n",largo1);
	
	largo2 = strlen(str2);
	printf("%d\n",largo2);
	
	if (largo1 != largo2) return 0; // Distinta cantidad de letras
	
	while( indice < largo1)
	{
		for (int j = 0; j < largo2;j++)
		{		
			igual = strchr(str2,str1[indice]); // Busca el char en el string
			if (igual == NULL) return 0; // Misma cantidad de letras pero no esta la buscada
			if (str2[j] == str1[indice])
			{
				str2[j] = 48; // Si esta rellenamos con un cero y pasamos a la proxima letra
				indice += 1;
			}
		}
	}
	return 1;
}


void main()
{
	char soup1[10];
	char suop2[10];
	char soup3[10];
	char suop4[10];
	strcpy(soup1,"base");
	strcpy(suop2,"aseb");
	strcpy(soup3,"hygs");
	strcpy(suop4,"lkhs");
	printf("%s %s %d\n",soup1,suop2,anagrama(soup1,suop2));
	printf("%s %s %d\n",soup3,suop4,anagrama(soup3,suop4));
}