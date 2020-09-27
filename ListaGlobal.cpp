#include "ListaGlobal.h"
#include "NodoNivel.h"

#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>

ListaGlobal::ListaGlobal()
{
    this->Inicio = 0; //new NodoNivel();
    this->CantNivel = 0;
}

void ListaGlobal::NuevoNivel(int proy, int nivel, Lista *obj)
{
    NodoNivel *Nuevo = new NodoNivel(proy, nivel, obj);
    if (this->Inicio == 0)
    {
        this->Inicio = Nuevo;
        this->Final = Nuevo;
    }
    else
    {
        this->Final->Sig = Nuevo;
        this->Final = Nuevo;
    }
    CantNivel++;
}

void ListaGlobal::MostrarNivel(int proy)
{
    NodoNivel *Aux = this->Inicio;
    while(Aux != 0 )
    {
        if (Aux->getProy() == proy)
        {
            cout << Aux->getNivel() << ". Nivel " << Aux->getNivel() << endl;
        }
        Aux = Aux->Sig;
    }
}



int ListaGlobal::RetornarNivel(int proy)
{
    NodoNivel *Aux = this->Inicio;
    while(Aux != 0 )
    {
        if (Aux->getProy() == proy)
        {
            return Aux->getNivel();
        }
        Aux = Aux->Sig;
    }
}

bool ListaGlobal::ExisteNiv(int nivel)
{
    if(!Vacia())
    {
        NodoNivel *aux = this->BuscarNivel(nivel);
    }
}

///METODOS PRIVADOS
bool ListaGlobal::Vacia()
{
    if(this->CantNivel == 0)
        return true;
    else
        return false;
}

NodoNivel* ListaGlobal::BuscarNivel(int nivel)
{
    if(ExisteNiv(nivel))
    {
        NodoNivel *aux = this->Inicio->Sig;
        while(aux != this->Inicio)
        {
            if(aux->getNivel() == nivel)
            {
                return aux;
            }
            aux = aux->Sig;
        }
    }
    else
        return 0;
}
