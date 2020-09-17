#include "ArbolAVL.h"
#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Metodos.h"

ArbolAVL::ArbolAVL()
{
    this->Raiz = 0;
}

NodoAVL* ArbolAVL::getRaiz()
{
    return this->Raiz;
}

void ArbolAVL::setRaiz(NodoAVL *root)
{
    this->Raiz = root;
}

void ArbolAVL::NuevoNodo(int numero, string nombre)
{
    bool Altura = false;
    this->Raiz = InsertarEnAVL(this->getRaiz(), numero, nombre, Altura);
}
void ArbolAVL::GraficarArbol(NodoAVL *padre)
{
    string dot;
    dot = "digraph arbolAVL{ \n rankdir=TB; \n label = \"AVL\" \n node [shape = circle, style=filled, color=\"#F76B11\", fillcolor= \"#F7C4F5\" ]; \n";
    dot += Recorrer(padre);
    dot += "} \n";

    ofstream grafoAVL;
    grafoAVL.open("AVL.dot", ios::out);
    grafoAVL << dot;
    grafoAVL.close();
    system("dot AVL.dot -Tpng -o AVL.png");
}

void ArbolAVL::inorden(NodoAVL *padre)
{
    if (padre != 0)
    {
        orden(padre->getRamaIzq());
        cout << padre->getNombre() << endl;
        orden(padre->getRamaDer());
    }
}


///METODOS PRIVADOS

void ArbolAVL::orden(NodoAVL *padre)
{
    if (padre != 0)
    {
        orden(padre->getRamaIzq());
        orden(padre->getRamaDer());
        cout << padre->getNombre() << endl;
    }
}

string ArbolAVL::Recorrer(NodoAVL *padre)
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
        //cout << "Valor padre " << Padre << endl;
        //cout << "Valor hijo " << Hijo << endl;
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

NodoAVL* ArbolAVL::InsertarEnAVL(NodoAVL *raiz, int Valor, string Nombre, bool &AlturaEsMayor)
{
    NodoAVL *aux;
    if(raiz == 0)
    {
        raiz = new NodoAVL(Valor, Nombre);
        AlturaEsMayor = true;
    }
    //El nodo se va al subarbol izquierdo,
    else if (Valor < raiz->getInfo())
    {
        NodoAVL *auxIzq;
        auxIzq = InsertarEnAVL(raiz->getRamaIzq(), Valor, Nombre, AlturaEsMayor);
        raiz->setRamaIzq(auxIzq);

        if(AlturaEsMayor == true)
        {
            if(raiz->getFactorEquilibrio() == -1)
            {
                aux = raiz->getRamaIzq();
                if(aux->getFactorEquilibrio() == -1)
                {
                    raiz = RotIzqIzq(raiz, aux);
                }
                else
                {
                    raiz = RotIzqDer(raiz, aux);
                }
                AlturaEsMayor = false;
            }
            else if(raiz->getFactorEquilibrio() == 0)
            {
                raiz->setFactorEquilibrio(-1);
            }
            else if(raiz->getFactorEquilibrio() == +1)
            {
                raiz->setFactorEquilibrio(0);
                AlturaEsMayor = false;
            }
        }

    }
    //El nodo se va al subarbol derecho por ser mayor
    else if (Valor > raiz->getInfo())
    {
        NodoAVL *auxDer;
        auxDer = InsertarEnAVL(raiz->getRamaIzq(), Valor, Nombre, AlturaEsMayor);
        raiz->setRamaDer(auxDer);

        if(AlturaEsMayor == true)
        {
            if(raiz->getFactorEquilibrio() == +1)
            {
                aux = raiz->getRamaDer();
                if(aux->getFactorEquilibrio() == +1)
                {
                    raiz = RotDerDer(raiz, aux);
                }
                else
                {
                    raiz = RotDerIzq(raiz, aux);
                }
                AlturaEsMayor = false;
            }
            else if(raiz->getFactorEquilibrio() == 0)
            {
                raiz->setFactorEquilibrio(+1);
            }
            else if(raiz->getFactorEquilibrio() == -1)
            {
                raiz->setFactorEquilibrio(0);
                AlturaEsMayor = false;
            }
        }

    }
    else
    {
        cout << "ERROR " << endl;
    }
    return raiz;
}

NodoAVL* ArbolAVL::RotDerIzq(NodoAVL *a, NodoAVL *b)
{
    NodoAVL *aux;
    aux = b->getRamaIzq();
    a->setRamaDer(aux->getRamaIzq());
    b->setRamaIzq(aux->getRamaIzq());
    aux->setRamaIzq(a);
    aux->setRamaDer(b);
    if (aux->getFactorEquilibrio() == +1)
    {
        a->setFactorEquilibrio(-1);
    }
    else
    {
        a->setFactorEquilibrio(0);
    }

    if (aux->getFactorEquilibrio() == -1)
    {
        b->setFactorEquilibrio(+1);
    }
    else
    {
        b->setFactorEquilibrio(0);
    }

    aux->setFactorEquilibrio(0);
    return aux;
}

NodoAVL* ArbolAVL::RotIzqDer(NodoAVL *a, NodoAVL *b)
{
    NodoAVL *aux;
    aux = b->getRamaDer();
    a->setRamaIzq(aux->getRamaDer());
    b->setRamaDer(aux->getRamaIzq());
    aux->setRamaIzq(b);
    aux->setRamaDer(a);
    if (aux->getFactorEquilibrio() == +1)
    {
        b->setFactorEquilibrio(-1);
    }
    else
    {
        b->setFactorEquilibrio(0);
    }

    if (aux->getFactorEquilibrio() == -1)
    {
        a->setFactorEquilibrio(+1);
    }
    else
    {
        a->setFactorEquilibrio(0);
    }

    aux->setFactorEquilibrio(0);
    return aux;
}

NodoAVL* ArbolAVL::RotDerDer(NodoAVL *a, NodoAVL *b)
{
    a->setRamaDer(b->getRamaIzq());
    b->setRamaIzq(a);
    if(b->getFactorEquilibrio() == +1)
    {
        a->setFactorEquilibrio(0);
        b->setFactorEquilibrio(0);
    }
    else
    {
        a->setFactorEquilibrio(1);
        b->setFactorEquilibrio(-1);
    }
    return b;
}

NodoAVL* ArbolAVL::RotIzqIzq(NodoAVL *a, NodoAVL *b)
{
    a->setRamaIzq(b->getRamaDer());
    b->setRamaDer(a);
    if(b->getFactorEquilibrio() == -1)
    {
        a->setFactorEquilibrio(0);
        b->setFactorEquilibrio(0);
    }
    else
    {
        a->setFactorEquilibrio(-1);
        b->setFactorEquilibrio(1);
    }
    return b;
}
