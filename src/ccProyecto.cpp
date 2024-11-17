#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

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

void Cerrar(){
    exit(0);
}

void actualizarFilaVehiculos(int Nlinea) {
    string nombreArchivo= "./bin/Vehiculos.csv";
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 1;
    Vehiculo v;
    string TF;

    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo Vehiculos.csv"<< endl;
        return;
    }

    if (!archivoTemp.is_open()) {
        cout << "Error al abrir el archivo temporal." << endl;
        return;
    }

    while (getline(archivo, linea)) {
        if (i == Nlinea) {
            cout << "Ingrese los nuevos detalles del vehículo:\n";
            cout << "Modelo: ";
            cin .ignore();
            getline(cin, v.modelo );
            cout << "Marca: ";
            getline(cin, v.marca);
            cout << "Placa: ";
            getline(cin, v.placa);
            cout << "Color: ";
            getline(cin, v.color);
            cout << "Año: ";
            cin >> v.year;
            cout << "Kilometraje: ";
            cin >> v.kilometraje;
            cout << "Rentado (TRUE para sí, FALSE para no): ";
            cin >> TF;
            cout << "Motor: ";
            cin >> v.motor;
            cout << "Precio de renta: ";
            cin >> v.precioRenta;
            cout << "Cédula del cliente: ";
            cin >> v.cedula;
            cin.ignore(); 
            cout << "Fecha de entrega: ";
            getline(cin, v.fechaEntrega);

            archivoTemp << "\"" << v.modelo << "\","
                        << "\"" << v.marca << "\","
                        << "\"" << v.placa << "\","
                        << "\"" << v.color << "\","
                        << v.year << ","
                        << v.kilometraje << ","
                        << TF << ","
                        << v.motor << ","
                        << v.precioRenta << ","
                        << v.cedula << ","
                        << "\"" << v.fechaEntrega << "\"\n";
        } else {
            archivoTemp << linea << "\n";
        }
        i++;
    }

    archivo.close();
    archivoTemp.close();

    if (remove(nombreArchivo.c_str()) != 0) {
        cout << "Error al eliminar el archivo original." << endl;
        return;
    }
    if (rename("temp.csv", nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
    }
}

void actualizarFilaClientes(int Nlinea) {
    string nombreArchivo= "./bin/Clientes.csv";
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 1;
    Cliente c;
    string TFC;

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
            cin .ignore();
            getline(cin, c.nombre );
            cout << "Apellido: ";
            getline(cin, c.apellido);
            cout << "Direccion: ";
            getline(cin, c.direccion);
            cout << "Email: ";
            getline(cin, c.email);
            cout << "Activo (TRUE para si, FALSE para no): ";
            cin >> TFC;
            cout << "Numero de vehiculos rentados: ";
            cin >> c.nVehiculosRentados;
            cout << "Cedula: ";
            cin >> c.cedula;
            archivoTemp << "\"" << c.cedula << "\","
                        << "\"" << c.nombre << "\","
                        << "\"" << c.apellido << "\","
                        << "\"" << c.email << "\","
                        << c.nVehiculosRentados << ","
                        << c.direccion << ","
                        << TFC << ",\n";
        } else {
            archivoTemp << linea << "\n";
        }
        i++;
    }

    archivo.close();
    archivoTemp.close();

    if (remove(nombreArchivo.c_str()) != 0) {
        cout << "Error al eliminar el archivo original." << endl;
        return;
    }
    if (rename("temp.csv", nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
    }
}

