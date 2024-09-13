#ifndef PAGINAWEB_H
#define PAGINAWEB_H
#include<iostream>
#include<sstream>

using namespace std;
class PaginaWeb {
private:
	string url, dominio, titulo;
public:
	PaginaWeb(string,string,string);
	string getUrl();
	string getTitulo();
};

#endif // !PAGINAWEB_H


