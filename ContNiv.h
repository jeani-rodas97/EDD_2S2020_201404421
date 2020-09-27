#ifndef CONTNIV_H
#define CONTNIV_H


class ContNiv
{
    public:
        ContNiv(int proy, int cantNiv, int cantObj);

        ContNiv* Sig;
        ContNiv* Ant;

        int Proy;
        int CantNiv;
        int CantObj;
    protected:

    private:
};

#endif // CONTNIV_H
