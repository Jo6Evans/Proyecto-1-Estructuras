#ifndef CARGARSITIOSWEB_H
#define CARGARSITIOSWEB_H
#include<fstream>
#include<string>
#include"PaginaWeb.h"
#include<list>
class CargarSitiosWeb {
public:
	static list<PaginaWeb> cargarSitiosWeb();
};
#endif // !CARGARSITIOSWEB_H