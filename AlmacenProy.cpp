#include "AlmacenProy.h"
#include "Proyecto.h"

AlmacenProy::AlmacenProy()
{
    this->Inicio = 0; //new Proyecto();
    this->CantProy = 0;
}

int AlmacenProy::getCant()
{
    return this->CantProy;
}

int AlmacenProy::MostrarProy()
{
    Proyecto *Aux = this->Inicio;
    while(Aux != 0 )
    {
        return Aux->getProy();
        Aux = Aux->Sig;
    }
}

void AlmacenProy::NuevoProy(int proy, ListaGlobal *Niv)
{
    Proyecto *Nuevo = new Proyecto(proy, Niv);

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
    CantProy++;
}

bool AlmacenProy::ExisteProy(int proy)
{
    if(!Vacia())
    {
        Proyecto *aux = this->Inicio->Sig;
        while (aux != this->Inicio)
        {
            if(aux->getProy() == proy)
            {
                return true;
            }
            aux = aux->Sig;
        }
        return false;
    }
    else
        return false;
}

Proyecto* AlmacenProy::BuscarProy(int proy)
{
    if(ExisteProy(proy))
    {
        Proyecto *aux = this->Inicio->Sig;
        while(aux != this->Inicio)
        {
            if(aux->getProy() == proy)
            {
                return aux;
            }
            aux = aux->Sig;
        }
    }
    else
        return 0;
}
///METODOS PRIVADOS
bool AlmacenProy::Vacia()
{
    if(this->CantProy == 0)
        return true;
    else
        return false;
}
