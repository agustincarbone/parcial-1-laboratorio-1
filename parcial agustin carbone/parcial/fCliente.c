#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fGets.h"
#include "fCliente.h"

static int proximoId(void);
static int buscarLugarLibre(ECliente* array,int limite);

/** \brief inicializa al array de estrucutras en 1, indicando que estan vacios
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int cliente_init(ECliente array[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            array[i].estado=1;
        }
    }
    return retorno;
}

int cliente_alta(ECliente array[],int limite)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char apellido[50];
    char cuit[50];

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido valido","El maximo es 50",apellido,50,2))
                {
                    if(!getStringNumeros("\nCuit? ",cuit))
                    {
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        array[i].idCliente = proximoId();
                        array[i].estado = 0;
                        retorno = array[i].idCliente;
                    }
                }
            }
        }
        else
        {
            retorno = -3;
        }
    }
    else
    {
        retorno = -2;
    }
    return retorno;
}

int cliente_baja(ECliente array[],int limite, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = cliente_buscarPorId(array,limite,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].estado=1;
        retorno=0;
    }
    return retorno;
}

int cliente_modificacion(ECliente array[],int limite, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[50];

    indiceAModificar = cliente_buscarPorId(array,limite,id);
    if(indiceAModificar>=0)
    {
        if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido valido","El maximo es 50",apellido,50,2))
                {
                    if(!getStringNumeros("\nCuit? ",cuit))
                    {
                        retorno = 0;
                        strcpy(array[indiceAModificar].nombre,nombre);
                        strcpy(array[indiceAModificar].apellido,apellido);
                        strcpy(array[indiceAModificar].cuit,cuit);
                        array[indiceAModificar].idCliente = proximoId();
                        array[indiceAModificar].estado = 0;
                    }
                }
            }
    }
    return retorno;
}

int cliente_mostrar(ECliente array[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado)
                printf("ID: %d - nombre: %s - apellido:%s - CUIT:%s estado: %d\n",array[i].idCliente, array[i].nombre, array[i].apellido, array[i].cuit, array[i].estado);

        }
    }
    return retorno;
}

static int buscarLugarLibre(ECliente array[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(array[i].estado==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

int cliente_buscarPorId(ECliente array[],int limite, int id)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!array[i].estado && array[i].idCliente==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_altaForzada(ECliente array[],int limite,char nombre[], char apellido[], char cuit[])
{
    int retorno = -1;
    int i;

    if(limite > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,limite);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            strcpy(array[i].cuit,cuit);
            array[i].idCliente = proximoId();
            array[i].estado = 0;
        }
        retorno = 0;
    }
    return retorno;
}





