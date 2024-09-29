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
	criterioDeEliminado = 20;
	bandera = true;
	obtenerHoraActual();
}

Menu::~Menu() {
	delete navegador;
}

void Menu::mostrar() {
	char tecla;
	int opc = 1;
	future<void> futuro = async(launch::async, &Menu::eliminarHistorial, this);
	do {
		if (navegador->verificaPestania())
			if (navegador->verificarHistorial())
				navegador->mostrarActual();

		cout << " ---------------- Menu de opciones ----------------\n"
			<< " | 1. Acceder a un sitio web                      |\n"	//solo si existe al menos 1 pestana
			<< " | 2. Aniadir pestanias                           |\n"	//crear y eliminar pestanas
			<< " | 3. Sistema de marcadores                       |\n"	//setear si es marcador o no
			<< " | 4. Busqueda y filtrado de historial            |\n"
			<< " | 5. Navegacion privada                          |\n"
			<< " | 6. Importar historial                          |\n"
			<< " | 7. Exportar historial                          |\n"
			<< " | 8. Politicas de administracion del historial   |\n" //cambiar cantidad de entradas de historial y el tiempo que permanecen en el historial
			<< " | 9. Salir                                       |\n"
			<< " --------------------------------------------------\n";
		tecla = _getch();
		if (tecla == 0 || tecla == -32) {
			tecla = _getch();
			if (tecla == 75 || tecla == 77) { //codigos de las teclas izquierda y derecha respectivamente
				opc = 0;
				system("cls");
				//aux();
				navegador->navegarHistorial(tecla);
			}
			else if (tecla == 72 || tecla == 80) {//codigos de las teclas arriba y abajo respectivamente
				opc = 0;
				system("cls");
				//aux();
				navegador->navegar(tecla);
			}
		}
		else //if(decision >= '0' && decision <= '9')
			opc = tecla - '0'; //se puede asignar al int porque siempre tiene el valor de un numero entero, se resta '0' porque sino da el valor ASCII

		cout << "\n";
		subMenu(opc);

	} while (opc != 9);
	bandera = false;
	futuro.get();
}

void Menu::busquedaYfiltrado() {
	int op;
	string fragmento;
	system("cls");
	cout << " ---- Busqueda y Filtrado----\n"
		<< " | 1. Busqueda              |\n"
		<< " | 2. Filtrado              |\n"
		<< " | 3. Salir                 |\n"
		<< " ----------------------------\n"
		<< "Digite una opcion: ";
	cin >> op;
	if (navegador->verificaPestania()) {
		switch (op) {
		case 1:
			cout << " Digite el criterio de busqueda: ";
			cin >> fragmento;
			cout << "\n";
			navegador->mostrarBusqueda(fragmento);
			break;
		case 2:
			filtrado();
			break;
		default:
			break;
		}
	}
	else
		cout << "Debe aniadir al menos una pestania y un sitio web antes...\n";

}

