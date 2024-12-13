#include<stdio.h>
#include "tipoVariedad.h"
void cargarTipoVariedad(TipoVariedad &tipoVariedad)
{
    int valor;
    printf("Ingrese 0-Comun, 1-Especial, 2-Premium: ");
    scanf("%d", &valor);
    if(valor==0)
    {
        tipoVariedad=COMUN;
    }
    else if(valor==1)
    {
        tipoVariedad=ESPECIAL;
    }else if(valor==2){
        tipoVariedad=PREMIUM;
    }
}

void mostrarTipoVariedad(TipoVariedad tipoVariedad)
{
    if(tipoVariedad==COMUN)
    {
        printf("Comun");
    }
    else if(tipoVariedad==ESPECIAL)
    {
        printf("Especial");
    }else if(tipoVariedad==PREMIUM)
    {
        printf("Premium");
    }
}
