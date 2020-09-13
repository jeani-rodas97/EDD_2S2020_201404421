#include "NodoMDisp.h"

NodoMDisp::NodoMDisp(int PX, int PY, ObjetoM *Pobj)
{
    arribaN = 0;
    abajoN = 0;
    sigN = 0;
    antN = 0;
    PX = CabX;
    PY = CabY;
    Pobj = obj;
}

NodoMDisp::NodoMDisp(int cabecera)
{
    sigNC = 0;
    antNC = 0;
    arribaN = abajoN = sigN = antN = 0;
    cabeza = cabecera;
}

int NodoMDisp::getPX()
{
    return CabX;
}

int NodoMDisp::getPY()
{
    return CabY;
}

ObjetoM* NodoMDisp::getObj()
{
    return obj;
}
