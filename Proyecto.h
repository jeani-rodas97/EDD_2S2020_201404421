#ifndef PROYECTO_H
#define PROYECTO_H
#include "ListaGlobal.h"


class Proyecto
{
    public:
        Proyecto();
        Proyecto(int Proy, ListaGlobal *niv);
        int getProy();
        ListaGlobal* getListaNiv();
        Proyecto *Sig;
        Proyecto *Ant;
        int proy;
        ListaGlobal *Niveles;

    protected:

    private:
};

#endif // PROYECTO_H
