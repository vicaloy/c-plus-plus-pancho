#include<stdio.h>
#include "menu.h"

void mostrarMenuPrincipal(int &opcion)
{
    printf("\n-------------MENU PRINCIPAL---------------\n");
    printf("1- Registrar una nueva variedad de pancho \n");
    printf("2- Dar de baja una variedad de pancho que deja de producirse \n");
    printf("3- Menu de listados y consultas \n");
    printf("4- Salir del programa \n\n\n");
    scanf("%d", &opcion);
}

void mostrarMenuSecundario(int &opcion)
{
    printf("\n-------------MENU LISTADOS---------------\n");
    printf("1- Listado reducido (codigo, nombre y tipo de variedad) de todos los panchos registrados, ordenado cronologicamente por fecha en que se comenzo a fabricar. \n");
    printf("2- Listado detallado de un pancho, dado su codigo identificador. \n");
    printf("3- Obtener la cantidad de panchos ingresados de cada variedad. \n");
    printf("4- Obtener codigo y el nombre del pancho con la mayor cantidad de unidades por semana. \n");
    printf("5- Dado un ingrediente, contar cuantos panchos especiales lo tienen como ingrediente principal. \n");
    printf("6- Dada una cantidad de premios, buscar un pancho premium con al menos esa cantidad de premios. \n");
    printf("7- Dado un codigo de pancho, incrementar o decrementar su cantidad de unidades por semana. \n");
    printf("8- Salir del menu. \n\n\n");
    scanf("%d", &opcion);
}
