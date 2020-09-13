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