void Menu::filtrado() {
	string filtro;
	char tecla;
	int aux = 0;
	int actual = 0;

	cout << " Digite el criterio de filtrado: ";
	cin >> filtro;
	vector<Sitioweb*> vector = navegador->navegarFiltro(filtro);
	if (vector.size() > 0) {
		do {
			system("cls");
			cout << vector[actual]->toString();
			cout << "\n-----------\n";
			cout << "|1. Salir |\n";
			cout << "-----------\n\n";
			tecla = _getch();

			if (tecla == 0 || tecla == -32) {
				tecla = _getch();
				if (tecla == 75) { //codigo de la tecla izquierda
					aux = 0;
					if (actual - 1 >= 0)
						actual--;
				}
				else if (tecla == 77) {
					aux = 0;
					if (actual + 1 < vector.size())
						actual++;
				}
			}
			else
				aux = tecla - '0'; //se puede asignar al int porque siempre tiene el valor de un numero entero, se resta '0' porque sino da el valor ASCII
		} while (aux != 1);
	}
	else
		cout << "\nNo existe ningun sitio web cuyo URL contenga: '" << filtro << "'\n";
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
		//Administrar las pestañas
		navegador->agregarPestana();
		cout << "Pestania agregada correctamente\n";
		aux();
		break;

	case 3:
		if (navegador->verificaPestania() && navegador->verificarHistorial()) {
			//Sistema de marcadores
			system("cls");
			cout << "----- Sistema de Marcadores -----\n"
				<< "| 1. Agregar marcador.	     	 |\n"
				<< "| 2. Eliminar marcador.	     	 |\n"
				<< "| 3. Mostrar marcadores.         |\n"
				<< "---------------------------------\n";
			cout << "Digite su opcion: ";
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
		busquedaYfiltrado();
		aux();
		break;

	case 5:
		modoIncognito();
		aux();
		break;
	case 6: {
		//Importar historial
		list<Vector*> lista = Serializar::deserializar();
		if (lista.size() > 0) {
			navegador->setNavegador(lista);
			cout << "Historial importado exitosamente\n";
		}
		aux();
		break;
	}

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
		politicas();
		aux();
		break;
	case 9:
		cout << "Saliendo, hasta luego\n\n";
		bandera = false; //se acaba el hilo para eliminar historiales
		break;
	default: break;
	}
}

void Menu::politicas() {
	int op;
	int cantPaginas; //cantidad de paginas

	system("cls");
	cout << "----------------- Sistema Politicas ------------------\n"
		<< " | 1. Modificar cantidad de paginas buscadas.         |\n"
		<< " | 2. Modificar tiempo de limpieza de el historial.   |\n"
		<< " | 3. Salir.                                          |\n"
		<< "-------------------------------------------------------\n"
		<< "Digite su opcion: ";
	cin >> op;
	switch (op) {
	case 1:
		if (navegador->verificaPestania()) {
			cout << "Digite la cantidad de entradas que desea para la pestania actual.\n";
			cin >> cantPaginas;
			if (cantPaginas > 0) {
				navegador->modificarCapacidad(cantPaginas);
				system("cls");
				cout << "Se modifico la cantidad de entradas para la pestania actual exitosamente.\n";
			}
			else {
				cout << "No puede ingresar un valor menor a la cantidad de sitios web accedidos\n\n";
			}
		}
		else
			cout << "Ingrese al menos una pestania antes\n\n";
		break;
	case 2:
		cout << "Cuantos minutos desea que transcurran antes de que se elimine el historial? ";
		cin >> criterioDeEliminado;
		system("cls");
		cout << "El historial se actualizo. Se eliminara cada: " << criterioDeEliminado << " min(s)\n";
		break;
	}
}

void Menu::obtenerHoraActual() {
	// obtener la hora actual del sistema
	auto ahora = chrono::system_clock::now();

	//convertir a tiempo de sistema con time_t
	time_t tiempo_actual = chrono::system_clock::to_time_t(ahora);

	tm hora_local;
	localtime_s(&hora_local, &tiempo_actual);

	horaInicio = hora_local.tm_hour * 100 + hora_local.tm_min;
}

void Menu::eliminarHistorial() {
	while (bandera) {
		this_thread::sleep_for(chrono::seconds(10)); //se refresca cada 10s
		auto ahora = chrono::system_clock::now();

		time_t tiempo_actual = chrono::system_clock::to_time_t(ahora);
		tm hora_local;

		localtime_s(&hora_local, &tiempo_actual);

		int horaActualAux = hora_local.tm_hour * 100 + hora_local.tm_min;
		if (navegador->verificaPestania())
			if (navegador->verificarHistorial())
				if ((horaActualAux - horaInicio) >= criterioDeEliminado) {
					navegador->eliminarHistorial();
					horaInicio = horaActualAux;
				}
	}
}

void Menu::aux() {
	system("pause");
	system("cls");
}