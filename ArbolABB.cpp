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

void ArbolABB::BorrarNodo(NodoAVL* padre ,int num)
{
    if (padre == 0)
    {
        cout << "El arbol de objetos ABB esta vacio " << endl;
    }
    else
        //this->setRaiz(BorrarEnABB(this->getRaiz(), num));
        this->Raiz = BorrarEnABB(this->getRaiz(), num);
        //this->getRaiz() = BorrarEnABB(padre, num);
}

int ArbolABB::Buscar(NodoAVL *padre, int num)
{
    int objNum = 0;
    if(padre == 0)
    {
        return objNum;
    }

    if(num < padre->getInfo())
    {
        objNum = Buscar(padre->getRamaIzq(), num);
    }
    else if (num >padre->getInfo())
    {
        objNum = Buscar(padre->getRamaDer(), num);
    }
    else
    {
        objNum = padre->getInfo();
    }
    return objNum;
}

bool ArbolABB::BuscarPost(int num)
{
    int comparar = Post(this->getRaiz());
    if (comparar == num)
    {
        return true;
    }
}

///Metodos privados

int ArbolABB::Post(NodoAVL *padre)
{
    if(padre != 0)
    {
        Post(padre->getRamaIzq());
        Post(padre->getRamaDer());
        return padre->getInfo();
    }
}

int ArbolABB::Revisar(NodoAVL *padre, int num)
{
    if(padre != 0)
    {
        Revisar(padre->getRamaIzq(), num);
        if (padre->getInfo() == num)
        {
            return padre->getInfo();
        }
        Revisar(padre->getRamaDer(), num);
    }
}

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

NodoAVL* ArbolABB::BorrarEnABB(NodoAVL *raiz, int Valor)
{
    if (raiz == 0)                      //Arbol vacio
    {
        cout << "Arbol vacio "<< endl;
    }
    else if (Valor < raiz->getInfo())   //Nos vamos por la rama izquierda
    {
        NodoAVL *auxIzq;
        auxIzq = BorrarEnABB(raiz->getRamaIzq(), Valor);
        raiz->setRamaIzq(auxIzq);
    }
    else if (Valor > raiz->getInfo())   //Nos vamos por la rama derecha
    {
        NodoAVL *auxDer;
        if(raiz)
        auxDer = BorrarEnABB(raiz->getRamaDer(), Valor);
        raiz->setRamaDer(auxDer);
    }
    else
    {
        NodoAVL *aux = raiz;
        if (aux->getRamaIzq() == 0)
        {
            raiz = aux->getRamaDer();
            //aux->setRamaDer(aux);
        }
        else if (aux->getRamaDer() == 0)
        {
            raiz = aux->getRamaIzq();
        }
        else
        {
            aux = Eliminar(aux);
        }
        aux == 0;
    }
    return raiz;
}

NodoAVL* ArbolABB::Eliminar(NodoAVL *encontrado)
{
    NodoAVL *padre = encontrado;
    NodoAVL *hijo = encontrado->getRamaIzq();
    while(hijo->getRamaDer() != 0)
    {
        padre = hijo;
        hijo = hijo->getRamaDer();
    }
    encontrado->setInfo(hijo->getInfo());
    if(padre == encontrado)
    {
        padre->setRamaIzq(hijo->getRamaIzq());
    }
    else
    {
        padre->setRamaDer(hijo->getRamaIzq());
    }
    return hijo;
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



