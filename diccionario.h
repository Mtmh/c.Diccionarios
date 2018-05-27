#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include "arreglo.h"

typedef struct Pareja Pareja;
typedef struct Diccionario Diccionario;

struct Pareja{
    const char *llave;
    const char *valor;
};

struct  Diccionario
{
   Pareja **parejas;
   int tamanyo;
};

Diccionario *diccionario_nuevo(void);

void diccionario_agrega(Diccionario *D,
                        const char *llave,
                        const char *valor);

void diccionario_muestra(const Diccionario *D);

void diccionario_aumenta(Diccionario **D, int unidades);

void diccionario_copia(const Diccionario *Do, Diccionario *Dd, int unidades);

void diccionario_libera(Diccionario *D);

void diccionario_inicializa_contenido(Diccionario *D);

Arreglo *diccionario_busca_significados(const Diccionario *D,
                                      const char *llave);

Arreglo *dicionario_busca_palabras(const Diccionario *D,
                                  const char *valor);





#endif // DICCIONARIO_H
