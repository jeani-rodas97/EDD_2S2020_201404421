#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoAVL.h"
#include <iostream>
#include <string>

using namespace std;


class ArbolAVL
{
    public:
        ArbolAVL();
        NodoAVL *getRaiz();
        void setRaiz(NodoAVL *root);
        bool Buscar(int num);
        void NuevoNodo(int numero, string cadena);
        void GraficarArbol(NodoAVL *padre);
        void inorden(NodoAVL *padre);

    protected:

    private:
        NodoAVL *Raiz;
        NodoAVL *InsertarEnAVL(NodoAVL *raiz, int Valor, string Nombre, bool &AlturaEsMayor);
        NodoAVL *RotDerIzq(NodoAVL *a, NodoAVL *b);
        NodoAVL *RotDerDer(NodoAVL *a, NodoAVL *b);
        NodoAVL *RotIzqDer(NodoAVL *a, NodoAVL *b);
        NodoAVL *RotIzqIzq(NodoAVL *a, NodoAVL *b);
        string Recorrer(NodoAVL *padre);
        void orden(NodoAVL *padre);
        int Revisar(NodoAVL *padre);


};

#endif // ARBOLAVL_H
