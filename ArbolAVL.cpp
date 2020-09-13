#include "ArbolAVL.h"

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

NodoAVL* ArbolAVL::InsertarEnAVL(NodoAVL *raiz, int Valor, bool &AlturaEsMayor)
{
    NodoAVL *aux;
    if(raiz == 0)
    {
        raiz = new NodoAVL(Valor);
        AlturaEsMayor = true;
    }
    else if (Valor < raiz->getInfo())
    {
        NodoAVL *auxIzq;
        auxIzq = InsertarEnAVL(raiz->getRamaIzq(), Valor, AlturaEsMayor);
        raiz->setRamaIzq(auxIzq);

        if(AlturaEsMayor == true)
        {

        }
    }
}

///Metodos privados
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
        a->setFactorEquilibrio(1);
        b->setFactorEquilibrio(-1);
    }
    return b;
}
