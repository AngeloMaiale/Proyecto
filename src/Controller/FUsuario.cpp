#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include "../Model/CUsuario.h"
#include "../View/Visual.cpp"

using namespace std;

void registro(const string& nombre, const string& apellido, int opcion1) {
    ofstream archivo("../model/Usuario/Usuarios.csv", ios::app);
    if (archivo.is_open()) {
        string tipoUsuario;
        switch (opcion1) {
            case 1: tipoUsuario = "Admin"; break;
            case 2: tipoUsuario = "Manager"; break;
            case 3: tipoUsuario = "Empleado"; break;
            default: cerr << "Opción de usuario no válida." << endl; return;
        }
        archivo << nombre << "," << apellido << "," << tipoUsuario << "\n";
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
    }
}

void borrarRegistro() {
    int confirmar;
    ifstream input("../model/Usuario/Usuarios.csv");
    ofstream temp("../model/Usuario/temp.csv");
    int numero_fila = 1;
    int filaABorrar;
    
    std::cout << "Ingrese el número de la fila que desea borrar (la fila 1 es la cabecera y no se puede eliminar): "; 
    cin >> filaABorrar;

    if (filaABorrar == 1) {
        std::cout << "Error: No se puede borrar la fila 1, ya que es la cabecera del archivo y contiene información esencial." << endl;
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

    std::cout << "Desea confirmar el cambio?  1. Si |  2. No" << endl; 
    cin >> confirmar;

    if (confirmar == 1) {
        remove("../model/Usuario/Usuarios.csv");
        rename("../model/Usuario/temp.csv", "../model/Usuario/Usuarios.csv");
        std::cout << "Registro borrado con éxito." << endl;
    } else if (confirmar == 2) {
        remove("../model/Usuario/temp.csv");
        std::cout << "Operación cancelada." << endl;
    }
}

void leerUsuariosCSV() {
    ifstream archivo("../model/Usuario/Usuarios.csv");
    if (archivo.is_open()) {
        string linea;
        std::cout << "Lista de usuarios registrados:" << endl;
        while (getline(archivo, linea)) {
            std::cout << linea << endl;
        }
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo para leer." << endl;
    }
}

string obtenerFechaActual() {
    time_t t = time(nullptr);
    tm* tmPtr = localtime(&t);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", tmPtr);
    return string(buffer);
}

void crearCopiaDeSeguridad(const string& nombreArchivo) {
    string fecha = obtenerFechaActual();
    string nombreCopia = "./copiaProyecto/" + fecha + "_" + nombreArchivo;
    if (!filesystem::exists("./copiaProyecto")) {
        filesystem::create_directory("./copiaProyecto");
    }

    ifstream archivoOriginal(nombreArchivo, ios::binary);
    ofstream archivoCopia(nombreCopia, ios::binary);

    if (archivoOriginal && archivoCopia) {
        archivoCopia << archivoOriginal.rdbuf(); 
        std::cout << "Copia de seguridad creada: " << nombreCopia << endl;
    } else {
        std::cout << "Error al crear la copia de seguridad." << endl;
        if (!archivoOriginal) {
            std::cout << "No se pudo abrir el archivo original: " << nombreArchivo << endl;
        }
        if (!archivoCopia) {
            std::cout << "No se pudo crear el archivo de copia: " << nombreCopia << endl;
        }
    }
}
class Admin {
public:
    void copiaSeguridad();
    void vehiculosAdmin();
    void clientesAdmin();
    void repuestosAdmin();
    void usuariosAdmin();
};

void Admin::copiaSeguridad() {
    string archivo;
    int opcion;

    cout << "Copia de seguridad" << endl;
    cout << "¿Qué archivo desea respaldar? \n1 = Vehiculos | 2 = Clientes | 3 = Repuestos | 4 = Usuarios\n"; 
    cin >> opcion;

    switch (opcion) {
        case 1: archivo = "../model/Vehiculos/Vehiculos.csv"; break;
        case 2: archivo = "../model/Clientes/Clientes.csv"; break;
        case 3: archivo = "../model/Repuestos/Repuestos.csv"; break;
        case 4: archivo = "../model/Usuario/Usuarios.csv"; break;
        default:
            cout << "Opción no válida" << endl;
            return;
    }

    crearCopiaDeSeguridad(archivo);
}

void Admin::vehiculosAdmin() {
    Vehiculo v;
    int opcion;
    cout << "VEHICULOS" << endl;
    cout << "¿Qué acción desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Inserción | 4 = Consulta\n"; 
    cin >> opcion;

    switch (opcion) {
        case 1: v.borrar(); break;
        case 2: v.actualizar(); break;
        case 3: v.insercion(); break;
        case 4: v.consulta(); break;
        default: cout << "Opción no válida" << endl; break;
    }
}

void Admin::clientesAdmin() {
    Cliente c;
    int opcion;
    cout << "CLIENTES" << endl;
    cout << "¿Qué acción desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Inserción | 4 = Consulta\n"; 
    cin >> opcion;

    switch (opcion) {
        case 1: c.borrar(); break;
        case 2: c.actualizar(); break;
        case 3: c.insercion(); break;
        case 4: c.consulta(); break;
        default: cout << "Opción no válida" << endl; break;
    }
}

void Admin::repuestosAdmin() {
    Repuesto r;
    int opcion;
    cout << "REPUESTOS" << endl;
    cout << "¿Qué acción desea realizar? \n1 = Borrar | 2 = Actualizar | 3 = Inserción | 4 = Consulta\n"; 
    cin >> opcion;

    switch (opcion) {
        case 1: r.borrar(); break;
        case 2: r.actualizar(); break;
        case 3: r.insercion(); break;
        case 4: r.consulta(); break;
        default: cout << "Opción no válida" << endl; break;
    }
}

void Admin::usuariosAdmin() {
    int opcion;
    cout << "USUARIOS" << endl;
    cout << "¿Qué acción desea realizar? \n1. Registro | 2. Borrar | 3. Consulta" << endl; 
    cin >> opcion;

    string nombre, apellido;
    int opcion1;

    switch (opcion) {
        case 1:
            std::cout << "Ingrese el nombre del usuario: "; cin >> nombre;
            std::cout << "Ingrese el apellido del usuario: "; cin >> apellido;
            std::cout << "Ingrese el tipo de usuario: 1.Admin | 2.Manager | 3.Empleado" << endl; 
            cin >> opcion1;
            registro(nombre, apellido, opcion1);
            break;
        case 2:
            borrarRegistro();
            break;
        case 3:
            leerUsuariosCSV();
            break;
        default:
            std::cout << "Opción no válida" << endl;
    }
}

class Manager {
public:
    void clientesManager();
    void vehiculosManager();
    void repuestosManager();
    void usuariosManager();
};

void Manager::clientesManager() {
    Cliente c;
    int opcion;
    cout << "CLIENTES" << endl;
    cout << "¿Qué acción desea realizar? \n1. Borrar | 2. Actualizar | 3. Inserción | 4. Consulta" << endl; 
    cin >> opcion;

    switch (opcion) {
        case 1: c.borrar(); break;
        case 2: c.actualizar(); break;
        case 3: c.insercion(); break;
        case 4: c.consulta(); break;
        default: cout << "Opción no válida" << endl; break;
    }
}

void Manager::vehiculosManager() {
    Vehiculo v;
    int opcion;
    cout << "VEHICULOS" << endl;
    cout << "¿Qué acción desea realizar? \n1. Borrar | 2. Actualizar | 3. Inserción | 4. Consulta" << endl; 
    cin >> opcion;

    switch (opcion) {
        case 1: v.borrar(); break;
        case 2: v.actualizar(); break;
        case 3: v.insercion(); break;
        case 4: v.consulta(); break;
        default: cout << "Opción no válida" << endl; break;
    }
}

void Manager::repuestosManager() {
    Repuesto r;
    int opcion;
    cout << "REPUESTOS" << endl;
    cout << "¿Qué acción desea realizar? \n1. Borrar | 2. Actualizar | 3. Inserción | 4. Consulta" << endl; 
    cin >> opcion;

    switch (opcion) {
        case 1: r.borrar(); break;
        case 2: r.actualizar(); break;
        case 3: r.insercion(); break;
        case 4: r.consulta(); break;
        default: cout << "Opción no válida" << endl; break;
    }
}

void Manager::usuariosManager() {
    int opcion;
    cout << "USUARIOS" << endl;
    cout << "¿Qué acción desea realizar? \n1. Registro | 2. Borrar | 3. Consulta" << endl; 
    cin >> opcion;

    string nombre, apellido;
    int opcion1 = 0;
    int opcion2;

    switch (opcion) {
        case 1:
            cout << "Ingrese el nombre del usuario: "; cin >> nombre;
            cout << "Ingrese el apellido del usuario: "; cin >> apellido;
            cout << "Ingrese el tipo de usuario: 1. Manager | 2. Empleado: " << endl; 
            cin >> opcion2;
            if (opcion2 < 1 || opcion2 > 2) {
                cout << "Opción no válida" << endl;
            } else {
                opcion1 = 1 + opcion2; 
                registro(nombre, apellido, opcion1);
            }
            break;
        case 2:
            borrarRegistro(); 
            break;
        case 3:
            leerUsuariosCSV(); 
            break;
        default:
            cout << "Opción no válida" << endl; break;
    }
}

class Empleado {
public:
    void clientesEmpleados();
    void vehiculosEmpleados();
    void repuestosEmpleados();
};

void Empleado::clientesEmpleados() {
    Cliente c;
    int opcion, opciong;
    cout << "CLIENTES" << endl;
    cout << "¿Qué acción desea realizar? \n1. Vender | 2. Consultar" << endl; 
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "El cliente está registrado? \n1. Sí | 2. No" << endl; 
            cin >> opciong;
            if (opciong == 1) {
                c.actualizar(); 
            } else if (opciong == 2) {
                c.insercion(); 
            } else {
                cout << "Opción no válida" << endl;
            }
            break;
        case 2:
            c.consulta();
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}

void Empleado::vehiculosEmpleados() {
    Vehiculo v;
    int opcion;
    cout << "VEHICULOS" << endl;
    cout << "¿Qué acción desea realizar? \n1. Consultar | 2. Actualizar (Realizar una venta)" << endl; 
    cin >> opcion;

    switch (opcion) {
        case 1:
            v.consulta(); 
            break;
        case 2:
            v.actualizar();
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}

void Empleado::repuestosEmpleados() {
    Repuesto r;
    int opcion;
    cout << "REPUESTOS" << endl;
    cout << "¿Qué acción desea realizar? \n1. Consultar | 2. Actualizar (Realizar una venta)" << endl; 
    cin >> opcion;

    switch (opcion) {
        case 1:
            r.consulta(); 
            break;
        case 2:
            r.actualizar(); 
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}