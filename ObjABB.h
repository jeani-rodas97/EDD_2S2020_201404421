#ifndef OBJABB_H
#define OBJABB_H
#include <string>

using namespace std;

class ObjABB
{
    public:
        ObjABB(int id, string nombre, char letra, string color);
        int getId();
        string getNombre();
        char getLetra();
        string getColor();

        void setId(int id);
        void setNombre(string nombre);
        void setLetra(char letra);
        void setColor(string color);

    protected:

    private:
        int id;
        string nombre;
        char letra;
        string color;
};

#endif // OBJABB_H
