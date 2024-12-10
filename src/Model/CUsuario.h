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
class Usuario {
public:
    string nombre;
    string password;
    string rol; // "Admin", "Manager", "Empleado"

    Usuario() {}

    Usuario(const string& n, const string& p, const string& r) : nombre(n), password(p), rol(r) {}

    bool autenticar(const string& p) {
        return password == p;
    }

    bool tienePermiso(const string& permiso) {
        if (rol == "Admin") {
            return true; 
        } else if (rol == "Manager") {
            return (permiso == "agregarCliente" || permiso == "agregarVehiculo");
        } else if (rol == "Empleado") {
            return (permiso == "consultarDatos" || permiso == "realizarVenta");
        }
        return false;
    }
};

class Cliente {
public:
    string id;
    string nombre;
    string telefono;

    void agregar() {
        ofstream archivo("./bin/Clientes.csv", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << nombre << "," << telefono << endl;
            archivo.close();
            std::cout << "Cliente agregado exitosamente." << endl;
        } else {
            std::cout << "Error al abrir el archivo de clientes." << endl;
        }
    }
    void borrar() {
        string idBuscado;
        cout << "Ingrese el ID del cliente a borrar: ";
        cin >> idBuscado;

        ifstream archivo("./bin/Clientes.csv");
        ofstream archivoTemp("./copiaProyecto/temp_Clientes.csv");
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id;
            getline(ss, id, ',');

            if (id == idBuscado) {
                encontrado = true;
                cout << "Cliente con ID " << idBuscado << " borrado exitosamente." << endl;
            } else {
                archivoTemp << linea << endl; // Copiar línea si no es el cliente a borrar
            }
        }

        archivo.close();
        archivoTemp.close();
        remove("./bin/Clientes.csv");
        rename("./copiaProyecto/temp_Clientes.csv", "./bin/Clientes.csv");

        if (!encontrado) {
            cout << "Cliente no encontrado." << endl;
        }
    }
    void actualizar() {
        string idBuscado;
        cout << "Ingrese el ID del cliente a actualizar: ";
        cin >> idBuscado;

        ifstream archivo("./bin/Clientes.csv");
        ofstream archivoTemp("./copiaProyecto/temp_Clientes.csv");
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id, nombre, telefono;
            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, telefono, ',');

            if (id == idBuscado) {
                encontrado = true;
                cout << "Cliente encontrado. Ingrese nuevos datos." << endl;
                cout << "Nuevo nombre: ";
                cin >> nombre;
                cout << "Nuevo teléfono: ";
                cin >> telefono;
            }
            archivoTemp << id << "," << nombre << "," << telefono << endl;
        }

        archivo.close();
        archivoTemp.close();
        remove("./bin/Clientes.csv");
        rename("./copiaProyecto/temp_Clientes.csv", "./bin/Clientes.csv");

        if (encontrado) {
            cout << "Cliente actualizado exitosamente." << endl;
        } else {
            cout << "Cliente no encontrado." << endl;
        }
    }

    void consulta() {
        ifstream archivo("./bin/Clientes.csv");
        string linea;
        cout << "Clientes:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    }
    void insercion() {
        cout << "Ingrese ID del cliente: ";
        cin >> id;
        cout << "Ingrese nombre del cliente: ";
        cin >> nombre;
        cout << "Ingrese teléfono del cliente: ";
        cin >> telefono;

        ofstream archivo("./bin/Clientes.csv", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << nombre << "," << telefono << endl;
            archivo.close();
            cout << "Cliente agregado exitosamente." << endl;
        } else {
            cout << "Error al abrir el archivo de clientes." << endl;
        }
    }
};

class Repuesto {
public:
    string id;
    string nombre;
    double precio;

    void agregar() {
        ofstream archivo("./bin/Repuestos.csv", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << nombre << "," << precio << endl;
            archivo.close();
            std::cout << "Repuesto agregado exitosamente." << endl;
        } else {
            std::cout << "Error al abrir el archivo de repuestos." << endl;
        }
    }
    void borrar() {
        string idBuscado;
        cout << "Ingrese el ID del repuesto a borrar: ";
        cin >> idBuscado;

        ifstream archivo("./bin/Repuestos.csv");
        ofstream archivoTemp("./copiaProyecto/temp_Repuestos.csv");
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id;
            getline(ss, id, ',');

            if (id == idBuscado) {
                encontrado = true;
                cout << "Repuesto con ID " << idBuscado << " borrado exitosamente." << endl;
            } else {
                archivoTemp << linea << endl; // Copiar línea si no es el repuesto a borrar
            }
        }

