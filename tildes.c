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
                    case -101 :
                        nuevo[indice]= 'u';
                        indice++;
                        i++;
                        break;
                    case -111 :
                        nuevo[indice]= 'n';
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
