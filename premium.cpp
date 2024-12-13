#include<stdio.h>
#include "premium.h"
#include "boolean.h"
void mostrarPremium(Premium premium){
    printf("Exportar exterior: ");
    mostrarBoolean(premium.exportarExterior);
    printf("Cantidad de premios: %d", premium.cantPremio);
}
void cargarPremium(Premium &premium){
    printf("Ingrese si se exporta al exterior o no: ");
    cargarBoolean(premium.exportarExterior);
    printf("Ingrese cantidad de premios: ");
    scanf("%d", &premium.cantPremio);
}
boolean darExportarExterior(Premium premium){
    return premium.exportarExterior;
}
int darCantPremio(Premium premium){
    return premium.cantPremio;
}
