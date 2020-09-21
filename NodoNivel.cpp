#include "NodoNivel.h"

NodoNivel::NodoNivel(int Proy, int Nivel)
{
    this->proy = Proy;
    this->nivel = Nivel;
    this->Sig = 0;
    this->Ant = 0;
}

int NodoNivel::getProy()
{
    return this->proy;
}

int NodoNivel::getNivel()
{
    return this->nivel;
}
