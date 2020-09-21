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
        bool BuscarProy(int proy);
        bool BuscarNivel(int proy, int nivel);
        string EliminarObjeto(int proy, int nivel, int idO);

    protected:

    private:
        Nodo *Inicio;
        Nodo *Fin;
        Nodo *Sig;
        int Cant;
};

#endif // LISTA_H
