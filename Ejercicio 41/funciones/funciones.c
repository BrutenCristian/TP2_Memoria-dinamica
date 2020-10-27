#include "lib_41.h"
void crear(void)
{
    FILE *fp;
    if((fp=fopen("stock.dat","wb"))==0)
    {
        printf("\nError al crear el archivo de stock.");
        system("pause");
        return;
    }
    fclose(fp);
    return;
}
struct lista * listado(struct lista *p, struct lista **u)
{
    struct lista *aux, *r;
    int op;
    do
    {
        aux=(struct lista *)malloc(sizeof(struct lista));
        printf("\nIngresar el partnumber: ");
        fflush(stdin);
        scanf("%ld",&aux->data.partnumber);
        printf("\nIngresar el serialnumber: ");
        fflush(stdin);
        scanf("%ld",&aux->data.serialnumber);
        printf("\nIngresar la descripcion: ");
        fflush(stdin);
        gets(aux->data.descripcion);
        printf("\nIngresar la ubicacion: ");
        fflush(stdin);
        gets(aux->data.ubicacion);
        if(p==NULL)
        {
            p=(*u)=aux;
            p->sig=(*u);
            (*u)->sig=NULL;
            (*u)->ant=p;
        }
        else
        {
            r=p;
            if((strcmp(aux->data.descripcion,p->data.descripcion))==1)//si es el primero
            {
                aux->sig=p;
                p->ant=aux;
                p=aux;//actualizo primero
            }
            else
            {
                while(r->sig!=NULL)
                {
                    if((strcmp(aux->data.descripcion,r->sig->data.descripcion))==1)//si es el segundo
                {
                    aux->sig=r->sig->sig;
                    aux->ant=r;
                    r->sig=aux;//lo inserto
                }
                else
                {
                    r=r->sig;//si no es avanzo
                }

                }
                if(r==(*u))//si es el ultimo
                {
                    (*u)->sig=aux;
                    aux->ant=(*u);
                    (*u)=aux;
                    (*u)->sig=NULL;
                }
            }
        }
        r=p;
        printf("\nImpresion de la lista hasta el momento: ");
        while(r!=NULL)
        {
            printf("\nPartnumber: %ld",r->data.partnumber);
            printf("\nSerialnumber: %ld",r->data.serialnumber);
            printf("\nDescripcion: %s",r->data.descripcion);
            printf("\nUbicacion: %s",r->data.ubicacion);
            printf("\n-----------------------------------");
            r=r->sig;
        }
        system("pause");
        system("cls");
        printf("\nDesea seguir ingresando productos?\n1-Si\t0-No");
        fflush(stdin);
        scanf("%d",&op);
    }while(op!=0);
    return p;
}
void carga(struct lista *p, struct lista **u)
{
    struct lista *r;
    FILE *fp;
    int c=0;
    repuestos_t datos, aux;
    if((fp=fopen("stock.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo stock.");
        system("pause");
        return;
    }
    r=p;
    while(r!=NULL)
    {
        fseek(fp,0,0);
        datos.partnumber=r->data.partnumber;
        datos.serialnumber=r->data.serialnumber;
        strcpy(datos.descripcion,r->data.descripcion);
        strcpy(datos.ubicacion,r->data.ubicacion);
        fread(&aux,sizeof(repuestos_t),1,fp);
        while(!feof(fp))
        {
            if(aux.serialnumber==datos.serialnumber)
            {
                printf("\nEste producto ya fue ingresado.");
                c=1;
            }
            fread(&aux,sizeof(repuestos_t),1,fp);
        }
        if(c!=1)
        {
            aux.serialnumber=datos.serialnumber;
            aux.partnumber=datos.partnumber;
            strcpy(aux.descripcion,datos.descripcion);
            strcpy(aux.ubicacion,datos.ubicacion);
            fwrite(&aux,sizeof(repuestos_t),1,fp);
        }
        r=r->sig;
    }
    fclose(fp);
    return;
}
void impresion_archivo(void)
{
    repuestos_t datos;
    FILE *fp;
    if((fp=fopen("stock.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo stock.");
        system("pause");
        return;
    }
    printf("\nLa impresion del archivo es: ");
    fread(&datos,sizeof(repuestos_t),1,fp);
    while(!feof(fp))
    {
        printf("\nPartnumber: %ld",datos.partnumber);
        printf("\nSerialnumber: %ld",datos.serialnumber);
        printf("\nDescripcion: %s",datos.descripcion);
        printf("\nUbicacion: %s",datos.ubicacion);
        printf("\n--------------------------------");
        fread(&datos,sizeof(repuestos_t),1,fp);
    }
    fclose(fp);
}
