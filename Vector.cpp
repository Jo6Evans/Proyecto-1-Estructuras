#include "Vector.h"

Vector::Vector() {
	historial.reserve(20); //reservar 20 posiciones de memoria para cada historial de cada pestana
	actual = -1;		   //se tiene que empezar en 0, para que cuando se agregue empiece desde 0 y no desde 1
}

Vector::~Vector(){
	for (auto sitio : historial) {
		delete sitio;  // Liberar la memoria del objeto Sitioweb
	}
	historial.clear();
}

void Vector::agregarSitio(Sitioweb* s) {
	if (historial.size() < historial.capacity()) {  //verificar que la capacidad sea mayor a la cantidad
		historial.push_back(s);		//agregando
		actual++;
	}
	else
		cout << "\nSe llego a la capacidad maxima del historial para la pestania\n";
}

string Vector::mostrarHistorial() { //muestra todo el historial
	stringstream s;
	for (int i = 0; i < historial.size(); i++) {
		s << historial[i]->toString();
	}
	return s.str();
}

string Vector::mostrarActual() {  //muestra el sitio web actual
	return historial[actual]->toString();
}

string Vector::mostrarMarcadores() //probar
{
	stringstream s;
	for (int i = 0; i < historial.size(); i++) {
		if (historial[i]->getMarcador())
			s << historial[i]->toString();
	}
	return s.str();
}

string Vector::navegar(char tecla) { //las teclas son derecha e izquierda porque son los sitios web
//	if (actual > -1)
		switch (tecla) {
		case 77:
			actual++;
			if (actual < historial.size())
				return mostrarActual();
			else {
				actual--;
				return mostrarActual();
			}
			break;
		case 75:
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

vector<Sitioweb*> Vector::getHistorial(){
	return historial;
}

void Vector::agregarMarcador() { //se setea en true porque si esta marcado 
	historial[actual]->setMarcador(true);
}

void Vector::eliminarMarcador() { //se setea en false porque no esta marcado 
	historial[actual]->setMarcador(false);
}

void Vector::modificarCapacidad(int c) {
	if (c > historial.size())	//se verifica que la entrada sea mayor a la capacidad
		historial.resize(c);
	else
		cout << "\nNo se puede limitar la cantidad de entradas en el historial ya que se perderia parte del historial existente\n";
}

bool Vector::verificarHistorial() {

	return actual > -1;
}
