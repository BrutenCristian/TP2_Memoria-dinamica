#include "lib_38.h"
struct cola * primer_cuarto(struct cola *p, struct cola **u)
{
    unsigned char c;
    struct cola *aux, *r;
    c=0;
    aux=(struct cola *)malloc(sizeof(struct cola));
    aux->valor=c;
    p=(*u)=aux;
    p->s=(*u);
    (*u)->a=p;
    p->a=NULL;
    do
    {
        if(c<125)
        {
            c=c+5;
        }else
        {
            c=127;
        }
        r=(struct cola *)malloc(sizeof(struct cola));
        r->valor=c;
        r->a=(*u);
        (*u)->s=r;
        (*u)=r;
        (*u)->s=NULL;
    }while(c<127);
    return p;
}
void impresion_primer_cuarto(struct cola **p)
{
    struct cola *r;
    r=(*p);
    printf("\nPrimer cuarto: ");
    while(r!=NULL)
    {
        printf("\n%d",r->valor);
        r=r->s;
    }
}
void impresion_segundo_cuarto(struct cola **u)
{
    struct cola *l;
    l=(*u);
    printf("\nSegundo cuarto: ");
    while(l!=NULL)
    {
        printf("\n%d",l->valor);
        l=l->a;
    }
}
void impresion_tercer_cuarto(struct cola **p)
{
    struct cola *r;
    r=(*p);
    printf("\nTercer cuarto: ");
    while(r!=NULL)
    {
        printf("\n%d",r->valor*-1);
        r=r->s;
    }
}
void impresion_cuarto_cuarto(struct cola **u)
{
    struct cola *l;
    l=(*u);
    printf("\nCuarto cuarto: ");
    while(l!=NULL)
    {
        printf("\n%d",l->valor*-1);
        l=l->a;
    }
}