void actualizarFilaRepuestos(int Nlinea) {
    string nombreArchivo= "./bin/Repuestos.csv";
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 1;
    Repuesto r;

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
            cin .ignore();
            getline(cin, r.modelo );
            cout << "Marca: ";
            getline(cin, r.marca);
            cout << "Nombre: ";
            getline(cin, r.nombre);
            cout << "Modelo del repuesto: ";
            getline(cin, r.partModel);
            cout << "Año del vehiculo: ";
            cin >> r.yearCarro;
            cout << "Existencias: ";
            cin >> r.existencias;
            cout << "Precio: ";
            cin >> r.precio;

            archivoTemp << "\"" << r.modelo << "\","
                        << "\"" << r.marca << "\","
                        << "\"" << r.nombre << "\","
                        << "\"" << r.partModel << "\","
                        << r.yearCarro << ","
                        << r.precio << ","
                        << r.existencias << ",\n";
        } else {
            archivoTemp << linea << "\n";
        }
        i++;
    }

    archivo.close();
    archivoTemp.close();

    if (remove(nombreArchivo.c_str()) != 0) {
        cout << "Error al eliminar el archivo original." << endl;
        return;
    }
    if (rename("temp.csv", nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
    }
}

void borrarLinea(const string& nombreArchivo, int Nlinea) {
    ifstream archivo(nombreArchivo);
    ofstream archivoTemp("temp.csv");
    string linea;
    int i = 1;

    if (!archivo.is_open()) {
    cout << "Error al abrir el archivo " << nombreArchivo << endl;
    return;
    }
    if (!archivoTemp.is_open()) {
        cout << "Error al abrir el archivo temporal." << endl;
        return;
    }
    while (getline(archivo, linea)) {
        if (i != Nlinea) {
            archivoTemp << linea << "\n";
        }
        i++;
    }
    archivo.close();
    archivoTemp.close();
    if (remove(nombreArchivo.c_str()) != 0) {
        cout << "Error al eliminar el archivo original." << endl;
        return;
    }
    if (rename("temp.csv", nombreArchivo.c_str()) != 0) {
        cout << "Error al renombrar el archivo temporal." << endl;
    }
}

void insertarNuevaLineaVehiculos() {
    string nombreArchivo= "./bin/Vehiculos.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Vehiculo v;
    string ToF;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    cout << "Ingrese los detalles del vehiculo:\n";
    cout << "Modelo: ";
    cin >> v.modelo;
    cout << "Marca: ";
    cin >> v.marca;
    cout << "Placa: ";
    cin >> v.placa;
    cout << "Color: ";
    cin >> v.color;
    cout << "Year: ";
    cin >> v.year;
    cout << "Kilometraje: ";
    cin >> v.kilometraje;
    cout << "Rentado (TRUE para si, FALSE para no): ";
    cin >> ToF;
    cout << "Motor: ";
    cin >> v.motor;
    cout << "Precio de renta: ";
    cin >> v.precioRenta;
    cout << "Cedula del cliente: ";
    cin >> v.cedula;
    cin.ignore();
    cout << "Fecha de entrega(dd/mm/yyyy): ";
    getline(cin, v.fechaEntrega);
    archivo << v.modelo << "," << v.marca << "," << v.placa << "," << v.color << "," << v.year << "," << v.kilometraje << ","
            << ToF << "," << v.motor << "," << v.precioRenta << "," << v.cedula << "," << v.fechaEntrega << "\n";
    archivo.close(); 
    cout << "Linea insertada en " << nombreArchivo << endl;
}

void insertarNuevaLineaClientes() {
    string nombreArchivo= "./bin/Clientes.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Cliente c;
    string ToFa;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    cout << "Ingrese los detalles del cliente:\n";
    cout << "Nombre: ";
    cin >> c.nombre;
    cout << "Apellido: ";
    cin >> c.apellido;
    cin.ignore();
    cout << "Direccion: "; 
    getline(cin, c.direccion);
    cout << "Cedula: ";
    cin >> c.cedula;
    cout << "Activo (TRUE para si, FALSE para no): ";
    cin >> ToFa;
    cout << "email: ";
    cin >> c.email;
    cout << "Numero de vehiculos rentados: ";
    cin >> c.nVehiculosRentados;
    archivo << c.cedula << "," << c.nombre << "," << c.apellido << "," << c.email << "," << c.nVehiculosRentados << "," << c.direccion << ","
            << ToFa << "\n";
    archivo.close(); 
    cout << "Linea insertada en " << nombreArchivo << endl;
}

