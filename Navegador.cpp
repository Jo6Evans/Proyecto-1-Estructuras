#include "Navegador.h"

void Navegador::navegarArriba() {
	list<Vector*>::iterator iterFin = navegador.end(); //ve al null o sea fin de la lista de pestanas
	iter++;//avanzar
	if (iter == iterFin)
		iter--;
}

void Navegador::navegarAbajo() {
	if (iter != navegador.begin())
		iter--;//devolverse
}

Navegador::Navegador() {
	paginasWeb = CargarSitiosWeb::cargarSitiosWeb();
}

void Navegador::agregarPestana() { //creando pestana y agregandola
	Vector* pestania = new Vector();
	navegador.push_back(pestania);
	iter = navegador.end(); //esto apunta a null entonces 
	iter--;					//se disminuye la posicion o mueve para la izquierda (n-1) para estar en la ultima pestana (objeto) agregada
}

bool Navegador::verificaPestania() { //un if que si la cantidad de pestanas del navegador es 0 retorna false sino true
	return navegador.size() == 0 ? false : true;
}

void Navegador::navegar(char tecla) {// arriba y abajo porque es entre pestanas
	switch (tecla) {
	case 72:
		navegarArriba();
		break;
	case 80:
		navegarAbajo();
		break;
	}
}

void Navegador::navegarHistorial(char c){
	(*iter)->navegar(c);
}

void Navegador::mostrarActual() {
	cout << (*iter)->mostrarActual();
}

void Navegador::agregarSitioWeb(string url) {
	Sitioweb* sitio = new Sitioweb();
	for (PaginaWeb p : paginasWeb) {
		if (p.getUrl() == url) {
			sitio->setTitulo(p.getTitulo());
			sitio->setUrl(url);
			break;
		}
	}
	if (sitio->getTitulo() != "404 - NOT FOUND") 
		(*iter)->agregarSitio(sitio);
	else {
		cout << sitio->toString();
		Sleep(2000);
		system("cls");
	}
	mostrarActual();
}

void Navegador::agregarMarcador(){
	(*iter)->agregarMarcador();
}

void Navegador::eliminarMarcador(){
	(*iter)->eliminarMarcador();
}

void Navegador::modificarCapacidad(int c){
	(*iter)->modificarCapacidad(c);
}

void Navegador::mostrarHistorial(){
	cout << (*iter)->mostrarHistorial();
}

bool Navegador::verificarHistorial(){
	return (*iter)->verificarHistorial();
}
