#include "Serializar.h"

bool Serializar::archivoVacio(ifstream& archivo) {
	return archivo.peek() == ifstream::traits_type::eof();
}

void Serializar::serializar(list<Vector*> lista) {
	ofstream archivo("historial.bin", ios::binary);

	if (!archivo) {
		cerr << "Error al abrir el archivo para escribir." << endl;
		return;
	}

	size_t cantidadPestanas = lista.size();
	archivo.write(reinterpret_cast<const char*>(&cantidadPestanas), sizeof(cantidadPestanas));

	for (Vector* pestana : lista) {
		size_t cantidadHistorial = pestana->getHistorial().size();
		archivo.write(reinterpret_cast<const char*>(&cantidadHistorial), sizeof(cantidadHistorial));

		for (Sitioweb* sitioweb : pestana->getHistorial()) {
			size_t cantTitulo = sitioweb->getTitulo().size();
			size_t cantURL = sitioweb->getUrl().size();

			archivo.write(reinterpret_cast<const char*>(&cantTitulo), sizeof(cantTitulo));
			archivo.write(sitioweb->getTitulo().c_str(), cantTitulo);

			archivo.write(reinterpret_cast<const char*>(&cantURL), sizeof(cantURL));
			archivo.write(sitioweb->getUrl().c_str(), cantURL);

			bool marcador = sitioweb->getMarcador();
			archivo.write(reinterpret_cast<const char*>(&marcador), sizeof(marcador));
		}
	}
	archivo.close();
}

list<Vector*> Serializar::deserializar() { //ejemplo de caamano  O(n^2)
	list<Vector*> lista;
	ifstream archivo("historial.bin", ios::binary);

	if (!archivo) {
		cerr << "Error al abrir el archivo para escribir." << endl;
		return lista;
	}
	if (!archivoVacio(archivo)) {
		size_t cantPestanas;
		archivo.read(reinterpret_cast<char*>(&cantPestanas), sizeof(cantPestanas));

		for (size_t i = 0; i < cantPestanas; ++i) {
			Vector* historial = new Vector();
			vector<Sitioweb*> vector; //se ocupa para cargar lo del archivo, despues se ingresa al historial
			size_t cantHistorial;
			archivo.read(reinterpret_cast<char*>(&cantHistorial), sizeof(cantHistorial));

			vector.resize(cantHistorial);
			for (Sitioweb* sitio : vector) {
				string titulo, url;
				bool marcador;
				size_t tamanoTitulo;
				size_t tamanoURL;

				archivo.read(reinterpret_cast<char*>(&tamanoTitulo), sizeof(tamanoTitulo));
				char* bufferTitulo = new char[tamanoTitulo + 1];
				archivo.read(bufferTitulo, tamanoTitulo);
				bufferTitulo[tamanoTitulo] = '\0';
				titulo = bufferTitulo;
				delete[] bufferTitulo;

				archivo.read(reinterpret_cast<char*>(&tamanoURL), sizeof(tamanoURL));
				char* bufferURL = new char[tamanoURL + 1];
				archivo.read(bufferURL, tamanoURL);
				bufferURL[tamanoURL] = '\0';
				url = bufferURL;
				delete[] bufferURL;

				archivo.read(reinterpret_cast<char*>(&marcador), sizeof(marcador));
				sitio = new Sitioweb();
				sitio->setTitulo(titulo);
				sitio->setUrl(url);
				sitio->setMarcador(marcador);
				historial->agregarSitio(sitio);
			}
			lista.push_back(historial);
		}
	}
	else
		cout << "El archivo se encuentra vacio\n";
	archivo.close();
	return lista;
}