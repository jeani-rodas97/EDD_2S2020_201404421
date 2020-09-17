#include "MatrizDisp.h"
#include <iostream>
#include <fstream>
#include "Metodos.h"
#include <string>
#include <stdlib.h>

using namespace std;

MatrizDisp::MatrizDisp()
{
    HorizontalX = new ListaCab();
    VerticalY = new ListaCab();
}

void MatrizDisp::InsertarObj(ObjetoM *objNuevo, int x, int y)
{
    NodoMDisp *Cab_Horizontal = HorizontalX->Encontrar(x);
    NodoMDisp *Cab_Vertical = VerticalY->Encontrar(y);
    if((Cab_Horizontal == 0) && (Cab_Vertical == 0))
    {
        NoHayXniY(objNuevo, x, y);
        cout << "Caso 1 no hay x ni y" << endl;
    }
    else if((Cab_Horizontal == 0) && (Cab_Vertical != 0))
    {
        HayY(objNuevo, x, y);
        cout << "Caso 2 no hay x hay y" << endl;
    }
    else if((Cab_Horizontal != 0) && (Cab_Vertical == 0))
    {
        HayX(objNuevo, x, y);
        cout << "Caso 3 no hay y si hay X" << endl;
    }
    else if((Cab_Horizontal != 0) && (Cab_Vertical != 0))
    {
        HayXY(objNuevo, x, y);
        cout << "Caso 4 hay X y Y" << endl;
    }
    else
    {
        cout<<"Error"<<endl;
    }
}

void MatrizDisp::GraficarMatriz()
{
    Metodos metodo;
    ofstream GrafMatriz;
    int indiceX, indiceY, contador;
    string X;
    string Y;
    string CoordeenadasCol;
    string letra;
    string dot = "digraph matriz{\n node[shape=box color=\"#E85BB9\" ranksep=0.2] \n";
    NodoMDisp *Fila = this->HorizontalX->getInicio();
    NodoMDisp *Columna = this->VerticalY->getInicio();
    NodoMDisp *TempX = Fila->abajoN;
    NodoMDisp *TempY = Columna->sigN;
    NodoMDisp *Actual;
    ///Dibujando las cabeceras de las filas
    indiceX = Fila->getPX();
    contador = 1;
    dot += "0" + metodo.ConvtirIntString(indiceX) + " [label = \""+ metodo.ConvtirIntString(indiceX) + "\" pos = \"0,-" + metodo.ConvtirIntString(indiceX) + "!\"]";
    while (TempX != 0)
    {
        indiceX = TempX->getPX();
        dot += "0" + metodo.ConvtirIntString(indiceX) + " [label = \""+ metodo.ConvtirIntString(indiceX) + "\" pos = \"0,-" + metodo.ConvtirIntString(contador) + "!\"]";
        contador++;
        TempX = TempX->abajoN;
    }
    ///Dibujando las cabeceras de las columnas
    indiceY = Columna->getPY();
    contador = 1;
    dot += metodo.ConvtirIntString(indiceY) + "0" + " [label = \""+ metodo.ConvtirIntString(indiceY) + "\" pos = \"" + metodo.ConvtirIntString(contador) + ",0!\"]";
    while (TempY != 0)
    {
        indiceY = TempY->getPY();
        dot += metodo.ConvtirIntString(indiceY) + "0" + " [label = \""+ metodo.ConvtirIntString(indiceY) + "\" pos = \"" + metodo.ConvtirIntString(contador) + ",0!\"]";
        contador++;
        TempY = TempY->sigN;
    }
    ///Dibujando los nodos
    /*TempY = Columna;
    while (Columna != 0)
    {
        while(Fila != 0)
        {
            if (TempY->abajoN)
            X = Columna->getPX();
            Y = Columna->getPY();
            CoordeenadasCol = X + Y;
                            ///10 [label = "C(1,0)" pos = "1,0!"]
            dot += CoordeenadasCol + " [label = \"" + Columna->getObj()->getLetra() + "\" pos = \"" ;
        }
    }*/
    dot += "}";

    GrafMatriz.open("GrafoMatriz.txt", ios::out);
    GrafMatriz << dot;
    GrafMatriz.close();
    system("neato GrafoMatriz.txt -Tpng -o matriz.png");
}

    /*
    if(TempX != 0)
    {
        do
        {
            letra = TempX->getObj()->getLetra();
            dot += "t" + letra + " ";
        }
        while(TempX != this->HorizontalX->getUltimo());
    }*/


///Metodos privados para usar en declaraciones publicas
void MatrizDisp::NoHayXniY(ObjetoM *objNuevo, int x, int y)
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
    return;
}

