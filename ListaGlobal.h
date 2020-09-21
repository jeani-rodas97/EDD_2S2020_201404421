#ifndef LISTAGLOBAL_H
#define LISTAGLOBAL_H
#include "NodoLista.h"
#include <string>

class ListaGlobal
{
    public:
        ListaGlobal();
        void NuevaLista(int proy, int nivel, Lista Nuevo);
        string EliminarObj(int Proy, int Nivel, int Id);

    protected:

    private:
        NodoLista *Root;
        NodoLista *Last;
};

#endif // LISTAGLOBAL_H
