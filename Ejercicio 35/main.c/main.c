#include "lib_35.h"
int main()
{
    int opc;
    Crear();
    do
    {
        Mdinamica();
        printf("\nLo que se almaceno en el archivo fue:\n");
        Listado();
        printf("\nDesea ingresar mas contactos?\n0-No\t1-Si");
        fflush(stdin);
        scanf("%d",&opc);
    }while(opc!=0);
}
