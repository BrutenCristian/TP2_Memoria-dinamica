#include "lib_38.h"
int main()
{
    struct cola *p, *u;
    p=u=NULL;
    p=primer_cuarto(p, &u);
    impresion_primer_cuarto(&p);
    impresion_segundo_cuarto(&u);
    impresion_tercer_cuarto(&p);
    impresion_cuarto_cuarto(&u);
    printf("\n");
    system("pause");
    return;
}
