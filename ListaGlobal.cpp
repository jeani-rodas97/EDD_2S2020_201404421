#include "ListaGlobal.h"
#include "Lista.h"

ListaGlobal::ListaGlobal()
{

}

void ListaGlobal::NuevoNivel(int proy, int nivel)
{
    this->proy = proy;
    this->nivel = nivel;
    this->Cant = 0;
}
