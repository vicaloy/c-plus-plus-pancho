#include <stdio.h>
#include "menu.h"
#include "fabrica.h"
using namespace std;

int main()
{
    ArregloConTope arre;
    Pancho pancho;
    int opcion=0;
    int codigo;
    int cantComun, cantEspecial, cantPremium, cantPremios, entero;
    String nombre;
    boolean incrementa;
    inicializarTope(arre);
    while (opcion!=4)
    {
        mostrarMenuPrincipal(opcion);
        switch(opcion)
        {
        case 1:
            printf("1- Selecciono registrar una nueva variedad de pancho \n");
            if(hayLugar(arre))
            {
                cargarPancho(pancho);
                insertarValor(arre, pancho);
            }
            else
            {
                printf("No hay lugar para ingresar nuevo pancho\n");
            }
            break;
        case 2:
            printf("2- Selecciono dar de baja una variedad de pancho que deja de producirse \n");
            printf("Ingrese codigo para eliminar variedad de pancho: ");
            scanf("%d", &codigo);
            if(pertenecePorCodigo(arre, codigo)==TRUE)
            {
                eliminarPorCodigo(arre, codigo);
            }
            else
            {
                printf("No existe codigo ingresado.");
            }
            break;
        case 3:
            int opcionSecundaria=0;
            while(opcionSecundaria!=8)
            {
                mostrarMenuSecundario(opcionSecundaria);
                switch(opcionSecundaria)
                {
                case 1:
                    printf("1- Selecciono listado reducido (codigo, nombre, tipo de variedad y fecha). \n");
                    mostrarCodigoNombreTipoVariedadFechaTodos(arre);
                    break;
                case 2:
                    printf("2- Selecciono listado detallado de un pancho, dado su codigo identificador. \n");
                    printf("Ingrese codigo de pancho: ");
                    scanf("%d", &codigo);
                    if(pertenecePorCodigo(arre, codigo)==TRUE)
                    {
                        mostrarDatosPorCodigo(arre, codigo);
                    }
                    else
                    {
                        printf("No existe codigo ingresado.");
                    }

                    break;
                case 3:
                    printf("3- Selecciono obtener la cantidad de panchos ingresados de cada variedad. \n");
                    darCantidadDePanchosCadaVariedad(arre, cantComun, cantEspecial, cantPremium);
                    printf("Cantidad de panchos comun: %d\nCantidad de panchos especial: %d\nCantidad de panchos premium: %d\n", cantComun, cantEspecial, cantPremium);
                    break;
                case 4:
                    printf("4- Selecciono obtener codigo y el nombre del pancho con la mayor cantidad de unidades por semana. \n");
                    darCodigoNombreMayorCantUnidSemana(arre, codigo, nombre);
                    printf("Codigo: %d\n", codigo);
                    printf("Nombre:\n");
                    print(nombre);
                    break;
                case 5:
                    printf("5- Selecciono dado un ingrediente, contar cuantos panchos especiales lo tienen como ingrediente principal. \n");
                    printf("Ingrese nombre principal ingrediente: ");
                    scan(nombre);
                    printf("Cantidad de panchos con el ingrediente %d\n", cantidadPanchosConIngrediente(arre, nombre));
                    break;
                case 6:
                    printf("6- Selecciono dada una cantidad de premios, buscar un pancho premium con al menos esa cantidad de premios. \n");
                    printf("Ingrese cantidad de premios: ");
                    scanf("%d", &cantPremios);
                    panchoPorCantPremio(arre, cantPremios, codigo, nombre);
                    printf("Codigo pancho: %d", codigo);
                    printf("\nNombre pancho: ");
                    print(nombre);
                    printf("\n");
                    break;
                case 7:
                    printf("7- Selecciono dado un codigo de pancho, incrementar o decrementar su cantidad de unidades por semana. \n");
                    printf("Ingrese cadigo de pancho: ");
                    scanf("%d", &codigo);
                    if(pertenecePorCodigo(arre, codigo)==TRUE)
                    {
                        printf("Incrementa cantidad de unidades por semana: ");
                        cargarBoolean(incrementa);
                        printf("Ingrese numero de cantidades: ");
                        scanf("%d", &entero);
                        modificarCantPorSemana(arre, codigo, entero, incrementa);
                    }
                    else
                    {
                        printf("No existe codigo ingresado.");
                    }
                    break;

                }
            }
            break;
        }

    }
    return 0;
}
