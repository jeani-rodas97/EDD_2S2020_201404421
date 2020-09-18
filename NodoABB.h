#ifndef NODOABB_H
#define NODOABB_H
#include "ObjABB.h"


class NodoABB
{
    public:
        NodoABB(int Numero, );

    protected:

    private:
        int Numero;
        NodoABB *HijoIzquierdo;
        NodoABB *HijoDerecho;


};

#endif // NODOABB_H