        archivo.close();
        archivoTemp.close();
        remove("./bin/Repuestos.csv");
        rename("./copiaProyecto/temp_Repuestos.csv", "./bin/Repuestos.csv");

        if (!encontrado) {
            cout << "Repuesto no encontrado." << endl;
        }
    }
    void actualizar() {
        string idBuscado;
        cout << "Ingrese el ID del repuesto a actualizar: ";
        cin >> idBuscado;

        ifstream archivo("./bin/Repuestos.csv");
        ofstream archivoTemp("./copiaProyecto/temp_Repuestos.csv");
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id, nombre;
            double precio;
            getline(ss, id, ',');
            getline(ss, nombre, ',');
            ss >> precio;

            if (id == idBuscado) {
                encontrado = true;
                cout << "Repuesto encontrado. Ingrese nuevos datos." << endl;
                cout << "Nuevo nombre: ";
                cin >> nombre;
                cout << "Nuevo precio: ";
                cin >> precio;
            }
            archivoTemp << id << "," << nombre << "," << precio << endl;
        }

        archivo.close();
        archivoTemp.close();
        remove("./bin/Repuestos.csv");
        rename("./copiaProyecto/temp_Repuestos.csv", "./bin/Repuestos.csv");

        if (encontrado) {
            cout << "Repuesto actualizado exitosamente." << endl;
        } else {
            cout << "Repuesto no encontrado." << endl;
        }
    }

    void consulta() {
        ifstream archivo("./bin/Repuestos.csv");
        string linea;
        cout << "Repuestos:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    }
    void insercion() {
        cout << "Ingrese ID del repuesto: ";
        cin >> id;
        cout << "Ingrese nombre del repuesto: ";
        cin >> nombre;
        cout << "Ingrese precio del repuesto: ";
        cin >> precio;

        ofstream archivo("./bin/Repuestos.csv", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << nombre << "," << precio << endl;
            archivo.close();
            cout << "Repuesto agregado exitosamente." << endl;
        } else {
            cout << "Error al abrir el archivo de repuestos." << endl;
        }
    }
};

class Vehiculo {
public:
    string id;
    string marca;
    string modelo;
    
    void agregar() {
        ofstream archivo("./bin/Vehiculos.csv", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << marca << "," << modelo << endl;
            archivo.close();
            std::cout << "Vehículo agregado exitosamente." << endl;
        } else {
            std::cout << "Error al abrir el archivo de vehículos." << endl;
        }
    }
    void borrar() {
        string idBuscado;
        cout << "Ingrese el ID del vehículo a borrar: ";
        cin >> idBuscado;

        ifstream archivo("./bin/Vehiculos.csv");
        ofstream archivoTemp("./copiaProyecto/temp_Vehiculos.csv");
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id;
            getline(ss, id, ',');

            if (id == idBuscado) {
                encontrado = true;
                cout << "Vehículo con ID " << idBuscado << " borrado exitosamente." << endl;
            } else {
                archivoTemp << linea << endl; 
            }
        }

        archivo.close();
        archivoTemp.close();
        remove("./bin/Vehiculos.csv");
        rename("./copiaProyecto/temp_Vehiculos.csv", "./bin/Vehiculos.csv");

