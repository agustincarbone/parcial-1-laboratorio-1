#ifndef FCLIENTE_H_INCLUDED
#define FCLIENTE_H_INCLUDED

typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit [50];
    int idCliente;
    int estado;
}ECliente;

int cliente_init(ECliente array[],int limite);
int cliente_alta(ECliente array[],int limite);
int cliente_baja(ECliente array[],int limite, int id);
int cliente_modificacion(ECliente array[],int limite, int id);
int cliente_mostrar(ECliente array[],int limite);
int cliente_buscarPorId(ECliente array[],int limite, int id);
int cliente_altaForzada(ECliente array[],int limite,char nombre[], char apellido[], char cuit[]);




#endif // FCLIENTE_H_INCLUDED
