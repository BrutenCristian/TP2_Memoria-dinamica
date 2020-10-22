#ifndef LIB_39_H_INCLUDED
#define LIB_39_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char desc[60];
    unsigned char potencia;
    unsigned int estado;//desc[1]*potencia(todos los valores en ascii)
}datos_t;
struct lista
{
    datos_t data;
    struct lista *l;
};
datos_t carga(void);
void crear(void);
struct lista * listado(struct lista *p, struct lista **u, datos_t dat);
void guardado(struct lista *p, struct lista **u);
void impresion_archivo(void);
#endif // LIB_39_H_INCLUDED
