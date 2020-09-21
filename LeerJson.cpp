#include "LeerJson.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Metodos.h"
#include "ArbolAVL.h"
#include "ArbolABB.h"
#include "MatrizDisp.h"
#include "Lista.h"
#include "ListaGlobal.h"
//
#include "json\json.h"
#include "jsoncpp.cpp"


//#include <json/json.h>
//#include <jsoncpp/json/json.h>
//#include <jsoncpp/json/json.h>
//#include "json.h"//Tira error

using namespace std;
ArbolAVL *AVL = new ArbolAVL();
ArbolABB *ABB = new ArbolABB();
ListaGlobal *LGeneral = new ListaGlobal();

LeerJson::LeerJson()
{

}
void LeerJson::RecibirArchivo()
{
    ///C:\\Users\\Jeany\\Downloads\\Proy.json   Para que funcione, colocar sin comilas y doble slash inverso
    Metodos metodo;

    char rutJson[100];
    int NumNombreProy, Xinicial, Yinicial, Xfinal, Yfinal, NumNivel, id;
    string ColorNodo, nombre, letra, RecorrerList ;
    Json::Value dato;
    Json::Reader ReadJson;
    cout << "Ingrese la ruta de ubicacion ";
    cin >> rutJson;
    ifstream ArchJson(rutJson, ifstream::binary);
    //cout << "Abre el archivo" << endl;
    ReadJson.parse(ArchJson, dato);
    //cout << dato["proyectos"] << endl; /// En dato esta todo el archivo+;
                ///Estoy en proyectos
    const Json::Value& proy = dato["proyectos"]; // array of characters
    for (int i = 0; i < proy.size(); i++)
    {
        cout << "Nombre: " << proy[i]["nombre"].asString() << endl;
        NumNombreProy = metodo.ConvertirAscci(proy[i]["nombre"].asString());
        cout << NumNombreProy << endl;
        ///Aqui voy a insertar el nombre al arbol
        AVL->NuevoNodo(NumNombreProy, proy[i]["nombre"].asString());
                ///Estoy en niveles
        const Json::Value& nivel = proy[i]["niveles"];
        for (int j = 0; j < nivel.size(); j++)
        {
            NumNivel = nivel[j]["nivel"].asInt();
            cout << "Nivel: " << nivel[j]["nivel"].asString() << endl;
            cout << "Nuevo nivel, nueva matriz:     " << NumNombreProy << NumNivel << endl;
            RecorrerList = "";
            MatrizDisp *MatrizNivel = new MatrizDisp(NumNombreProy, NumNivel);
            Lista *ListaNivel = new Lista();
            LGeneral->NuevoNivel(NumNombreProy, NumNivel);
                ///Estoy en paredes
            const Json::Value& paredes = nivel[j]["paredes"];
            for (int k = 0; k < paredes.size(); k++)
            {
                ColorNodo = paredes[k]["color"].asString();
                cout << "color: " << paredes[k]["color"].asString() << endl;
                const Json::Value& paredInicio = paredes[k]["inicio"];
                Xinicial = paredInicio[0].asInt();
                Yinicial = paredInicio[1].asInt();
                cout << "inicioX: " << paredInicio[0].asString() << endl;
                cout << "inicioY: " << paredInicio[1].asString() << endl;
                const Json::Value& paredFinal = paredes[k]["final"];
                cout << "finalX: " << paredFinal[0].asString() << endl;
                cout << "finalY: " << paredFinal[1].asString() << endl;
                Xfinal = paredFinal[0].asInt();
                Yfinal = paredFinal[1].asInt();
                if (Xinicial == Xfinal)
                {
                    ///Avanzamox en y
                    for(int y = Yinicial; y <= Yfinal; y++)
                    {
                        cout << "creando " << Xinicial << " , " << y << endl;
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 100, "Paredes", "P", ColorNodo, Xinicial, y);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "P", ColorNodo, Xinicial, y ), Xinicial, y);
                        LGeneral->NuevoNivel(NumNombreProy, NumNivel);
                    }
                }
                if (Yinicial == Yfinal)
                {
                    for (int x = Xinicial; x <= Xfinal; x++)
                    {
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 100, "Paredes", "P", ColorNodo, x, Yinicial);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "P", ColorNodo, x, Yinicial), x, Yinicial);
                        LGeneral->NuevoNivel(NumNombreProy, NumNivel);
                    }
                }
            }
            const Json::Value& ventanas = nivel[j]["ventanas"];
            for (int k = 0; k < ventanas.size(); k++)
            {
                ColorNodo = ventanas[k]["color"].asString();
                cout << "color: " << ventanas[k]["color"].asString() << endl;
                const Json::Value& ventanaInicio = ventanas[k]["inicio"];
                Xinicial = ventanaInicio[0].asInt();
                Yinicial = ventanaInicio[1].asInt();
                cout << "inicioX: " << ventanaInicio[0].asString() << endl;
                cout << "inicioY: " << ventanaInicio[1].asString() << endl;
                const Json::Value& ventanaFinal = ventanas[k]["final"];
                cout << "finalX: " << ventanaFinal[0].asString() << endl;
                cout << "finalY: " << ventanaFinal[1].asString() << endl;
                Xfinal = ventanaFinal[0].asInt();
                Yfinal = ventanaFinal[1].asInt();
                if (Xinicial == Xfinal)
                {
                    ///Avanzamox en y
                    for(int y = Yinicial; y <= Yfinal; y++)
                    {
                        cout << "creando " << Xinicial << " , " << y << endl;
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 200, "Ventanas", "V", ColorNodo, Xinicial, y);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "V", ColorNodo, Xinicial, y ), Xinicial, y);
                        LGeneral->NuevoNivel(NumNombreProy, NumNivel);
                    }
                }
                if (Yinicial == Yfinal)
                {
                    for (int x = Xinicial; x <= Xfinal; x++)
                    {
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 200, "Ventanas", "V", ColorNodo, x, Yinicial);
                        LGeneral->NuevoNivel(NumNombreProy, NumNivel);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "V", ColorNodo, x, Yinicial ), x, Yinicial);
                    }
                }
            }
            const Json::Value& objetos = nivel[j]["objetos"];
            for (int k = 0; k < objetos.size(); k++)
            {
                id = objetos[k]["identificador"].asInt();
                nombre = objetos[k]["nombre"].asString();
                letra = objetos[k]["letra"].asString();
                ColorNodo = objetos[k]["color"].asString();
                const Json::Value& puntos = objetos[k]["puntos"];
                for(int p= 0; p < puntos.size(); p++)
                {
                    Xinicial = puntos[p]["x"].asInt();
                    Yinicial = puntos[p]["y"].asInt();
                    ListaNivel->NuevoObje(NumNombreProy, NumNivel, id, nombre, letra, ColorNodo, Xinicial, Yinicial);
                    MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, letra , ColorNodo, Xinicial, Yinicial ), Xinicial, Yinicial);
                }

            }
            cout << ListaNivel->Vacia() << endl;
            RecorrerList  = ListaNivel->Recorrer();
            MatrizNivel->GraficarMatriz(NumNombreProy, NumNivel, RecorrerList);
        }
    }
    AVL->GraficarArbol(AVL->getRaiz());
}

