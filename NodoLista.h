#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Lista.h"


class NodoLista
{
    public:
        NodoLista(int Proy);
        void NuevoNivel(int Nivel, Lista *Niv);
        Lista *ListaNivel;
    protected:

    private:
        int Proy;
        int Nivel;
        NodoLista *Siguiente;

};

#endif // NODOLISTA_H
