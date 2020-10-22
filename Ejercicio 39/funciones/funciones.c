#include "lib_39.h"
void crear(void)
{
    FILE *fp;
    datos_t aux;
    if((fp=fopen("potencia.dat","wb"))==0)
    {
        printf("\nError al crear el archivo potencia");
        system("pause");
        return;
    }
    strcpy(aux.desc,"Registro nulo");
    aux.potencia=0;
    aux.estado=aux.desc[1]*aux.potencia;
    fwrite(&aux,sizeof(datos_t),1,fp);
    fclose(fp);
}
datos_t carga(void)
{
    datos_t dat;
    int aux;
    printf("\nIngresar el valor de potencia medido(valores del 0 al 255 permitidos): ");
    fflush(stdin);
    scanf("%d",&aux);
    if(aux<256)
    {
        dat.potencia=aux;
    }
    else
    {
        printf("\nError al ingresar el valor de potencia.");
        system("pause");
        strcpy(dat.desc,"Error");
        return dat;
    }
    printf("\nIngresar la descripcion: ");
    fflush(stdin);
    gets(dat.desc);
    dat.estado=dat.potencia*dat.desc[0];
    return dat;
}
struct lista * listado(struct lista *p, struct lista **u, datos_t dat)
{
    struct lista *aux, *r;
    aux=(struct lista *)malloc(sizeof(struct lista));
    strcpy(aux->data.desc,dat.desc);
    aux->data.estado=dat.estado;
    aux->data.potencia=dat.potencia;
    r=p;
    if(p==NULL)
    {
        p=(*u)=aux;
        p->l=(*u);
        (*u)->l=NULL;
        return p;
    }
    else
    {
        while(r!=NULL)
        {
            if(aux->data.potencia>p->data.potencia)
            {
                aux->l=p;
                p=aux;
                return p;
            }
            if(r->l->data.potencia<aux->data.potencia)
            {
                aux->l=r->l;
                r->l=aux;
                return p;
            }
            else
            {
                r=r->l;
            }
            if(r==(*u))
            {
                if(aux->data.potencia<r->data.potencia)
                {
                    (*u)->l=aux;
                    (*u)=aux;
                    (*u)->l=NULL;
                    return p;
                }
            }
        }
    }
}
void guardado(struct lista *p, struct lista **u)
{
    FILE *fp;
    struct lista *r;
    datos_t data;
    if((fp=fopen("potencia.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        return;
    }
    r=p;
    while(r!=NULL)
    {
        strcpy(data.desc,r->data.desc);
        data.estado=r->data.estado;
        data.potencia=r->data.potencia;
        fwrite(&data,sizeof(datos_t),1,fp);
        r=r->l;
    }
    fclose(fp);
    return;
}
void impresion_archivo(void)
{
    FILE *fp;
    datos_t dat;
    if((fp=fopen("potencia.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo.");
        system("pause");
        return;
    }
    fread(&dat,sizeof(datos_t),1,fp);
    while(!feof(fp))
    {
        printf("\nPotencia: %d",dat.potencia);
        printf("\nDescripcion: %s",dat.desc);
        printf("\nEstado: %d",dat.estado);
        fread(&dat,sizeof(datos_t),1,fp);
    }
    return;
}