void LeerJson::MostrarProy()
{
    AVL->inorden(AVL->getRaiz());
}

bool LeerJson::VerificarProy(int proy)
{
    return AVL->BuscarPost(proy);
}

bool LeerJson::VerificarObj(int obj)
{
    return ABB->BuscarPost(obj);
}

void LeerJson::Niveles(int Proy)
{
    LGeneral->MostrarNivel(Proy);
}

void LeerJson::MostrarObjetos()
{
    ABB->InOrden(ABB->getRaiz());
}

void LeerJson::RecibirLibreria()
{
    char rutJson[100];
    Json::Value dato;
    Json::Reader ReadJson;
    int id;
    string nombre;
    cout << "Ingrese la ruta de ubicacion ";
    cin >> rutJson;
    ifstream ArchJson(rutJson, ifstream::binary);
    ReadJson.parse(ArchJson, dato);

    const Json::Value& lib = dato["Libreria"];
    for (int i = 0; i < lib.size(); i++)
    {
        cout << "Identificador: " << lib[i]["identificador"].asInt() << endl;
        id = lib[i]["identificador"].asInt();
        cout << "Nombre: " << lib[i]["nombre"].asString() << endl;
        nombre = lib[i]["nombre"].asString();
        cout << "Letra: " << lib[i]["letra"].asString() << endl;
        cout << "Color: " << lib[i]["color"].asString() << "\n" << endl;

        ABB->NuevoNodo(id, nombre);
    }
    ABB->GraficarArbol(ABB->getRaiz());
    cout<< "pasar a in orden" << endl;
    ABB->InOrden(ABB->getRaiz());
}

