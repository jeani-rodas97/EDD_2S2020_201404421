#include "NodoAVL.h"

NodoAVL::NodoAVL(int Info, string Nombre)
{
    this->Info = Info;
    this->Nombre = Nombre;
    this->HijoDerecho = 0;
    this->HijoIzquierdo = 0;
    this->FactorEquilibrio = 0;

}

int NodoAVL::getInfo()
{
    return Info;
}

string NodoAVL::getNombre()
{
    return Nombre;
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

void NodoAVL::setInfo(int Info)
{
    this->Info = Info;
}

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
