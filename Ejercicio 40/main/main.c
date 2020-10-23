#include "lib_40.h"

int main()
{
    salida_t reg;
    struct pila *p;
    p=NULL;
    crear();
    reg=actualizado();
    impresion_archivo();
    if(reg.estado&(1<<2)&&reg.estado&(1<<0))
    {
        p=apilar(p,reg.potencia);
        impresion_pila(p);
    }
    else
    {
        salida(reg);
        impresion_salida();
    }
    return 0;
}
