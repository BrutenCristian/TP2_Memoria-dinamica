#include "lib_37.h"
void crear(void)
{
    FILE *fp;
    if((fp=fopen("datos.dat","wb"))==0)
    {
        printf("\nError al crear el archivo de datos.");
        system("pause");
        return;
    }
}
void carga(void)
{
    FILE *fp;
    datos_t info;
    long aux;
    if((fp=fopen("datos.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo de datos.");
        system("pause");
        return;
    }


            printf("\nIngrese la clave del registro a cargar: ");
            fflush(stdin);
            scanf("%ld",&aux);
            fread(&info,sizeof(datos_t),1,fp);
            while(!feof(fp))
            {
                if(aux==info.clave)
                {
                    printf("\nClave ya existente.");
                    system("pause");
                    return;
                }
                fread(&info,sizeof(datos_t),1,fp);
            }

                info.clave=aux;
                printf("\nIngrese la descripcion del registro: ");
                fflush(stdin);
                gets(info.d);
                printf("\nIngrese el tipo(si ingresa mas de un caracter se tendra en cuenta el primero): ");
                fflush(stdin);
                scanf("%c",&info.tipo);
                info.b='A';
                fwrite(&info,sizeof(datos_t),1,fp);
                fclose(fp);


       return;
}
int posicion(long cl)
{
    FILE *fp;
    int cont=0;
    datos_t info;
    if((fp=fopen("datos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo de datos.");
        system("pause");
        return -1;
    }
    fread(&info,sizeof(datos_t),1,fp);
    while(!feof(fp))
    {
        cont++;
        if(info.clave==cl)
        {
            fclose(fp);
            return cont;
        }
        fread(&info,sizeof(datos_t),1,fp);
    }
    fclose(fp);
    return -1;//No encontrado
}
struct pila * apilar(long id, int pos, struct pila *p, struct pila *u)
{
    struct pila *aux;
    aux=(struct pila *)malloc(sizeof(dat_t));
    aux->data.clave=id;
    aux->data.posi=pos;
    if(p==NULL)//Es el primero
    {
        p=aux;
    }
    else//Actalizo el primero
    {
        aux->l=p;
        p=aux;
    }
    return p;
}
datos_t busca_registro(long c)
{
    FILE *fp;
    datos_t aux;
    if((fp=fopen("datos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo");
        system("pause");
        aux.b='E';
        return aux;
    }
    fread(&aux,sizeof(datos_t),1,fp);
    while(!feof(fp))
    {
        if(c==aux.clave)
        {
            fclose(fp);
            return aux;
        }
        fread(&aux,sizeof(datos_t),1,fp);
    }
    fclose(fp);
    aux.b='E';
    return aux;
}
char tip(unsigned char t)
{
    unsigned char aux;
    aux=t^(1<<4);
    if(aux>t)
    {
        printf("\nBit 4 del tipo en 0");
        system("pause");
        return 'N';
    }
    else
    {
        printf("\nBit 4 del tipo en 1");
        system("pause");
        return 'S';
    }
}
void impresion_pila(struct pila *p, struct pila *u)
{
    struct pila *r;
    r=p;
    if(r==NULL)
    {
        printf("\nPila vacia");
        system("pause");
        return;
    }
    else
    {
        while(r!=NULL)
        {
            printf("\nClave: %ld",r->data.clave);
            printf("\nPosicion: %d",r->data.posi);
            printf("\n-------------------------");
            r=r->l;
        }
    }
    return;
}
