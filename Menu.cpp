#include "Menu.h"
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "MatrizDisp.h"
#include "ObjetoM.h"
#include "Metodos.h"
#include "LeerJson.h"
#include "ArbolAVL.h"

using namespace std;

int Menu::Principal(void)
{
    //MatrizDisp *matriz = new MatrizDisp();
    Metodos metodo;
    Menu menu;
    LeerJson leerfile;
    ArbolAVL Avl;
    //ArbolAVL *AVL = new ArbolAVL();
    int OpPrincipal, NumProy;
    system("color 57");
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|              ELIJA UNA OPCION             |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. Ver proyectos                         |"<<endl;
    cout<<" \t|  2. Editar proyectos                      |"<<endl;
    cout<<" \t|  3. Cargar proyecto                       |"<<endl;
    cout<<" \t|  4. Graficar proyectos                    |"<<endl;
    cout<<" \t|  5. Guardar proyectos                     |"<<endl;
    cout<<" \t|  6. Cargar librerias                      |"<<endl;
    cout<<" \t|  7. Ver reportes                          |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> OpPrincipal;
    switch (OpPrincipal)
    {
        case 1:
            /*AVL->NuevoNodo(5, "hoy");
            AVL->NuevoNodo(4, "sientes");
            AVL->NuevoNodo(3, "te");
            AVL->NuevoNodo(2, "Como");
            AVL->NuevoNodo(1, "Hola");*/
            //AVL->GraficarArbol(AVL->getRaiz());
            cout << "Arbol AVL de proyectos" << endl;
            leerfile.MostrarProy();
            //AVL->inorden(AVL->getRaiz());
            menu.Opcion();

            break;

        case 2:
            //system("cls");
            leerfile.MostrarProy();
            cout << "Elija el numero del proyecto " << endl;
            cin >> NumProy;
            if (leerfile.VerificarProy(NumProy) == true)
            {
                menu.EditarProy(NumProy);
            }
            else
            {
                cout << "Numero invalido " << endl;
                menu.Opcion();
            }


            break;

        case 3:
            //cout << metodo.ConvertirAscci("casa ")<< endl;
            leerfile.RecibirArchivo();
            //leerjson.LeerJson("hola");
            menu.Opcion();
            break;

        case 4:
            system("start AVL.png");
            menu.Opcion();
            break;

        case 5:
            menu.Opcion();
            break;

        case 6:
            leerfile.RecibirLibreria();
            menu.Opcion();
            break;

        case 7:
            system("start AVL.png");
            system("start ABB.png");
            cout << "3. Proyectos con mayor numero de niveles       Descendente  " << endl;
            cout << "4. Proyectos con mayor numero de niveles       Ascendente  " << endl;
            menu.Opcion();
            break;

        default: cout<< "Ingrese un numero correcto" << endl;

    }
}

int Menu::EditarProy(int Proy)
{
    Menu menu;
    Metodos metodo;
    LeerJson Archivos;
    int OpPrincipal, NumObj, NumNivel;
    char Eli[100];
    string Nivel;
    system("color 75");
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|              ELIJA UNA OPCION             |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. Agregar nivel                         |"<<endl;
    cout<<" \t|  2. Editar nivel                          |"<<endl;
    cout<<" \t|  3. Copiar nivel                          |"<<endl;
    cout<<" \t|  4. Crear cant. pisos                     |"<<endl;
    cout<<" \t|  5. Agregar objeto                        |"<<endl;
    cout<<" \t|  6. Mover objeto                          |"<<endl;
    cout<<" \t|  7. Eliminar objeto                       |"<<endl;
    cout<<" \t|  8. Eliminar pared                        |"<<endl;
    cout<<" \t|  9. Eliminar nivel                        |"<<endl;
    cout<<" \t|  10. Eliminar proyecto                    |"<<endl;
    cout<<" \t|  11. Salir                                |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> OpPrincipal;
    switch (OpPrincipal)
    {
        case 1:
            Archivos.RecibirNivel(Proy);
            menu.Opcion();
            break;

        case 2:
            Archivos.Niveles(Proy);
            menu.Opcion();
            break;

        case 3:
            menu.Opcion();

            break;

        case 4:
            menu.Opcion();

            break;

        case 5:
            Archivos.MostrarObjetos();
            menu.Opcion();
            break;

        case 6:
            menu.Opcion();

            break;

        case 7:
            Archivos.MostrarObjetos();
            cout << "Ingrese el numero del objeto que desee eliminar" << endl;
            cin >> NumObj;
            if (Archivos.VerificarObj(NumObj) == true)
            {
                Archivos.EliminarObjetos(Proy, 1, NumObj);
            }
            else
                cout << "Numero de identificador incorrecto " << endl;

            menu.Opcion();


            break;

        case 8:
            menu.Opcion();

            break;

        case 9:
            cout << "Que nivel desea eliminar " << endl;
            cin >> NumNivel;

            Nivel = "Matriz" + metodo.ConvtirIntString(Proy) + metodo.ConvtirIntString(NumNivel) + ".png";
            strcpy(Eli, Nivel.c_str());
            remove(Eli);
            cout << "Nivel eliminado exitosamente " << endl;
            menu.Opcion();
            break;

        case 10:
            menu.Opcion();

            break;

        case 11:
            system("cls");
            menu.Principal();
            break;

        default: cout<< "Ingrese un numero correcto" << endl;

    }
}

int Menu::Opcion(void)
{
    Menu menu;
    int Op;
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|              ELIJA UNA OPCION             |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  1. Menu principal                        |"<<endl;
    cout<<" \t|  2. Salir                                 |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> Op;
    switch (Op)
    {
        case 1:
            system("cls");
            menu.Principal();
            break;

        case 2:
            system("cls");
            break;

    }
}

