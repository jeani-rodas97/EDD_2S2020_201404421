#ifndef LISTA_H
#define LISTA_H
#include "Nodo.h"
#include <string>


class Lista
{
    public:
        Lista();
        Nodo *getInicio();
        void setInicio(Nodo *raiz);
        string Recorrer();
        void NuevoObje(int proy, int nivel, int id, string nombre, string letra, string color, int posX, int posY);
        int Vacia();
        Lista *Buscar(int proy);

    protected:

    private:
        Nodo *Inicio;
        Nodo *Fin;
        int Cant;
};

#endif // LISTA_H
