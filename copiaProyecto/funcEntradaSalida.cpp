#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>
#include <ctime>

using namespace std;

string obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* tmPtr = localtime(&t);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tmPtr);
    return string(buffer);
}

void crearCopiaDeSeguridad(const string& nombreArchivo) {
    string fecha = obtenerFechaActual();
    string nombreCopia = "./copiaProyecto/" + fecha + "_" + nombreArchivo;

    filesystem::create_directory("./copiaProyeto");

    ifstream archivoOriginal(nombreArchivo, ios::binary);
    ofstream archivoCopia(nombreCopia, ios::binary);

    if (archivoOriginal && archivoCopia) {
        archivoCopia << archivoOriginal.rdbuf(); 
        cout << "Copia de seguridad creada: " << nombreCopia << endl;
    } else {
        cout << "Error al crear la copia de seguridad." << endl;
    }
}

int main() {
    crearCopiaDeSeguridad("./bin/Vehiculos.csv");
    crearCopiaDeSeguridad("./bin/Clientes.csv");
    crearCopiaDeSeguridad("./bin/Repuestos.csv");

    return 0;
}