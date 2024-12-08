#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/CVehiculos.h"

using namespace std;
void actualizarColumnaVehiculos(int Nlinea, int ind, const string& ValorN) {
    ifstream Archivo("./bin/Vehiculos.csv");
    ofstream archivoTemp("temp.csv"); 

    if (Archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        int contador = 0;
        while (getline(Archivo, linea)) {
            if (contador == Nlinea) {
                string bolv, modelo, marca, placa, color, fechaEntrega, motor;
                int year, kilometraje, cedula;
                float precioRenta;
                stringstream ss(linea);
                getline(ss, modelo, ',');
                getline(ss, marca, ',');
                getline(ss, placa, ',');
                getline(ss, color, ',');
                ss >> year;
                ss.ignore(); 
                ss >> kilometraje;
                ss.ignore(); 
                getline(ss, bolv, ',');
                getline(ss, motor, ',');
                ss >> precioRenta;
                ss.ignore(); 
                ss >> cedula;
                ss.ignore(); 
                getline(ss, fechaEntrega, ',');
                Vehiculo v(modelo, marca, placa, color, fechaEntrega, motor, year, kilometraje, cedula, false, precioRenta);
                switch (ind) {
                    case 1: 
                        v.setModelo(ValorN); 
                        break;
                    case 2: 
                        v.setMarca(ValorN); 
                        break;
                    case 3: 
                        v.setPlaca(ValorN);
                        break;
                    case 4: 
                        v.setColor(ValorN); 
                        break;
                    case 5: 
                        v.setYear(stoi(ValorN)); 
                        break;
                    case 6: 
                        v.setKilometraje(stoi(ValorN)); 
                        break;
                    case 7: 
                        bolv = ValorN; 
                        break;
                    case 8: 
                        v.setMotor(ValorN); 
                        break;
                    case 9: 
                        v.setPrecioRenta(stof(ValorN)); 
                        break;
                    case 10: 
                        v.setCedula(stoi(ValorN)); 
                        break;
                    case 11: 
                        v.setFechaEntrega(ValorN); 
                        break;
                }

                archivoTemp << v.getModelo() << ","
                            << v.getMarca() << ","
                            << v.getPlaca() << ","
                            << v.getColor() << ","
                            << v.getYear() << ","
                            << v.getKilometraje() << ","
                            << bolv << ","
                            << v.getMotor() << ","
                            << v.getPrecioRenta() << ","
                            << v.getCedula() << ","
                            << v.getFechaEntrega() << endl;
            } else {
                archivoTemp << linea << endl;
            }
            contador++;
        }
        Archivo.close();
        archivoTemp.close();

        if (remove("./bin/Vehiculos.csv") != 0) {
            cout << "Error al eliminar el archivo original." << endl;
        } else if (rename("temp.csv", "./bin/Vehiculos.csv") != 0) {
            cout << "Error al renombrar el archivo temporal." << endl;
        } else {
            cout << "Columna actualizada" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo Vehiculos.csv" << endl;
    }
}
void actualizarFilaVehiculos(int Nlinea) {
    bool SoN;
    string nombreArchivo = "./bin/Vehiculos.csv";
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 0;
    string modelo, marca, placa, color, motor, fechaEntrega, TF;
    int year, kilometraje, cedula;
    float precioRenta;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo Vehiculos.csv" << endl;
        return;
    }

    if (!archivoTemp.is_open()) {
        cout << "Error al abrir el archivo temporal." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        if (i == Nlinea) {
            cout << "Ingrese los nuevos detalles del vehiculo:\n";
            cout << "Modelo: ";
            cin.ignore();
            getline(cin, modelo);
            cout << "Marca: ";
            getline(cin, marca);
            cout << "Placa: ";
            getline(cin, placa);
            cout << "Color: ";
            getline(cin, color);
            cout << "Year: ";
            cin >> year;
            cout << "Kilometraje: ";
            cin >> kilometraje;
            cout << "Rentado (TRUE para si, FALSE para no): ";
            cin >> TF;
            cin.ignore();
            cout << "Motor: ";
            getline(cin, motor);
            cout << "Precio de renta: ";
            cin >> precioRenta;
            cout << "Cedula del cliente: ";
            cin >> cedula;
            cin.ignore();
            cout << "Fecha de entrega: ";
            getline(cin, fechaEntrega);

            archivoTemp << "\"" << modelo << "\","
                        << "\"" << marca << "\","
                        << "\"" << placa << "\","
                        << "\"" << color << "\","
                        << year << ","
                        << kilometraje << ","
                        << TF << ","
                        << "\"" << motor << "\","
                        << precioRenta << ","
                        << cedula << ","
                        << "\"" << fechaEntrega << "\"\n";
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

void insertarNuevaLineaVehiculos() {
    bool SoN;
    string nombreArchivo = "./bin/Vehiculos.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Vehiculo v("", "", "", "", "", "", 0, 0, 0, false, 0.0f);
    string ToF;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }
    cout << "Ingrese los detalles del vehiculo:\n";
    cout << "Modelo: ";
    string modelo;
    cin.ignore();
    getline(cin, modelo);
    v.setModelo(modelo);
    cout << "Marca: ";
    string marca;
    getline(cin, marca);
    v.setMarca(marca);
    cout << "Placa: ";
    string placa;
    getline(cin, placa);
    v.setPlaca(placa);
    cout << "Color: ";
    string color;
    getline(cin, color);
    v.setColor(color);
    cout << "Year: ";
    int year;
    cin >> year;
    v.setYear(year);
    cout << "Kilometraje: ";
    int kilometraje;
    cin >> kilometraje;
    v.setKilometraje(kilometraje);
    cin.ignore(); 
    cout << "Rentado (TRUE para si, FALSE para no): ";
    cin >> ToF;
    cin.ignore(); 
    cout << "Motor: ";
    string motor;
    getline(cin, motor);
    v.setMotor(motor);
    cout << "Precio de renta: ";
    float precioRenta;
    cin >> precioRenta;
    v.setPrecioRenta(precioRenta);
    cout << "Cedula del cliente: ";
    int cedula;
    cin >> cedula;
    v.setCedula(cedula);
    cin.ignore(); 
    cout << "Fecha de entrega(dd/mm/yyyy): ";
    string fechaEntrega;
    getline(cin, fechaEntrega);
    v.setFechaEntrega(fechaEntrega);
    cout << "¿Está seguro de los cambios que va a realizar? Se va a reemplazar el archivo con uno nuevo con los cambios realizados (1 para sí, 0 para no): ";
    cin >> SoN;
    if (SoN) {
        archivo << v.getModelo() << "," << v.getMarca() << "," << v.getPlaca() << "," << v.getColor() << ","
                << v.getYear() << "," << v.getKilometraje() << "," << (v.isRentado() ? "TRUE" : "FALSE") << "," 
                << v.getMotor() << "," << v.getPrecioRenta() << "," << v.getCedula() << "," << v.getFechaEntrega() << "\n";
        archivo.close();
        cout << "Linea insertada en " << nombreArchivo << endl;
    } else {
        cout << "Operación cancelada" << endl;
        archivo.close();
    }
}


void leerVehiculos(const string& nombreArchivo, Vehiculo*& vehiculos, int& numVehiculos) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    numVehiculos = 0;
    while (getline(file, line)) {
        numVehiculos++;
    }

    file.clear(); 
    file.seekg(0); 

    vehiculos = new Vehiculo[numVehiculos];

    getline(file, line); 
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        string modelo, marca, placa, color, motor, fechaEntrega;
        int year, kilometraje, cedula;
        float precioRenta;
        bool rentado;

        getline(ss, modelo, ',');
        getline(ss, marca, ',');
        getline(ss, placa, ',');
        getline(ss, color, ',');
        ss >> year; ss.ignore();
        ss >> kilometraje; ss.ignore();
        ss >> rentado; ss.ignore();
        getline(ss, motor, ',');
        ss >> precioRenta; ss.ignore();
        ss >> cedula; ss.ignore();
        getline(ss, fechaEntrega);

        vehiculos[i].setModelo(modelo);
        vehiculos[i].setMarca(marca);
        vehiculos[i].setPlaca(placa);
        vehiculos[i].setColor(color);
        vehiculos[i].setYear(year);
        vehiculos[i].setKilometraje(kilometraje);
        if (rentado) vehiculos[i].rentar();
        else vehiculos[i].devolver();
        vehiculos[i].setMotor(motor);
        vehiculos[i].setPrecioRenta(precioRenta);
        vehiculos[i].setCedula(cedula);
        vehiculos[i].setFechaEntrega(fechaEntrega);

        i++;
    }
    file.close();
}

