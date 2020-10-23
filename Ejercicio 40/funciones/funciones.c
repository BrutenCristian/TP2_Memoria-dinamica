 #include "lib_40.h"
 void crear(void)
 {
     FILE *fp;
     if((fp=fopen("salida.dat","wb"))==0)
     {
         printf("\nError al abrir el archivo salida.");
         system("pause");
         return;
     }
     fclose(fp);
     return;
 }
salida_t actualizado(void)
 {
     FILE *fp;
     int op, i=0, t=0, k=0;
     long id;
     salida_t nuevo;
     char *p, aux[60], palabra[20], actual[60];
     if((fp=fopen("potencia.dat","rb+"))==0)
     {
         printf("\nError al abrir el archivo potencia.");
         system("pause");
         return;
     }
     do//Busqueda
     {
         printf("\nIngrese el ID que desea buscar: ");
         fflush(stdin);
         scanf("%ld",&id);
         fseek(fp,sizeof(salida_t)*(id-1),0);
         fread(&nuevo,sizeof(salida_t),1,fp);
         if(id==(long *)nuevo.id)
         {
             printf("\nRegistro encontrado.");
             op=0;
         }
         else
         {
             printf("\nNo se encontro registro relacionado al ID ingresado.");
             op=1;
         }
     }while(op!=0);
     strcpy(aux,nuevo.desc);
     p=&aux[0];
     while(*p!=' '&&(*p)!=NULL)//guardo la primera palabra
     {
         palabra[i]=*p;
         i++;
         p++;
     }
     p=&palabra[i];
     for(t;t<i;t++)//invierto
     {
         p=p-1;
         actual[t]=*p;
         actual[t+1]='\0';
     }
     p=&actual[0];
     printf("\nPalabra invertida: ");
     while(t!=0)
     {
         printf("%c",*p);//Imprimo la palabra invertida con punteros
         p++;
         t=t-1;
     }
     for(k;i<60;k++)//concateno el resto
     {
         actual[i]=aux[i];
         i++;
     }
     strcpy(nuevo.desc,actual);
     nuevo.estado=nuevo.estado^(1<<3);//Cambio el bit 3 del campo estado.
     fseek(fp,sizeof(salida_t)*-1,1);
     fwrite(&nuevo,sizeof(salida_t),1,fp);
     fclose(fp);
     return nuevo;
 }
 void impresion_archivo(void)
 {
     FILE *fp;
     salida_t dat;
     if((fp=fopen("potencia.dat","rb"))==0)
     {
         printf("\nError");
         system("pause");
         return;
     }
     printf("\nArchivo actualizado: ");
     fread(&dat,sizeof(salida_t),1,fp);
     while(!feof(fp))
     {
        printf("\nPotencia: %d",dat.potencia);
        printf("\nEstado: %d",dat.estado);
        printf("\nDescripcion: %s",dat.desc);
        fread(&dat,sizeof(salida_t),1,fp);
     }
     fclose(fp);
     return;
 }
struct pila * apilar(struct pila *p, unsigned char pot)
{
    struct pila *aux;
    aux=(struct pila *)malloc(sizeof(struct pila));
    aux->potencia=pot;
    if(p==NULL)
    {
        p=aux;
        p->l=NULL;
    }
    else
    {
        aux->l=p;
        p=aux;
        p->l=aux->l;
    }
    return p;
}
void salida(salida_t sal)
{
    FILE *fp;
    salida_t aux;
    int op;
    if((fp=fopen("salida.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo salida.");
        system("pause");
        return;
    }
    fread(&aux,sizeof(salida_t),1,fp);
    while(!feof(fp))
    {
        if(sal.id==aux.id)
        {
            printf("\nRegistro ya guardado en el archivo salida.");
            op=0;
        }
        fread(&aux,sizeof(salida_t),1,fp);
    }
    if(op!=0)
    {
        strcpy(aux.desc,sal.desc);
        aux.id=sal.id;
        aux.estado=sal.estado;
        aux.potencia=sal.potencia;
        fwrite(&aux,sizeof(salida_t),1,fp);
    }
    fclose(fp);
    return;
}
void impresion_pila(struct pila *p)
{
    struct pila *r;
    p=r;
    printf("\nImpresion de la pila: ");
    while(r!=NULL)
    {
        printf("\nPotencia: %d",r->potencia);
        r=r->l;
    }
}
void impresion_salida(void)
{
    FILE *fp;
    salida_t aux;
    if((fp=fopen("salida.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo salida.");
        system("pause");
        return;
    }
    printf("\nImpresion del archivo salida: ");
    fread(&aux,sizeof(salida_t),1,fp);
    while(!feof(fp))
    {
        printf("\nID: %d",aux.id);
        printf("\nDescripcion: %s",aux.desc);
        printf("\nPotenica: %d",aux.potencia);
        printf("\nEstado: %d",aux.estado);
        fread(&aux,sizeof(salida_t),1,fp);
    }
}
