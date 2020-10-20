#include "lib_37.h"

int main()
{
    struct pila *p, *u;
    p=u=NULL;
    int po,opc, opci;
    char t;
    datos_t aux;
    long cla;
    crear();
    do{
    carga();
    printf("\nDesea seguir cargando datos?\n1-Si\t0-No");
    fflush(stdin);
    scanf("%d",&opci);
    }while(opci!=0);
    do{
    printf("\nIngrese la clave que desea apilar: ");
    fflush(stdin);
    scanf("%ld",&cla);
    aux=busca_registro(cla);
    if(aux.b!='E')
    {
        po=posicion(cla);
        t=tip(aux.tipo);
        if(t=='S')
        {
            p=apilar(cla,po,p,u);
        }
        else
        {
            printf("\nBit 4 en 0");
        }
    }
    else
    {
        printf("\nRegistro no encontrado");
    }
    printf("\nDesea ingresar otra clave en la pila?\n1-Si\t0-No");
    fflush(stdin);
    scanf("%d",&opc);
    }while(opc!=0);
    impresion_pila(p,u);
}
