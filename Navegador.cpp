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

Navegador::Navegador() { //carga las paginas web en una lista de vectores
	paginasWeb = CargarSitiosWeb::cargarSitiosWeb();
}

Navegador::~Navegador() { //O(n)
	for (auto it = navegador.begin(); it != navegador.end(); ++it) {
		delete* it;  // Liberar la memoria del vector
	}
	navegador.clear();
}

void Navegador::setNavegador(list<Vector*> nav) {
	navegador = nav;
	iter = navegador.end();
	iter--;
}

void Navegador::agregarPestana() { //creando pestana y agregandola O(1)
	Vector* pestania = new Vector();
	navegador.push_back(pestania);
	iter = navegador.end(); //esto apunta a null entonces 
	iter--;					//se disminuye la posicion o mueve para la izquierda (n-1) para estar en la ultima pestana (objeto) agregada
}

bool Navegador::verificaPestania() { //verificacion con un if siendo true si la cantidad de pestanas del navegador es > 0, retorna false si no
	return navegador.size() == 0 ? false : true;
}

void Navegador::navegar(char tecla) {// moverse arriba y abajo porque es entre PESTANAS
	if (verificaPestania())
		switch (tecla) {
		case 72:
			navegarArriba();
			break;
		case 80:
			navegarAbajo();
			break;
		}
}

list<Vector*> Navegador::getNavegador() { //devuelve el V ector o sea el historial con las paginas
	return navegador;
}

void Navegador::navegarHistorial(char c) {
	if (verificaPestania())
		if (verificarHistorial())
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
			cout << "\n\n-Sitio web encontrado-\n\n";
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
}

void Navegador::agregarMarcador() {
	(*iter)->agregarMarcador();
	cout << "Marcador agregado\n\n";
}

void Navegador::eliminarMarcador() {
	(*iter)->eliminarMarcador();
	cout << "Marcador eliminado\n\n";
}

void Navegador::modificarCapacidad(int c) {
	(*iter)->modificarCapacidad(c);
}

void Navegador::mostrarHistorial() {
	cout << (*iter)->mostrarHistorial();
}

void Navegador::mostrarMarcadores() {
	list<Vector*>::iterator iterAux = navegador.begin();
	while (iterAux != navegador.end()) {
		cout << (*iterAux)->mostrarMarcadores();
		iterAux++;
	}
}

bool Navegador::verificarHistorial() {
	return (*iter)->verificarHistorial();
}

void Navegador::mostrarBusqueda(string fragmento) {
	cout << (*iter)->mostrarBusqueda(fragmento);
}

vector<Sitioweb*> Navegador::navegarFiltro(string filtro) {
	return (*iter)->navegaFiltro(filtro);
}

void Navegador::eliminarHistorial() {
	(*iter)->eliminarHistorial();
}
