#include "NodoAVL.h"

NodoAVL::NodoAVL(int Info)
{
    this->Info = Info;
    this->HijoDerecho = 0;
    this->HijoIzquierdo = 0;
    this->FactorEquilibrio = 0;

}

int NodoAVL::getInfo()
{
    return Info;
}

NodoAVL* NodoAVL::getRamaIzq()
{
    return this->HijoIzquierdo;
}

NodoAVL* NodoAVL::getRamaDer()
{
    return this->HijoDerecho;
}

int NodoAVL::getFactorEquilibrio()
{
    return this->FactorEquilibrio;
}

//setters
void NodoAVL::setRamaIzq(NodoAVL *n)
{
    this->HijoIzquierdo = n;
}

void NodoAVL::setRamaDer(NodoAVL *n)
{
    this->HijoDerecho = n;
}

void NodoAVL::setFactorEquilibrio(int Valor)
{
    this->FactorEquilibrio = Valor;
}
