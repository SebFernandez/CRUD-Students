#include <stdio.h>
#include "Fecha.h"

void cargar_fecha (t_fecha * fecha) {
    do  {
        printf("Ingresar fecha (DD/MM/YYYY): ");
        fflush(stdin);
        scanf("%d/%d/%d", &fecha->dia, &fecha->mes, &fecha->anio);
    }   while (!fecha_valida(fecha));
}

void mostrar_fecha (const t_fecha * fecha)    {
    printf("-> %d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
}

int fecha_bisiesta (const t_fecha * fecha) {
    if (fecha->anio % 400 == 0 || (fecha->anio % 4 == 0 && fecha->anio % 100 != 0)) {
        return 1;
    }

    return 0;
}

int cantidad_dias_mes (const t_fecha * fecha) {
    int dias_mes [2][12] = {
            {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
            {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

    return dias_mes [fecha_bisiesta(fecha)][fecha->mes-1];
}

//   Ejercicio 14
int fecha_valida (const t_fecha * fecha)  {
    if (fecha->anio >= 1600)    {
        if (fecha->mes > 0 && fecha->mes < 13)  {
            if (fecha->dia > 0 && fecha->dia <= cantidad_dias_mes (fecha))  {
                return 1;
            }   else    {
                printf("-> Día erroneo.\n");
            }
        }   else    {
            printf("-> Mes erroneo.\n");
        }
    }   else    {
        printf("-> Año erroneo.\n");
    }

    printf("-> Fecha invalida.\n");
    return 0;
}

void incremento_fecha (t_fecha * fecha)   {
    fecha->dia++;

    if (fecha->dia > cantidad_dias_mes(fecha))    {
        fecha->dia = 1;
        fecha->mes++;

        if (fecha->mes > 12)  {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

//   Ejercicio 15
void dia_siguiente (t_fecha * fecha)  {
    t_fecha proximo_dia;

    proximo_dia = *fecha;

    incremento_fecha(&proximo_dia);

    printf("\nPróximo día\n");
    mostrar_fecha(&proximo_dia);
}

//   Ejercicio 16
void sumar_dias (t_fecha * fecha, const int * n)   {
    t_fecha proxima_fecha;

    proxima_fecha = *fecha;

    int dias_a_sumar = *n, dias_restantes_mes;

    while (dias_a_sumar > 0)    {
        dias_restantes_mes = cantidad_dias_mes(&proxima_fecha) - proxima_fecha.dia;
        if (dias_restantes_mes >= dias_a_sumar)  {
            proxima_fecha.dia += dias_a_sumar;
            dias_a_sumar -= dias_a_sumar;
        }   else    {
            proxima_fecha.dia += dias_restantes_mes;
            dias_a_sumar -= (dias_restantes_mes + 1);
            incremento_fecha (&proxima_fecha);
        }
    }

    printf("\nLuego de sumar %d días, la fecha resultantes es\n", *n);
    mostrar_fecha(&proxima_fecha);

}

void decremento_fecha (t_fecha * fecha) {
    fecha->dia--;

    if (fecha->dia < 1) {
        fecha->mes--;

        if (fecha->mes < 1) {
            fecha->mes = 12;
            fecha->anio--;
        }

        fecha->dia = cantidad_dias_mes(fecha);
    }
}

// Ejercicio 17
void restar_dias (t_fecha * fecha, const int * n)  {
    t_fecha proxima_fecha;

    proxima_fecha = *fecha;


    int dias_a_restar = *n;

    while (dias_a_restar > 0)   {
        if (proxima_fecha.dia > dias_a_restar) {
            proxima_fecha.dia -= dias_a_restar;
            dias_a_restar -= dias_a_restar;
        }   else    {
            dias_a_restar -= proxima_fecha.dia;
            proxima_fecha.dia = 1;
            decremento_fecha(&proxima_fecha);
        }
    }

    printf("\nLuego de restar %d días, la fecha resultantes es\n", *n);
    mostrar_fecha(&proxima_fecha);
}

//  Ejercicio 18
void dias_entre_fechas (const t_fecha * fecha1, const t_fecha * fecha2) {
    int dias = 0;
    t_fecha fecha = *fecha1;

    if ((fecha1->mes == fecha2->mes) && (fecha1->anio == fecha2->anio)) {
        dias = (fecha2->dia > fecha1->dia) ? fecha2->dia - fecha1->dia : fecha1->dia - fecha2->dia;
    }   else    {
        dias += (cantidad_dias_mes (&fecha) - fecha.dia) + fecha2->dia;
        fecha.dia = cantidad_dias_mes (&fecha);
        incremento_fecha(&fecha);

        while   ((fecha.mes != fecha2->mes) || (fecha.anio != fecha2->anio))    {
            dias+= cantidad_dias_mes(&fecha);
            fecha.dia = cantidad_dias_mes (&fecha);
            incremento_fecha(&fecha);
        }
    }

    printf("\nHay %d días de diferencia entre ambas fechas.\n", dias);
}
