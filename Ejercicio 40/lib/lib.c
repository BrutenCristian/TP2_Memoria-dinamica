#ifndef LIB_40_H_INCLUDED
#define LIB_40_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char desc[60];
    unsigned char potencia;
    unsigned int estado;
}salida_t;
struct pila
{
    unsigned char potencia;
    struct pila *l;
};
 void crear(void);
 salida_t actualizado(void);
 void impresion_archivo(void);
 struct pila * apilar(struct pila *p, unsigned char pot);
 void salida(salida_t sal);
 void impresion_pila(struct pila *p);
 void impresion_salida(void);
 #endif // LIB_40_H_INCLUDED
