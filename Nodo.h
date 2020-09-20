#ifndef NODO_H
#define NODO_H
#include "ObjABB.h"
#include <string>

using namespace std;


class Nodo
{
    public:
        Nodo(int proy, int nivel, int id, string nombre, string letra, string color, int posX, int posY);

        ObjABB *Objeto;
        Nodo *Siguiente;

    protected:

    private:
};

#endif // NODO_H
