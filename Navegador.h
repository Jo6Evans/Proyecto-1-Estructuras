#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include<list>
#include<Windows.h>
#include"Vector.h"
#include"CargarSitiosWeb.h"

class Navegador{
private:
    list<Vector*> navegador;
    list<Vector*>::iterator iter; //con este siempre tenemos la pesta�a actual
    list<PaginaWeb> paginasWeb; //lista de paginas web
    void navegarArriba(); // metodos visibles solo para la propia clase y Dentro de la clase
    void navegarAbajo();
public:
    Navegador();
    ~Navegador();
    void setNavegador(list<Vector*>);
    void agregarPestana();
    bool verificaPestania();
    void navegar(char);
    list<Vector*> getNavegador();
    void navegarHistorial(char);
    void mostrarActual();
    void agregarSitioWeb(string);
    void agregarMarcador();
    void eliminarMarcador();
    void modificarCapacidad(int);
    void mostrarHistorial(); //de pestana actual
    void mostrarMarcadores();
    bool verificarHistorial();
    void mostrarBusqueda(string);
    vector<Sitioweb*> navegarFiltro(string);
    void eliminarHistorial();

};
#endif // !NAVEGADOR_H