#pragma once
#include <string>
#include <iostream>

using namespace std;

class Usuario {
private:
    string nombre;
    string password;
    string rol;

public:
    Usuario(const string& nombre, const string& password, const string& rol)
        : nombre(nombre), password(password), rol(rol) {}

    string getNombre() const { return nombre; }
    string getRol() const { return rol; }

    bool tieneAcceso(const string& funcion) const {
        if (rol == "Admin") {
            return true; 
        } else if (rol == "Manager") {
            return (funcion == "gestionarVehiculos" || funcion == "gestionarClientes" || funcion == "gestionarEmpleados");
        } else if (rol == "Empleado") {
            return (funcion == "consultarDatos" || funcion == "realizarVentas");
        }
        return false; 
    }

    void mostrarInfo() const {
        cout << "Nombre: " << nombre << ", Rol: " << rol << endl;
    }

    bool verificarPassword(const string& pass) const {
        return password == pass;
    }
};

class GestorUsuarios {
private:
    Usuario** usuarios; 
    int capacidad;      
    int cantidad;      

public:
    GestorUsuarios(int capacidad) : capacidad(capacidad), cantidad(0) {
        usuarios = new Usuario*[capacidad]; 
    }

    ~GestorUsuarios() {
        for (int i = 0; i < cantidad; ++i) {
            delete usuarios[i]; 
        }
        delete[] usuarios; 
    }

    bool registrarUsuario(const string& nombre, const string& password, const string& rol) {
        for (int i = 0; i < cantidad; ++i) {
            if (usuarios[i]->getNombre() == nombre) {
                cout << "El usuario ya existe." << endl;
                return false; 
            }
        }

        if (cantidad >= capacidad) {
            cout << "No se puede registrar más usuarios. Capacidad máxima alcanzada." << endl;
            return false;
        }

        usuarios[cantidad++] = new Usuario(nombre, password, rol);
        cout << "Usuario registrado exitosamente." << endl;
        return true;
    }

    bool autenticarUsuario(const string& nombre, const string& password) {
        for (int i = 0; i < cantidad; ++i) {
            if (usuarios[i]->getNombre() == nombre && usuarios[i]->verificarPassword(password)) {
                cout << "Usuario autenticado: " << nombre << endl;
                return true;
            }
        }
        cout << "Autenticación fallida." << endl;
        return false;
    }

    void mostrarUsuarios() const {
        for (int i = 0; i < cantidad; ++i) {
            usuarios[i]->mostrarInfo();
        }
    }
};
class Admin {
public:
    void usuarios_admin() {
        int opcion;
        cout << "USUARIOS\nQue acción desea realizar? 1. Registro | 2. Borrar | 3. Consulta: ";
        cin >> opcion;
        string nombre, apellido;
        int opcion1;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre: "; cin >> nombre;
                cout << "Ingrese el apellido: "; cin >> apellido;
                cout << "Ingrese el tipo de usuario (1.Admin | 2.Manager | 3.Empleado): "; cin >> opcion1;
                registro(nombre, apellido, opcion1);
                break;
            case 2:
                borrarRegistro();
                break;
            case 3:
                leerUsuariosCSV();
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    }
};

class Manager {
public:
    void usuarios_manager() {
        int opcion;
        cout << "USUARIOS\nQue acción desea realizar? 1. Registro | 2. Borrar | 3. Consulta: ";
        cin >> opcion;
        string nombre, apellido;
        int opcion1;

        switch (opcion) {
            case 1:
                cout << "Ingrese el nombre: "; cin >> nombre;
                cout << "Ingrese el apellido: "; cin >> apellido;
                cout << "Ingrese el tipo de usuario (1.Manager | 2.Empleado): "; cin >> opcion1;
                registro(nombre, apellido, opcion1 + 1); // Ajuste para el rol
                break;
            case 2:
                cout << "No tiene permiso para borrar usuarios." << endl;
                break;
            case 3:
                leerUsuariosCSV();
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    }
};

class Empleado {
public:
    void usuarios_empleado() {
        int opcion;
        cout << "USUARIOS\nQue acción desea realizar? 1. Consultar: ";
        cin >> opcion;
        if (opcion == 1) {
            leerUsuariosCSV();
        } else {
            cout << "Opción no válida." << endl;
        }
    }
};