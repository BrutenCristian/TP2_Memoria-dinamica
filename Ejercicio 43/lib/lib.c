#ifndef LIB_43_H_INCLUDED
#define LIB_43_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    long numerodeorden;
    char cliente[40];
    char descripcionfalla[200];
    char modelo[65];
    char fecha[10];
    char hora[10];
}repuestos_t;
struct pila
{
    repuestos_t data;
    struct pila *l;
};
void crear(void);
void carga(void);
struct pila * apilado(struct pila *p);
void impresion_archivo(void);
void impresion_pila(struct pila *);
int cuenta_reg(void);
#endif // LIB_43_H_INCLUDED
