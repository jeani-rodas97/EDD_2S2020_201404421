#include "Nodo.h"
#include "ObjABB.h"
#include <string>

Nodo::Nodo(int proy, int nivel, int id, string nombre, string letra, string color, int posX, int posY)
{
    this->Objeto = new ObjABB(proy, nivel, id, nombre, letra, color, posX, posY);
    this->Siguiente = 0;
}
