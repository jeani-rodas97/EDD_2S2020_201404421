#include <iostream>
#include <string>
#include <stdlib.h>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu;

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

    menu.Principal();

    return 0;
}
