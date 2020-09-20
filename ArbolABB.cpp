#include "ArbolABB.h"
#include "Metodos.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>

ArbolABB::ArbolABB()
{
    this->Raiz = 0;
}

NodoAVL* ArbolABB::getRaiz()
{
    return this->Raiz;
}

void ArbolABB::setRaiz(NodoAVL *root)
{
    this->Raiz = root;
}

void ArbolABB::NuevoNodo(int numero, string nombre)
{
    this->Raiz = InsertarEnABB(this->getRaiz(), numero, nombre);
}

///Metodos privados

NodoAVL* ArbolABB::InsertarEnABB(NodoAVL *raiz, int Valor, string Nombre)
{
    NodoAVL *aux;
    if(raiz == 0) //Is empty
    {
        raiz = new NodoAVL(Valor, Nombre);
    }
    //El nodo se va al subarbol izquierdo,
    else if (Valor < raiz->getInfo())
    {
        NodoAVL *auxIzq;
        auxIzq = InsertarEnABB(raiz->getRamaIzq(), Valor, Nombre);
        raiz->setRamaIzq(auxIzq);
    }
    //El nodo se va al subarbol derecho por ser mayor
    else if (Valor > raiz->getInfo())
    {
        NodoAVL *auxDer;
        if(raiz)
        auxDer = InsertarEnABB(raiz->getRamaDer(), Valor, Nombre);
        raiz->setRamaDer(auxDer);
    }
    else
    {
        cout << "ERROR " << endl;
    }
    return raiz;

}

void ArbolABB::GraficarArbol(NodoAVL *padre)
{
    string dot;
    dot = "digraph arbolABB{ \n rankdir=TB; \n label = \"ABB\" \n node [shape = circle, style=filled, color=\"#F76B11\", fillcolor= \"#F7C4F5\" ]; \n";
    dot += Recorrer(padre);
    dot += "} \n";

    ofstream grafoABB;
    grafoABB.open("ABB.dot", ios::out);
    grafoABB << dot;
    grafoABB.close();
    system("dot ABB.dot -Tpng -o ABB.png");
}

string ArbolABB::Recorrer(NodoAVL *padre)
{
    Metodos metodo;
    string dot, Padre, Hijo;
    int iPadre, iHijo;
    if((padre->getRamaIzq() == 0) && (padre->getRamaDer() == 0))
    {
        Padre = metodo.ConvtirIntString(padre->getInfo());
        dot += Padre;
        dot += "\n";
    }

    if(padre->getRamaIzq() != 0)
    {
        iPadre = padre->getInfo();
        iHijo = padre->getRamaIzq()->getInfo();
        Padre = metodo.ConvtirIntString(iPadre);
        Hijo = metodo.ConvtirIntString(iHijo);
        dot = dot + Recorrer(padre->getRamaIzq()) +  Padre + "->" + Hijo + "\n";
    }

    if(padre->getRamaDer() != 0)
    {
        iPadre = padre->getInfo();
        iHijo = padre->getRamaDer()->getInfo();
        Padre = metodo.ConvtirIntString(iPadre);
        Hijo = metodo.ConvtirIntString(iHijo);
        dot = dot + Recorrer(padre->getRamaDer()) + Padre + "->" + Hijo + "\n";
    }
    return dot;

}

void ArbolABB::InOrden(NodoAVL *padre)
{
    if(padre != 0)
    {
        InOrden(padre->getRamaIzq());
        cout << padre->getInfo() << ".  " << padre->getNombre() << endl;
        InOrden(padre->getRamaDer());
    }
}



