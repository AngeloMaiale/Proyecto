#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/CClientes.h"
using namespace std;

void actualizarColumnaClientes(int Nlinea, int ind, const string& ValorN) {
    ifstream Archivo("./bin/Clientes.csv");
    ofstream archivoTemp("temp.csv", ios::out);

    if (Archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(Archivo, linea)) {
            if (contador == Nlinea) {
                string nombre, apellido, email, direccion, bolc;
                int cedula, nVehiculosRentados;
                bool rentado;
                stringstream ss(linea);

                ss >> cedula;
                ss.ignore();
                getline(ss, nombre, ',');
                getline(ss, apellido, ',');
                getline(ss, email, ',');
                ss >> nVehiculosRentados;
                ss.ignore();
                getline(ss, direccion, ',');
                getline(ss, bolc, ',');

                Cliente c(nombre, apellido, email, direccion, rentado, cedula, nVehiculosRentados);

                switch (ind) {
                    case 1:
                        c.setNombre(ValorN);
                        break;
                    case 2:
                        c.setApellido(ValorN);
                        break;
                    case 3:
                        c.setDireccion(ValorN);
                        break;
                    case 4:
                        c.setEmail(ValorN);
                        break;
                    case 5:
                        bolc = ValorN;
                        break;
                    case 6:
                        c.setVehiculosRentados(stoi(ValorN));
                        break;
                    case 7:
                        c.setCedula(stoi(ValorN));
                        break;
                }

                archivoTemp << "\"" << c.getCedula() << "\","
                            << "\"" << c.getNombre() << "\","
                            << "\"" << c.getApellido() << "\","
                            << "\"" << c.getEmail() << "\","
                            << c.getnVehiculosRentados() << ","
                            << c.getDireccion() << ","
                            << bolc << ",\n";
                contador++;
            } else {
                archivoTemp << linea << endl;
            }
            contador++;
        }
        Archivo.close();
        archivoTemp.close();

        if (remove("./bin/Clientes.csv") != 0) {
            cout << "Error al eliminar el archivo original." << endl;
        } else if (rename("temp.csv", "./bin/Clientes.csv") != 0) {
            cout << "Error al renombrar el archivo temporal." << endl;
        } else {
            cout << "Columna actualizada" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo Clientes.csv" << endl;
    }
}

void actualizarFilaClientes(int Nlinea) {
    bool SoN;
    string nombreArchivo = "./bin/Clientes.csv";
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 0;
    string nombre, apellido, direccion, email, TFC;
    int cedula, nVehiculosRentados;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo Clientes.csv" << endl;
        return;
    }

    if (!archivoTemp.is_open()) {
        cout << "Error al abrir el archivo temporal." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        if (i == Nlinea) {
            cout << "Ingrese los nuevos datos del cliente:\n";
            cout << "Nombre: ";
            cin.ignore();
            getline(cin, nombre);
            cout << "Apellido: ";
            getline(cin, apellido);
            cout << "Direccion: ";
            getline(cin, direccion);
            cout << "Email: ";
            getline(cin, email);
            cout << "Activo (TRUE para si, FALSE para no): ";
            cin >> TFC;
            cout << "Numero de vehiculos rentados: ";
            cin >> nVehiculosRentados;
            cout << "Cedula: ";
            cin >> cedula;
            cin.ignore();
            
            archivoTemp << "\"" << cedula << "\","
                        << "\"" << nombre << "\","
                        << "\"" << apellido << "\","
                        << "\"" << email << "\","
                        << nVehiculosRentados << ","
                        << direccion << ","
                        << TFC << ",\n";
        } else {
            archivoTemp << linea << "\n";
        }
        i++;
    }

    archivo.close();
    archivoTemp.close();
    cout << "¿Está seguro de los cambios que va a realizar? Se va a reemplazar el archivo con uno nuevo con los cambios realizados (1 para sí, 0 para no): ";
    cin >> SoN;
    if (SoN) {
        if (remove(nombreArchivo.c_str()) != 0) {
            cout << "Error al eliminar el archivo original." << endl;
            return;
        }
        if (rename("temp.csv", nombreArchivo.c_str()) != 0) {
            cout << "Error al renombrar el archivo temporal." << endl;
        }
    } else {
        cout << "Operación cancelada" << endl;
        remove("temp.csv") != 0;
    }
}

