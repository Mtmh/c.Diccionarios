#ifndef ARREGLO_H
#define ARREGLO_H

typedef struct Arreglo Arreglo;


struct Arreglo {
    const char **arreglo;
    int tamanyo;
};



Arreglo *arreglo_nuevo(void );

void arreglo_agrega(Arreglo *A, const char *palabra);

void arreglo_aumenta(Arreglo **A, int unidades);

void arreglo_copia(const Arreglo *Ao, Arreglo *Ad, int unidades);

void arreglo_libera(Arreglo *A);

void arreglo_muestra(const Arreglo *A);

#endif // ARREGLO_H
