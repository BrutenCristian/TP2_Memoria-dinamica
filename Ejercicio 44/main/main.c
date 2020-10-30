#include"lib_44.h"

int main()
{
    struct pila *p;
    struct lista *pi, *u;
    int op;
    pi=u=NULL;
    p=NULL;

    crear();
    carga();
    p=apilado(p);
    impresion_archivo();
    impresion_pila(p);
    do
    {
        pi=listado(pi,&u,p);
        printf("\nDesea hacer otra orden?\n1-Si\t0-No\n");
        fflush(stdin);
        scanf("%d",&op);
    }while(op!=0);
    impresion_lista(pi,u);
    return 0;
}
