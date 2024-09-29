#ifndef MENU_H
#define MENU_H
#include <sstream>
#include <iostream>
#include <conio.h>
#include <chrono> //para manejar la hora actual
#include <thread> //para el hilo (tiempo)
#include <future>
#include "Vector.h"
#include "Sitioweb.h"
#include "Navegador.h"
#include "MenuIncognito.h"
#include "Serializar.h"
using namespace std;

class Menu {
private:
	Navegador* navegador;
	int criterioDeEliminado; //cada cuantos minutos se elminan las paginas
	int horaInicio;
	bool bandera; //para que valide si se tiene que eliminar o no el historial de la pestana actual
	void accederSitioWeb();
	void modoIncognito();
public:
	Menu();
	~Menu();
	void mostrar();
	void busquedaYfiltrado();
	void filtrado();
	void subMenu(int);
	void politicas();
	void obtenerHoraActual();
	void eliminarHistorial();
	void aux();
};
#endif // !MENU_H