#ifndef LIB_38_H_INCLUDED
#define LIB_38_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
struct cola
{
    unsigned char valor;
    struct cola * s, *a;
};

struct cola * primer_cuarto(struct cola *p, struct cola **u);
void impresion_primer_cuarto(struct cola **p);
void impresion_segundo_cuarto(struct cola **u);
void impresion_tercer_cuarto(struct cola **p);
void impresion_cuarto_cuarto(struct cola **u);
#endif // LIB_38_H_INCLUDED
