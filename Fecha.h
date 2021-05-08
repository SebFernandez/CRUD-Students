#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct {
    int dia;
    int mes;
    int anio;
}   t_fecha;

void cargar_fecha (t_fecha * fecha);
void mostrar_fecha (const t_fecha * fecha);
int fecha_bisiesta (const t_fecha * fecha);
int cantidad_dias_mes (const t_fecha * fecha);
int fecha_valida (const t_fecha * fecha);
void incremento_fecha (t_fecha * fecha);
void dia_siguiente (t_fecha * fecha);
void sumar_dias (t_fecha * fecha, const int * n);
void decremento_fecha (t_fecha * fecha);
void restar_dias (t_fecha * fecha, const int * n);
void dias_entre_fechas (const t_fecha * fecha1, const t_fecha * fecha2);

#endif // FECHA_H_INCLUDED
