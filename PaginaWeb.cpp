#include "PaginaWeb.h"

PaginaWeb::PaginaWeb(string u, string d, string t) : url(u),dominio(d),titulo(t){
}

string PaginaWeb::getUrl()
{
    return url;
}

string PaginaWeb::getTitulo()
{
    return titulo;
}