void mostrarVehiculo(Vehiculo* vehiculos, int numVehiculos, const string& placa) {
    for (int i = 0; i < numVehiculos; ++i) {
        if (vehiculos[i].getPlaca() == placa) {
            cout << "Modelo: " << vehiculos[i].getModelo() << endl;
            cout << "Marca: " << vehiculos[i].getMarca() << endl;
            cout << "Placa: " << vehiculos[i].getPlaca() << endl;
            cout << "Color: " << vehiculos[i].getColor() << endl;
            cout << "Year: " << vehiculos[i].getYear() << endl; 
            cout << "Kilometraje: " << vehiculos[i].getKilometraje() << endl;
            cout << "Rentado: " << (vehiculos[i].isRentado() ? "Si" : "No") << endl;
            cout << "Motor: " << vehiculos[i].getMotor() << endl;
            cout << "Precio de Renta: " << vehiculos[i].getPrecioRenta() << endl;
            cout << "Cedula del Cliente: " << vehiculos[i].getCedula() << endl;
            cout << "Fecha de Entrega: " << vehiculos[i].getFechaEntrega() << endl;
            return;
        }
    }
    cerr << "Vehiculo con placa " << placa << " no encontrado." << endl;
}

void liberarMemoria(Vehiculo* vehiculos) {
    delete[] vehiculos;
}