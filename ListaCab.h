#ifndef LISTACAB_H
#define LISTACAB_H
#include "NodoMDisp.h"


class ListaCab
{
    public:
        ListaCab();
        bool EsMayor(int i1, int i2);
        void InsertarEnmedio(NodoMDisp *nuevo);
        void Insertar(int indice);
        NodoMDisp *Encontrar(int indice);

    protected:

    private:
        NodoMDisp *inicio;
        NodoMDisp *ultimo;
};

#endif // LISTACAB_H
