#include<stdio.h>
#include "especial.h"

void mostrarEspecial(Especial especial){
    printf("Nombre: ");
    print(especial.nombrePalIngrediente);
     printf("\n");
    printf("Cantidad ingredientes: %d", especial.cantIngrediente);
}
void cargarEspecial(Especial &especial){
    printf("Ingrese nombre ingrediente: ");
    scan(especial.nombrePalIngrediente);
    printf("Ingrese cantidad ingredientes: ");
    scanf("%d", &especial.cantIngrediente);
}
int darCantIngrediente(Especial especial){
    return especial.cantIngrediente;
}

void darNombreIngrediente(Especial especial, String &nombre)
{
    strcop(especial.nombrePalIngrediente, nombre);
}
