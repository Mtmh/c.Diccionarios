#include "arreglo.h"
#include <stdlib.h>
#include <stdio.h>

void arreglo_agrega(Arreglo *A, const char *palabra)
{
    arreglo_aumenta(&A, 1);
    A->arreglo[A->tamanyo - 1] = palabra;

}

void arreglo_aumenta(Arreglo **A, int unidades)
{
    Arreglo *N = arreglo_nuevo();
    N->arreglo = (const char **) calloc((**A).tamanyo,
                                 sizeof(const char **));
    N->tamanyo = (**A).tamanyo;
    arreglo_copia(*A, N, N->tamanyo);
    arreglo_libera(*A);
    *A = arreglo_nuevo();
    (**A).tamanyo = N->tamanyo + unidades;
    (**A).arreglo = (const char **) calloc((**A).tamanyo,
                                   sizeof(const char **));
    arreglo_copia(N, *A, N->tamanyo);
    arreglo_libera(N);

}

Arreglo *arreglo_nuevo()
{
    Arreglo *A = (Arreglo *) malloc(sizeof(Arreglo));
    A->arreglo = NULL;
    A->tamanyo = 0;
    return A;
}

void arreglo_copia(const Arreglo *Ao, Arreglo *Ad, int unidades)
{
    int i;
    for (i = 0; i < unidades; ++i){
        Ad->arreglo[i] = Ao->arreglo[i];
    }

}

void arreglo_libera(Arreglo *A)
{
   free(A->arreglo);
   free(A);
}

void arreglo_muestra(const Arreglo *A)
{
    int i;
    for (i = 0; i < A->tamanyo; ++i){
        printf("%s\n", A->arreglo[i]);
    }

}