void insertarNuevaLineaRepuestos() {
    string nombreArchivo= "./bin/Repuestos.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Repuesto r;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    cout << "Ingrese los detalles de los repuestos:\n";
    cout << "Modelo del repuesto: ";
    cin >> r.partModel;
    cout << "Marca: ";
    cin >> r.marca;
    cout << "Nombre: ";
    cin >> r.nombre;
    cout << "Modelo del vehiculo: ";
    cin >> r.modelo;
    cout << "Year: ";
    cin >> r.yearCarro;
    cout << "Existencias: ";
    cin >> r.existencias;
    cout << "Precio: ";
    cin >> r.precio;
    archivo << r.partModel << "," << r.marca << "," << r.nombre << "," << r.modelo << "," << r.yearCarro << "," << r.precio << ","
            << r.existencias << "\n";
    archivo.close(); 
    cout << "Linea insertada en " << nombreArchivo << endl;
}

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

void escribirClientes(const string& nombreArchivo, Cliente* clientes, int numClientes) {
    ofstream file(nombreArchivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    file << "nombre,apellido,direccion,email,activo,nVehiculosRentados,cedula\n";
    for (int i = 0; i < numClientes; ++i) {
        file << clientes[i].nombre << "," << clientes[i].apellido << "," << clientes[i].direccion << "," 
             << clientes[i].email << "," << clientes[i].activo << "," << clientes[i].nVehiculosRentados 
             << "," << clientes[i].cedula << "\n";
    }
    file.close();
}

void escribirVehiculos(const string& nombreArchivo, Vehiculo* vehiculos, int numVehiculos) {
    ofstream file(nombreArchivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    file << "modelo,marca,placa,color,year,kilometraje,rentado,motor,precioRenta,cedula,fechaEntrega\n";
    for (int i = 0; i < numVehiculos; ++i) {
        file << vehiculos[i].modelo << "," << vehiculos[i].marca << "," << vehiculos[i].placa << "," 
             << vehiculos[i].color << "," << vehiculos[i].year << "," << vehiculos[i].kilometraje << "," 
             << vehiculos[i].rentado << "," << vehiculos[i].motor << "," << vehiculos[i].precioRenta << "," 
             << vehiculos[i].cedula << "," << vehiculos[i].fechaEntrega << "\n";
    }
    file.close();
}

void escribirRepuestos(const string& nombreArchivo, Repuesto* repuestos, int numRepuestos) {
    ofstream file(nombreArchivo);
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    file << "modelo,marca,nombre,partModel,yearCarro,precio,existencias\n";
    for (int i = 0; i < numRepuestos; ++i) {
        file << repuestos[i].modelo << "," << repuestos[i].marca << "," << repuestos[i].nombre << "," 
             << repuestos[i].partModel << "," << repuestos[i].yearCarro << "," << repuestos[i].precio 
             << "," << repuestos[i].existencias << "\n";
    }
    file.close();
}

void mostrarCliente(Cliente* clientes, int numClientes, int cedula) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].cedula == cedula) {
            cout << "Nombre: " << clientes[i].nombre << endl;
            cout << "Apellido: " << clientes[i].apellido << endl;
            cout << "Dirección: " << clientes[i].direccion << endl;
            cout << "Email: " << clientes[i].email << endl;
            cout << "Activo: " << (clientes[i].activo ? "Sí" : "No") << endl;
            cout << "Vehículos rentados: " << clientes[i].nVehiculosRentados << endl;
            return;
        }
    }
    cerr << "Cliente con cédula " << cedula << " no encontrado" << endl;
}

