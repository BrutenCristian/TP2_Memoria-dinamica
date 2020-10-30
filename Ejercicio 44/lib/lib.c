#ifndef LIB_44_H_INCLUDED
#define LIB_44_H_INCLUDED
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
typedef struct
{
    repuestos_t repuestos;
    int cantidad;
}extraccionesRepuestos_t;
struct lista
{
    extraccionesRepuestos_t dat;
    struct lista *sig;
    struct lista *ant;
};
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
struct lista * listado(struct lista *pi, struct lista **u, struct pila *p);
struct lista * cantidad(struct lista *p, struct lista **u);
void impresion_lista(struct lista *p, struct lista *u);
#endif // LIB_44_H_INCLUDED
