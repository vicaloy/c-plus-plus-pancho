#include "fabrica.h"
#include "pancho.h"
#include<stdio.h>
#include<stdlib.h>

//PRECOND: Metodo a llamar al inicializar arreglo
void inicializarTope(ArregloConTope &arre)
{
    arre.tope=0;
}


boolean hayLugar(ArregloConTope arre)
{
    boolean hay=FALSE;
    if(arre.tope<TAM)
    {
        hay=TRUE;
    }
    return hay;
}
boolean pertenecePorCodigo(ArregloConTope arre, int codigo)
{
    int i=0;
    boolean encontre=FALSE;
    while(i<arre.tope && encontre==FALSE)
    {
        if(codigo==darCodigo(arre.arreglo[i]))
        {
            encontre=TRUE;
        }
        i++;
    }

    return encontre;
}
boolean pertenecePorNombre(ArregloConTope arre, String nombre)
{
    int i=0;
    boolean encontre=FALSE;
    String nombrePancho;
    while(i<arre.tope && encontre==FALSE)
    {
        darNombrePancho(arre.arreglo[i], nombrePancho);
        if(streq(nombrePancho, nombre))
        {
            encontre=TRUE;
        }
        i++;
    }

    return encontre;
}
//PRECOND: el arreglo no puede estar lleno, los panchos deben quedar ordenados por orden cronolgico de fecha de
//comienzo, no se debe ingresar uno existente
void insertarValor(ArregloConTope &arre, Pancho pancho)
{
    String nombrePancho;
    darNombrePancho(pancho, nombrePancho);

    if(pertenecePorNombre(arre, nombrePancho)==FALSE && pertenecePorCodigo(arre, darCodigo(pancho))==FALSE)
    {
        arre.arreglo[arre.tope]=pancho;
        arre.tope++;
        ordenarPorFecha(arre);
    }
    else
    {
        printf("Pancho no agregado, nombre y/o codigo repetido.");
    }

}

void ordenarPorFecha(ArregloConTope &arre)
{
    Pancho pancho;
    for(int i=0; i<arre.tope; i++)
    {
        for(int j=0; j<arre.tope-1; j++)
        {
            if(primeraFechaMayor(darFecha(arre.arreglo[j]), darFecha(arre.arreglo[j+1]))==TRUE) // cambia "<" a ">" para cambiar la manera de ordenar
            {
                pancho=arre.arreglo[j];
                arre.arreglo[j]=arre.arreglo[j+1];
                arre.arreglo[j+1]=pancho;
            }
        }
    }
}
void mostrar (ArregloConTope arre)
{
    printf("Mostrar lista de panchos: ");
    for(int i=0; i<arre.tope; i++)
    {
        mostrarPancho(arre.arreglo[i]);
    }
}
//PRECOND: existe pancho en el arreglo ¡¡¡¡¡¡¡¡¡¡¡ VERIFICAR!!!!!!!!!!
void eliminarPorCodigo(ArregloConTope &arre, int codigo)
{
    int i=0;
    while(codigo!=darCodigo(arre.arreglo[i]))
    {
        i++;
    }
    arre.arreglo[i]=arre.arreglo[arre.tope-1];
    arre.tope--;
}
//HAY QUE ORDENAR SEGUN FECHA DE COMIENZO LA LISTA
void mostrarCodigoNombreTipoVariedadFechaTodos(ArregloConTope arre)
{
    String nombre;
    printf("Mostrar lista de panchos: \n");
    for(int i=0; i<arre.tope; i++)
    {
        printf("\nPANCHO: \n");
        printf("Codigo: %d\n", darCodigo(arre.arreglo[i]));
        printf("Tipo variedad: ");
        mostrarTipoVariedad(darTipoVariedad(arre.arreglo[i]));
        printf("\nFecha: ");
        mostrarFecha(darFecha(arre.arreglo[i]));
        printf("\nNombre: ");
        darNombrePancho(arre.arreglo[i], nombre);
        print(nombre);
        printf("\n---------------------------------\n");


    }
}

