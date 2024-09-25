#ifndef MENU_H
#define MENU_H
#include <sstream>
#include <iostream>
#include "Vector.h"
#include "Sitioweb.h"
#include "Navegador.h"
using namespace std;
	
class Menu {
private:
public:
	void mostrar();
	void subMenu(int);
	void aux();
};


#endif // !MENU_H
