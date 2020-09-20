#include "MatrizDisp.h"
#include <iostream>
#include <fstream>
#include "Metodos.h"
#include <string>
#include <stdlib.h>
#include <cstring>
#include "ListaCab.h"

using namespace std;

MatrizDisp::MatrizDisp(int Proy, int Nivel)
{
    this->Proyecto = Proy;
    this->Nivel = Nivel;
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

void MatrizDisp::GraficarMatriz(int Proyecto, int Nivel)
{
    Metodos metodo;
    ofstream GrafMatriz;
    int indiceX, indiceY, contador;
    char rut[100], sy[100];
    string ruta, proy, niv, neato;
    string X;
    string Y;
    string CoordeenadasCol;
    string letra;
    string dot = "digraph matriz{\n node[shape=box color=\"#E85BB9\" ranksep=0.2] \n";

    proy = Proyecto;
    niv = Nivel;

    NodoMDisp *Fila = HorizontalX->getInicio();
    NodoMDisp *Columna = VerticalY->getInicio();

    NodoMDisp *TempX = Fila;
    NodoMDisp *TempY = Columna;

    ///Dibujando las cabeceras de las filas pero salieron los encabezados de las columnas (A, B, C)
    contador = 0;
    if (Fila != 0)
    {
        dot += "0" + metodo.ConvtirIntString(contador+1) + " [label = \""+ metodo.ConvtirIntString(contador) + "\" pos = \"0,-" + metodo.ConvtirIntString(contador+1) + "!\"] \n";
        TempX = TempX->abajoN;
        while (TempX != 0)
        {
            dot += "0" + metodo.ConvtirIntString(contador+1) + "->";
            indiceX = TempX->getPX();
            contador++;
            dot += "0" + metodo.ConvtirIntString(contador+1) + "\n";
            dot += "0" + metodo.ConvtirIntString(contador+1) + " [label = \""+ metodo.ConvtirIntString(contador) + "\" pos = \"0,-" + metodo.ConvtirIntString(contador+1) + "!\"] \n";
            TempX = TempX->abajoN;
        }
    }

    ///Dibujando las cabeceras de las filas (1 2 3)
    indiceY = 0;
    if (Columna != 0 )
    {
        dot += metodo.ConvtirIntString(indiceY+1) + "0 [label = \""+ metodo.ConvtirIntString(indiceY) + "\" pos = \"" + metodo.ConvtirIntString(indiceY+1) + ",0!\"] \n";
        TempY = TempY->sigN;
        while (TempY != 0)
        {
            dot += metodo.ConvtirIntString(indiceY+1) + "0 ->";
            indiceY++;
            dot += metodo.ConvtirIntString(indiceY+1) + "0 \n";
            dot += metodo.ConvtirIntString(indiceY+1) + "0 [label = \""+ metodo.ConvtirIntString(indiceY) + "\" pos = \"" + metodo.ConvtirIntString(indiceY+1) + ",0!\"] \n";
            TempY = TempY->sigN;
        }
    }

    ///Dibujando los nodos
    if ((Fila != 0) && (Columna != 0))
    {
        Fila = HorizontalX->getInicio();
        TempX = Fila;
        while(Fila != 0)
        {
            Columna = VerticalY->getInicio();
            while(Columna != 0)
            {
                if(TempX->abajoN != 0)
                {
                    TempX = TempX->abajoN;
                    //dot += metodo.ConvtirIntString(TempX->getObj()->getX() +1) + metodo.ConvtirIntString(TempX->getObj()->getY() +1) + " [style = filled, fillcolor=\"" + TempX->getObj()->getColor() + "\", shape = circle, height = 0.5  fixedsize=true label = \"" + TempX->getObj()->getLetra() + "\",pos=\"" + metodo.ConvtirIntString(TempX->getObj()->getX() +1) + ",-" + metodo.ConvtirIntString(TempX->getObj()->getY() +1) + "!\"] \n";
                }
            }
        }
        //TempX = HorizontalX->Encontrar(7);
        //dot += metodo.ConvtirIntString(TempX->getObj()->getX() +1) + metodo.ConvtirIntString(TempX->getObj()->getY() +1) + " [style = filled, fillcolor=\"" + TempX->getObj()->getColor() + "\", shape = circle, height = 0.5  fixedsize=true label = \"" + TempX->getObj()->getLetra() + "\",pos=\"" + metodo.ConvtirIntString(TempX->getObj()->getX() +1) + ",-" + metodo.ConvtirIntString(TempX->getObj()->getY() +1) + "!\"] \n";
        //31 [style = filled, fillcolor="#5BE8A4", shape = circle, height = 0.5  fixedsize=true label = "H(3,1)",pos="3,-1!"]
    }

    dot += "}";
    ruta = "Matriz" + metodo.ConvtirIntString(Proyecto) + metodo.ConvtirIntString(Nivel) + ".txt";
    strcpy(rut, ruta.c_str());
    GrafMatriz.open(rut, ios::out);
    GrafMatriz << dot;
    GrafMatriz.close();
    neato = "neato " + ruta + " -Tpng -o " + "matriz" + metodo.ConvtirIntString(Proyecto) + metodo.ConvtirIntString(Nivel) +".png";
    strcpy(sy, neato.c_str());
    system(sy);
}

int MatrizDisp::getProyecto()
{
    return this->Proyecto;
}

int MatrizDisp::getNivel()
{
    return this->Nivel;
}

void MatrizDisp::setNivel(int Nivel)
{
    this->Nivel = Nivel;
}

void MatrizDisp::setProyecto(int Proy)
{
    this->Proyecto = Proy;
}

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
