#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "boolean.h"
const int MAX=80;
typedef char String[MAX];

//strlar que devuelva el largo de un string.
int strlar(String cadena);
//print que despliegue un string por pantalla.
void print(String cadena);
//scan que lea un string desde el teclado
void scan(String &cadena);
//strmen que reciba dos strings y devuelva TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(String cadenaUno, String cadenaDos);
//streq que reciba dos strings y devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(String cadenaUno, String cadenaDos);
//strcop que reciba dos strings y copie el segundo en el primero.
void strcop(String &cadenaUno, String cadenaDos);
//strcon que reciba dos strings y concatene el segundo string al final del primero
void strcon(String &cadenaUno, String cadenaDos);
//strswp que reciba dos strings y devuelva el primero en el segundo y viceversa.
void strswap(String &cadenaUno, String &cadenaDos);
#endif // STRING_H_INCLUDED
