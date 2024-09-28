#ifndef VECTOR_H
#define VECTOR_H
#include"Sitioweb.h"
#include<Windows.h>
#include<vector>
class Vector{ //es historial
private:
	int actual;
	vector<Sitioweb*> historial;
public:
	Vector();
	~Vector();
	void agregarSitio(Sitioweb*);
	string mostrarHistorial(); //(tostring)
	string mostrarActual();   //(tostring 2)
	string mostrarMarcadores(); //(tostring 3)
	string navegar(char);
	vector<Sitioweb*> getHistorial(); //retorna todo el historial
	void agregarMarcador();
	void eliminarMarcador();
	void modificarCapacidad(int);
	bool verificarHistorial(); //verificar que hay al menos una pagina web dentro del historial
};
#endif // !VECTOR_H