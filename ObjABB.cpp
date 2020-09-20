#include "ObjABB.h"

ObjABB::ObjABB(int proy, int nivel, int id, string nombre, string letra, string color, int posX, int posY)
{
    this->proy = proy;
    this->nivel = nivel;
    this->id = id;
    this->nombre = nombre;
    this->letra = letra;
    this->color = color;
    this->posX = posX;
    this->posY = posY;
}

int ObjABB::getProy()
{
    return this->proy;
}

int ObjABB::getNivel()
{
    return this->nivel;
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

int ObjABB::getPosX()
{
    return this->posX;
}

int ObjABB::getPosY()
{
    return this->posY;
}


void ObjABB::setProy(int proy)
{
    this->proy = proy;
}

void ObjABB::setNivel(int nivel)
{
    this->nivel = nivel;
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

void ObjABB::setPosX(int posX)
{
    this->posX = posX;
}

void ObjABB::setPosY(int posY)
{
    this->posY = posY;
}
