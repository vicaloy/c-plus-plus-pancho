#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include "boolean.h"
typedef struct {
int dia;
int mes;
int ano;
}Fecha;

void mostrarFecha(Fecha fecha);
void cargarFecha(Fecha &fecha);
int darDia(Fecha fecha);
int darMes(Fecha fecha);
int darAno(Fecha fecha);
boolean validarFecha(int dia, int mes, int anio);
boolean primeraFechaMayor(Fecha primeraFecha, Fecha segundaFecha);



#endif // FECHA_H_INCLUDED
