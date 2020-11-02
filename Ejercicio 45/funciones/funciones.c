#include "lib_45.h"
void crear_destruible(void)
{
    FILE *fp;
    if((fp=fopen("destruible.dat","wb"))==0)
    {
        printf("\nError al crear el archivo.");
        system("pause");
        return;
    }
    fclose(fp);
    return;
}
struct cola * descuento(struct cola *pc, struct cola **uc, struct lista *pi, struct lista **u)
{
   struct lista *r;
   int stock;
   r=pi;
   while(r!=NULL)
   {
       stock=busqueda(r->dat.repuestos.modelo, r->dat.cantidad);
       if(stock==1)
       {
           printf("\nStock disponible del modelo pedido.");
       }
       else
       {
           printf("\nStock no disponible.");
           pc=cola_stock_ins(pc,&uc,r->dat.repuestos.modelo);
       }
       r=r->sig;
   }
   return pc;
}
int busqueda(char modelo[65], int cant)
{
    long partnum;
    int c=0, t=0;
    repuestos41_t rep;
    FILE *fp, *dest;
    fp=fopen("stock.dat","rb");
    dest=fopen("destruible.dat","rb+");
    if(fp==0||dest==0)
    {
        printf("\nError al abrir los archivos.");
        system("pause");
        return;
    }
    printf("\nIngresar el partnumber del modelo: %s\n",modelo);
    fflush(stdin);
    scanf("%ld",&partnum);
    fread(&rep,sizeof(repuestos41_t),1,fp);
    while(!feof(fp))
    {
        if(partnum==rep.partNumber)
        {
            c++;
        }
        fread(&rep,sizeof(repuestos41_t),1,fp);
    }
    if(c>=cant)
    {
        fseek(dest,0,2);
        fseek(fp,0,0);
        fread(&rep,sizeof(repuestos41_t),1,fp);
    while(!feof(fp))
    {
        if(t<=c)
        {
            if(partnum!=rep.partNumber)
            {
                fwrite(&rep,sizeof(repuestos41_t),1,dest);
            }
            t++;
        }
        else
        {
            fwrite(&rep,sizeof(repuestos41_t),1,dest);
        }
        fread(&rep,sizeof(repuestos41_t),1,fp);
    }
    fclose(fp);
    fclose(dest);
    remove("stock.dat");
    rename("destruible.dat","stock.dat");
    return 1;
    }
    else
    {
        fclose(fp);
        fclose(dest);
        return 0;
    }
}
struct cola * cola_stock_ins(struct cola *pc, struct cola **uc, char modelo[65])
{
    struct cola *aux;
    aux=(struct cola *)malloc(sizeof(struct cola));
    strcpy(aux->modelo,modelo);
    if(pc==NULL)
    {
        pc=(*uc)=aux;
        pc->sig=(*uc);
        (*uc)->ant=pc;
        (*uc)->sig=NULL;
    }
    else
    {
        aux->ant=(*uc);
        (*uc)->sig=aux;
        (*uc)=aux;
        (*uc)->sig=NULL;
    }
    return pc;
}
void impresion_arch_sto(void)
{
    FILE *fp;
    repuestos41_t rep;
    if((fp=fopen("stock.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        return;
    }
    printf("\nImpresion de lo que quedo en el deposito: ");
    fread(&rep,sizeof(repuestos41_t),1,fp);
    while(!feof(fp))
    {
        printf("\nPartNumber: %ld",rep.partNumber);
        printf("\nSerialnumber: %ld",rep.serialNumber);
        printf("\nDescripcion: %s",rep.descripcion);
        printf("\nUbicacion: %s",rep.ubicacion);
        printf("\n------------------------------");
        fread(&rep,sizeof(repuestos41_t),1,fp);
    }
    fclose(fp);
    return;
}
void impresion_cola(struct cola *pc)
{
    struct cola *r;
    r=pc;
    printf("\nRepuestos sin stock suficiente: ");
    while(r!=NULL)
    {
        printf("\nModelo: %s",r->modelo);
        printf("\n----------------------");
        r=r->sig;
    }
    return;
}
