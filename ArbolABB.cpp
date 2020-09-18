#include "ArbolABB.h"

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
    ///this->Raiz = InsertarEnAVL(this->getRaiz(), numero, nombre, Altura);

}

///Metodos privados

NodoAVL* ArbolABB::InsertarEnABB(NodoAVL *raiz, int Valor, string Nombre)
{
    NodoAVL *aux;
    if(raiz == 0)
    {
        raiz = new NodoAVL(Valor, Nombre);
    }
    else
    {
        if(raiz->getInfo() > Valor)
        {
            aux = InsertarEnABB(raiz->getRamaIzq(), Valor, Nombre);
        }
        else
        {
            aux = InsertarEnABB(raiz->getRamaDer(), Valor, Nombre);
        }
    }
}
