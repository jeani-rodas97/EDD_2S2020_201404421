#include "ObjABB.h"

ObjABB::ObjABB(int id, string nombre, string letra, string color)
{
    this->id = id;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
}

int ObjABB::getId()
{
    return this->id;
}

string ObjABB::getNombre()
{
    return this->nombre;
}

string ObjABB::getLetra()
{
    return this->letra;
}

string ObjABB::getColor()
{
    return this->color;
}


void ObjABB::setId(int id)
{
    this->id = id;
}

void ObjABB::setNombre(string nombre)
{
    this->nombre = nombre;
}

void ObjABB::setLetra(string letra)
{
    this->letra = letra;
}

void ObjABB::setColor(string color)
{
    this->color = color;
}

