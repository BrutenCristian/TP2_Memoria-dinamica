#include "lib_43.h"

int main()
{
    struct pila *p;
    p=NULL;
    crear();
    carga();
    p=apilado(p);
    impresion_archivo();
    impresion_pila(p);
    return 0;
}