void mostrarDatosPorCodigo(ArregloConTope arre, int codigo)
{
    int i=0;
    Pancho pancho;
    boolean encontre=FALSE;
    while(i<arre.tope && encontre==FALSE)
    {
        if(codigo==darCodigo(arre.arreglo[i]))
        {
            encontre=TRUE;
            pancho=arre.arreglo[i];
        }
        i++;
    }
    if(encontre==TRUE)
    {
        mostrarPancho(pancho);
    }
}

void darCantidadDePanchosCadaVariedad(ArregloConTope arre, int &cantComun, int &cantEspecial, int &cantPremium)
{
    cantComun=0;
    cantEspecial=0;
    cantPremium=0;

    for(int i=0; i<arre.tope; i++)
    {
        if(darTipoVariedad(arre.arreglo[i])==COMUN)
        {
            cantComun++;
        }
        else if(darTipoVariedad(arre.arreglo[i])==ESPECIAL)
        {
            cantEspecial++;
        }
        else
        {
            cantPremium++;
        }
    }
}

int cantidadPanchosConIngrediente(ArregloConTope arre, String nombrePalIngrediente)
{
    int cantidad=0;
    String nombreIng;
    for(int i=0; i<arre.tope; i++)
    {
        if(darTipoVariedad(arre.arreglo[i])==ESPECIAL)
        {
            darNombreIngrediente(darEspecial(arre.arreglo[i]), nombreIng);
            if(streq(nombreIng, nombrePalIngrediente))
            {
                cantidad++;
            }
        }
    }

    return cantidad;

}


void panchoPorCantPremio(ArregloConTope arre, int cantPremio, int &codigo, String &nombre)
{
    int i=0;
    boolean encontre=FALSE;
    while(i<arre.tope && encontre==FALSE)
    {
        if(darTipoVariedad(arre.arreglo[i])==PREMIUM)
        {
            if(darCantPremio(darPremium(arre.arreglo[i]))==cantPremio)
            {
                encontre=TRUE;
                codigo=darCodigo(arre.arreglo[i]);
                darNombrePancho(arre.arreglo[i], nombre);
            }
        }
        i++;
    }
}
/*Dados un código de pancho, un entero n > 0 y un valor booleano que indica si es incremento
o decremento, incrementar o decrementar (según corresponda) en n unidades la cantidad de
unidades de ese pancho vendidas semanalmente. En caso de que sea decremento y que n
supere la cantidad de unidades actualmente vendidas, se pondrá cero (0) como resultado.*/
void modificarCantPorSemana(ArregloConTope &arre, int codigo, int entero, boolean incremento)
{
    int i=0;
    boolean encontre=FALSE;
    Pancho pancho;
    entero=abs(entero);
    while(i<arre.tope && encontre==FALSE)
    {
        if(codigo==darCodigo(arre.arreglo[i]))
        {
            pancho=arre.arreglo[i];
            if(incremento==FALSE)
            {
                if(darCantPorSemana(pancho)<entero)
                {
                    cargarCantProduccionSemana(pancho, 0);
                }
                else
                {
                    cargarCantProduccionSemana(pancho, darCantPorSemana(pancho)-entero);
                }
            }
            else
            {
                cargarCantProduccionSemana(pancho, darCantPorSemana(pancho)+entero);
            }

            arre.arreglo[i]=pancho;

            encontre=TRUE;
        }
        i++;
    }
}

void darCodigoNombreMayorCantUnidSemana(ArregloConTope arre, int &codigo, String &nombre)
{
    int cantidadUnidadesSemana=0;
    for(int i=0; i<arre.tope; i++)
    {
        if(i==0)
        {
            cantidadUnidadesSemana=darCantPorSemana(arre.arreglo[i]);
            codigo=darCodigo(arre.arreglo[i]);
            darNombrePancho(arre.arreglo[i], nombre);
        }
        else
        {
            if(cantidadUnidadesSemana<darCantPorSemana(arre.arreglo[i]))
            {
                cantidadUnidadesSemana=darCantPorSemana(arre.arreglo[i]);
                codigo=darCodigo(arre.arreglo[i]);
                darNombrePancho(arre.arreglo[i], nombre);
            }
        }
    }
}