void MatrizDisp::HayY(ObjetoM *objNuevo, int x, int y)
{
    int indiceX;
    bool EncontreX = false;
    HorizontalX->Insertar(x);
    NodoMDisp *Fila = HorizontalX->Encontrar(x);
    NodoMDisp *Columna = VerticalY->Encontrar(y);
    NodoMDisp *Nuevo = new NodoMDisp(x, y, objNuevo);
    NodoMDisp *Temp = Columna->sigN;
    while (Temp != 0)
    {
        indiceX = Temp->getPX();
        if(indiceX > x)
        {
            Temp = Temp->sigN;
        }
        else
        {
            ///Insertamos y arrglamos los punteros
            Nuevo->sigN = Temp;
            Nuevo->antN = Temp->antN;
            Temp->antN->sigN = Nuevo;
            Temp->sigN = Nuevo;
            EncontreX = true;
            break;
        }
    }
    if(EncontreX == false)
    {
        Temp = Columna->sigN;
        while(Temp->sigN != 0)
        {
            ///Recorremos en la lista
            Temp = Temp->sigN;
        }
        Nuevo->antN = Temp;
        Temp->sigN = Nuevo;
    }
    Fila->abajoN = Nuevo;
    Nuevo->arribaN = Fila;
}

void MatrizDisp::HayX(ObjetoM *objNuevo, int x, int y)
{
    int indiceY;
    bool EncontreY = false;
    //int indiceX;
    //bool EncontreX = false;
    VerticalY->Insertar(y);
    NodoMDisp *Fila = HorizontalX->Encontrar(x);
    NodoMDisp *Columna = VerticalY->Encontrar(y);
    NodoMDisp *Nuevo = new NodoMDisp(x, y, objNuevo);
    NodoMDisp *Temp = Fila->abajoN;
    while (Temp != 0)
    {
        indiceY = Temp->getPY();
        if(indiceY > y)
        {
            Temp = Temp->abajoN;
        }
        else
        {
            ///Insertamos y arrglamos los punteros
            Nuevo->abajoN = Temp;
            Nuevo->arribaN = Temp->arribaN;
            Temp->arribaN->abajoN = Nuevo;
            Temp->arribaN = Nuevo;
            EncontreY = true;
            break;
        }
    }
    if(EncontreY == false)
    {
        Temp = Fila->abajoN;
        while(Temp->abajoN != 0)
        {
            ///Recorremos en la lista
            Temp = Temp->abajoN;
        }
        Nuevo->arribaN = Temp;
        Temp->abajoN = Nuevo;
    }
    Columna->sigN = Nuevo;
    Nuevo->antN = Columna;
}

void MatrizDisp::HayXY(ObjetoM *objNuevo, int x, int y)
{
    int indiceY;
    int indiceX;
    bool EncontreY = false;
    bool EncontreX = false;
    //bool Encontre = false;
    NodoMDisp *Fila = HorizontalX->Encontrar(x);
    NodoMDisp *Columna = VerticalY->Encontrar(y);
    NodoMDisp *Nuevo = new NodoMDisp(x, y, objNuevo);
    NodoMDisp *Temp = Fila->abajoN;
    while(Temp != 0)
    {
        indiceY = Temp->getPY();
        if (indiceY > y)
        {
            Temp = Temp->abajoN;
        }
        else
        {
            Nuevo->abajoN = Temp;
            Nuevo->arribaN = Temp->arribaN;
            Temp->arribaN = Nuevo;
            Temp->arribaN->abajoN = Nuevo;
            EncontreY = true;
            break;
        }
    }
    if (EncontreY == false)
    {
        Temp = Fila->abajoN;
        while(Temp->abajoN != 0)
        {
            Temp = Temp->abajoN;
        }
        Nuevo->arribaN = Temp;
        Temp->abajoN = Nuevo;
    }

    Temp = Columna->sigN;
    while(Temp != 0)
    {
        indiceX = Temp->getPX();
        if(indiceX > x)
        {
            Temp = Temp->sigN;
        }
        else
        {
            Nuevo->sigN = Temp;
            Nuevo->antN = Temp->antN;
            Temp->antN->sigN = Nuevo;
            Temp->antN = Nuevo;
            EncontreX = true;
            break;
        }
    }
    if(EncontreX == false)
    {
        Temp = Columna->sigN;
        while(Temp->sigN != 0)
        {
            Temp = Temp->sigN;
        }
        Nuevo->antN = Temp;
        Temp->sigN = Nuevo;
    }
}
