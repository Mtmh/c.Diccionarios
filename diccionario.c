#include "diccionario.h"
#include <stdio.h>
#include <stdlib.h>


Diccionario *diccionario_nuevo(void)
{
   Diccionario *D = (Diccionario *) malloc(sizeof(Diccionario));
   D->parejas = NULL;
   D->tamanyo = 0;

   return D;
}

void diccionario_agrega(Diccionario *D,
                        const char *llave,
                        const char *valor)
{
        diccionario_aumenta(&D, 1);// Aqui el fallo teni -1 y es entero
        D->parejas[D->tamanyo - 1]->llave = llave;
        D->parejas[D->tamanyo - 1]->valor = valor;


}

void diccionario_muestra(const Diccionario *D)
{
    int i;
    for (i = 0; i < D->tamanyo; ++i){
        printf("%s: %s\n", D->parejas[i]->llave,
                           D->parejas[i]->valor);
    }
}

void diccionario_aumenta(Diccionario **D, int unidades) // Diccionario Puntero Doble
{
  Diccionario *E = diccionario_nuevo();

  E->tamanyo = (**D).tamanyo;

  E->parejas = (Pareja **) calloc(E->tamanyo, sizeof(Pareja));

  diccionario_inicializa_contenido(E);

  diccionario_copia(*D, E, E->tamanyo);

  diccionario_libera(*D);

  *D = diccionario_nuevo();

  (**D).tamanyo = E->tamanyo + unidades;

  (**D).parejas = (Pareja **) calloc((**D).tamanyo, sizeof(Pareja));

  diccionario_inicializa_contenido(*D);

  diccionario_copia(E, *D, E->tamanyo);

  diccionario_libera(E);

}

void diccionario_copia(const Diccionario *Do, Diccionario *Dd, int unidades)
{
    int i;
    for (i = 0; i < unidades; ++i){
        Dd->parejas[i]->llave = Do->parejas[i]->llave;
        Dd->parejas[i]->valor = Do->parejas[i]->valor;
    }

}

void diccionario_libera(Diccionario *D)
{
    int i;
    for (i = 0; i < D->tamanyo; ++i){
        free(D->parejas[i]);
    }
    free(D->parejas);
    free(D);
}

void diccionario_inicializa_contenido(Diccionario *D)
{
    int i;
    for (i = 0; i < D->tamanyo; ++i) {
        D->parejas[i] = (Pareja *) malloc(sizeof(Pareja));
        D->parejas[i]->llave = NULL;
        D->parejas[i]->valor = NULL;
    }
}



Arreglo *diccionario_busca_significados(const Diccionario *D,
                                      const char *llave)
{
    Arreglo *A = arreglo_nuevo();

    int i;
    for (i = 0; i < D->tamanyo; ++i){
        if (D->parejas[i]->llave == llave){
            arreglo_agrega(A, D->parejas[i]->valor);
        }

    }
    return A;

}

Arreglo *dicionario_busca_palabras(const Diccionario *D,
                                  const char *valor)
{
    Arreglo *A = arreglo_nuevo();

    int i;
    for (i = 0; i < D->tamanyo; ++i){
        if (D->parejas[i]->valor == valor){
            arreglo_agrega(A, D->parejas[i]->llave);
        }

    }
    return A;
}

