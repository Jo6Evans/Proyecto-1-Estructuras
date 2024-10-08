#ifndef SERIALIZAR_H
#define SERIALIZAR_H
#include <fstream>
#include<list>
#include "Vector.h" //el historial
#include "Navegador.h"

class Serializar {
private:
	static bool archivoVacio(ifstream&);
public:
	static void serializar(list<Vector*>);
	static list<Vector*> deserializar();
};
#endif // !SERIALIZAR_H