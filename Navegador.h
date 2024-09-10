#ifndef NAVEGADOR_H
#define NAVEGADOR_H
#include<list>
#include<Windows.h>
#include"Vector.h"

class Navegador{
private:
    list<Vector> navegador;
public:
    Navegador();
    void agregarPestana();

};
#endif // !NAVEGADOR_H