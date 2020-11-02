#include "lib_45.h"
int main()
{
    struct pila *p;
    struct lista *pi, *u;
    struct cola *pc, *uc;
    int op;
    pi=u=NULL;
    p=NULL;
    pc=uc=NULL;
    crear();
    crear_destruible();
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
    system("cls");
    pc=descuento(pc,&uc,pi,&u);
    impresion_arch_sto();
    impresion_cola(pc);
    return 0;
}
