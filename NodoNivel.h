#ifndef NODONIVEL_H
#define NODONIVEL_H


class NodoNivel
{
    public:
        NodoNivel(int Proy, int Nivel);
        NodoNivel *Sig, *Ant;
        int getProy();
        int getNivel();
    protected:

    private:

        int proy, nivel;

};

#endif // NODONIVEL_H
