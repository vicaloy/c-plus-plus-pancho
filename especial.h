#ifndef ESPECIAL_H_INCLUDED
#define ESPECIAL_H_INCLUDED
#include "string.h"
typedef struct {
String nombrePalIngrediente;
int cantIngrediente;
}Especial;

void mostrarEspecial(Especial especial);
void cargarEspecial(Especial &especial);
void darNombreIngrediente(Especial especial, String &nombre);
int darCantIngrediente(Especial especial);


#endif // ESPECIAL_H_INCLUDED
