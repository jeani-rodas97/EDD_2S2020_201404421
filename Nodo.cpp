#include "Nodo.h"
#include "ObjABB.h"

Nodo::Nodo(ObjABB *Objeto)
{
    this->Objeto = Objeto;
    this->Siguiente = 0;
}
