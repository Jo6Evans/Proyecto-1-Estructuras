#ifndef PRUEBAUNIDAD_H
#define PRUEBAUNIDAD_H
#include <conio.h>
#include "Vector.h"
#include "Navegador.h"

class PruebaUnidad {
private:
	Vector* vec;
	Navegador* nav;
public:
	PruebaUnidad();
	~PruebaUnidad();

	void pruebaTeclas();
	void pruebaPestania();
	void pruebaCapacidad();
	void pruebaAgregarSitio();
	void pruebaHistorial();
	void pruebaAniadirMarcador();
	void pruebaMostrarMarcador();
	void pruebaEliminarMarcador();
	void pruebaVerificarHistorial();
};
#endif // !PRUEBAUNIDAD_H