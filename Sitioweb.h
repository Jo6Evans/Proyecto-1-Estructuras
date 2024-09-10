#ifndef SITIOWEB_H
#define SITIOWEB_H
#include<iostream>
#include<sstream>
using namespace std;

class Sitioweb{
private:
	string URL;
	string titulo;
	bool marcador;
public:
	Sitioweb();
	Sitioweb(string, string);

	void setUrl(string);
	void setTitulo(string);
	void setMarcador(bool);

	string getUrl();
	string getTitulo();
	bool getMarcador();

	string toString();
};
#endif // !SITIOWEB_H