        if (!encontrado) {
            cout << "Vehículo no encontrado." << endl;
        }
    }
      void actualizar() {
        string idBuscado;
        cout << "Ingrese el ID del vehículo a actualizar: ";
        cin >> idBuscado;

        ifstream archivo("./bin/Vehiculos.csv");
        ofstream archivoTemp("./copiaProyecto/temp_Vehiculos.csv");
        string linea;
        bool encontrado = false;

        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string id, marca, modelo;
            getline(ss, id, ',');
            getline(ss, marca, ',');
            getline(ss, modelo, ',');

            if (id == idBuscado) {
                encontrado = true;
                cout << "Vehículo encontrado. Ingrese nuevos datos." << endl;
                cout << "Nueva marca: ";
                cin >> marca;
                cout << "Nuevo modelo: ";
                cin >> modelo;
            }
            archivoTemp << id << "," << marca << "," << modelo << endl;
        }

        archivo.close();
        archivoTemp.close();
        remove("./bin/Vehiculos.csv");
        rename("./copiaProyecto/temp_Vehiculos.csv", "./bin/Vehiculos.csv");

        if (encontrado) {
            cout << "Vehículo actualizado exitosamente." << endl;
        } else {
            cout << "Vehículo no encontrado." << endl;
        }
    }

    void consulta() {
        ifstream archivo("./bin/Vehiculos.csv");
        string linea;
        cout << "Vehículos:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    }
    void insercion() {
        cout << "Ingrese ID del vehículo: ";
        cin >> id;
        cout << "Ingrese marca del vehículo: ";
        cin >> marca; 
        cout << "Ingrese modelo del vehículo: ";
        cin >> modelo;

        ofstream archivo("./bin/Vehiculos.csv", ios::app);
        if (archivo.is_open()) {
            archivo << id << "," << marca << "," << modelo << endl;
            archivo.close();
            cout << "Vehículo agregado exitosamente." << endl;
        } else {
            cout << "Error al abrir el archivo de vehículos." << endl;
        }
    }
};
class SistemaGestion {
private:
    Usuario usuario; 

public:
    SistemaGestion(const Usuario& user) : usuario(user) {} // Constructor que inicializa el usuario

    void agregarCliente() {
        if (usuario.tienePermiso("agregarCliente")) {
            Cliente cliente;
            cout << "Ingrese ID del cliente: ";
            cin >> cliente.id;
            cout << "Ingrese nombre del cliente: ";
            cin >> cliente.nombre;
            cout << "Ingrese teléfono del cliente: ";
            cin >> cliente.telefono;
            cliente.agregar();
        } else {
            cout << "No tiene permiso para agregar clientes." << endl;
        }
    }

    void agregarRepuesto() {
        if (usuario.tienePermiso("agregarRepuesto")) {
            Repuesto repuesto;
            cout << "Ingrese ID del repuesto: ";
            cin >> repuesto.id;
            cout << "Ingrese nombre del repuesto: ";
            cin >> repuesto.nombre;
            cout << "Ingrese precio del repuesto: ";
            cin >> repuesto.precio;
            repuesto.agregar();
        } else {
            cout << "No tiene permiso para agregar repuestos." << endl;
        }
    }

    void agregarVehiculo() {
        if (usuario.tienePermiso("agregarVehiculo")) {
            Vehiculo vehiculo;
            cout << "Ingrese ID del vehículo: ";
            cin >> vehiculo.id;
            cout << "Ingrese marca del vehículo: ";
            cin >> vehiculo.marca; 
            cout << "Ingrese modelo del vehículo: ";
            cin >> vehiculo.modelo;
            vehiculo.agregar();
        } else {
            cout << "No tiene permiso para agregar vehículos." << endl;
        }
    }

    void consultarDatos() {
        if (usuario.tienePermiso("consultarDatos")) {
            cout << "Consultando datos de clientes, repuestos y vehículos..." << endl;

            ifstream archivoClientes("./bin/Clientes.csv");
            string linea;
            cout << "Clientes:" << endl;
            while (getline(archivoClientes, linea)) {
                cout << linea << endl;
            }
            archivoClientes.close();

            ifstream archivoRepuestos("./bin/Repuestos.csv");
            cout << "Repuestos:" << endl;
            while (getline(archivoRepuestos, linea)) {
                cout << linea << endl;
            }
            archivoRepuestos.close();

            ifstream archivoVehiculos("./bin/Vehiculos.csv");
            cout << "Vehículos:" << endl;
            while (getline(archivoVehiculos, linea)) {
                cout << linea << endl;
            }
            archivoVehiculos.close();
        } else {
            cout << "No tiene permiso para consultar datos." << endl;
        }
    }
};