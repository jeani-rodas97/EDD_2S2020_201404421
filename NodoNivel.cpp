#include "NodoNivel.h"
#include "Lista.h"

/*NodoNivel::NodoNivel()
{
    this->Sig = 0;
    this->Ant = 0;
}*/

NodoNivel::NodoNivel(int Proy, int Nivel, Lista *obj)
{
    this->proy = Proy;
    this->nivel = Nivel;
    this->ListaNivel = obj;
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

Lista* NodoNivel::getLista()
{
    return this->ListaNivel;
}
