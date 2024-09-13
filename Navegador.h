#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include<list>
#include<Windows.h>
#include"Vector.h"

class Navegador{
private:
    list<Vector*> navegador;
    list<Vector*>::iterator iter;
    void navegarArriba(); // visibles solo para la propia clase Dentro de la clase
    void navegarAbajo();
public:
    Navegador();
    void agregarPestana();
    bool verificaPestania();
    void navegar(char);
    void mostrarActual();
};
#endif // !NAVEGADOR_H