void mostrarVehiculo(Vehiculo* vehiculos, int numVehiculos, const string& placa) {
    for (int i = 0; i < numVehiculos; ++i) {
        if (vehiculos[i].placa == placa) {
            cout << "Modelo: " << vehiculos[i].modelo << endl;
            cout << "Marca: " << vehiculos[i].marca << endl;
            cout << "Placa: " << vehiculos[i].placa << endl;
            cout << "Color: " << vehiculos[i].color << endl;
            cout << "Año: " << vehiculos[i].year << endl;
            cout << "Kilometraje: " << vehiculos[i].kilometraje << endl;
            cout << "Rentado: " << (vehiculos[i].rentado ? "Sí" : "No") << endl;
            cout << "Motor: " << vehiculos[i].motor << endl;
            cout << "Precio de Renta: " << vehiculos[i].precioRenta << endl;
            cout << "Cédula del Cliente: " << vehiculos[i].cedula << endl;
            cout << "Fecha de Entrega: " << vehiculos[i].fechaEntrega << endl;
            return;
        }
    }
    cerr << "Vehículo con placa " << placa << " no encontrado." << endl;
}

void mostrarRepuesto(Repuesto* repuestos, int numRepuestos, const string& modelo) {
    for (int i = 0; i < numRepuestos; ++i) {
        if (repuestos[i].modelo == modelo) {
            cout << "Modelo: " << repuestos[i].modelo << endl;
            cout << "Marca: " << repuestos[i].marca << endl;
            cout << "Nombre: " << repuestos[i].nombre << endl;
            cout << "Modelo del Carro: " << repuestos[i].partModel << endl;
            cout << "Año del Carro: " << repuestos[i].yearCarro << endl;
            cout << "Precio: " << repuestos[i].precio << endl;
            cout << "Existencias: " << repuestos[i].existencias << endl;
            return;
        }
    }
    cerr << "Repuesto con modelo " << modelo << " no encontrado." << endl;
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

    char confirmar;
    bool cambiosRealizados = false;

    Vehiculo* vehiculos = nullptr;
    int numVehiculos = 0;
    string placaBuscada; 

    Cliente* clientes = nullptr;
    int numClientes = 0; 
    int cedulaBuscada; 

    Repuesto* repuestos = nullptr;
    int numRepuestos = 0;
    string modeloBuscado; 

    leerClientes(nombreArchivoClientes, clientes, numClientes);
    leerRepuestos(nombreArchivoRepuestos, repuestos, numRepuestos);
    leerVehiculos(nombreArchivoVehiculos, vehiculos, numVehiculos);

    while (true) {
        cout << "Que archivo desea gestionar: " << endl;
        cout << "1. Vehiculos" << endl;
        cout << "2. Clientes" << endl;
        cout << "3. Repuestos" << endl;
        int opcion, Nlinea;
        cin >> opcion;

        if (opcion == 4) {
            break; // Salir del bucle
        }
        switch (opcion) {
        case 1: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4. Mostrar o buscar datos"<<endl;
            cout<<"5. Regresar"<<endl;
            cin>>opcion;
            switch (opcion){
                case 1:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Elegir fila a borrar"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            borrarLinea(nombreArchivoVehiculos,Nlinea);
                            break;
                        case 2:
                            Cerrar();
                            break;}
                break;
                case 2:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Actualizar una columna de la fila"<<endl;
                    cout<<"2.Actualizar toda una fila"<<endl;
                    cout<<"3.Regresar"<<endl;
                    cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            break;
                        case 2:
                            cout<<"Ingrese el numero de fila que quiere modificar: ";
                            cin>>Nlinea;
                            actualizarFilaVehiculos(Nlinea);
                            break;
                        case 4:
                            Cerrar();
                            break;}
                break;
                case 3:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Insertar una fila"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            insertarNuevaLineaVehiculos();
                            break;
                        case 2:
                            break;
                        case 3:
                            Cerrar();
                            break;}
                break;
                case 4:
                cout << "Ingrese la placa del vehículo a consultar: "; 
                cin >> placaBuscada; 
                mostrarVehiculo(vehiculos, numVehiculos, placaBuscada);
                break;

            case 5:
                continue;
        }

        if (cambiosRealizados) {
            cout << "¿Desea guardar los cambios realizados? (s/n): ";
            char confirmar;
            cin >> confirmar;
            if (confirmar == 's' || confirmar == 'S') {
                escribirVehiculos(nombreArchivoVehiculos, vehiculos, numVehiculos);
                cout << "Cambios guardados." << endl;
            } else {
                cout << "Cambios no guardados." << endl;
            }
            cambiosRealizados = false; 
        break;
        }
        case 2: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4. Mostrar o buscar datos"<<endl;
            cout<<"5. Regresar"<<endl;
            cin>>opcion;
            switch (opcion){
                case 1:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Elegir fila a borrar"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            borrarLinea(nombreArchivoClientes,Nlinea);
                            break;
                        case 2:
                            break;
                        case 3:
                            Cerrar();
                            break;
                    }
                break;
                case 2:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Actualizar una columna de la fila"<<endl;
                    cout<<"2.Actualizar toda una fila"<<endl;
                    cout<<"3.Regresar"<<endl;
                    cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            
                        case 2:
                            cout<<"Ingrese el numero de fila que quiere modificar: ";
                            cin>>Nlinea;
                            actualizarFilaClientes(Nlinea);
                            break;
                        case 3:
                            break;
                        case 4:
                            Cerrar();
                            break;
                    }
                break;
                case 3:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Insertar una fila"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            insertarNuevaLineaClientes();
                            break;
                        case 2:
                            Cerrar();
                            break;}
                break;
                case 4:
                cout << "Ingrese la cédula del cliente a consultar: "; 
                cin >> cedulaBuscada; 
                mostrarCliente(clientes, numClientes, cedulaBuscada);
                break;

            case 5:
                continue;
        }

        if (cambiosRealizados) {
            cout << "¿Desea guardar los cambios realizados? (s/n): ";
            char confirmar;
            cin >> confirmar;
            if (confirmar == 's' || confirmar == 'S') {
                escribirClientes(nombreArchivoClientes, clientes, numClientes); 
                cout << "Cambios guardados." << endl;
            } else {
                cout << "Cambios no guardados." << endl;
            }
            cambiosRealizados = false; 
        }
        break;
        case 3: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4. Mostrar o buscar datos"<<endl;
            cout<<"5. Regresar"<<endl;
            cin>>opcion;
            switch (opcion){
                case 1:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Elegir fila a borrar"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            borrarLinea(nombreArchivoRepuestos,Nlinea);
                            break;
                        case 3:
                            Cerrar();}
                break;
                case 2:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Actualizar una columna de la fila"<<endl;
                    cout<<"2.Actualizar toda una fila"<<endl;
                    cout<<"3.Regresar"<<endl;
                    cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:

                        case 2:
                            cout<<"Ingrese el numero de fila que quiere modificar: ";
                            cin>>Nlinea;
                            actualizarFilaRepuestos(Nlinea);
                        case 3:
                            break;
                        case 4:
                            Cerrar();
                    }
                break;
                case 3:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Insertar una fila"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion;
                    switch(opcion){
                        case 1:
                            insertarNuevaLineaRepuestos();
                            break;
                        case 3:
                            Cerrar();
                }
                break;
                case 4:
                cout << "Ingrese el modelo del repuesto a consultar: "; 
                cin >> modeloBuscado; 
                mostrarRepuesto(repuestos, numRepuestos, modeloBuscado);
                break;

            case 5:
                continue;
        }

        if (cambiosRealizados) {
            cout << "¿Desea guardar los cambios realizados? (s/n): ";
            char confirmar;
            cin >> confirmar;
            if (confirmar == 's' || confirmar == 'S') {
                escribirRepuestos(nombreArchivoRepuestos, repuestos, numRepuestos);  
                cout << "Cambios guardados." << endl;
            } else {
                cout << "Cambios no guardados." << endl;
            }
            cambiosRealizados = false; 
        }
        break;         
        default: 
            cout << "Opción no válida. Intente de nuevo." << endl;
            continue;
            break; 
        }
    delete[] vehiculos;
    delete[] clientes;
    delete[] repuestos;
    }
    return 0;       
}
