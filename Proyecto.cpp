#include "Proyecto.h"

/*Proyecto::Proyecto()
{
    this->Sig = 0;
    this->Ant = 0;
}*/

Proyecto::Proyecto(int Proy, ListaGlobal *niv)
{
    this->proy = Proy;
    this->Niveles = niv;
    this->Sig = 0;
    this->Ant = 0;
}

int Proyecto::getProy()
{
    return this->proy;
}


ListaGlobal* Proyecto::getListaNiv()
{
    return this->Niveles;
}
