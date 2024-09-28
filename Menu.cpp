#include "Menu.h"
#include "Navegador.h"

void Menu::accederSitioWeb() {
	string url;
	if (navegador->verificaPestania()) {
		cout << "Digite la URL del sitio web al que quiere acceder: ";
		cin >> url;

		navegador->agregarSitioWeb(url);
	}
	else
		cout << "Debe aniadir una pestania antes.\n";
}

void Menu::modoIncognito() {
	//Navegacion privada
	system("cls");
	MenuIncognito* menuI = new MenuIncognito();
	menuI->mostrarIncognito();
	aux();
	delete menuI;
}

Menu::Menu() {
	navegador = new Navegador();
}

Menu::~Menu() {
	delete navegador;
}

void Menu::mostrar() {
	char decision;
	int opc = 1;
	do {
		if (navegador->verificaPestania())
			if (navegador->verificarHistorial())
				navegador->mostrarActual();

		cout << "---------------- Menu de opciones ---------------\n"
			<< "| 1. Acceder a un sitio web						|\n"	//solo si existe al menos 1 pestana
			<< "| 2. Aniadir pestanias					|\n"			//crear y eliminar pestanas
			<< "| 3. Sistema de marcadores					|\n"		//setear si es marcador o no
			<< "| 4. Busqueda y filtrado de historial		|\n"
			<< "| 5. Navegacion privada						|\n"
			<< "| 6. Importar historial					|\n"
			<< "| 7. Exportar historial					|\n"
			<< "| 8. Politicas de administracion del historial  |\n" //cambiar cantidad de entradas de historial y el tiempo que permanecen en el historial
			<< "| 9. Salir								|\n"
			<< "-------------------------------------------------\n";
		decision = _getch();
		if (decision == 0 || decision == -32) {
			decision = _getch();
			if (decision == 75 || decision == 77) { //codigos de las teclas izquierda y derecha respectivamente
				opc = 0;
				system("cls");
				//aux();
				navegador->navegarHistorial(decision);
			}
			else if (decision == 72 || decision == 80) {//codigos de las teclas arriba y abajo respectivamente
				opc = 0;
				system("cls");
				//aux();
				navegador->navegar(decision);
			}
		}
		else //if(decision >= '0' && decision <= '9')
			opc = decision - '0'; //se puede asignar al int porque siempre tiene el valor de un numero entero, se resta '0' porque sino da el valor ASCII

		cout << "\n";
		subMenu(opc);

	} while (opc != 9);
}

void Menu::subMenu(int opcion) {
	int subOpc;

	switch (opcion) {
	case 1:
		//Funcion para acceder a una web
		accederSitioWeb();
		aux();
		break;
	case 2:
		//Administrar las pesta�as
		navegador->agregarPestana();
		aux();
		break;

	case 3:
		if (navegador->verificaPestania() && navegador->verificarHistorial()) {
			//Sistema de marcadores
			cout << "----- Sistema de Marcadores -----\n"
				<< "| 1. Agregar marcador.	     	 |\n"
				<< "| 2. Eliminar marcador.	     	 |\n"
				<< "| 3. Mostrar marcadores.         |\n"
				<< "---------------------------------\n";
			cin >> subOpc;
			switch (subOpc) {
			case 1:
				navegador->agregarMarcador();
				break;
			case 2:
				navegador->eliminarMarcador();
				break;
			case 3:
				navegador->mostrarMarcadores();
				break;
			default:
				cout << "Opcion invalida\n";
				break;
			}
		}
		else
			cout << "Debe aniadir al menos una pestania y un sitio web antes...\n";
		aux();
		break;

	case 4:
		//Busqueda de historial
		//cout << vec->mostrarHistorial();
		aux();
		break;

	case 5:
		modoIncognito();
		break;
	case 6:
		//Importar historial
		navegador->setNavegador(Serializar::deserializar());
		aux();
		break;

	case 7:
		//Exportar historial
		if (navegador->verificaPestania() && navegador->verificarHistorial()) {
			Serializar::serializar(navegador->getNavegador());
			cout << "Historial exportado exitosamente\n";
		}
		else
			cout << "Debe aniadir al menos una pestania y un sitio web antes...\n";
		aux();
		break;

	case 8:
		//Politicas

		aux();
		break;

	default:
		break;
	}
}

void Menu::aux() {
	system("pause");
	system("cls");
}
