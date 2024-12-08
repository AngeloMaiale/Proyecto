#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/CRepuestos.h"
using namespace std;

void actualizarColumnaRepuestos(int Nlinea, int ind, const string& ValorN) {
    ifstream Archivo("./bin/Repuestos.csv");
    ofstream archivoTemp("temp.csv", ios::out);

    if (Archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        int contador = 1;
        while (getline(Archivo, linea)) {
            if (contador == Nlinea) {
                string partModel, marca, nombre, modelo, bolr;
                int yearCarro, existencias;
                float precio;
                stringstream ss(linea);

                getline(ss, partModel, ',');
                getline(ss, marca, ',');
                getline(ss, nombre, ',');
                getline(ss, modelo, ',');
                ss >> yearCarro;
                ss.ignore();
                ss >> precio;
                ss.ignore();
                ss >> existencias;
                ss.ignore();

                Repuesto r(modelo, marca, nombre, partModel, yearCarro, existencias, precio);

                switch (ind) {
                    case 1:
                        r.setPartModel(ValorN);
                        break;
                    case 2:
                        r.setMarca(ValorN);
                        break;
                    case 3:
                        r.setNombre(ValorN);
                        break;
                    case 4:
                        r.setModelo(ValorN);
                        break;
                    case 5:
                        r.setYearCarro(stoi(ValorN));
                        break;
                    case 6:
                        r.setExistencias(stoi(ValorN));
                        break;
                    case 7:
                        r.setPrecio(stof(ValorN));
                        break;
                }

                archivoTemp << "\"" << r.getPartModel() << "\","
                            << "\"" << r.getMarca() << "\","
                            << "\"" << r.getNombre() << "\","
                            << "\"" << r.getModelo() << "\","
                            << r.getYearCarro() << ","
                            << r.getPrecio() << ","
                            << r.getExistencias() << ",\n";
                contador++;
            } else {
                archivoTemp << linea << endl;
            }
            contador++;
        }
        Archivo.close();
        archivoTemp.close();

        if (remove("./bin/Repuestos.csv") != 0) {
            cout << "Error al eliminar el archivo original." << endl;
        } else if (rename("temp.csv", "./bin/Repuestos.csv") != 0) {
            cout << "Error al renombrar el archivo temporal." << endl;
        } else {
            cout << "Columna actualizada" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo Repuestos.csv" << endl;
    }
}

void actualizarFilaRepuestos(int Nlinea) {
    bool SoN;
    string nombreArchivo = "./bin/Repuestos.csv";
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 1;
    string modelo, marca, nombre, partModel;
    int yearCarro, existencias;
    float precio;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo Repuestos.csv" << endl;
        return;
    }

    if (!archivoTemp.is_open()) {
        cout << "Error al abrir el archivo temporal." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        if (i == Nlinea) {
            cout << "Ingrese los nuevos detalles del repuesto:\n";
            cout << "Modelo: ";
            cin.ignore();
            getline(cin, modelo);
            cout << "Marca: ";
            getline(cin, marca);
            cout << "Nombre: ";
            getline(cin, nombre);
            cout << "Modelo del repuesto: ";
            getline(cin, partModel);
            cout << "Year del vehiculo: ";
            cin >> yearCarro;
            cout << "Existencias: ";
            cin >> existencias;
            cout << "Precio: ";
            cin >> precio;
            cin.ignore();

            archivoTemp << "\"" << modelo << "\","
                        << "\"" << marca << "\","
                        << "\"" << nombre << "\","
                        << "\"" << partModel << "\","
                        << yearCarro << ","
                        << precio << ","
                        << existencias << ",\n";
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

void insertarNuevaLineaRepuestos() {
    bool SoN;
    string nombreArchivo = "./bin/Repuestos.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Repuesto r("", "", "", "", 0, 0, 0.0f);
    
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    cout << "Ingrese los detalles de los repuestos:\n";
    
    string partModel, marca, nombre, modelo;
    int yearCarro, existencias;
    float precio;
    
    cout << "Modelo del repuesto: ";
    cin.ignore();
    getline(cin, partModel);
    r.setPartModel(partModel);

    cout << "Marca: ";
    getline(cin, marca);
    r.setMarca(marca);

    cout << "Nombre: ";
    getline(cin, nombre);
    r.setNombre(nombre);

    cout << "Modelo del vehiculo: ";
    getline(cin, modelo);
    r.setModelo(modelo);

    cout << "Year: ";
    cin >> yearCarro;
    r.setYearCarro(yearCarro);

    cout << "Existencias: ";
    cin >> existencias;
    r.setExistencias(existencias);

    cout << "Precio: ";
    cin >> precio;
    r.setPrecio(precio);

    cout << "Esta seguro de los cambios que va a realizar? Se va a reemplazar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin >> SoN;

    if (SoN) {
        archivo << "\"" << r.getPartModel() << "\","
                << "\"" << r.getMarca() << "\","
                << "\"" << r.getNombre() << "\","
                << "\"" << r.getModelo() << "\","
                << r.getYearCarro() << ","
                << r.getPrecio() << ","
                << r.getExistencias() << "\n";
        archivo.close(); 
        cout << "Linea insertada en " << nombreArchivo << endl;
    } else {
        cout << "Operacion cancelada" << endl;
        archivo.close();
    }
}

void leerRepuestos(const string& nombreArchivo, Repuesto*& repuestos, int& numRepuestos) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    numRepuestos = 0;
    while (getline(file, line)) {
        numRepuestos++;
    }

    file.clear(); 
    file.seekg(0); 

    repuestos = new Repuesto[numRepuestos];

    getline(file, line); 
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        string modelo, marca, nombre, partModel;
        int yearCarro, existencias;
        float precio;

        getline(ss, modelo, ',');
        getline(ss, marca, ',');
        getline(ss, nombre, ',');
        getline(ss, partModel, ',');
        ss >> yearCarro; ss.ignore();
        ss >> existencias; ss.ignore();
        ss >> precio; ss.ignore();

        repuestos[i].setModelo(modelo);
        repuestos[i].setMarca(marca);
        repuestos[i].setNombre(nombre);
        repuestos[i].setPartModel(partModel);
        repuestos[i].setYearCarro(yearCarro);
        repuestos[i].setExistencias(existencias);
        repuestos[i].setPrecio(precio);

        i++;
    }
    file.close();
}

void mostrarRepuesto(Repuesto* repuestos, int numRepuestos, const string& modelo) {
    for (int i = 0; i < numRepuestos; ++i) {
        if (repuestos[i].getModelo() == modelo) {
            cout << "Modelo: " << repuestos[i].getModelo() << endl;
            cout << "Marca: " << repuestos[i].getMarca() << endl;
            cout << "Nombre: " << repuestos[i].getNombre() << endl;
            cout << "Modelo del Carro: " << repuestos[i].getPartModel() << endl;
            cout << "Year del Carro: " << repuestos[i].getYearCarro() << endl; 
            cout << "Precio: " << repuestos[i].getPrecio() << endl;
            cout << "Existencias: " << repuestos[i].getExistencias() << endl;
            return;
        }
    }
    cerr << "Repuesto con modelo " << modelo << " no encontrado." << endl;
}

void liberarMemoria(Repuesto* repuestos) {
    delete[] repuestos;
}