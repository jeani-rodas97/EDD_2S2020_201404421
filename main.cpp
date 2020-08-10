#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int menuPrincipal(void)
{
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
}

int main()
{
    int OpPrincipal;
    int uno = 1;
    //system("color 57");
    system("color 75");
    //system("color 5e");
    cout<<"\n\n\t ===========================================\n";
    cout<<"\t|            DATOS DEL ESTUDIANTE           |\n";
    cout<<"\t|===========================================|\n";
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  USAC                                     |"<<endl;
    cout<<" \t|  Estructuras de datos                     |"<<endl;
    cout<<" \t|  Seccion C                                |"<<endl;
    cout<<" \t|  Jeanifer Alejandra Garcia Rodas          |"<<endl;
    cout<<" \t|  201404421                                |"<<endl;
    cout<<" \t|                                           |"<<endl;
    cout<<" \t|  Presione 1 para continuar                |"<<endl;
    cout<<"\t ===========================================\n";

    cin >> uno ;
    system("cls");

    menuPrincipal();
    cin >> OpPrincipal;
    return 0;
}
