#include "Menu.h"

void Menu::mostrar() {
	int decision;
	int subOpc;
	Vector* vec = new Vector();

	do {
		cout << "---------------- Menu de opciones ---------------\n"
			<< "| 1. Acceder a un sitio web			|\n"	//solo si existe al menos 1 pestana
			<< "| 2. Administrador de pestanias			|\n" //crear y eliminar pestanas
			<< "| 3. Sistema de marcadores			|\n"		//setear si es marcador o no
			<< "| 4. Busqueda y filtrado de historial		|\n"
			<< "| 5. Navegacion privada				|\n"
			<< "| 6. Importar historial				|\n"
			<< "| 7. Exportar historial				|\n"
			<< "| 8. Politicas de administracion del historial  |\n" //cambiar cantidad de entradas de historial y el tiempo que permanecen en el historial
			<< "-------------------------------------------------\n";
		cin >> decision;
		system("cls");

		switch (decision) {
		case 1:
			//Funcion para acceder a una web
			
			aux();
			break;
		case 2:
			//Administrar las pestañas

			//vec->agregarSitio();
			aux();
			break;

		case 3:
			//Sistema de marcadores
			cout << "----- Sistema de Marcadores -----\n"
				<< "| 1. Agregar marcador.		|\n"
				<< "| 2. Eliminar marcador.		|\n"
				<< "---------------------------------\n";
			cin >> subOpc;
			if (subOpc == 1) {
				vec->agregarMarcador();
			}
			if (subOpc == 2) {
				vec->eliminarMarcador();
			}
			aux();
			break;

		case 4:
			//Busqueda de historial
			cout << vec->mostrarHistorial();
			aux();
			break;

		case 5:
			//Navegacion privada

			aux();
			break;

		case 6:
			//Importar historial

			aux();
			break;

		case 7:
			//Exportar historial

			aux();
			break;

		case 8:
			//Politicas

			aux();
			break;

		default:
			break;
		}
	} while (decision < 9 and decision > 0);
}

void Menu::subMenu(int opcion){
	switch (opcion){
	

	default:
		break;
	}
}

void Menu::aux(){
	system("pause");
	system("cls");
}
