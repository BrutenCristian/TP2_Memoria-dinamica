#include "lib_42.h"
void crear_nuevo(void)
{
    FILE *fp;
    if((fp=fopen("nuevo.dat","wb"))==0)
    {
        printf("\nError al crear el archivo nuevo.");
        system("pause");
        return;
    }
    fclose(fp);
    return;
}
void crear(void)
{
    FILE *fp;
    repuestos_t info;
    if((fp=fopen("invertido.dat","wb"))==0)
    {
        printf("\nError al crear el archivo invertido.");
        system("pause");
        return;
    }
    info.partnumber=0;
    info.serialnumber=0;
    strcat(info.descripcion,"Registro nulo");
    strcat(info.ubicacion,"--");
    fwrite(&info,sizeof(repuestos_t),1,fp);
    fclose(fp);
}
struct cola * fallados(struct cola *p, struct cola **u)
{
    FILE *fp, *n;
    repuestos_t aux, ok;
    if((fp=fopen("stock.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo de stock.");
        system("pause");
        return;
    }
    if((n=fopen("nuevo.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo historico.");
        system("pause");
        return;
    }
    fread(&aux,sizeof(repuestos_t),1,fp);
    while(!feof(fp))
    {
        if(aux.partnumber==1234)
        {
            if(aux.serialnumber&(1<<5)&&aux.serialnumber&(1<<3))
            {
                p=cola_fallados(p,&(*u),aux);
            }
            else
            {
                ok.partnumber=aux.partnumber;
                ok.serialnumber=aux.serialnumber;
                strcpy(ok.descripcion,aux.descripcion);
                strcpy(ok.ubicacion,aux.ubicacion);
                fseek(n,0,2);
                fwrite(&ok,sizeof(repuestos_t),1,n);
            }
        }
        else
        {
            ok.partnumber=aux.partnumber;
            ok.serialnumber=aux.serialnumber;
            strcpy(ok.descripcion,aux.descripcion);
            strcpy(ok.ubicacion,aux.ubicacion);
            fseek(n,0,2);
            fwrite(&ok,sizeof(repuestos_t),1,n);
        }
        fread(&aux,sizeof(repuestos_t),1,fp);
    }
    fclose(fp);
    fclose(n);
    remove("stock.dat");
    rename("nuevo.dat","stock.dat");
    return p;
}
struct cola * cola_fallados(struct cola *p, struct cola **u, repuestos_t datos)
{
    struct cola *aux;
    aux=(struct cola *)malloc(sizeof (struct cola));
    aux->data=datos;
    if(p==NULL)
    {
        p=(*u)=aux;
        p->sig=(*u);
        (*u)->ant=p;
    }
    else
    {
        aux->ant=(*u);
        (*u)->sig=aux;
        (*u)=aux;
    }
    return p;
}
void archivo_cola(struct cola *p, struct cola **u)
{
    FILE *fp;
    struct cola *r;
    repuestos_t aux;
    if((fp=fopen("invertido.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo invertido.");
        system("pause");
        return;
    }
    fseek(fp,0,0);
    if((*u)==NULL)
    {
        printf("\nCola vacia.");
    }
    else
    {
        r=(*u);
        while(r!=p->ant)
        {
            strcpy(aux.descripcion,r->data.descripcion);
            strcpy(aux.ubicacion,r->data.ubicacion);
            aux.partnumber=r->data.partnumber;
            aux.serialnumber=r->data.serialnumber;
            fwrite(&aux,sizeof(repuestos_t),1,fp);
            r=r->ant;
        }
    }
    fclose(fp);
    return;
}
void impresion_cola(struct cola *p, struct cola **u)
{
    struct cola *r;
    if(p==NULL)
    {
        printf("\nCola vacia.");
    }
    else
    {
        printf("\nImpresion de la cola:");
        r=p;
        while(r!=(*u)->sig)
        {
            printf("\nPartnumber: %ld",r->data.partnumber);
            printf("\nSerialnumber: %ld",r->data.serialnumber);
            printf("\nDescripcion: %s",r->data.descripcion);
            printf("\nUbicacion: %s",r->data.ubicacion);
            printf("\n--------------------------------");
            r=r->sig;
        }
    }
    return;
}
void impresion_archivo(void)
{
    FILE *fp, *st;
    repuestos_t inv, stck;
    if((fp=fopen("invertido.dat","rb"))==0||(st=fopen("stock.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        return;
    }
    printf("\nArchivo de la cola invertida: ");
    fread(&inv,sizeof(repuestos_t),1,fp);
    while(!feof(fp))
    {
        printf("\nPartnumber: %ld",inv.partnumber);
        printf("\nSerialnumber: %ld",inv.serialnumber);
        printf("\nDescripcion: %s",inv.descripcion);
        printf("\nUbicacion: %s",inv.ubicacion);
        printf("\n---------------------------");
        fread(&inv,sizeof(repuestos_t),1,fp);
    }
    printf("\nArchivo de stock: ");
    fread(&stck,sizeof(repuestos_t),1,st);
    while(!feof(st))
    {
        printf("\nPartnumber: %ld",stck.partnumber);
        printf("\nSerialnumber: %ld",stck.serialnumber);
        printf("\nDescripcion: %s",stck.descripcion);
        printf("\nUbicacion: %s",stck.ubicacion);
        printf("\n---------------------------");
        fread(&stck,sizeof(repuestos_t),1,st);
    }
    fclose(fp);
    fclose(st);
}
