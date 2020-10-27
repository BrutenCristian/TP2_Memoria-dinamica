#ifndef LIB_41_H_INCLUDED
#define LIB_41_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    long partnumber;
    long serialnumber;
    char descripcion[40];
    char ubicacion[100];
}repuestos_t;
struct lista
{
    repuestos_t data;
    struct lista *sig, *ant;
};
void crear(void);
struct lista * listado(struct lista *p, struct lista **u);
void carga(struct lista *p, struct lista **u);
void impresion_archivo(void);
#endif // LIB_41_H_INCLUDED
