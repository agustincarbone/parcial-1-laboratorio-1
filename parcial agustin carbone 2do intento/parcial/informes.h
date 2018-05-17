#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informes_masAvisosAct(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP);
int informes_masAvisosPausados(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP);
int informes_CantAvisosTotal(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP);
int informes_informarCliente(ECliente arrayC[],int limiteC,EPublicacion arrayP[],int limiteP);
int informes_cantidadPubMismoRubro(EPublicacion array[],int limete,int numRubro);
int informes_rubroMasActivas(EPublicacion array[],int limete,int numRubro);
int informes_rubroMenosActivas(EPublicacion array[],int limite);
int informes_informarPublicacion(EPublicacion array[],int limite);

#endif // INFORMES_H_INCLUDED
