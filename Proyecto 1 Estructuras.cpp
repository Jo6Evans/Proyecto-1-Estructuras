// Proyecto 1 Estructuras.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//aLo

#include <iostream>
#include "Sitioweb.h"
#include"Vector.h"
#include"CargarSitiosWeb.h"
#include "Menu.h"
int main()
{
    list<int> lista;
    lista.push_back(1);
    lista.push_back(2);
    lista.push_back(3);
    lista.push_back(4);

    Menu menu;
    menu.mostrar();

    


    ////escucha para el movimiento entre pestanas y sitios web
    //while (true) {
    //    // Detectar si la flecha derecha fue presionada
    //    if (GetAsyncKeyState(VK_UP)) {
    //        cout << " a\n";
    //    }

    //    // Añadir una pequeña pausa para no sobrecargar el CPU
    //    Sleep(100);
    //}

    system("pause");
    return 0;
}