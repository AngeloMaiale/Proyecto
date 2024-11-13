#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

struct Vehiculo{
    string modelo, marca, placa, color, cedula, fechaEntrega;
    int year, kilometraje;
    bool rentado;
    float motor, precioRenta;
};

struct Cliente {
    string cedula, nombre, apellido, direccion, telefono, email;
    int nVehiculosRentados;
    bool activo;
};

struct Repuesto {
    string modelo,marca, nombre;
    int yearCarro, existencias;
    float precio;
};

void leerVehiculos(const string& misVehiculos, vector<Vehiculo>& vehiculos) {
    ifstream file("misVehiculos.csv");
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << misVehiculos << endl;
        return;
    }

    getline(file, line); //Ignora la primera linea
    
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
        getline(ss, v.cedula, ',');
        getline(ss, v.fechaEntrega);

        vehiculos.push_back(v);
    }
}

void buscarVehiculoPorPlaca(const vector<Vehiculo>& vehiculos, const string& placa) {
    for (const auto& v : vehiculos) {
        if (v.placa == placa) {
            cout << "Vehículo encontrado: " << endl;
            cout << "Modelo: " << v.modelo << ", Marca: " << v.marca << ", Placa: " << v.placa 
                 << ", Color: " << v.color << ", Año: " << v.year 
                 << ", Kilometraje: " << v.kilometraje << ", Rentado: " 
                 << (v.rentado ? "Sí" : "No") << ", Motor: " 
                 << v.motor << ", Precio Renta: " << v.precioRenta 
                 << ", Cédula Cliente: " << v.cedula 
                 << ", Fecha de Entrega: " << v.fechaEntrega << endl;
            return; // Sale del bucle después de encontrar el vehículo
        }
    }
    cout << "Vehículo con placa " << placa << " no encontrado." << endl;
}

int main() {
    vector<Vehiculo> vehiculos;
    string nombreArchivo = "minsVehiculos.csv";

    leerVehiculos(nombreArchivo, vehiculos);
    
    // Ejemplo de búsqueda
    string placaABuscar;
    cout << "Ingrese la placa del vehículo a buscar: ";
    cin >> placaABuscar;

    buscarVehiculoPorPlaca(vehiculos, placaABuscar);

    return 0;
}