#ifndef FABRICA_H_INCLUDED
#define FABRICA_H_INCLUDED
#include "pancho.h"
const int TAM=30;
typedef struct{
Pancho arreglo[TAM];
int tope;
}ArregloConTope;

void inicializarTope(ArregloConTope &arre);

boolean hayLugar(ArregloConTope arre);
boolean pertenecePorCodigo(ArregloConTope arre, int codigo);
boolean pertenecePorNombre(ArregloConTope arre, String nombre);
//PRECOND: el arreglo no puede estar lleno, los panchos deben quedar ordenados por orden cronolgico de fecha de
//comienzo, no se debe ingresar uno existente
void insertarValor(ArregloConTope &arre, Pancho pancho);
void mostrar (ArregloConTope arre);
//PRECOND: existe pancho en el arreglo
void eliminarPorCodigo(ArregloConTope &arre, int codigo);
void mostrarCodigoNombreTipoVariedadFechaTodos(ArregloConTope arre);
void mostrarDatosPorCodigo(ArregloConTope arre, int codigo);
void darCantidadDePanchosCadaVariedad(ArregloConTope arre, int &cantComun, int &cantEspecial, int &cantPremium);
int cantidadPanchosConIngrediente(ArregloConTope arre, String nombrePalIngrediente);
void panchoPorCantPremio(ArregloConTope arre, int cantPremio, int &codigo, String &nombre);
/*Dados un código de pancho, un entero n > 0 y un valor booleano que indica si es incremento
o decremento, incrementar o decrementar (según corresponda) en n unidades la cantidad de
unidades de ese pancho vendidas semanalmente. En caso de que sea decremento y que n
supere la cantidad de unidades actualmente vendidas, se pondrá cero (0) como resultado.*/
void modificarCantPorSemana(ArregloConTope &arre, int codigo, int entero, boolean incremento);
void darCodigoNombreMayorCantUnidSemana(ArregloConTope arre, int &codigo, String &nombre);
void ordenarPorFecha(ArregloConTope &arre);



#endif // FABRICA_H_INCLUDED
