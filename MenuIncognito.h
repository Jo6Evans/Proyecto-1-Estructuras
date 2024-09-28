#ifndef MENUINCOGNITO_H
#define MENUINCOGNITO_H
#include <sstream>
#include <iostream>
#include "Vector.h"
#include "Sitioweb.h"
#include "Navegador.h"
#include <conio.h>
using namespace std;

class MenuIncognito{
private:
	Navegador* navegador;
	void accederSitioWeb();
public:
	MenuIncognito();
	~MenuIncognito();
	void mostrarIncognito();
	void subMenuIncognito(int);
	void aux();
};
#endif // !MENUINCOGNITO_H