#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
#include <Fecha.h>

typedef struct  {
    long dni;
    char apyn [40];
    char genero;
    t_fecha fecha_nacimiento;
    char carrera [4];
    int materias_aprobadas;
    t_fecha ultima_materia_aprobada;
    char alumno_regular;
    t_fecha fecha_baja;
}   t_alumno;

void valores_default (t_alumno * alumno);
void mostrar_info_alumno (t_alumno * alumno);
void nuevo_alumno (t_alumno * alumno);
void nombre_nuevo_alumno (t_alumno * alumno);
void dni_nuevo_alumno (long * id);
void genero_nuevo_alumno (char * genero);
void carrera_nuevo_alumno (char * carrera);

#endif // ALUMNO_H_INCLUDED
