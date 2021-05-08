#include <stdio.h>
#include <stdlib.h>
/*-----------------*/
#include <Alumno.h>
#include <Fecha.h>
#include <Cadena.h>

void valores_default (t_alumno * alumno)    {
    alumno->alumno_regular = 'R';
    alumno->fecha_baja.dia = 31;
    alumno->fecha_baja.mes = 12;
    alumno->fecha_baja.anio = 1999;

    for (int i = 0; i < 40; i++)    {
        alumno->apyn [i] = 0;
    }
}

void mostrar_info_alumno (t_alumno * alumno)    {
    printf ("\n\t------------------\n\n");
    printf("Apellido y nombre: %s", alumno->apyn);
    printf("\nFecha de nacimiento: %d/%d/%d", alumno->fecha_nacimiento.dia, alumno->fecha_nacimiento.mes, alumno->fecha_nacimiento.anio);
    printf("\nDNI: %ld", alumno->dni);
    printf("\nGénero: %c", alumno->genero);
}

void nuevo_alumno (t_alumno * alumno)   {
    valores_default (alumno);

    nombre_nuevo_alumno(alumno);
    //cargar_fecha(&alumno->fecha_nacimiento);
    dni_nuevo_alumno (&alumno->dni);
    genero_nuevo_alumno (&alumno->genero);
    carrera_nuevo_alumno (alumno->carrera);
}

void nombre_nuevo_alumno (t_alumno * alumno)    {
    char aux [40] = {0};

    printf("Ingresar apellido y nombre: ");
    fflush(stdin);
    gets(aux);

    normalizar_nombre(aux, alumno->apyn);
}

void dni_nuevo_alumno (long * id)   {
    printf("Ingresar número de DNI: ");
    fflush(stdin);
    scanf("%ld", id);
}

void genero_nuevo_alumno (char * genero)    {
    char tmp;

    //Levanta el \n que queda en el buffer.
    tmp = getc(stdin);

    do  {
        printf("Ingresar género (M/F): ");
        *genero = toupper(getc(stdin));
    }   while (*genero == 'M' && *genero == 'F');
}

void carrera_nuevo_alumno (char * carrera)   {
    char carreras [1][3] = {"INF", "ELE", "IND", "ECO", "DER", "ADM", "MED", "EDF", "FIL"};

    printf("Ingresar opción de carrera a la que se inscribe:");
    printf("\n\t1. Ingeniería en Informática.\n\t2. Ingeniería Electrónica\n\t3. Ingeniería Industrial.\n\t");
}
