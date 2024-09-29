#include "CargarSitiosWeb.h"

list<PaginaWeb> CargarSitiosWeb::cargarSitiosWeb(){ //O(1) carga las paginas creando una lista con el contenido del .csv
    ifstream archivo("sitiosweb.csv");
    string linea, url, dominio, titulo;
    list<PaginaWeb> paginas;
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo sitiosweb.csv\n\n";
        return list<PaginaWeb>();
    }
    while (getline(archivo, linea)) {
        stringstream s(linea);

        getline(s, url, ',');
        getline(s, dominio, ',');
        getline(s, titulo, ',');
        PaginaWeb pagina(url, dominio, titulo);
        paginas.push_back(pagina);
    }
    return paginas;
}