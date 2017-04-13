#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void destildar(char *str)
{
	int largo;
    int indice = 0;
    largo = strlen(str);
    char *nuevo;
    nuevo = (char *)malloc(sizeof(char)*largo);
    for (int i = 0; i < largo; i++)
    {
        if (str[i]>= 97 && str[i]<=122)
        {
            nuevo[indice] = str[i];
            indice++;
        }
        else if (str[i] >= 65 && str[i] <= 90)
        {
            // Si es una minuscula la cambiamos a una mayúscula
            nuevo[indice] = str[i] + 32;
            indice++;
        }
        else
        {
            if (str[i] == -61) // caracteres diacriticos empiezan con -61
            {
                switch (str[i+1])
                {
                    case -95 :
                        nuevo[indice]= 'a';
                        indice++;
                        i++;
                        break;
                    case -87 :
                        nuevo[indice]= 'e';
                        indice++;
                        i++;
                        break;
                    case -83 :
                        nuevo[indice]= 'i';
                        indice++;
                        i++;
                        break;
                    case -77 :
                        nuevo[indice]= 'o';
                        indice++;
                        i++;
                        break;
                    case -70 :
                        nuevo[indice]= 'u';
                        indice++;
                        i++;
                        break;
                    case -79 :
                        nuevo[indice]= 'N';
                        indice++;
                        i++;
                        break;
                    case -127 :
                        nuevo[indice]= 'a';
                        indice++;
                        i++;
                        break;
					case -119 :
                        nuevo[indice]= 'e';
                        indice++;
                        i++;
                        break;
                    case -115 :
                        nuevo[indice]= 'i';
                        indice++;
                        i++;
                        break;
                    case -109 :
                        nuevo[indice]= 'o';
                        indice++;
                        i++;
                        break;
                    case -102 :
                        nuevo[indice]= 'u';
                        indice++;
                        i++;
                        break;
                    case -111 :
                        nuevo[indice]= 'N';
                        indice++;
                        i++;
                        break;
                }
            }
        }
    }
    strcpy(str,nuevo);
    free((void*)nuevo);
}

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
	return 1;
}

int anagramas(char **S, int n, char *str)
{
	int a,suma=0;
	FILE *fp;
	fp = fopen("salida-1.txt","a");
	a = strlen(str);
	char aux[a];
	strcpy(aux,str);
	destildar(aux);
	for (int i = 0; i < n; i++)
	{
		destildar(S[i]);
		if (comparar(aux,S[i])) suma++;
	}
	
	fprintf(fp,"%d\n",suma);
	fclose(fp);
	return suma;
}

void main()
{
    int n,q,t,m,w;
    char **S,**F;
    char str[10];
    char aux3[20];
    char aux4[20];
    strcpy(str,"Roma");
    FILE *archivo;
    archivo = fopen("strings-10K.txt","r");
    while(!feof(archivo))
    {
    	fscanf(archivo,"%d",&n);
    	S = (char **)malloc(sizeof(char*)*n);
    	for (int i = 0; i < n; i++)
    	{
    		fscanf(archivo,"%s",aux3);
    		t = strlen(aux3);
    		S[i] = (char *)malloc(t*sizeof(char));
    		strcpy(S[i],aux3);	
    	}
    	fscanf(archivo,"%d",&m);
    	F = (char **)malloc(sizeof(char *)*m);
    	for (int j = 0; j < m; j++)
    	{
    		fscanf(archivo,"%s",aux4);
    		t = strlen(aux4);
    		F[j] = (char *)malloc(t*sizeof(char));
    		strcpy(F[j],aux4);
    	}
    	for (int w = 0; w < m; w++)
    	{
    		q = anagramas(S,n,F[w]);
    	}
    	free((void *)S);
    	free((void *)F);
    	break;
    }
    fclose(archivo);
    
}
