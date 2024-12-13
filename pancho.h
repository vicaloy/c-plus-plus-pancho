#ifndef PANCHO_H_INCLUDED
#define PANCHO_H_INCLUDED
#include "tipovariedad.h"
#include "especial.h"
#include "premium.h"
#include "Fecha.h"

typedef struct {
int codigo;
String nombre;
int cantPorSemana;
Fecha fechaComienzo;
//int cantProduccionSemana;
TipoVariedad tipoVariedad;
union{
    float pesoGramos;
    Especial especial;
    Premium premium;
} DiscriminanteTipoVariedad;
}Pancho;

void mostrarPancho(Pancho pancho);
void cargarPancho(Pancho &pancho);
int darCodigo(Pancho pancho);
void darNombrePancho(Pancho pancho, String &nombre);
int darCantPorSemana(Pancho pancho);
Fecha darFecha(Pancho pancho);
TipoVariedad darTipoVariedad(Pancho pancho);
float darPesoGramos(Pancho pancho);
Especial darEspecial(Pancho pancho);
Premium darPremium(Pancho pancho);
void cargarCantProduccionSemana(Pancho &pancho, int cantidadSemana);

#endif // PANCHO_H_INCLUDED
