#ifndef LIB_45_H_INCLUDED
#define LIB_45_H_INCLUDED
#include "lib_44.h"
typedef struct{
   long partNumber;
   long serialNumber;
   char descripcion[40];
   char ubicacion[100];
}repuestos41_t;
struct cola
{
    char modelo[65];
    struct cola *sig;
    struct cola *ant;
};
struct cola * cola_stock_ins(struct cola *pc, struct cola **uc, char modelo[65]);
void crear_destruible(void);
int busqueda(char modelo[65], int cant);
struct cola * descuento(struct cola *pc, struct cola **uc, struct lista*pi, struct lista **u);
void impresion_arch_sto(void);
void impresion_cola(struct cola *pc);
#endif // LIB_45_H_INCLUDED
