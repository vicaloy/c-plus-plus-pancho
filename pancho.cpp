#include "pancho.h"
#include "stdio.h"
void mostrarPancho(Pancho pancho)
{
    printf("Codigo: %d \n", pancho.codigo);
    printf("Nombre: ");
    print(pancho.nombre);
    printf("\nCantidad por semana: %d\n", pancho.cantPorSemana);
    printf("Fecha: ");
    mostrarFecha(pancho.fechaComienzo);
    printf("\nTipo variedad:\n");
    mostrarTipoVariedad(pancho.tipoVariedad);
    printf("\n");
    if(pancho.tipoVariedad==COMUN)
    {
        printf("Gramos: %f", pancho.DiscriminanteTipoVariedad.pesoGramos);
    }
    else if(pancho.tipoVariedad==ESPECIAL)
    {
        mostrarEspecial(pancho.DiscriminanteTipoVariedad.especial);
    }
    else
    {
        mostrarPremium(pancho.DiscriminanteTipoVariedad.premium);
    }
}
void cargarPancho(Pancho &pancho)
{
    printf("Ingrese a continuacion los valores para un nuevo Pancho.\n");

    printf("Codigo: ");
    scanf("%d",&pancho.codigo);
    while(pancho.codigo < 0)
    {
        printf("El codigo debe ser un valor entero mayor que 0.\nCodigo: ");
        scanf("%d",&pancho.codigo);
    }

    printf("Nombre: ");
    scan(pancho.nombre);
    while (strlar(pancho.nombre) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(pancho.nombre);
    }

    printf("Ingrese la cantidad producida por semana: ");
    scanf("%d",&pancho.cantPorSemana);
    while(pancho.cantPorSemana < 0) //verificar la letra, si el 0 es valido
    {
        printf("La cantidad producida por semana no puede ser negativa.\nIngrese la cantidad producida por semana: ");
        scanf("%d",&pancho.cantPorSemana);
    }

    printf("Ingrese la Fecha de Comienzo: ");
    cargarFecha(pancho.fechaComienzo);

    printf("Ingrese tipo variedad: ");
    cargarTipoVariedad(pancho.tipoVariedad);

    if(pancho.tipoVariedad==COMUN)
    {
        printf("Ingrese peso en gramos: ");
        scanf("%f", &pancho.DiscriminanteTipoVariedad.pesoGramos);
    }
    else if(pancho.tipoVariedad==ESPECIAL)
    {
        printf("Cargue tipo variedad Especial: ");
        cargarEspecial(pancho.DiscriminanteTipoVariedad.especial);
    }
    else
    {
        printf("Cargue tipo variedad Premium: ");
        cargarPremium(pancho.DiscriminanteTipoVariedad.premium);
    }

}

int darCodigo(Pancho pancho)
{
    return pancho.codigo;
}
void darNombrePancho(Pancho pancho, String &nombre)
{
    strcop(pancho.nombre, nombre);
}
int darCantPorSemana(Pancho pancho)
{
    return pancho.cantPorSemana;
}
Fecha darFecha(Pancho pancho)
{
    return pancho.fechaComienzo;
}
TipoVariedad darTipoVariedad(Pancho pancho)
{
    return pancho.tipoVariedad;
}
float darPesoGramos(Pancho pancho)
{
    return pancho.DiscriminanteTipoVariedad.pesoGramos;

}
Especial darEspecial(Pancho pancho)
{
    return pancho.DiscriminanteTipoVariedad.especial;
}
Premium darPremium(Pancho pancho)
{
    return pancho.DiscriminanteTipoVariedad.premium;
}
void cargarCantProduccionSemana(Pancho &pancho, int cantidadSemana){
    pancho.cantPorSemana=cantidadSemana;
}
