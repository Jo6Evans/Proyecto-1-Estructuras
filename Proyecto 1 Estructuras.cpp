// Proyecto 1 Estructuras.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Sitioweb.h"
#include"Vector.h"
#include"CargarSitiosWeb.h"
#include "Menu.h"
int main()
{
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