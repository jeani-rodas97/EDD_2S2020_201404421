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
        NodoAVL *InsertarEnAVL(NodoAVL *raiz, int Valor, bool &AlturaEsMayor);



    protected:

    private:
        NodoAVL *Raiz;
        NodoAVL *RotDerIzq(NodoAVL *a, NodoAVL *b);
        NodoAVL *RotDerDer(NodoAVL *a, NodoAVL *b);
        NodoAVL *RotIzqDer(NodoAVL *a, NodoAVL *b);
        NodoAVL *RotIzqIzq(NodoAVL *a, NodoAVL *b);

};

#endif // ARBOLAVL_H
