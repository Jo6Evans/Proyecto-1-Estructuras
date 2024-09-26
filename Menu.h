#ifndef MENU_H
#define MENU_H
#include <sstream>
#include <iostream>
#include "Vector.h"
#include "Sitioweb.h"
#include "Navegador.h"
#include <conio.h>
using namespace std;

class Menu {
private:
	Navegador* navegador;
	void accederSitioWeb();
public:
	Menu();
	void mostrar();
	void subMenu(int);
	void aux();
};


#endif // !MENU_H
