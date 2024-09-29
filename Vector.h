#ifndef VECTOR_H
#define VECTOR_H
#include"Sitioweb.h"
#include<Windows.h>
#include<vector>
class Vector{ //es el Historial, Vector/Historial. historial de sitios web l.10
private:
	int actual;
	int cantElementos;
	vector<Sitioweb*> historial; 
public:
	Vector();
	~Vector();
	void agregarSitio(Sitioweb*);

	string mostrarHistorial(); //(tostring)
	string mostrarActual();   //(tostring 2)
	string mostrarMarcadores(); //(tostring 3)
	string mostrarBusqueda(string); //(tostring 4) para la parte de busqueda (y filtro)
	string navegar(char);
	vector<Sitioweb*> getHistorial(); //retorna todo el historial

	void agregarMarcador();
	void eliminarMarcador();
	void modificarCapacidad(int);
	void eliminarHistorial();

	bool verificarHistorial(); //verificar que hay al menos una pagina web dentro del historial
	vector<Sitioweb*> navegaFiltro(string); //para el filtrado navegacion
};
#endif // !VECTOR_H