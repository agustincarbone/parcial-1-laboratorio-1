#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fCliente.h"
#include "fGets.h"
#include "publicacion.h"

/** \brief calcula cual es la mayor cantidad de avisos activos que posee un cliente
 *
 * \param arrayC[] ECliente accede a los datos del array del cliente
 * \param limiteC int recibe el largo del array del cliente
 * \param arrayP[] EPublicacion accede a los datos del array de la publicacion
 * \param limiteP int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_masAvisosAct(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP)
{
    int i;
    int max=0;

    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].estado)
        {
            arrayC[i].cantAvisosActivos=publicacion_contadorAvisosAct(arrayP,limiteP,arrayC[i].cuit);
        }
    }

    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].estado &&  arrayC[i].cantAvisosActivos>max)
        {
            max=arrayC[i].cantAvisosActivos;
        }
    }
    return max;
}

/** \brief calcula cual es la mayor cantidad de avisos pausados que posee un cliente
 *
 * \param arrayC[] ECliente accede a los datos del array del cliente
 * \param limiteC int recibe el largo del array del cliente
 * \param arrayP[] EPublicacion accede a los datos del array de la publicacion
 * \param limiteP int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_masAvisosPausados(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP)
{
    int i;
    int max=0;

    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].estado)
        {
            arrayC[i].cantAvisosPausados=publicacion_contadorAvisosPausados(arrayP,limiteP,arrayC[i].cuit);
        }
    }

    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].estado &&  arrayC[i].cantAvisosPausados>max)
        {
            max=arrayC[i].cantAvisosPausados;
        }
    }
    return max;
}

/** \brief calcula cual es la mayor cantidad de avisos que posee un cliente
 *
 * \param arrayC[] ECliente accede a los datos del array del cliente
 * \param limiteC int recibe el largo del array del cliente
 * \param arrayP[] EPublicacion accede a los datos del array de la publicacion
 * \param limiteP int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_CantAvisosTotal(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP)
{
    int i;
    int maxActivos=0;
    int maxPausados=0;
    int maxtotal;

    for(i=0;i<limiteC;i++)
    {
        if(!arrayC[i].estado)
        {
            arrayC[i].cantAvisosPausados=publicacion_contadorAvisosPausados(arrayP,limiteP,arrayC[i].cuit);
            arrayC[i].cantAvisosActivos=publicacion_contadorAvisosAct(arrayP,limiteP,arrayC[i].cuit);
        }
    }

    for(i=0;i<limiteC;i++)
    {
        if((arrayC[i].cantAvisosActivos+arrayC[i].cantAvisosPausados) > (maxPausados+maxActivos))
        {
            maxActivos=arrayC[i].cantAvisosActivos;
            maxPausados=arrayC[i].cantAvisosPausados;
        }
    }
    maxtotal=maxActivos+maxPausados;
    return maxtotal;
}

/** \brief informa cuales son los clientes que tienen la maxima cantidad de avisos activos, pausados, y en total
 *
 * \param arrayC[] ECliente accede a los datos del array del cliente
 * \param limiteC int recibe el largo del array del cliente
 * \param arrayP[] EPublicacion accede a los datos del array de la publicacion
 * \param limiteP int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_informarCliente(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP)
{
    int retorno=-1;
    int auxAct;
    int auxPaus;
    int auxTotal;
    int i;

    if((limiteC > 0 && arrayC != NULL) && (limiteP > 0 && arrayP != NULL))
    {
        auxAct=informes_masAvisosAct(arrayC,limiteC,arrayP,limiteP);
        auxPaus=informes_masAvisosPausados(arrayC,limiteC,arrayP,limiteP);
        auxTotal=informes_CantAvisosTotal(arrayC,limiteC,arrayP,limiteP);

        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].estado && arrayC[i].cantAvisosActivos==auxAct)
            {
                printf("\ncliente con mayor cant. de avisos activos: %s %s id: %d cuit: %s\n",arrayC[i].nombre,arrayC[i].apellido,arrayC[i].idCliente,arrayC[i].cuit);
            }
        }

        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].estado && arrayC[i].cantAvisosPausados==auxPaus)
            {
                printf("\ncliente con mayor cant. de avisos pausados: %s %s id: %d cuit: %s\n",arrayC[i].nombre,arrayC[i].apellido,arrayC[i].idCliente,arrayC[i].cuit);
            }
        }

        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].estado && (arrayC[i].cantAvisosActivos+arrayC[i].cantAvisosPausados)==auxTotal)
            {
                printf("\ncliente con mayor cant. de avisos : %s %s id: %d cuit: %s\n",arrayC[i].nombre,arrayC[i].apellido,arrayC[i].idCliente,arrayC[i].cuit);
            }
        }
    }
    return retorno;
}

/** \brief calcula la cantidad de publicaciones activas de un mismo rubro
 *
 * \param array[] EPublicacion accede a los datos del array de la publicacion
 * \param limite int recibe el largo del array de la publicacion
 * \param numRubro int recibe el numero de rubro ingresado
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_cantidadPubMismoRubro(EPublicacion array[],int limite,int numRubro)
{
    int retorno=-1;
    int i;
    int cantMismoRubro=0;

    if(limite>0 && array!=NULL)
    {
        for(i=0;i<limite;i++)
       {
           if(!array[i].estado && !array[i].pausa && (array[i].numeroRubro==numRubro))
           {
               cantMismoRubro++;
           }
       }
       retorno=cantMismoRubro;
    }
    return retorno;
}

/** \brief calcula el rubro con mas publicaciones activas
 *
 * \param array[] EPublicacion accede a los datos del array de la publicacion
 * \param limite int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_rubroMasActivas(EPublicacion array[],int limite)
{
    int retorno=-1;
    int i,j;
    char arrayRubro[100];
    int max=0;
    int auxRubro;

    for(j=0;j<100;j++)
    {
        arrayRubro[j]=0;
    }

    if(limite>0 && array!=NULL)
    {
        for(i=0;i<limite;i++)
        {
           if(!array[i].estado && !array[i].pausa)
           {
               for(j=0;j<100;j++)
               {
                   if(array[i].numeroRubro==j)
                    {
                        arrayRubro[j]++;
                    }
               }
           }
        }
        for(i=0;i<limite;i++)
        {
            if(arrayRubro[i]>max)
            {
                max=arrayRubro[i];
                auxRubro=i;
            }
        }
        retorno=i;
    }
    return retorno;
}

/** \brief calcula el rubro con menos publicaciones activas
 *
 * \param array[] EPublicacion accede a los datos del array de la publicacion
 * \param limite int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_rubroMenosActivas(EPublicacion array[],int limite)
{
    int retorno=-1;
    int i,j;
    char arrayRubro[100];
    int min=1000;
    int auxRubro;

    for(j=0;j<100;j++)
    {
        arrayRubro[j]=0;
    }

    if(limite>0 && array!=NULL)
    {
        for(i=0;i<limite;i++)
        {
           if(!array[i].estado && !array[i].pausa)
           {
               for(j=0;j<100;j++)
               {
                   if(array[i].numeroRubro==j)
                    {
                        arrayRubro[j]++;
                    }
               }
           }
        }
        for(i=0;i<limite;i++)
        {
            if(arrayRubro[i]<min)
            {
                min=arrayRubro[i];
                auxRubro=i;
            }
        }
        retorno=i;
    }
    return retorno;
}

/** \brief informa datos sobre los rubros
 *
 * \param array[] EPublicacion accede a los datos del array de la publicacion
 * \param limite int recibe el largo del array de la publicacion
 * \return int retorna -1 si hay error, 0 si no hay
 *
 */
int informes_informarPublicacion(EPublicacion array[],int limite)
{
    int numRubro=-1;
    int auxMasAct;
    int cantRubroAct;
    int auxMenosAct;

    getValidInt("\nIngrese un numero de rubro\n","rubro no valido\n",&numRubro,0,99,2);
    cantRubroAct=informes_cantidadPubMismoRubro(array,limite,numRubro);
    auxMasAct=informes_rubroMasActivas(array,limite);
    auxMenosAct=informes_rubroMenosActivas(array,limite);

    printf("\nPublicaciones activas del rubro introducido: %d\n",cantRubroAct);
    printf("\nRubro con mas publicaciones activas: %d\n",auxMasAct);
    printf("\nRubro con menos publicaciones activas: %d\n",auxMenosAct);
    return 0;
}




