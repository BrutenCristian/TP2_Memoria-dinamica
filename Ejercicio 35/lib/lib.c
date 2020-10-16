#include "lib_35.h"
void Crear(void)
{
    FILE *fp;
    if((fp=fopen("contactos.dat","wb"))==0)
    {
        printf("\nError al crear el archivo.");
        system("pause");
        return;
    }
    else
        fclose(fp);
}
void Mdinamica(void)
{
struct pila_t *aux, *p, *r, *c;
contactos_t dat;
int cant;
p=aux=r=NULL;
do
{
    printf("\nIngresar el nombre: ");
    fflush(stdin);
    gets(dat.nombre);
    printf("\nIngresar el apellido: ");
    fflush(stdin);
    gets(dat.apellido);
    printf("\nIngresar la edad: ");
    fflush(stdin);
    scanf("%d",&dat.edad);
    printf("\nIngresar el telefono celular: ");
    fflush(stdin);
    scanf("%ld",&dat.telefono);
    printf("\nIngresar el mail: ");
    fflush(stdin);
    gets(dat.mail);
    aux=(struct pila_t*)malloc(sizeof(struct pila_t));
    strcpy(aux->datos.nombre,dat.nombre);
    strcpy(aux->datos.apellido,dat.apellido);
    aux->datos.edad=dat.edad;
    aux->datos.telefono=dat.telefono;
    strcpy(aux->datos.mail,dat.mail);
    if(p==NULL)//Pila vacia
    {
        p=aux;
        p->l=NULL;
    }
    else//Pila con elementos
    {
        aux->l=p;
        p=aux;
    }
    printf("\nDesea ingresar mas contactos?\n0-No\t1-Si\n");
    fflush(stdin);
    scanf("%d",&cant);
}while(cant!=0);
r=p;
while(1)
{
    c=r;
    if(r==NULL)
        break;
    printf("\nNombre: %s\tApellido: %s ",r->datos.nombre,r->datos.apellido);
    printf("\nEdad: %d\tTelefono: %ld\tMail: %s",r->datos.edad,r->datos.telefono,r->datos.mail);
    if(r->datos.edad>21)
    {
        carga(c);
    }
    r=r->l;
}
system("pause");
return;
}
void carga(struct pila_t *c)
{
    FILE *fp;
    contactos_t dat;
    if((fp=fopen("contactos.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo");
        system("pause");
        return;
    }
    fread(&dat,sizeof(struct pila_t),1,fp);
    while(!feof(fp))
    {
        if(dat.telefono==c->datos.telefono)
        {
            printf("\nEste numero de telefono ya existe en la lista de contactos.");
            system("pause");
            return;
        }
        fread(c,sizeof(struct pila_t),1,fp);
    }
    strcpy(dat.nombre,c->datos.nombre);
    strcpy(dat.apellido,c->datos.apellido);
    dat.edad=c->datos.edad;
    dat.telefono=c->datos.telefono;
    strcpy(dat.mail,c->datos.mail);
    fwrite(&dat,sizeof(contactos_t),1,fp);
    fclose(fp);
    system("pause");
    return;
}
void Listado(void)
{
    FILE *fp;
    contactos_t dat;
    if((fp=fopen("contactos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo de contactos.");
        system("pause");
        return;
    }
    fread(&dat,sizeof(contactos_t),1,fp);
    while(!feof(fp))
    {
        printf("\nNombre: %s\tApellido: %s",dat.nombre,dat.apellido);
        printf("\nEdad: %d\tTelefono: %ld\tMail: %s",dat.edad,dat.telefono,dat.mail);
        fread(&dat,sizeof(contactos_t),1,fp);
    }
    fclose(fp);
    system("pause");
    return;
}
