#include <stdio.h>
#include <stdlib.h>
#include "fCliente.h"
#include "fGets.H"
#include "publicacion.h"
#include "informes.h"
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
    char auxCuit[12];
    int opcion;

    cliente_init(cliente,size_cliente);

    publicacion_init(publicacion,size_publicacion);


    cliente_altaForzada(cliente,size_cliente,"carlos","perez","22355");
    cliente_altaForzada(cliente,size_cliente,"pedro","gonzales","45656");
    cliente_altaForzada(cliente,size_cliente,"diego","gomez","25887");
    cliente_altaForzada(cliente,size_cliente,"roberto","hernandez","86567");
    cliente_altaForzada(cliente,size_cliente,"tito","mendez","786867");
    cliente_altaForzada(cliente,size_cliente,"juan","domingo","786968");

    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,"22355",12);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,"45656",5);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,"45656",6);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,"25887",4);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,"86567",8);
    publicacion_altaForzada(publicacion,size_publicacion,cliente,size_cliente,"786968",15);

    publicacion_mostrarCliente(cliente,size_cliente,publicacion,size_publicacion);
    publicacion_mostrar(publicacion,size_publicacion);

    do
    {
        menuCliente=0;
        getValidInt("\n\nCliente:\n1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.informe\n6.salir\n","\nNo valida\n",&menuCliente,1,6,1);
        switch(menuCliente)
        {
            case 1:
                printf("ID: %d",cliente_alta(cliente,size_cliente));
                break;
            case 2:
                getValidInt("ID cliente? ","\n Numero invalido\n",&auxId,0,999999999,2);
                getStringNumeros("CUIT cliente? ",auxCuit);
                cliente_baja(cliente,size_cliente,auxId);
                publicacion_baja(publicacion,size_publicacion,auxCuit);
                break;
            case 3:
                getValidInt("ID? ","\nID invalido\n",&auxId,0,200,2);
                cliente_modificacion(cliente,size_cliente,auxId);
                break;
            case 4:
                publicacion_mostrarCliente(cliente,size_cliente,publicacion,size_publicacion);
                break;
            case 5:
                informes_informarCliente(cliente,size_cliente,publicacion,size_publicacion);
                break;
        }
    }while(menuCliente != 6);

    do
    {
        menuPublicacion=0;
        opcion=-1;

        getValidInt("\nPublicaciones:\n1.Alta\n2.Reanudar o Pausar\n3.Mostrar\n4.informe\n5.Salir\n","\nNo valida\n",&menuPublicacion,1,5,1);
        switch(menuPublicacion)
        {
            case 1:
                printf("ID: %d",publicacion_alta(publicacion,size_publicacion,cliente,size_cliente));
                break;
            case 2:
                getValidInt("ingrese:\n0.reanudar\n1.pausar\n","\nNumero invalido\n",&opcion,0,1,2);
                getValidInt("ID publicacion? ","\nNumero invalido\n",&auxIdPublic,0,99999999,2);
                publicacion_pausarReanudar(publicacion,size_publicacion,auxIdPublic,opcion);
            case 3:
                publicacion_mostrar(publicacion,size_publicacion);
                break;
            case 4:
                informes_informarPublicacion(publicacion,size_publicacion);
                break;
        }
    }while(menuPublicacion != 5);
    return 0;
}
