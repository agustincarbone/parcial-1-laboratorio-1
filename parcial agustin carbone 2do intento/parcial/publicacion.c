#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicacion.h"
#include "fGets.h"
#include "fCliente.h"

static int proximoId(void);
static int buscarLugarLibre(EPublicacion publicacion[], int limite);

/** \brief inicializa el estado de la publicacion en 1 indicando que esta vacia y la pausa en 0 indicando que no esta en pausa
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int publicacion_init(EPublicacion publicacion[], int limite)
{
    int retorno=-1;
    int i;

    if(limite>0 && publicacion!=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            publicacion[i].estado=1;
            publicacion[i].pausa=1;
        }
    }
    return retorno;
}

/** \brief carga los datos de la publicacion en el array
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \param arrayCliente[] ECliente
 * \param lenCliente int
 * \return int retorna -3 si el cuit ingresado no pertenece a un cliente registrado, -2 si no hay un lugar libre,
 -1 para otro error, si no hay error retorna la id de la publicacion
 *
 */
int publicacion_alta(EPublicacion publicacion[], int limite, ECliente arrayCliente[],int lenCliente)
{
    int retorno=-1;
    int i,j;
    int auxRubro;
    char auxTexto[64];
    char auxCuit[12];


    if(limite>0 && publicacion!=NULL)
    {
        i=buscarLugarLibre(publicacion,limite);

        if(i>=0)
        {
            getStringNumeros("CUIT? ",auxCuit);

            for(j=0;j<lenCliente;j++)
            {
                if(auxCuit==arrayCliente[j].cuit)
                {
                    getValidInt("\nnumero rubro?\n","numero no valido\n",&auxRubro,0,99,2);
                    getValidString("\n texto del aviso\n","no es un mensaje valido\n","el mensaje supera el maximo de caracteres(64)\n",
                                   auxTexto,64,2);

                    publicacion[i].numeroRubro = auxRubro;
                    strcpy(publicacion[i].cuitCliente,auxCuit);
                    strcpy(publicacion[i].textoAviso,auxTexto);
                    publicacion[i].estado = 0;
                    publicacion[i].pausa=0;
                    publicacion[i].idPublicacion = proximoId();
                    retorno = publicacion[i].idPublicacion;
                    break;
                }else
                {
                    retorno=-3;
                }
            }
        }else
        {
            retorno=-2;
        }
    }
    return retorno;
}

/** \brief borra la publicaion
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \param cuitCliente[12] char
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int publicacion_baja(EPublicacion publicacion[], int limite, char cuitCliente[12])
{
    int indiceAEliminar;
    int i;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        indiceAEliminar = publicacion_buscarPorCuit(publicacion,limite,cuitCliente);
        if(indiceAEliminar>=0)
        {
            publicacion[indiceAEliminar].estado=1;
            retorno=0;
        }else
        {
            break;
        }
    }
    return retorno;
}

/** \brief muestra los datos de la publicacion
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int publicacion_mostrar(EPublicacion publicacion[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && publicacion != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!publicacion[i].estado && !publicacion[i].pausa)
                printf("\n id: %d - aviso: %s -  vacio: %d - pausa: %d - numero rubro: %d - cuit cliente: %s\n",publicacion[i].idPublicacion, publicacion[i].textoAviso,
                        publicacion[i].estado,publicacion[i].pausa, publicacion[i].numeroRubro,publicacion[i].cuitCliente);
        }
    }
    return retorno;
}

/** \brief busca un lugar libre en el arrayy donde cargar los datos
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \return int retorna -1 si hay error, si no, retorna el indice del lugar libre
 *
 */
int buscarLugarLibre(EPublicacion publicacion[], int limite)
{
    int retorno=-1;
        int i;

        if(limite>0 && publicacion!=NULL)
        {
            retorno=0;
            for(i=0;i<limite;i++)
            {
                if(publicacion[i].estado==1)
                {
                    retorno=i;
                    break;
                }
            }
        }
    return retorno;
}

/** \brief busca el cuit ingresado
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \param cuit[12] char
 * \return int retorna -1 si hay error, si no, retorna el indice del cuit ingresado
 *
 */
