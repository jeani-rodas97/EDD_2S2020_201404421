#include "ObjetoM.h"

ObjetoM::ObjetoM(int id, int nivel, string letra, string color, int x, int y)
{
    this->idAVL = id;
    this->nivel = nivel;
    this->letra = letra;
    this->color = color;
    this->x = x;
    this->y = y;
}

int ObjetoM::getId()
{
    return this->idAVL;
}

int ObjetoM::getNivel()
{
    return this->nivel;
}

string ObjetoM::getLetra()
{
    return this->letra;
}

string ObjetoM::getColor()
{
    return this->color;
}

int ObjetoM::getX()
{
    return this->x;
}

int ObjetoM::getY()
{
    return this->y;
}

void ObjetoM::setId(int id)
{
    this->idAVL = id;
}

void ObjetoM::setNivel(int nivel)
{
    this->nivel = nivel;
}

void ObjetoM::setLetra(string letra)
{
    this->letra = letra;
}

void ObjetoM::setColor(string color)
{
    this->color = color;
}

void ObjetoM::setX(int x)
{
    this->x = x;
}

void ObjetoM::setY(int y)
{
    this->y = y;
}
