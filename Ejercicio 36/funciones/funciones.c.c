#ifndef LIB_36_H_INCLUDED
#define LIB_36_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;
    long telefono;
    char mail[40];
}contactos_t;
struct lista
{
    contactos_t data;
    struct lista *l;
};

void crear(void);
int cuenta_registros(void);
void listado(void);
void archivo_directo(struct lista *p, struct lista *u);
void impresion_archivo(void);
#endif // LIB_36_H_INCLUDED
