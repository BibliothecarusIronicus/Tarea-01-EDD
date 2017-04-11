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
                        nuevo[indice]= 'n';
                        indice++;
                        i++;
                        break;
                }
            }
        }
    }
    strcpy(str,nuevo);
}

void main()
{
    char str[100];
    strcpy(str,"Albárícoqúe");
    destildar (str);
    printf("%s\n",str); 
}


