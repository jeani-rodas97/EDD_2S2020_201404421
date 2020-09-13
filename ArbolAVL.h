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
        NodoAVL *InsertarEnAVL(NodoAVL *raiz, int Valor, bool &AlturaMayor);



    protected:

    private:
        NodoAVL *Raiz;
        NodoAVL *RotDerIzq(NodoAVL *Padre, NodoAVL *Hijo);
        NodoAVL *RotDerDer(NodoAVL *Padre, NodoAVL *Hijo);
        NodoAVL *RotIzqDer(NodoAVL *Padre, NodoAVL *Hijo);
        NodoAVL *RotIzqIzq(NodoAVL *Padre, NodoAVL *Hijo);

};

#endif // ARBOLAVL_H
