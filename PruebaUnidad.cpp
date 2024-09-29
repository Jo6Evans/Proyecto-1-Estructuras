#include "PruebaUnidad.h"

PruebaUnidad::PruebaUnidad() {
	vec = new Vector();
	nav = new Navegador();
}

PruebaUnidad::~PruebaUnidad() {
	delete vec;
	delete nav;
}

void PruebaUnidad::pruebaTeclas() {
	cout << "-Probando flechas-\n\n";
	char tecla;
	tecla = _getch();
	if (tecla == 0 || tecla == -32) {
		tecla = _getch();
		//if (tecla == 75 || tecla == 77) { //codigos de las teclas izquierda y derecha respectivamente
		//	system("cls");
		//	cout << "Flecha izquierda\n";
		//}
		//else if (tecla == 72 || tecla == 80) {//codigos de las teclas arriba y abajo respectivamente
		//	system("cls");
		//	cout << "Flecha arriba\n";
		//}

		switch (tecla) {
		case 75:
			cout << "Flecha izquierda\n";
			break;
		case 77:
			cout << "Flecha derecha\n";
			break;

		case 72:
			cout << "Flecha arriba\n";
			break;

		case 80:
			cout << "Flecha abajo\n";
			break;

		}

	}

}

void PruebaUnidad::pruebaPestania() {
	cout << "\n\n-Probando verificar pestania-\n\n";

	if (nav->verificaPestania()) {
		cout << "Pestania verificada\n";
	}
	else {
		cout << "Error en verificar pestania\n";
	}
}

void PruebaUnidad::pruebaCapacidad() {
	cout << "\n\n-Probando aumentar capacidad-\n\n";
	int c = 6;
	vec->modificarCapacidad(c);
}

void PruebaUnidad::pruebaAgregarSitio() {
	cout << "\n\n-Probando agregar Sitio Web-\n\n";
	nav->agregarPestana();
	string url1 = "www.x.com";
	string url2 = "www.facebook.com";
	nav->agregarSitioWeb(url1);
	nav->agregarSitioWeb(url2);
}

void PruebaUnidad::pruebaHistorial() {
	cout << "\n\n-Probando mostrar historial-\n\n";
	nav->mostrarHistorial();
}

void PruebaUnidad::pruebaAniadirMarcador() {
	cout << "\n\n-Probando agregar marcador-\n\n";
	nav->agregarMarcador();
	nav->mostrarHistorial();
}

void PruebaUnidad::pruebaMostrarMarcador() {
	cout << "\n\n-Probando mostrar marcadores-\n\n";
	nav->mostrarMarcadores();
}

void PruebaUnidad::pruebaEliminarMarcador() {
	cout << "\n\n-Probando eliminar marcador-\n\n";
	nav->eliminarMarcador();
	nav->mostrarHistorial();
}

void PruebaUnidad::pruebaVerificarHistorial() {
	cout << "\n\n-Probando verificar historial-\n\n";
	if (nav->verificarHistorial()) {
		cout << "Historial verificado\n";
	}
	else {
		cout << "Error en verificar historial\n";
	}
}