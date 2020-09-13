#include "ListaCab.h"

ListaCab::ListaCab()
{
    inicio = 0;
    ultimo = 0;
}

bool ListaCab::EsMayor(int i1, int i2)
{
    if(i1 > i2)
    {
        return true;
    }
    return false;
}



void ListaCab::InsertarEnmedio(NodoMDisp *nuevo)
{
    NodoMDisp *temp = inicio;
    while(temp != 0)
    {
        if(EsMayor(nuevo->cabeza, temp->cabeza))
        {
            ///El NC porque es el siguiente Nodo Cabecera
            temp = temp->sigNC;
        }
        else
        {
            if (temp == inicio)
            {
                nuevo->sigNC = temp;
                temp->antNC = nuevo;
                inicio = nuevo;
            }
            else
            {
                ///Manejo de punteros
                nuevo->antNC = temp->antNC;
                temp->antNC->sigNC = nuevo;
                nuevo->sigNC = temp;
                temp->antNC = nuevo;
            }
            return;
        }
    }
    ultimo->sigNC = nuevo;
    nuevo->antNC = ultimo;
    ultimo = nuevo;
}

void ListaCab::Insertar(int indice)
{
    NodoMDisp *nuevo = new NodoMDisp(indice);
    if (inicio == 0)
    {
        inicio = ultimo = nuevo;
    }
    else
    {
        InsertarEnmedio(nuevo);
    }
}

NodoMDisp* ListaCab::Encontrar(int indice)
{
    NodoMDisp *aux = inicio;
    while(aux != 0)
    {
        if(aux->cabeza == indice)
        {
            return aux;
        }
        aux = aux->sigNC;
    }
    return 0;
}

NodoMDisp* ListaCab::getInicio()
{
    return inicio;
}

NodoMDisp* ListaCab::getUltimo()
{
    return ultimo;
}
