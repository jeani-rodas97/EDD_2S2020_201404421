#ifndef OBJETOM_H
#define OBJETOM_H
#include <string>

using namespace std;


class ObjetoM
{
    public:
        ObjetoM(int idAVL, int nivel, char letra, string color, int x, int y);

        int getId();
        int getNivel();
        char getLetra();
        string getColor();
        int getX();
        int getY();

        void setId(int id);
        void setNivel(int nivel);
        void setLetra(char letra);
        void setColor(string color);
        void setX(int x);
        void setY(int y);

    protected:

    private:
        int idAVL;
        int nivel;
        char letra;
        string color;
        int x;
        int y;
};

#endif // OBJETOM_H
