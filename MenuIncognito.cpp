#include "MenuIncognito.h"

void MenuIncognito::accederSitioWeb() {
	string url;
	if (navegador->verificaPestania()) {
		cout << "Digite la URL del sitio web al que quiere acceder: ";
		cin >> url;

		navegador->agregarSitioWeb(url);
	}
	else
		cout << "Debe aniadir una pestania antes.\n";
}

MenuIncognito::MenuIncognito() {
	navegador = new Navegador();
}

MenuIncognito::~MenuIncognito() {
	delete navegador;
}

void MenuIncognito::mostrarIncognito() {
	char decision;
	int opc = 1;
	do {
		if (navegador->verificaPestania())
			if (navegador->verificarHistorial())
				navegador->mostrarActual();

		cout << "---------------- Menu de opciones ---------------\n"
			<< "| 1. Acceder a un sitio web				|\n"
			<< "| 2. Aniadir pestanias					|\n"
			<< "| 3. Salir de modo incognito			|\n"
			<< "-------------------------------------------------\n";
		decision = _getch();
		if (decision == 0 || decision == -32) {
			decision = _getch();
			if (decision == 75 || decision == 77) {
				opc = 0;
				system("cls");
				navegador->navegarHistorial(decision);
			}
			else if (decision == 72 || decision == 80) {
				opc = 0;
				system("cls");
				navegador->navegar(decision);
			}
		}
		else
			opc = decision - '0';

		cout << "\n";
		subMenuIncognito(opc);

	} while (opc != 3);
}

void MenuIncognito::subMenuIncognito(int opcion) {
	int subOpc;

	switch (opcion) {
	case 1:
		accederSitioWeb();
		aux();
		break;
	case 2:
		navegador->agregarPestana();
		aux();
		break;

	case 3:
		cout << "Saliendo de modo incognito\n";
		aux();
		break;

	default:
		break;
	}
}

void MenuIncognito::aux() {
	system("pause");
	system("cls");
}
