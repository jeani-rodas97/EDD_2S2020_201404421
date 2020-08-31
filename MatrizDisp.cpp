#include "MatrizDisp.h"

MatrizDisp::MatrizDisp()
{
    //ctor
}

void MatrizDisp::Vacia(ObjetoM *objNuevo, int x, int y)
{
    HorizontalX->Insertar(x);
    VerticalY->Insertar(y);
    NodoMDisp *Fila = HorizontalX->Encontrar(x);
    NodoMDisp *Columna = VerticalY->Encontrar(y);
    NodoMDisp *Nuevo = new NodoMDisp(x, y, objNuevo);
    ///Enlaces de punteros
    Fila->abajoN = Nuevo;
    Nuevo->arribaN = Fila;
    Columna->sigN = Nuevo;
    Nuevo->antN = Columna;
}
