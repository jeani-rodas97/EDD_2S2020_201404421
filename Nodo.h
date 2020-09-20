#ifndef NODO_H
#define NODO_H
#include "ObjABB.h"


class Nodo
{
    public:
        Nodo(ObjABB *Objeto);

    protected:

    private:
        ObjABB *Objeto;
        Nodo *Siguiente;
};

#endif // NODO_H
