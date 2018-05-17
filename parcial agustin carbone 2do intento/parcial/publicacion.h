#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
#include "fCliente.h"

typedef struct
{
    char cuitCliente[12];
    int numeroRubro;
    char textoAviso[64];
    int idPublicacion;
    int estado;
    int pausa;
}EPublicacion;

int publicacion_init(EPublicacion publicacion[], int limite);
int publicacion_alta(EPublicacion publicacion[], int limite,ECliente* arrayCliente,int lenPantalla);
int publicacion_mostrar(EPublicacion pbulcicacion[],int limite);
int publicacion_buscarPorCuit(EPublicacion publicacion[],int limite,char cuit[12]);
int publicacion_baja(EPublicacion publicacion[], int limite, char cuitCliente[12]);
int publicacion_altaForzada(EPublicacion publicacion[],int limite,ECliente arrayClientes[],int lenClientes,char cuitCliente[12],
                            int numeroRubro);
int publicacion_mostrarCliente(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP);
int publicacion_contadorAvisosAct(EPublicacion publicacion[], int limite,char cuitCliente[12]);
int publicacion_contadorAvisosPausados(EPublicacion publicacion[],int limite,char cuitCliente[12]);
int publicacion_pausarReanudar(EPublicacion publicacion[],int limite,int id, int opcion)
;

#endif // PUBLICACION_H_INCLUDED
