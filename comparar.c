#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(char *str1, char *str2) 
{
	// Encuentra si str1 y str2 son anagramas en caso de ser así retorna 1 en caso contrario 0
	// Se deben primero cambiar las str para que no contengan tildes
	int largo1,largo2,indice=0,i;
	char *igual;
	
	largo1 = strlen(str1);
	largo2 = strlen(str2);
	char copy1[largo1],copy2[largo2];
	strcpy(copy1,str1);
	strcpy(copy2,str2);
	
	if (largo1 != largo2) return 0; // Distinta cantidad de letras
	
	for(i=0; i < largo1; i++)
	{
		for (int j = 0; j < largo2;j++)
		{		
			igual = strchr(copy2,copy1[indice]);		 // Busca el char en el string
			if (igual == NULL) return 0; 		// Misma cantidad de letras pero no esta la buscada
			else if (copy2[j] == copy1[indice])
			{
				copy2[j] = 48;	// Si esta rellenamos con un cero y pasamos a la proxima letra
				indice++;
			}
		}
	}
	printf("Agregando %s de %s\n",str1,str2);
	return 1;
}
