#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fGets.h"
#include "fCliente.h"

static int proximoId();
static int buscarLugarLibre(ECliente* array,int limite);

/** \brief inicializa al array de estrucutras en 1, indicando que estan vacios e inicializa a las cantidades de publicaciones
en 0 indicando que el cliente no tiene publicaciones
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
            array[i].cantAvisosActivos=0;
            array[i].cantAvisosPausados=0;
        }
    }
    return retorno;
}

/** \brief carga los datos de un cliente en el array
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \return int retorna -4 si el error esta en el cuit, -3 si esta en el apellido,
 -2 si esta en el nombre, o -1 si esta en otro lado, si no hay error retorna el id del cliente
 *
 */
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
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50\n",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 50\n",nombre,50,2))
                {
                    if(getStringNumeros("\nCUIT? ",cuit))
                    {
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].apellido,apellido);
                        strcpy(array[i].cuit,cuit);
                        array[i].idCliente = proximoId();
                        array[i].estado = 0;
                        retorno = array[i].idCliente;
                    }
                    else
                    {
                        retorno = -4;
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
        }
    }
    return retorno;
}

/** \brief borra los datos del cliente
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \param id int recibe el id del cliente
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int cliente_baja(ECliente array[],int limite,int id)
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

/** \brief borra los datos del cliente
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \param id int recibe el id del cliente
 * \return int retorna -4 si el error esta en el cuit, -3 si esta en el apellido,
 -2 si esta en el nombre, o -1 si esta en otro lado, si no hay error retorna el id del cliente
 *
 */
int cliente_modificacion(ECliente array[],int limite,int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char apellido[50];
    char cuit[50];

    indiceAModificar = cliente_buscarPorId(array, limite, id);
    if(indiceAModificar>=0)
        {
            if(!getValidString("\nNombre? ","\nEso no es un nombre","El maximo es 50\n",nombre,50,2))
            {
                if(!getValidString("\nApellido? ","\nEso no es un apellido","El maximo es 50\n",nombre,50,2))
                {
                    if(getStringNumeros("\nCUIT? ",cuit))
                    {
                        strcpy(array[indiceAModificar].nombre,nombre);
                        strcpy(array[indiceAModificar].apellido,apellido);
                        strcpy(array[indiceAModificar].cuit,cuit);
                        retorno = 0;
                    }
                    else
                    {
                        retorno = -4;
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
        }
    return retorno;
}

/** \brief inicializa al array de estrucutras en 1, indicando que estan vacios
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \return int retorna -1 si hay error, o el indice del lugar libre si no hay error
 *
 */
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

/** \brief calcula el proximo id
 *
 * \return int retorna el id siguiente
 *
 */
static int proximoId()
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}

/** \brief busca un cliente que coincida con el id que recibe
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \param id int recibe el id que tiene que buscar
 * \return int retorna -2 si no encuentra el id, -1 si no pudo recorrer el array,
  o la posicion que ocupa el id buscado
 *
 */
int cliente_buscarPorId(ECliente array[],int limite,int id)
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

/** \brief fuerza la carga de datos del cliente
 *
 * \param array[] ECliente accede a los datos del array
 * \param limite int recibe el largo del array
 * \param nombre[] char recibe el nombre del cliente
 * \param apellido[] char recibe el apellido del cliente
 * \param cuit[] char recibe el apellido del cliente
 * \return int retorna -1 si hay error, 0 si no lo hay
 *
 */
int cliente_altaForzada(ECliente array[],int limite,char nombre[],char apellido[],char cuit[])
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




