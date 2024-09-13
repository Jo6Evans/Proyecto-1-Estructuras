#include "Menu.h"

Menu::Menu() {
	int decision;
	cout << "Menu de opciones\n"
		<< "1. Acceder a un sitio web\n"	//solo si existe al menos 1 pestana
		<< "2. Administrador de pestañas\n" //crear y eliminar pestanas
		<< "3. Sistema de marcadores\n"		//setear si es marcador o no
		<< "4. Busqueda y filtrado de historial\n"
		<< "5. Navegacion privada\n"
		<< "6. Importar historial\n"
		<< "7. Exportar historial\n"
		<< "8. Políticas de administración del historial\n"; //cambiar cantidad de entradas de historial y el tiempo que permanecen en el historial
	cin >> decision;

	switch (decision) {

	default:
		break;
	}
}
