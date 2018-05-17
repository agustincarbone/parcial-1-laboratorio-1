#ifndef FGETS_H_INCLUDED
#define FGETS_H_INCLUDED

int getValidInt(char requestMessage[],char errorMessage[], int* input,int lowLimit, int hiLimit,int attemps);
int getStringNumeros(char mensaje[],char input[]);
int esNumerico(char str[]);
int getValidString(char requestMessage[],char errorMessage[], char errorMessageLenght[],char input[], int maxLenght,int attemps);
int getStringLetras(char mensaje[],char input[]);
int esSoloLetras(char str[]);
void getString(char mensaje[],char input[]);
void clearStdin(void);


#endif // FGETS_H_INCLUDED
