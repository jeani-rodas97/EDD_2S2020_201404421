#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Lista.h"


class NodoLista
{
    public:
        NodoLista(int Proy, int Nivel);

    protected:

    private:
        int Proy;
        int Nivel;
        NodoLista *Siguiente;
        Lista *ListaNivel;
};

#endif // NODOLISTA_H
