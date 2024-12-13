#include<stdio.h>
#include "fecha.h"
void mostrarFecha(Fecha fecha)
{
    printf("Dia %d ", fecha.dia);
    printf("Mes %d ", fecha.mes);
    printf("Ano %d ", fecha.ano);
}
void cargarFecha(Fecha &fecha)
{
    printf("Ingrese dia: ");
    scanf("%d", &fecha.dia);
    printf("Ingrese mes: ");
    scanf("%d", &fecha.mes);
    printf("Ingrese ano: ");
    scanf("%d", &fecha.ano);
    while(validarFecha(fecha.dia, fecha.mes, fecha.ano)==FALSE)
    {
        printf("Fecha invalida. \n");
        printf("Ingrese dia: ");
        scanf("%d", &fecha.dia);
        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);
        printf("Ingrese ano: ");
        scanf("%d", &fecha.ano);
    }

}
int darDia(Fecha fecha)
{
    return fecha.dia;
}
int darMes(Fecha fecha)
{
    return fecha.mes;
}
int darAno(Fecha fecha)
{
    return fecha.ano;
}

boolean validarFecha(int dia, int mes, int anio)
{
    boolean validado=FALSE;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia >= 1 && dia <= 31)
            validado=TRUE;
        else
            validado=FALSE;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia >= 1 && dia <= 30)
            validado=TRUE;
        else
            validado=FALSE;
        break;
    case 2:
        if (anio % 4 == 0)
        {
            if (dia >= 1 && dia <= 29)
                validado=TRUE;
            else
                validado=FALSE;
        }
        else
        {
            if (dia >= 1 && dia <= 28)
                validado=TRUE;
            else
                validado=FALSE;
        }
        break;
    default:
        validado=FALSE;
    }

    return validado;
}

boolean primeraFechaMayor(Fecha primeraFecha, Fecha segundaFecha)
{
    boolean primeraMayor=FALSE;
    if(primeraFecha.ano>segundaFecha.ano)
    {
        primeraMayor=TRUE;
    }
    else if(primeraFecha.ano==segundaFecha.ano && primeraFecha.mes>segundaFecha.mes)
    {
        primeraMayor=TRUE;
    }
    else if(primeraFecha.ano==segundaFecha.ano && primeraFecha.mes==segundaFecha.mes && primeraFecha.dia>segundaFecha.dia)
    {
        primeraMayor=TRUE;
    }

    return primeraMayor;
}

