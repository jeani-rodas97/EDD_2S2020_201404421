#ifndef ALMACENPROY_H
#define ALMACENPROY_H
#include "Proyecto.h"


class AlmacenProy
{
    public:
        AlmacenProy();
        void NuevoProy(int proy, ListaGlobal *Niv);
        bool ExisteProy(int proy);
        Proyecto *BuscarProy(int proy);
        int getCant();
        int MostrarProy();

        int CantNiveles;
        int CantObjetos;

    protected:

    private:
        bool Vacia();
        Proyecto *Inicio, *Final;
        int CantProy;
        int CantNiv;
};

#endif // ALMACENPROY_H