void insertarNuevaLineaClientes() {
    bool SoN;
    string nombreArchivo = "./bin/Clientes.csv";
    ofstream archivo(nombreArchivo, ios::app);
    Cliente c("", "", "", "", false, 0, 0);
    string ToFa;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }
    cout << "Ingrese los detalles del cliente:\n";
    cin.ignore(); 
    cout << "Nombre: ";
    string nombre;
    getline(cin, nombre);
    c.setNombre(nombre);
    cout << "Apellido: ";
    string apellido;
    getline(cin, apellido);
    c.setApellido(apellido);
    cout << "Direccion: "; 
    string direccion;
    getline(cin, direccion);
    c.setDireccion(direccion);
    cout << "Cedula: ";
    int cedula;
    cin >> cedula;
    c.setCedula(cedula);
    cin.ignore(); 
    cout << "Activo (TRUE para si, FALSE para no): ";
    getline(cin, ToFa);
    cout << "Email: ";
    string email;
    getline(cin, email);
    c.setEmail(email);
    cout << "Numero de vehiculos rentados: ";
    int nVehiculosRentados;
    cin >> nVehiculosRentados;
    c.setVehiculosRentados(nVehiculosRentados);
    cout << "¿Está seguro de los cambios que va a realizar? Se va a reemplazar el archivo con uno nuevo con los cambios realizados (1 para sí, 0 para no): ";
    cin >> SoN;
    if (SoN == true) {
        archivo << c.getCedula() << "," << c.getNombre() << "," << c.getApellido() << "," << c.getEmail() << "," << c.getnVehiculosRentados() << "," << c.getDireccion() << ","
                << ToFa << "\n";
        archivo.close();
        cout << "Linea insertada en " << nombreArchivo << endl;
    } else {
        cout << "Operación cancelada" << endl;
        archivo.close();
    }
}


void leerClientes(const string& nombreArchivo, Cliente*& clientes, int& numClientes) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    numClientes = 0;
    while (getline(file, line)) {
        numClientes++;
    }
    
    file.clear(); 
    file.seekg(0);

    clientes = new Cliente[numClientes];

    getline(file, line);
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        string nombre, apellido, direccion, email;
        bool activo;
        int nVehiculosRentados, cedula;

        getline(ss, nombre, ',');
        getline(ss, apellido, ',');
        getline(ss, direccion, ',');
        getline(ss, email, ',');
        ss >> activo; ss.ignore();
        ss >> nVehiculosRentados; ss.ignore();
        ss >> cedula; ss.ignore();

        clientes[i].setNombre(nombre);
        clientes[i].setApellido(apellido);
        clientes[i].setDireccion(direccion);
        clientes[i].setEmail(email);
        clientes[i].setCedula(cedula);
        clientes[i].setVehiculosRentados(nVehiculosRentados);
        if (activo) clientes[i].rentar();
        else clientes[i].devolver();

        i++;
    }
    file.close();
}

void mostrarCliente(Cliente* clientes, int numClientes, int cedula) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].getCedula() == cedula) {
            cout << "Nombre: " << clientes[i].getNombre() << endl;
            cout << "Apellido: " << clientes[i].getApellido() << endl;
            cout << "Direccion: " << clientes[i].getDireccion() << endl;
            cout << "Email: " << clientes[i].getEmail() << endl;
            cout << "Activo: " << (clientes[i].isRentado() ? "Si" : "No") << endl;
            cout << "Vehiculos rentados: " << clientes[i].getnVehiculosRentados() << endl;
            return;
        }
    }
    cerr << "Cliente con cedula " << cedula << " no encontrado" << endl;
}

void liberarMemoria(Cliente* clientes) {
    delete[] clientes;
}