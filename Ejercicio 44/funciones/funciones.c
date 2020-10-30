#include"lib_44.h"
void crear(void)
{
    FILE *fp;
    if((fp=fopen("repuestos.dat","wb"))==0)
    {
        printf("\nError al crear el archivo.");
        system("pause");
        return;
    }
    fclose(fp);
    return;
}
void carga(void)
{
    FILE *fp;
    int op, c=0;
    long orden;
    repuestos_t datos;
    if((fp=fopen("repuestos.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        return;
    }
    do
    {
        printf("\nIngresar el numero de orden que desea cargar al archivo: ");
        fflush(stdin);
        scanf("%ld",&orden);
        fread(&datos,sizeof(repuestos_t),1,fp);
        while(!feof(fp))
        {
            if(orden==datos.numerodeorden)
            {
                printf("\nEste repuesto ya fue ingresado.");
                c=1;
            }
            fread(&datos,sizeof(repuestos_t),1,fp);
        }
        if(c!=1)
        {
            datos.numerodeorden=orden;
            printf("\nIngresar el nombre del cliente: ");
            fflush(stdin);
            gets(datos.cliente);
            printf("\nIngresar la descripcion de la falla que tuvo el cliente: ");
            fflush(stdin);
            gets(datos.descripcionfalla);
            printf("\nIngresar el modelo del repuesto: ");
            fflush(stdin);
            gets(datos.modelo);
            printf("\nIngresar la fecha: ");
            fflush(stdin);
            gets(datos.fecha);
            printf("\nIngresar la hora: ");
            fflush(stdin);
            gets(datos.hora);
            fwrite(&datos,sizeof(repuestos_t),1,fp);
            fseek(fp,0,2);
        }
        printf("\nDesea ingresar mas ordenes?\n1-Si\t0-No\n");
        fflush(stdin);
        scanf("%d",&op);
    }while(op!=0);
    fclose(fp);
    system("cls");
    return;
}
struct pila * apilado(struct pila *p)
{
    struct pila *aux;
    FILE *fp;
    int t;
    repuestos_t datos;
    t=cuenta_reg();
    if((fp=fopen("repuestos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        return p;
    }
    for(int r=0;r<t;r++)
    {
        fseek(fp,(1L)*(t-r-1)*sizeof(repuestos_t),0);
        fread(&datos,sizeof(repuestos_t),1,fp);
        aux=(struct pila *)malloc(sizeof(struct pila));
        aux->data.numerodeorden=datos.numerodeorden;
        strcpy(aux->data.cliente,datos.cliente);
        strcpy(aux->data.descripcionfalla,datos.descripcionfalla);
        strcpy(aux->data.modelo,datos.modelo);
        strcpy(aux->data.fecha,datos.fecha);
        strcpy(aux->data.hora,datos.hora);
        if(p==NULL)
        {
            p=aux;
            p->l=NULL;
        }
        else
        {
            aux->l=p;
            p=aux;
        }
    }
    return p;
}
int cuenta_reg(void)
{
    FILE *ff;
    int t=0;
    repuestos_t datos;
    if((ff=fopen("repuestos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo");
        system("pause");
        return 0;
    }
    fread(&datos,sizeof(repuestos_t),1,ff);
    while(!feof(ff))
    {
        t++;
        fread(&datos,sizeof(repuestos_t),1,ff);
    }
    fclose(ff);
    return t;
}
void impresion_archivo(void)
{
    FILE *fp;
    repuestos_t datos;
    if((fp=fopen("repuestos.dat","rb"))==0)
    {
        printf("\nError al abrir al archivo.");
        system("pause");
        return;
    }
    printf("\nLa impresion del archivo es: ");
    fread(&datos,sizeof(repuestos_t),1,fp);
    while(!feof(fp))
    {
        printf("\nNumero de orden: %ld",datos.numerodeorden);
        printf("\nCliente: %s",datos.cliente);
        printf("\nDescripcion de la falla: %s",datos.descripcionfalla);
        printf("\nModelo: %s",datos.modelo);
        printf("\nFecha: %s",datos.fecha);
        printf("\nHora: %s",datos.hora);
        printf("\n------------------------------------");
        fread(&datos,sizeof(repuestos_t),1,fp);
    }
    fclose(fp);
    return;
}
void impresion_pila(struct pila *p)
{
    struct pila *r;
    r=p;
    printf("\nLa impresion de la pila es: ");
    while(r!=NULL)
    {
       printf("\nNumero de orden: %ld",r->data.numerodeorden);
        printf("\nCliente: %s",r->data.cliente);
        printf("\nDescripcion de la falla: %s",r->data.descripcionfalla);
        printf("\nModelo: %s",r->data.modelo);
        printf("\nFecha: %s",r->data.fecha);
        printf("\nHora: %s",r->data.hora);
        printf("\n------------------------------------");
        r=r->l;
    }
    return;
}
struct lista * listado(struct lista *pi, struct lista **u, struct pila *p)
{
   struct lista *aux, *re;
   extraccionesRepuestos_t rep;
   struct pila *r;
   int c=0;
   printf("\nIngresar el modelo de repuesto requerido: ");
   fflush(stdin);
   gets(rep.repuestos.modelo);
    r=p;
    while(r!=NULL)
    {
        if((strcmp(rep.repuestos.modelo,r->data.modelo))==0)
        {
            printf("\nRepuesto disponible");
            rep.repuestos.numerodeorden=r->data.numerodeorden;
            strcpy(rep.repuestos.cliente,r->data.cliente);
            strcpy(rep.repuestos.descripcionfalla,r->data.descripcionfalla);
            strcpy(rep.repuestos.fecha,r->data.fecha);
            strcpy(rep.repuestos.hora,r->data.hora);
            c=1;
        }
        r=r->l;
        if(r==NULL)
        {
            if(c==0){
            printf("\nNo se encontro el repuesto pedido.");
            return pi;}
        }
    }
    aux=(struct lista *)malloc(sizeof(struct lista));
    aux->dat.repuestos=rep.repuestos;
    if(pi==NULL)
    {
        aux->dat.cantidad=0;
        pi=(*u)=aux;
        pi->sig=(*u);
        (*u)->ant=pi;
        (*u)->sig=NULL;
    }
    else
    {
        re=pi;
        if((strcmp(aux->dat.repuestos.modelo,re->dat.repuestos.modelo))==-1)//para generar un orden alfabetico
        {
            aux->dat.cantidad=0;
            aux->sig=pi;
            pi->ant=aux;
            pi=aux;
        }
        else
        {
            while(re!=NULL)
            {
                if((strcmp(aux->dat.repuestos.modelo,re->dat.repuestos.modelo))==-1)
                {
                    aux->dat.cantidad=0;
                    aux->sig=re;
                    aux->ant=re->ant;
                    re->ant=aux;
                }
                else{re=re->sig;}
                if(r==NULL)
                {
                    aux->dat.cantidad=0;
                    aux->ant=(*u);
                    (*u)->sig=aux;
                    (*u)=aux;
                    (*u)->sig=NULL;
                }
            }
        }
    }
    pi=cantidad(pi,&u);
    return pi;
}
void impresion_lista(struct lista *p, struct lista *u)
{
    struct lista *r;
    r=p;
    if(r==NULL)
    {
        printf("\nLista vacia.");
    }
    else
    {
        while(r!=NULL)
        {
            printf("\nNumero de orden: %ld",r->dat.repuestos.numerodeorden);
            printf("\nCliente: %s",r->dat.repuestos.cliente);
            printf("\nDescripcion de la falla: %s",r->dat.repuestos.descripcionfalla);
            printf("\nModelo: %s",r->dat.repuestos.modelo);
            printf("\nFecha: %s",r->dat.repuestos.fecha);
            printf("\nHora: %s",r->dat.repuestos.hora);
            printf("\nCantidad: %d",r->dat.cantidad);
            printf("\n---------------------------------------------");
            r=r->sig;
        }
    }
    system("pause");
    return;
}
struct lista * cantidad(struct lista *p, struct lista **u)
{
    struct lista *r;
    char modelo[65];
    int cant;
    r=p;
    printf("\nIngresar nuevamente el modelo deseado: ");
    fflush(stdin);
    gets(modelo);
    while(r!=NULL)
    {
        if((strcmp(modelo,r->dat.repuestos.modelo))==0)
        {
            printf("\nQue cantidad de %s necesita?\n",modelo);
            fflush(stdin);
            scanf("%d",&cant);
            r->dat.cantidad=r->dat.cantidad+cant;
        }
        if(r==p)
        {
            p=r;
        }
        if(r==(*u))
        {
            (*u)==r;
        }
        r=r->sig;
    }
    return p;
}
