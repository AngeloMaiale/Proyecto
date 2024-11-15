#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Vehiculo {
    string modelo, marca, placa, color, fechaEntrega;
    int year, kilometraje, cedula;
    bool rentado;
    float motor, precioRenta;
};

struct Cliente {
    string nombre, apellido, direccion, email;
    bool activo;
    int nVehiculosRentados, cedula;
};

struct Repuesto {
    string modelo, marca, nombre, partModel;
    int yearCarro, existencias;
    float precio;
};

void leerClientes(const string& nombreArchivo, Cliente*& clientes, int& numClientes) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    // Contar el número de líneas (clientes)
    numClientes = 0;
    while (getline(file, line)) {
        numClientes++;
    }
    
    file.clear(); // Limpiar el estado del archivo
    file.seekg(0); // Volver al inicio del archivo

    // Asignar memoria para los clientes
    clientes = new Cliente[numClientes];

    getline(file, line); // Leer encabezados
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        Cliente c;
        getline(ss, c.nombre, ',');
        getline(ss, c.apellido, ',');
        getline(ss, c.direccion, ',');
        getline(ss, c.email, ',');
        ss >> c.activo; ss.ignore();
        ss >> c.nVehiculosRentados; ss.ignore();
        ss >> c.cedula; ss.ignore();
        clientes[i++] = c; // Asignar cliente al arreglo
    }
    file.close();
}

void leerVehiculos(const string& nombreArchivo, Vehiculo*& vehiculos, int& numVehiculos) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    // Contar el número de líneas (vehículos)
    numVehiculos = 0;
    while (getline(file, line)) {
        numVehiculos++;
    }

    file.clear(); // Limpiar el estado del archivo
    file.seekg(0); // Volver al inicio del archivo

    // Asignar memoria para los vehículos
    vehiculos = new Vehiculo[numVehiculos];

    getline(file, line); // Leer encabezados
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        Vehiculo v;
        getline(ss, v.modelo, ',');
        getline(ss, v.marca, ',');
        getline(ss, v.placa, ',');
        getline(ss, v.color, ',');
        ss >> v.year; ss.ignore();
        ss >> v.kilometraje; ss.ignore();
        ss >> v.rentado; ss.ignore();
        ss >> v.motor; ss.ignore();
        ss >> v.precioRenta; ss.ignore();
        ss >> v.cedula; ss.ignore();
        getline(ss, v.fechaEntrega);
        vehiculos[i++] = v; // Asignar vehículo al arreglo
    }
    file.close();
}

void leerRepuestos(const string& nombreArchivo, Repuesto*& repuestos, int& numRepuestos) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    // Contar el número de líneas (repuestos)
    numRepuestos = 0;
    while (getline(file, line)) {
        numRepuestos++;
    }

    file.clear(); // Limpiar el estado del archivo
    file.seekg(0); // Volver al inicio del archivo

    // Asignar memoria para los repuestos
    repuestos = new Repuesto[numRepuestos];

    getline(file, line); // Leer encabezados
    int i = 0;
    while (getline(file, line)) {
        istringstream ss(line);
        Repuesto r;
        getline(ss, r.modelo, ',');
        getline(ss, r.marca, ',');
        getline(ss, r.nombre, ',');
        getline(ss, r.partModel, ',');
        ss >> r.yearCarro; ss.ignore();
        ss >> r.existencias; ss.ignore();
        ss >> r.precio; ss.ignore();
                repuestos[i++] = r; // Asignar repuesto al arreglo
    }
    file.close();
}

void liberarMemoria(Cliente* clientes) {
    delete[] clientes;
}

void liberarMemoria(Vehiculo* vehiculos) {
    delete[] vehiculos;
}

void liberarMemoria(Repuesto* repuestos) {
    delete[] repuestos;
}

int main() {
    string nombreArchivoVehiculos = "./bin/Vehiculos.csv";
    string nombreArchivoClientes = "./bin/Clientes.csv";
    string nombreArchivoRepuestos = "./bin/Repuestos.csv";

    int opcion;

    cout << "Que archivo desea gestionar: " << endl;
    cout << "1. Vehiculos" << endl;
    cout << "2. Clientes" << endl;
    cout << "3. Repuestos" << endl;

    cin >> opcion;

    switch (opcion) {
        case 1: {
            Vehiculo* vehiculos = nullptr;
            int numVehiculos = 0;
            leerVehiculos(nombreArchivoVehiculos, vehiculos, numVehiculos);
            // Aquí puedes agregar lógica para trabajar con los vehículos leídos
            liberarMemoria(vehiculos);
            break;
        }
        case 2: {
            Cliente* clientes = nullptr;
            int numClientes = 0;
            leerClientes(nombreArchivoClientes, clientes, numClientes);
            // Aquí puedes agregar lógica para trabajar con los clientes leídos
            liberarMemoria(clientes);
            break;
        }
        case 3: {
            Repuesto* repuestos = nullptr;
            int numRepuestos = 0;
            leerRepuestos(nombreArchivoRepuestos, repuestos, numRepuestos);
            // Aquí puedes agregar lógica para trabajar con los repuestos leídos
            liberarMemoria(repuestos);
            break;
        }
        default:
            cout << "Opción no válida." << endl;
            break;
    }

    return 0;
}
