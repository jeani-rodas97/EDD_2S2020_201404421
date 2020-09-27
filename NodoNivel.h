#ifndef NODONIVEL_H
#define NODONIVEL_H
#include "Lista.h"

class NodoNivel
{
    public:
        NodoNivel();
        NodoNivel(int Proy, int Nivel, Lista *obj);
        int getProy();
        int getNivel();
        Lista* getLista();
        NodoNivel *Sig;
        NodoNivel *Ant;
        int CantNivel;
        Lista *ListaNivel;
        int proy, nivel;

    protected:

    private:

};

#endif // NODONIVEL_H
