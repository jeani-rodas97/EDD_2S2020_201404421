#ifndef CONTOBJ_H
#define CONTOBJ_H


class ContObj
{
    public:
        ContObj(int proy, int niv, int cantPared, int CantVentanas, int cantObj);
        ContObj *Sig;
        ContObj *Ant;

        int proy;
        int niv;
        int cantPared;
        int cantVentanas;
        int cantObj;

    protected:

    private:
};

#endif // CONTOBJ_H
