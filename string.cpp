#include<stdio.h>
#include "string.h"
//strlar que devuelva el largo de un string.
int strlar(String cadena)
{
    int i=0;
    while(cadena[i]!='\0')
    {
        i++;
    }
    return i;
}
//print que despliegue un string por pantalla.
void print(String cadena)
{
    int i=0;
    while(cadena[i]!='\0')
    {
        printf("%c", cadena[i]);
        i++;
    }
}
//scan que lea un string desde el teclado
void scan(String &cadena)
{
    fflush(stdin);
    char caracter;
    int i=0;
    printf("Ingrese cadena: ");
    scanf("%c", &caracter);
    while(caracter!='\n' && i<MAX-1)
    {
        cadena[i]=caracter;
        i++;
        scanf("%c", &caracter);
    }
    cadena[i]='\0';
}
//strmen que reciba dos strings y devuelva TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(String cadenaUno, String cadenaDos)
{
    boolean retorno=TRUE;
    int i=0;
    while(cadenaUno[i]!='\0' && cadenaDos[i]!='\0')
    {
        if(cadenaUno[i]>cadenaDos[i])
        {
            retorno=FALSE;
        }
        i++;
    }
    return retorno;
}
//streq que reciba dos strings y devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(String cadenaUno, String cadenaDos)
{
    boolean retorno=TRUE;
    int i=0;
    while(cadenaUno[i]!='\0' && cadenaDos[i]!='\0')
    {
        if(cadenaUno[i]!=cadenaDos[i])
        {
            retorno=FALSE;
        }
        i++;
    }
    return retorno;
}
//strcop que reciba dos strings y copie el primero en el segundo.
void strcop(String &cadenaUno, String cadenaDos)
{
    int i=0;
    while(cadenaUno[i]!='\0')
    {
        cadenaDos[i]=cadenaUno[i];
        i++;
    }
    cadenaDos[i]='\0';
}
//strcon que reciba dos strings y concatene el segundo string al final del primero
void strcon(String &cadenaUno, String cadenaDos)
{
    int i=0;
    int j=0;

    while(cadenaUno[j]!='\0')
    {
        j++;
    }

    while(j<MAX
          -1 && cadenaDos[i]!='\0')
    {
        cadenaUno[j]=cadenaDos[i];
        i++;
        j++;
    }
    cadenaUno[j]='\0';
}
//strswp que reciba dos strings y devuelva el primero en el segundo y viceversa.
void strswap(String &cadenaUno, String &cadenaDos){
    int i=0;
    int j=0;
    int k=0;
    String cadenaAux;

    while(cadenaUno[i]!='\0')
    {
        cadenaAux[i]=cadenaUno[i];
        i++;
    }
    cadenaAux[i]='\0';

    while(cadenaDos[j]!='\0')
    {
        cadenaUno[j]=cadenaDos[j];
        j++;
    }
    cadenaUno[j]='\0';

    while(cadenaAux[k]!='\0')
    {
        cadenaDos[k]=cadenaAux[k];
        k++;
    }
    cadenaDos[k]='\0';

}