int publicacion_buscarPorCuit(EPublicacion publicacion[],int limite,char cuit[12])
{
    int retorno = -1;
    int i;

    if(limite > 0 && publicacion != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!publicacion[i].estado && !strcmp(publicacion[i].cuitCliente,cuit))
            {
                retorno=i;
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
static int proximoId(void)
{
    static int proximoId=-1;
    proximoId++;
    return proximoId;
}


/** \brief fuerza la carga de datos de la publicacion
 *
 * \param publicacion[] EPublicacion accede a los datos del array de la publicacion
 * \param limite int recibe el largo del array de la publicacion
 * \param arrayC[] ECliente accede a los datos del array del cliente
 * \param limiteC int recibe el largo del array del cliente
 * \param cuitCliente[] char recibe el CUIT del cliente
 * \param numeroRubro int recibe el numero del rubro de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int publicacion_altaForzada(EPublicacion publicacion[],int limite,ECliente arrayClientes[],int lenClientes,char cuitCliente[],
                            int numeroRubro)
{
    int retorno = -1;
    int i,j;
    if(limite > 0 && publicacion != NULL)
    {
        i = buscarLugarLibre(publicacion,limite);
        if(i >= 0)
        {
            for(j=0;j<lenClientes;j++)
            {
                if(cuitCliente>=0)
                {
                    publicacion[i].numeroRubro = numeroRubro;
                    strcpy(publicacion[i].cuitCliente,cuitCliente);
                    publicacion[i].estado = 0;
                    publicacion[i].pausa=0;
                    publicacion[i].idPublicacion = proximoId();
                    retorno = publicacion[i].idPublicacion;
                    break;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

/** \brief cuenta la cantidad de publicaciones activas
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \param cuitCliente[12] char
 * \return int retorna -1 si hay error, retorna el acumulador si no hay error
 *
 */
int publicacion_contadorAvisosAct(EPublicacion publicacion[],int limite,char cuitCliente[12])
{
    int i;
    int retorno=-1;
    int acumuladorAvisos=0;

    if(limite > 0 && publicacion != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!strcmp(cuitCliente,publicacion[i].cuitCliente) && !publicacion[i].estado && !publicacion[i].pausa)
            {
                acumuladorAvisos++;
            }
        }
        retorno=acumuladorAvisos;
    }
    return retorno;
}

/** \brief cuenta la cantidad de publicaciones pausadas
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \param cuitCliente[12] char
 * \return int retorna -1 si hay error, retorna el acumulador si no hay error
 *
 */
int publicacion_contadorAvisosPausados(EPublicacion publicacion[],int limite,char cuitCliente[12])
{
    int i;
    int retorno=-1;
    int acumuladorAvisos=0;

    if(limite > 0 && publicacion != NULL)
    {
        for(i=0;i<limite;i++)
        {
            if(!strcmp(cuitCliente,publicacion[i].cuitCliente) && !publicacion[i].estado && publicacion[i].pausa)
            {
                acumuladorAvisos++;
            }
        }
        retorno=acumuladorAvisos;
    }
    return retorno;
}


/** \brief muestra los datos del cliente
 *
 * \param arrayC[] ECliente accede a los datos del array del cliente
 * \param limiteC int recibe el largo del array del cliente
 * \param arrayP[] EPublicacion accede a los datos del array de la publicacion
 * \param limiteP int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int publicacion_mostrarCliente(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP)
{
    int retorno = -1;
    int i;

    if(limiteC > 0 && arrayC != NULL)
    {
        retorno = 0;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].estado)
            {
                arrayC[i].cantAvisosActivos=publicacion_contadorAvisosAct(arrayP,limiteP,arrayC[i].cuit);
                printf("ID: %d - nombre: %s - apellido: %s - CUIT: %s - estado: %d - avisos activos: %d \n",arrayC[i].idCliente,
                    arrayC[i].nombre,arrayC[i].apellido,arrayC[i].cuit,arrayC[i].estado,arrayC[i].cantAvisosActivos);
            }

        }
    }
    return retorno;
}

/** \brief pausa o reanuda una publicacion
 *
 * \param publicacion[] EPublicacion accede a los datos del array
 * \param limite int recibe el largo del array
 * \param id int recibe el id de la publicacion a pausar o renaudar
 * \param opcion int recibe un numero, 1 para pausar, 0 para reanudar
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int publicacion_pausarReanudar(EPublicacion publicacion[],int limite,int id, int opcion)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if((id==publicacion[i].idPublicacion) && opcion)
        {
            publicacion[i].pausa=1;
            retorno=0;
            break;
        }else if((id==publicacion[i].idPublicacion) && !opcion)
        {
            publicacion[i].pausa=0;
            retorno=0;
            break;
        }
    }
    return retorno;
}



