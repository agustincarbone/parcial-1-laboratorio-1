#include <stdio.h>
#include <stdlib.h>
#include "fCliente.h"
#include "fGets.h"
#include "publicacion.h"
#define size_cliente 7
#define size_publicacion 15

int main()
{
    ECliente cliente[size_cliente];
    int auxId;
    int menuCliente=0;

    EPublicacion publicacion[size_publicacion];
    int menuPublicacion=0;
    int auxIdPublic;

    cliente_init(cliente,size_cliente);

    publicacion_init(publicacion,size_publicacion);


    cliente_altaForzada(cliente,size_cliente,"carlos","perez","22355");
    cliente_altaForzada(cliente,size_cliente,"pedro","gonzales","45656");
    cliente_altaForzada(cliente,size_cliente,"diego","gomez","25887");
    cliente_altaForzada(cliente,size_cliente,"roberto","hernandez","86567");
    cliente_altaForzada(cliente,size_cliente,"tito","mendez","786867");
    cliente_altaForzada(cliente,size_cliente,"juan","domingo","786968");

    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,0,"video.avi","20911911915",100);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,0,"video1.avi","20911911915",400);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,0,"video2.avi","30911911915",300);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,2,"video3.avi","30911911915",400);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,2,"video4.avi","40911911915",500);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,2,"video5.avi","40911911915",600);

    cliente_mostrar(cliente,size_cliente);

    do
    {
        menuCliente=0;
        getValidInt("\n\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n\n\n","\nNo valida\n",&menuCliente,1,11,1);
        switch(menuCliente)
        {
            case 1:
                printf("ID: %d",cliente_alta(cliente,size_cliente));
                break;
            case 2:
                getValidInt(" DNI? ","\n Numero invalido\n",&auxId,0,999999999,2);
                cliente_baja(cliente,size_cliente,auxId);
                break;
            case 3:
                getValidInt("ID?","\nID invalido\n",&auxId,0,200,2);
                cliente_modificacion(cliente,size_cliente,auxId);
                break;
            case 4:
                cliente_mostrar(cliente,size_cliente);
                break;
        }
    }while(menuCliente != 5);

    do
    {
        menuPublicacion=0;

        getValidInt("\nContrataciones:\n\n1.Alta\n2.Baja\n3.Mostrar\n9.Salir\n","\nNo valida\n",&menuPublicacion,1,9,1);
       switch(menuPublicacion)
       {
            case 1:
                publicacion_alta(publicacion,size_publicacion,cliente,size_cliente);
                break;
            case 2:
                getValidInt("ID?","\nNumero invalido\n",&auxIdPublic,0,200,2);
                publicacion_pausa(publicacion,size_publicacion,auxIdPublic);
                break;
            case 4:
                publicacion_mostrar(publicacion,size_publicacion);
                break;

        }
    }while(menuPublicacion != 9);
    return 0;
}
