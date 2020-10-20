#ifndef LIB_37_H_INCLUDED
#define LIB_37_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    long clave;//ID
    char d[30];//Descripcion
    unsigned char tipo;//tipo de datos
    char b;//A=alta B=baja
}datos_t;
typedef struct
{
    long clave;
    int posi;
}dat_t;
struct pila
{
    dat_t data;
    struct pila *l;
};
void crear(void);
void carga(void);
datos_t busca_registro(long c);
int posicion(long cl);
struct pila * apilar(long id, int pos, struct pila *p, struct pila *u);
char tip(unsigned char t);
void impresion_pila(struct pila *p, struct pila *u);
#endif // LIB_37_H_INCLUDED
