#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED

typedef struct
{
    int idCliente;
    int numeroRubro;
    char textoAviso[64];
    int idPublicacion;
    int estado;
}EPublicacion;

int publicacion_init(EPublicacion* arrayPublic, int limite);
int publicacion_alta(EPublicacion* arrayPublic, int limite,ECliente* arrayCliente,int lenPantalla);
int publicacion_mostrar(EPublicacion* arrayPublic,int limite);
int publicacion_buscarPorId(EPublicacion* arrayPublic,int limite,int id);


#endif // PUBLICACION_H_INCLUDED
