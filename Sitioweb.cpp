#include "Sitioweb.h"
Sitioweb::Sitioweb() {
	URL = " - ";
	titulo = "404 - NOT FOUND";
	marcador = false;
}

Sitioweb::Sitioweb(string u, string t) : URL(u), titulo(t), marcador(false) { }

void Sitioweb::setUrl(string u) { URL = u; }
void Sitioweb::setTitulo(string t) { titulo = t; }

void Sitioweb::setMarcador(bool ma) { marcador = ma; }

string Sitioweb::getUrl() { return URL; }
string Sitioweb::getTitulo() { return titulo; }

bool Sitioweb::getMarcador() {
	return marcador;
}

string Sitioweb::toString() {
	stringstream s;
	s << "\t\t" << URL;
	if (marcador)
		s << "   *\n";
	else
		s << "\n";
	s << "\t\t" << titulo << "\n\n";
	return s.str();
}