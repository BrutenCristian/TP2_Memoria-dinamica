#ifndef LIB_35_H_INCLUDED
#define LIB_35_H_INCLUDED
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
struct pila_t
{
    contactos_t datos;
    struct pila_t *l;
};
void Mdinamica(void);
void carga(struct pila_t *c);
void Listado(void);
void Crear(void);
#endif // LIB_35_H_INCLUDED
