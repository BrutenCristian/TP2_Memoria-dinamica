#include "lib_42.h"

int main()
{
    struct cola *p, *u;
    p=u=NULL;
    crear();
    crear_nuevo();
    p=fallados(p,&u);
    archivo_cola(p,&u);
    impresion_archivo();
    impresion_cola(p,&u);
    return 0;
}
