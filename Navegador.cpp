#include "Navegador.h"

void Navegador::navegarArriba() {
	list<Vector*>::iterator iterFin = navegador.end(); //ve al null o sea fin de la lista de pestanas
	iter++;//avanzar
	if (iter != iterFin)
		mostrarActual();
	else {
		iter--;
		mostrarActual();
	}
}

void Navegador::navegarAbajo() {
	list<Vector*>::reverse_iterator iterFin = navegador.rend(); //ve al principio null de la lista de pestanas
	iter--; //devolverse
	if (iter != --iterFin.base()) //comparar con el base()-1 porque esta +1 del normal
		mostrarActual();
	else {						  //si es igual es porque ven a nulo entonces tiene que avanzar/quedarse en la posicion 0 y no -1
		iter++;
		mostrarActual();
	}
}

Navegador::Navegador() { }

void Navegador::agregarPestana() { //creando pestana y agregandola
	Vector* pestania = new Vector();
	navegador.push_back(pestania);
	iter = navegador.end(); //esto apunta a null entonces 
	iter--;					//se disminuye la posicion o mueve para la izquierda para estar en la ultima pestana (objeto) agregada
}

bool Navegador::verificaPestania() { //un if que si la cantidad de pestanas del navegador es 0 retorna false sino true
	return navegador.size() == 0 ? false : true;
}

void Navegador::navegar(char tecla) {// arriba y abajo porque es entre pestanas
	switch (tecla) {
	case 'W':
		navegarArriba();
		break;
	case 'S':
		navegarAbajo();
		break;
	}
}

void Navegador::mostrarActual(){
	(*iter)->mostrarActual();
}
