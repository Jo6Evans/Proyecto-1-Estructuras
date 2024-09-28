#ifndef MENU_H
#define MENU_H
#include <sstream>
#include <iostream>
#include <conio.h>
#include "Vector.h"
#include "Sitioweb.h"
#include "Navegador.h"
#include "MenuIncognito.h"
#include "Serializar.h"
using namespace std;

class Menu {
private:
	Navegador* navegador;
	void accederSitioWeb();
	void modoIncognito();
public:
	Menu();
	~Menu();
	void mostrar();
	void subMenu(int);
	void aux();
};
#endif // !MENU_H