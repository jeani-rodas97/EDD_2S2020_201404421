#include "NodoLista.h"

NodoLista::NodoLista(int Proy, int Nivel)
{
    this->Nivel = Nivel;
    this->Proy = Proy;
    this->Siguiente = 0;
    this->ListaNivel = new Lista();
}


