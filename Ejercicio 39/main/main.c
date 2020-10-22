#include "lib_39.h"
int main()
{
    struct lista *p, *u;
    int op;
    datos_t info;
    p=u=NULL;
    crear();
    do
    {
        info=carga();
        p=listado(p, &u, info);
        printf("\nDesea seguir ingresando datos?\n1-Si\t0-No\n");
        fflush(stdin);
        scanf("%d",&op);
    }while(op!=0);
    guardado(p,&u);
    impresion_archivo();
    system("pause");
    return 0;
}
