#include "Lista.h"
#include "Metodos.h"
#include <string>

Lista::Lista()
{
    this->Inicio = 0;
    this->Fin = 0;
    this->Cant = 0;
    this->Sig = 0;
}

void Lista::NuevoObje(int proy, int nivel, int id, string nombre, string letra, string color, int posX, int posY)
{
    Nodo *Nuevo = new Nodo(proy, nivel, id, nombre, letra, color, posX, posY);
    if(this->Inicio == 0)
    {
        this->Inicio = Nuevo;
        this->Fin = Nuevo;
    }
    else
    {
        this->Fin->Siguiente = Nuevo;
        this->Fin = Nuevo;
    }
    Cant++;
}

Nodo* Lista::getInicio()
{
    return this->Inicio;
}

string Lista::Recorrer()
{
    Metodos metodo;
    string dot;
    int x, y;
    Nodo *aux = this->Inicio;
    while (aux != 0)
    {
        x = aux->Objeto->getPosX();
        y = aux->Objeto->getPosY();
        dot += metodo.ConvtirIntString(x +1) + metodo.ConvtirIntString(y+1) + " [style = filled, fillcolor=\"" + aux->Objeto->getColor() + "\", shape = circle, height = 0.5  fixedsize=true label = \"" + aux->Objeto->getLetra() + "\",pos=\"" + metodo.ConvtirIntString(x +1) + ",-" + metodo.ConvtirIntString(y +1) + "!\"] \n";
        aux = aux->Siguiente;
    }
    return dot;
}

bool Lista::BuscarProy(int proy)
{
    Nodo *aux = this->Inicio;
    while (aux != 0)
    {
        if (aux->Objeto->getNivel() == proy)
        {
            return true;
        }
    }
}

bool Lista::BuscarNivel(int proy, int nivel)
{
    Nodo *aux = this->Inicio;
    while (aux != 0)
    {
        if ((aux->Objeto->getNivel() == proy) & (aux->Objeto->getNivel() == nivel))
        {
            return true;
        }
    }
}

string Lista::EliminarObjeto(int proy, int nivel, int idO)
{
    Metodos metodo;
    string dotObj;
    int x, y;
    Nodo *aux = this->Inicio;
    while (aux != 0)
    {
        if ((aux->Objeto->getNivel() == proy) & (aux->Objeto->getNivel() == nivel))
        {
            if(aux->Objeto->getId() != idO)
            {
                x = aux->Objeto->getPosX();
                y = aux->Objeto->getPosY();
                dotObj += metodo.ConvtirIntString(x +1) + metodo.ConvtirIntString(y+1) + " [style = filled, fillcolor=\"" + aux->Objeto->getColor() + "\", shape = circle, height = 0.5  fixedsize=true label = \"" + aux->Objeto->getLetra() + "\",pos=\"" + metodo.ConvtirIntString(x +1) + ",-" + metodo.ConvtirIntString(y +1) + "!\"] \n";
                aux = aux->Siguiente;
            }

        }
    }
    return dotObj;
}


int Lista::Vacia()
{
    return Cant;
}
