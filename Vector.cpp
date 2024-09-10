#include "Vector.h"

Vector::Vector() {
	historial.reserve(20); //reservar 20 posiciones de memoria para cada historial de cada pestana
	actual = 0;
}

void Vector::agregarSitio(Sitioweb* s) {
	if (historial.size() < historial.capacity()) {  //verificar que la capacidad sea mayor a la cantidad
		historial.push_back(s);		//agregando
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

string Vector::navegar(char tecla) { //las teclas son derecha e izquierda porque son los sitios web
	switch (tecla) {
	case 'D':
		actual++;
		return mostrarActual();
		break;
	case 'I':
		actual--;
		return mostrarActual();
		break;
	default:
		return mostrarActual();
		break;
	}
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