#include "ListaGlobal.h"
#include "Lista.h"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

ListaGlobal::ListaGlobal()
{

}

void ListaGlobal::NuevoNivel(int proy, int nivel)
{
    NodoNivel *Nuevo = new NodoNivel(proy, nivel);
    if (this->Inicio = 0)
    {
        this->Inicio = Nuevo;
        this->Final = Nuevo;
    }
    else
    {
        this->Final->Sig = Nuevo;
        Nuevo->Ant = this->Final;
        Final = Nuevo;
    }
}

void ListaGlobal::MostrarNivel(int proy)
{
    NodoNivel *Aux = this->Inicio;
    while(Aux != 0 )
    {
        if (Aux->getProy() == proy)
        {
            cout << Aux->getNivel() << endl;
        }
        Aux = Aux->Sig;
    }
}
