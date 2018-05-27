#include <stdio.h>
#include "arreglo.h"
#include "diccionario.h"

int main(void)
{
    Diccionario *D = diccionario_nuevo();
    diccionario_agrega(D, "Linux", "Derivado de Unix");
    diccionario_agrega(D, "Linux", "S.O. con licencia GPL");
    diccionario_agrega(D, "FreeBSD", "Derivado de Unix");
    diccionario_agrega(D, "MacOS", "Derivado de FreeBSD");
    diccionario_agrega(D, "Windows", "Derivado de MSDOS");

    Arreglo *linux = diccionario_busca_significados(D, "Linux");
    arreglo_muestra(linux);
    arreglo_libera(linux);

    printf("\n");

    Arreglo *unix = dicionario_busca_palabras(D, "Derivado de Unix");
    arreglo_muestra(unix);
    arreglo_libera(unix);

    diccionario_libera(D);
    return 0;
}
