#include "ObjetoM.h"

ObjetoM::ObjetoM(int nivel, char letra, string color, int x, int y)
{
    this->nivel = nivel;
    this->letra = letra;
    this->color = color;
    this->x = x;
    this->y = y;
}

int ObjetoM::getNivel()
{
    return this->nivel;
}

char ObjetoM::getLetra()
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

void ObjetoM::setNivel(int nivel)
{
    this->nivel = nivel;
}

void ObjetoM::setLetra(char letra)
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
