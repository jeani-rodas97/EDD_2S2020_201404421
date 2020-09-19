#ifndef OBJETOM_H
#define OBJETOM_H
#include <string>

using namespace std;


class ObjetoM
{
    public:
        ObjetoM(int idAVL, int nivel, string letra, string color, int x, int y);

        int getId();
        int getNivel();
        string getLetra();
        string getColor();
        int getX();
        int getY();

        void setId(int id);
        void setNivel(int nivel);
        void setLetra(string letra);
        void setColor(string color);
        void setX(int x);
        void setY(int y);

    protected:

    private:
        int idAVL;
        int nivel;
        string letra;
        string color;
        int x;
        int y;
};

#endif // OBJETOM_H
