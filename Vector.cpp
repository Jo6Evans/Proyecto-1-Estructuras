#include "Vector.h"

Vector::Vector() {
	historial.reserve(20); //reservar 20 posiciones de memoria para cada historial de cada pestana
	actual = -1;		   //se tiene que empezar en 0, para que cuando se agregue empiece desde 0 y no desde 1
	cantElementos = 20;
}

Vector::~Vector() {
	eliminarHistorial();
}

void Vector::agregarSitio(Sitioweb* s) {
	if (historial.size() < cantElementos) {  //verificar que la capacidad sea mayor a la cantidad
		historial.push_back(s);		//agregando
		actual++;
	}
	else
		cout << "\nSe llego a la capacidad maxima del historial para la pestania\n"<<"El ultimo sitio web no se aniadira\n\n";
}

string Vector::mostrarHistorial() { //muestra todo el historial O(n)
	stringstream s;
	for (int i = 0; i < historial.size(); i++) {
		s << historial[i]->toString();
	}
	return s.str();
}

string Vector::mostrarActual() {  //muestra el sitio web actual
	return historial[actual]->toString();
}

string Vector::mostrarMarcadores() //O(n)
{
	stringstream s;
	for (int i = 0; i < historial.size(); i++) {
		if (historial[i]->getMarcador())
			s << historial[i]->toString();
	}
	return s.str();
}

string Vector::mostrarBusqueda(string fragmento) { //fragmento dentro de lo buscado O(n)
	bool noExiste = true; //sitio con fragmento en la url
	stringstream s;
	s << "\nSitios que contienen: '" << fragmento << "': \n\n";
	for (int i = 0; i < historial.size(); i++) {
		if (historial[i]->getUrl().find(fragmento) != string::npos) {
			s << historial[i]->toString();
			noExiste = false;
		}
	}
	if (noExiste)
		s << "\nNo se ha encontrado ningun sitio web que contenga en su url: '"<<fragmento<<"'\n\n";
	return s.str();
}

string Vector::navegar(char tecla) { //las teclas son derecha e izquierda porque son los sitios web
	switch (tecla) {
	case 77:			//ir hacia la derecha
		actual++;
		if (actual < historial.size())
			return mostrarActual();
		else {
			actual--;
			return mostrarActual();
		}
		break;
	case 75:			//ir hacia la izquierda(devolverse)
		actual--;
		if (actual >= 0)
			return mostrarActual();
		else {
			actual++;
			return mostrarActual();
		}
		break;
	default:
		return mostrarActual();
		break;
	}
}

vector<Sitioweb*> Vector::getHistorial() {
	return historial;
}

void Vector::agregarMarcador() { //se setea en true porque si esta marcado 
	historial[actual]->setMarcador(true);
}

void Vector::eliminarMarcador() { //se setea en false porque no esta marcado 
	historial[actual]->setMarcador(false);
}

void Vector::modificarCapacidad(int c) {
	if (c > historial.size() && c > 0)	//se verifica que la entrada sea mayor a la capacidad
		cantElementos = c;
	else
		cout << "\nNo se puede limitar la cantidad de entradas en el historial ya que se perderia parte del historial existente\n";
}

bool Vector::verificarHistorial() {
	return actual > -1;
}

vector<Sitioweb*> Vector::navegaFiltro(string filtro) { //O(n)
	vector<Sitioweb*> vectorAux;
	for (int i = 0; i < historial.size(); i++) {
		if (historial[i]->getUrl().find(filtro) != string::npos)
			vectorAux.push_back(historial[i]);
	}
	return vectorAux;
}

void Vector::eliminarHistorial(){
	for (auto sitio : historial) {
		delete sitio;  // Liberar la memoria del objeto Sitioweb
	}
	historial.clear();
	actual = -1; // resetear todo, cuando se elimina, el actual sigue en la posicion u objeto existente, al eliminar todo; si este no se resetea, se cae: acceso a espacio de memoria nulo
}
