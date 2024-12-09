#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/CUsuario.h"  

using namespace std;
void registro(const string& nombre, const string& apellido, int opcion1) {
    ofstream archivo("./Model/Usuario/Usuarios.csv", ios::app);
    if (archivo.is_open()) {
        string rol;
        if (opcion1 == 1) {
            rol = "Admin";
        } else if (opcion1 == 2) {
            rol = "Manager";
        } else if (opcion1 == 3) {
            rol = "Empleado";
        }
        archivo << nombre << " " << apellido << "," << rol << "\n";
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
    }
}

void borrarRegistro() {
    int confirmar;
    ifstream input("../Model/Usuario/Usuarios.csv");
    ofstream temp("../Model/Usuario/temp.csv");
    int numero_fila = 1;
    int filaABorrar;
    cout << "Ingrese la fila a borrar: "; cin >> filaABorrar;
    if (filaABorrar == 1) {
        cout << "No se puede borrar la fila 1 ya que es la cabecera del archivo..." << endl;
        return;
    }
    string linea;
    while (getline(input, linea)) {
        if (numero_fila != filaABorrar) {
            temp << linea << endl;
        }
        numero_fila++;
    }
    input.close();
    temp.close();
    cout << "Desea confirmar el cambio?  1. Si |  2. No" << endl; cin >> confirmar;
    if (confirmar == 1) {
        remove("../Model/Usuario/Usuarios.csv");
        rename("../Model/Usuario/temp.csv", "../model/Usuario/Usuarios.csv");
    } else if (confirmar == 2) {
        remove("../Model/Usuario/temp.csv");
    }
}

void leerUsuariosCSV() {
    ifstream archivo("../Model/Usuario/Usuarios.csv");
    if (archivo.is_open()) {
        string linea;
        cout << "Lista de usuarios registrados:" << endl;
        while (getline(archivo, linea)) {
            cout << linea << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para leer." << endl;
    }
}
class Admin {
public:
    void usuarios_admin();
};

class Manager {
public:
    void usuarios_manager();
};

class Empleado {
public:
    void usuarios_empleado();
};
void Admin::usuarios_admin() {
    int opcion;
    cout << "USUARIOS" << endl;
    cout << "Que accion desea realizar? 1. Registro | 2. Borrar | 3. Consulta" << endl; cin >> opcion;
    string nombre;
    string apellido;
    int opcion1;
    switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del usuario: "; cin >> nombre;
            cout << "Ingrese el apellido del usuario: "; cin >> apellido;
            cout << "Ingrese el tipo de usuario: 1.Admin | 2.Manager | 3.Empleado" << endl; cin >> opcion1;
            registro(nombre, apellido, opcion1);
            break;
        case 2:
            borrarRegistro();
            break;
        case 3:
            leerUsuariosCSV();
            break;
        default:
            cout << "Opcion no valida" << endl;
    }
}
void Manager::usuarios_manager() {
    int opcion;
    cout << "USUARIOS" << endl;
    cout << "Que accion desea realizar? 1. Registro | 2. Borrar | 3. Consulta" << endl; cin >> opcion;
    string nombre;
    string apellido;
    int opcion1 = 0;
    int opcion2;
    switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del usuario: "; cin >> nombre;
            cout << "Ingrese el apellido del usuario: "; cin >> apellido;
            cout << "Ingrese el tipo de usuario: 1.Manager | 2.Empleado: " << endl; cin >> opcion2;
            if (opcion2 < 1 || opcion2 > 2) {
                cout << "Opcion no valida" << endl;
            } else {
                opcion1 = 1 + opcion2; 
                registro(nombre, apellido, opcion1);
            }
            break;
        case 2:
            cout << "No tiene permiso para borrar usuarios." << endl;
            break;
        case 3:
            leerUsuariosCSV();
            break;
        default:
            cout << "Opcion no valida" << endl;
    }
}
void Empleado::usuarios_empleado() {
    int opcion;
    cout << "USUARIOS" << endl;
    cout << "Que accion desea realizar? 1. Consultar" << endl; cin >> opcion;
    switch (opcion) {
        case 1:
            leerUsuariosCSV(); 
            break;
        default:
            cout << "Opcion no valida" << endl;
    }
}