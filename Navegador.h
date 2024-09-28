#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include<list>
#include<Windows.h>
#include"Vector.h"
#include"CargarSitiosWeb.h"

class Navegador{
private:
    list<Vector*> navegador;
    list<Vector*>::iterator iter; //con este siempre tenemos la pestaña actual
    list<PaginaWeb> paginasWeb;
    void navegarArriba(); // visibles solo para la propia clase Dentro de la clase
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
};
#endif // !NAVEGADOR_H