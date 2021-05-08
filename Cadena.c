#include <Cadena.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void normalizar_nombre (const char * cadena, char * cadena_OK)  {
    int i = 0, j = 0;
    bool palabra_iniciada = false, es_apellido = true, hubo_palabra = false, hay_coma = false;

    for (i = 0; i < strlen(cadena) && *(cadena+i) != '\0'; i++) {
        if (*(cadena+i) == ',') {
            hay_coma = true;
        }
    }

    for (i = 0; i < strlen(cadena) && *(cadena+i) != '\0'; i++)   {
        if ((tolower(*(cadena+i)) >= 'a' && tolower(*(cadena+i)) <= 'z'))  {
            if (palabra_iniciada)   {
                *(cadena_OK+j) = tolower(*(cadena+i));
            }   else if (!palabra_iniciada)    {
                *(cadena_OK+j) = toupper(*(cadena+i));
                palabra_iniciada = true;
            }
            j++;
        }

        if (isspace(*(cadena + i)) != 0)   {
            if (palabra_iniciada)  {
                if (es_apellido && !hay_coma && palabra_iniciada)    {
                    es_apellido = false;
                    poner_coma_con_espacio(cadena_OK, &j);
                }   else    {
                    *(cadena_OK+j) = *(cadena+i);
                    j++;
                }
            }
            palabra_iniciada = false;
        }   else if ((*(cadena + i) == ',' || *(cadena + i) == '.') && es_apellido)  {
            palabra_iniciada = false;
            es_apellido = false;
            poner_coma_con_espacio(cadena_OK, &j);
        }
    }

    *(cadena_OK+j) = '\0';
}

void poner_coma_con_espacio (char * cadena, int * indice) {
    *(cadena + (*indice)) = ',';
    (*indice)++;
    *(cadena + (*indice)) = ' ';
    (*indice)++;
}

