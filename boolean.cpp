#include<stdio.h>
#include "boolean.h"

void cargarBoolean(boolean &b)
{
    int valor;
    printf("Ingrese 0-False, 1-True: ");
    scanf("%d", &valor);
    if(valor==0)
    {
        b=FALSE;
    }
    else
    {
        b=TRUE;
    }
}

void mostrarBoolean(boolean b)
{
    if(b==FALSE)
    {
        printf("False");
    }
    else
    {
        printf("True");
    }
}
