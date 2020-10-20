void crear(void)
{
    FILE *fp;
    contactos_t reg;
    if((fp=fopen("contactos_ordenados.dat","wb"))==0)
    {
        printf("\nError al crear el archivo de contactos ordenados.");
        system("pause");
        return;
    }
    strcpy(reg.nombre,"Registro nulo");
    strcpy(reg.apellido,"Registro nulo");
    strcpy(reg.mail,"Registronulo@maul.com");
    reg.edad=0;
    reg.telefono=00000000;
    fwrite(&reg,sizeof(contactos_t),1,fp);
    fclose(fp);
    return;
}
int cuenta_registros(void)
{
    FILE *fp;
    contactos_t reg;
    int t=0;
    if((fp=fopen("contactos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo de contactos.");
        system("pause");
        return;
    }
    fread(&reg,sizeof(contactos_t),1,fp);
    while(!feof(fp))
    {
        t++;
        fread(&reg,sizeof(contactos_t),1,fp);
    }
    fclose(fp);
    return t;
}
void listado(void)
{
    FILE *fp;
    struct lista *p=NULL, *u=NULL, *aux, *r;
    int t,i=0,cmp;
    contactos_t reg;
    if((fp=fopen("contactos.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo de contactos.");
        system("pause");
        return;
    }
    t=cuenta_registros();
    fread(&reg,sizeof(contactos_t),1,fp);
    while(!feof(fp))
    {
        if(i!=t)
        {
           aux=(struct lista *)malloc(sizeof(contactos_t));
           strcpy(aux->data.nombre,reg.nombre);
           strcpy(aux->data.apellido,reg.apellido);
           strcpy(aux->data.mail,reg.mail);
           aux->data.edad=reg.edad;
           aux->data.telefono=reg.telefono;
           if(p==NULL)
           {
               p=u=aux;
               u->l=NULL;
               r=p;
           }
           else
           {
               while(1)
               {
                   if((strcmp(r->data.apellido,aux->data.apellido))==1)
                   {
                       //tiene que ir primero
                       aux->l=p;
                       p=aux;
                       break;
                   }
                   while(r->l)//si el lazo apunta a null termina el while
                   {
                       if((strcmp(r->l->data.apellido,aux->data.apellido))==-1)
                       {
                           r=r->l;
                       }
                       else break;
                   }
                   if(r==u)
                   {
                       //Es el ultimo
                       u->l=aux;
                       u=aux;
                       u->l=NULL;
                       break;
                   }
                   else
                   {
                       //es uno central
                       aux->l=r->l;
                       r->l=aux;
                       break;
                   }
               }
           }
        }
        fread(&reg,sizeof(contactos_t),1,fp);
        i++;
    }
    archivo_directo(p,u);
    fclose(fp);

}
void archivo_directo(struct lista *p, struct lista *u)
{
    struct lista *r;
    FILE *fp;
    contactos_t reg;
    if((fp=fopen("contactos_ordenados.dat","rb+"))==0)
    {
        printf("\nError al abrir el archivo de contactos ordenados.");
        system("pause");
        return;
    }
    printf("\nImpresion por lista:");
    r=p;
    if(p==NULL)
    {
        printf("\nLista vacia.");
        system("pause");
        fclose(fp);
        return;
    }
    do
    {
        strcpy(reg.nombre,r->data.nombre);
        strcpy(reg.apellido,r->data.apellido);
        strcpy(reg.mail,r->data.mail);
        reg.edad=r->data.edad;
        reg.telefono=r->data.telefono;
        fwrite(&reg,sizeof(contactos_t),1,fp);
        printf("\nNombre: %s",r->data.nombre);
        printf("\nApellido: %s",r->data.apellido);
        printf("\nEdad: %d",r->data.edad);
        printf("\nTelefono: %ld",r->data.telefono);
        printf("\nMail: %s",r->data.mail);
        r=r->l;
    }while(r!=NULL);
    system("pause");
    fclose(fp);
}
void impresion_archivo(void)
{
    FILE *fp;
    contactos_t reg;
    if((fp=fopen("contactos_ordenados.dat","rb"))==0)
    {
        printf("\nError al abrir el archivo de contactos ordenados");
        system("pause");
        return;
    }
    printf("\nImpresion por archivo: ");
    fread(&reg,sizeof(contactos_t),1,fp);
    while(!feof(fp))
    {
        printf("\nNombre: %s",reg.nombre);
        printf("\nApellido: %s",reg.apellido);
        printf("\nEdad: %d",reg.edad);
        printf("\nTelefono: %ld",reg.telefono);
        printf("\nMail: %s",reg.mail);
        fread(&reg,sizeof(contactos_t),1,fp);
    }
    fclose(fp);
}
