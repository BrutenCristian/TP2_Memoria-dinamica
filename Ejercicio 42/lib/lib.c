#ifndef LIB_42_H_INCLUDED
#define LIB_42_H_INCLUDED
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
struct cola
{
    repuestos_t data;
    struct cola *sig;
    struct cola *ant;
};
void crear(void);
void crear_nuevo(void);
struct cola * cola_fallados(struct cola *p, struct cola **u, repuestos_t datos);
struct cola * fallados(struct cola *p, struct cola **u);
void archivo_cola(struct cola *p, struct cola **u);
void impresion_cola(struct cola *p, struct cola **u);
void impresion_archivo(void);

#endif // LIB_42_H_INCLUDED
