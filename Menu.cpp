#include "Menu.h"
#include <iostream>
#include <string>
#include <stdlib.h>
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
    int OpPrincipal;
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
            system("cls");
            menu.EditarProy();
            break;

        case 3:
            //cout << metodo.ConvertirAscci("casa ")<< endl;
            leerfile.RecibirArchivo();
            //leerjson.LeerJson("hola");
            menu.Opcion();
            break;

        case 4:

            break;

        case 5:

            break;

        case 6:
            leerfile.RecibirLibreria();
            menu.Opcion();
            break;

        default: cout<< "Ingrese un numero correcto" << endl;

    }
}

int Menu::EditarProy(void)
{
    Menu menu;
    LeerJson Archivos;
    int OpPrincipal;
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
            cout << "Opcion 1 " << endl;
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:
            Archivos.MostrarObjetos();
            break;

        case 6:

            break;

        case 7:
            Archivos.MostrarObjetos();

            break;

        case 8:

            break;

        case 9:

            break;

        case 10:

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

