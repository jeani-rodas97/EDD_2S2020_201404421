#include "NodoLista.h"

NodoLista::NodoLista(int Proy)
{
    this->Proy = Proy;
    this->Siguiente = 0;
    this->ListaNivel = new Lista();
}