void LeerJson::RecibirNivel(int NumNombreProy)
{
    char rutJson[100];
    Json::Value dato;
    Json::Reader ReadJson;
    int id, NumNivel, Xinicial, Yinicial, Xfinal, Yfinal;
    string nombre, RecorrerList, ColorNodo, letra;
    cout << "Ingrese la ruta de ubicacion ";
    cin >> rutJson;
    ifstream ArchJson(rutJson, ifstream::binary);
    ReadJson.parse(ArchJson, dato);

    const Json::Value& nivel = dato["niveles"];
        for (int j = 0; j < nivel.size(); j++)
        {
            NumNivel = nivel[j]["nivel"].asInt();
            cout << "Nivel: " << nivel[j]["nivel"].asString() << endl;
            cout << "Nuevo nivel, nueva matriz:     " << NumNombreProy << NumNivel << endl;
            RecorrerList = "";
            MatrizDisp *MatrizNivel = new MatrizDisp(NumNombreProy, NumNivel);
            Lista *ListaNivel = new Lista();

                ///Estoy en paredes
            const Json::Value& paredes = nivel[j]["paredes"];
            for (int k = 0; k < paredes.size(); k++)
            {
                ColorNodo = paredes[k]["color"].asString();
                cout << "color: " << paredes[k]["color"].asString() << endl;
                const Json::Value& paredInicio = paredes[k]["inicio"];
                Xinicial = paredInicio[0].asInt();
                Yinicial = paredInicio[1].asInt();
                cout << "inicioX: " << paredInicio[0].asString() << endl;
                cout << "inicioY: " << paredInicio[1].asString() << endl;
                const Json::Value& paredFinal = paredes[k]["final"];
                cout << "finalX: " << paredFinal[0].asString() << endl;
                cout << "finalY: " << paredFinal[1].asString() << endl;
                Xfinal = paredFinal[0].asInt();
                Yfinal = paredFinal[1].asInt();
                if (Xinicial == Xfinal)
                {
                    ///Avanzamox en y
                    for(int y = Yinicial; y <= Yfinal; y++)
                    {
                        cout << "creando " << Xinicial << " , " << y << endl;
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 100, "Paredes", "P", ColorNodo, Xinicial, y);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "P", ColorNodo, Xinicial, y ), Xinicial, y);
                    }
                }
                if (Yinicial == Yfinal)
                {
                    for (int x = Xinicial; x <= Xfinal; x++)
                    {
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 100, "Paredes", "P", ColorNodo, x, Yinicial);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "P", ColorNodo, x, Yinicial), x, Yinicial);
                    }
                }
            }
            const Json::Value& ventanas = nivel[j]["ventanas"];
            for (int k = 0; k < ventanas.size(); k++)
            {
                ColorNodo = ventanas[k]["color"].asString();
                cout << "color: " << ventanas[k]["color"].asString() << endl;
                const Json::Value& ventanaInicio = ventanas[k]["inicio"];
                Xinicial = ventanaInicio[0].asInt();
                Yinicial = ventanaInicio[1].asInt();
                cout << "inicioX: " << ventanaInicio[0].asString() << endl;
                cout << "inicioY: " << ventanaInicio[1].asString() << endl;
                const Json::Value& ventanaFinal = ventanas[k]["final"];
                cout << "finalX: " << ventanaFinal[0].asString() << endl;
                cout << "finalY: " << ventanaFinal[1].asString() << endl;
                Xfinal = ventanaFinal[0].asInt();
                Yfinal = ventanaFinal[1].asInt();
                if (Xinicial == Xfinal)
                {
                    ///Avanzamox en y
                    for(int y = Yinicial; y <= Yfinal; y++)
                    {
                        cout << "creando " << Xinicial << " , " << y << endl;
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 200, "Ventanas", "V", ColorNodo, Xinicial, y);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "V", ColorNodo, Xinicial, y ), Xinicial, y);
                    }
                }
                if (Yinicial == Yfinal)
                {
                    for (int x = Xinicial; x <= Xfinal; x++)
                    {
                        ListaNivel->NuevoObje(NumNombreProy, NumNivel, 200, "Ventanas", "V", ColorNodo, x, Yinicial);
                        MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, "V", ColorNodo, x, Yinicial ), x, Yinicial);
                    }
                }
            }
            const Json::Value& objetos = nivel[j]["objetos"];
            for (int k = 0; k < objetos.size(); k++)
            {
                id = objetos[k]["identificador"].asInt();
                nombre = objetos[k]["nombre"].asString();
                letra = objetos[k]["letra"].asString();
                ColorNodo = objetos[k]["color"].asString();
                const Json::Value& puntos = objetos[k]["puntos"];
                for(int p= 0; p < puntos.size(); p++)
                {
                    Xinicial = puntos[p]["x"].asInt();
                    Yinicial = puntos[p]["y"].asInt();
                    ListaNivel->NuevoObje(NumNombreProy, NumNivel, id, nombre, letra, ColorNodo, Xinicial, Yinicial);
                    MatrizNivel->InsertarObj(new ObjetoM(NumNombreProy, NumNivel, letra , ColorNodo, Xinicial, Yinicial ), Xinicial, Yinicial);
                }

            }
            cout << ListaNivel->Vacia() << endl;
            RecorrerList  = ListaNivel->Recorrer();
            MatrizNivel->GraficarMatriz(NumNombreProy, NumNivel, RecorrerList);
        }
}

void LeerJson::EliminarObjetos(int proy, int nivel, int obj)
{
    string dot;
    cout << "Usted va a eliminar el objeto " << obj;
    /*dot = LGeneral->EliminarObj(proy, nivel, obj);
    MatrizDisp *Mat = new MatrizDisp(proy, nivel);
    Mat->GraficarMatriz(proy, nivel, dot); */
}
