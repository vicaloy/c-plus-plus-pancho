#ifndef PREMIUM_H_INCLUDED
#define PREMIUM_H_INCLUDED
#include "boolean.h"
typedef struct {
boolean exportarExterior;
int cantPremio;
}Premium;

void mostrarPremium(Premium premium);
void cargarPremium(Premium &premium);
boolean darExportarExterior(Premium premium);
int darCantPremio(Premium premium);


#endif // PREMIUM_H_INCLUDED
