#include "ListaGlobal.h"
#include "Lista.h"

ListaGlobal::ListaGlobal()
{
    this->Root = 0;
    this->Last = 0;
}

void ListaGlobal::NuevaLista(int proy, int nivel, Lista Nuevo)
{
    if(this->Root == 0)
    {
        this->Root = new NodoLista(proy);
        this->Last = new NodoLista(proy);
    }
}

string ListaGlobal::EliminarObj(int Proy, int Nivel, int Id)
{
    string graf;
    graf = this->Root->ListaNivel->EliminarObjeto(Proy, Nivel, Id);
}
