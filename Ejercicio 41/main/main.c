#include "lib_41.h"

int main()
{
    struct lista *p, *u;
    p=u=NULL;
    p=listado(p,&u);
    if(p!=NULL)
    {
        crear();
        carga(p,&u);
        impresion_archivo();
    }
    return 0;
}
