#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "publicacion.h"
#include "fGets.h"
#include "fCliente.h"

static int proximoId(void);
static int buscarLugarLibre(EPublicacion* publicacion, int limite);

//funciones privadas de este archivo


/** \brief
 *
 * \param publicacion publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_init(EPublicacion* publicacion, int limite)
{
    int retorno=-1;
    int i;

    if(limite>0 && publicacion!=NULL)
    {
        retorno=0;
        for(i=0;i<limite;i++)
        {
            publicacion[i].estado=1;
        }
    }
    return retorno;
}

/** \brief
 *
 * \param publicacion publicacion*
 * \param limite int
 * \return int
 *
 */
int publicacion_alta(EPublicacion[] publicacion, int limite,ECliente arrayCliente[],int lenCliente)
{
    int retorno=-1;
    int i;
    int idCliente;
    int posCliente;
    //char auxCuit[32];
    //char auxFile[32];
    int auxDias;


    if(limite>0 && publicacion!=NULL)
    {
        i=buscarLugarLibre(publicacion,limite);

        if(i>=0)
        {
            /*getValidString("\nNombre? ","\nEso no es un nombre","\nEl maximo es 40",&auxFile,40,2);
            strcpy(publicacion[i].archivo,auxFile);*/

            getValidInt("ID?","\nNumero invalido\n",&idCliente,0,99999999,2);
            posCliente = pantalla_buscarPorId(arrayCliente,lenCliente,idCliente);

            if(posCliente<=0)
            {
                getValidInt("dias?","\nnumero invalido\n",&auxDias,0,7,2);

                publicacion[i].dias = auxDias;
                publicacion[i].idCliente = idCliente;
                publicacion[i].estado = 0;
                publicacion[i].id = proximoId();
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \param publicacion EPublicacion*
 * \param limite int
 * \return int
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
            if(!publicacion[i].estado)
                printf("[RELEASE] - id: %d - nombre Archivo: %s -  vacio: %d cuit: %s\n",publicacion[i].id, publicacion[i].archivo, publicacion[i].estado, publicacion[i].cuit);
        }
    }
    return retorno;
}

/** \brief
 *
 * \param publicacion EPublicacion*
 * \param limite int
 * \return int
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

/** \brief
 *
 * \return int
 *
 */
int publicacion_buscarPorId(EPublicacion publicacion[],int limite,int id)
{
    int retorno = -1;
    int i;

    if(limite > 0 && publicacion != NULL)
    {
        retorno = -2;
        for(i=0;i<limite;i++)
        {
            if(!publicacion[i].estado && publicacion[i].id==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief
 *
 * \return int
 *
 */
int proximoId(void)
{
    static int proximoId=-1;
    proximoId++;
    return proximoId;
}

int publicacion_altaForzada(EPublicacion publicacion[],int limite,ECliente[] arrayClientes, int lenClientes,int idCliente,char nombre[],char cuit[])
{
    int retorno = -1;
    int i;
    int posCliente;
    if(limite > 0 && publicacion != NULL)
    {
        i = buscarLugarLibre(publicacion,limite);
        if(i >= 0)
        {

            posCliente = cliente_buscarPorId(arrayClientes,lenClientes,idCliente);
            if(posCliente>=0)
            {
                strcpy(publicacion[i].cuit,cuit);
                strcpy(publicacion[i].archivo,archivo);
                publicacion[i].idCliente = idCliente;
                publicacion[i].estado=0;
                publicacion[i]. = proximoId();


                int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int idPublicacion;
    int estado;
            }
        }
        retorno = 0;
    }
    return retorno;
}







