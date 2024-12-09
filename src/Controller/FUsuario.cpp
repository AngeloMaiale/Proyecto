#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <filesystem>
#include <ctime>

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
            return (permiso == "consultarDatos");
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
            cout << "Vehículo agregado exitosamente." << endl;
        } else {
            cout << "Error al abrir el archivo de vehículos." << endl;
        }
    }
};

bool autenticarUsuario(const string& nombre, const string& password, Usuario& usuario) {
    ifstream archivo("./bin/Usuarios.csv");
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string user, pass, rol;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, rol, ',');
        if (user == nombre && pass == password) {
            usuario = Usuario(user, pass, rol);
            return true;
        }
    }
    return false;
}

int main() {
    Usuario usuario;
    string nombre, password;

    cout << "Ingrese su nombre de usuario: ";
    cin >> nombre;
    cout << "Ingrese su contraseña: ";
    cin >> password;

    if (!autenticarUsuario(nombre, password, usuario)) {
        cout << "Autenticación fallida. Saliendo del programa." << endl;
        return 1;
    }

    int opcion;
    do {
        cout << "Seleccione una opción:\n";
        cout << "1. Agregar Cliente\n";
        cout << "2. Agregar Repuesto\n";
        cout << "3. Agregar Vehículo\n";
        cout << "4. Salir\n";
        cin >> opcion;

        switch (opcion) {
             case 1: 
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
                break;

            case 2: 
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
                break;

            case 3: 
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
                break;

            case 4:
                cout << "Saliendo del programa." << endl;
                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);

    return 0;
}