#include <stdio.h>
#include <stdlib.h>
#include <Fecha.h>
#include <Alumno.h>

int main() {

    t_alumno alumno;

    nuevo_alumno(&alumno);

    mostrar_info_alumno(&alumno);

    printf("\n\n");
    return 0;
}
