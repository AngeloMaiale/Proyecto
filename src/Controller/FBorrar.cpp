#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/CClientes.h"
#include "../Model/CVehiculos.h"
#include "../Model/CRepuestos.h"
using namespace std;

void borrarLinea(const string& nombreArchivo, int Nlinea) {
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 0;

    if (!archivo.is_open()) {
    cout << "Error al abrir el archivo " << nombreArchivo << endl;
    return;
    }
    if (!archivoTemp.is_open()) {
        cout << "Error al abrir el archivo temporal." << endl;
        return;
    }
    while (getline(archivo, linea)) {
        if (i != Nlinea) {
            archivoTemp << linea << "\n";
        }
        i++;
    }
    archivo.close();
    archivoTemp.close();
    if (remove(nombreArchivo.c_str()) != 0) {
        cout << "Error al eliminar el archivo original." << endl;
        return;
    }
    if (rename("temp.csv", nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
    }
}

