#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Vehiculo {
    string modelo, marca, placa, color, fechaEntrega, motor;
    int year, kilometraje, cedula;
    bool rentado;
    float precioRenta;
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


void actualizarColumnaVehiculos(int Nlinea, int ind, const string& ValorN) {
    ifstream Archivo("./bin/Vehiculos.csv");
    ofstream archivoTemp("temp.csv"); 

    if (Archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        int contador = 1;
        while (getline(Archivo, linea)) {
            if (contador == Nlinea) {
                string bolv;
                stringstream ss(linea);
                Vehiculo v;
                getline(ss, v.modelo, ',');
                getline(ss, v.marca, ',');
                getline(ss, v.placa, ',');
                getline(ss, v.color, ',');
                ss >> v.year;
                ss.ignore();
                ss >> v.kilometraje;
                ss.ignore();
                getline(ss, bolv, ',');
                getline(ss, v.motor, ',');
                ss >> v.precioRenta;
                ss.ignore();
                ss >> v.cedula;
                ss.ignore();
                getline(ss, v.fechaEntrega, ',');

                switch (ind) {
                    case 1: 
                        v.modelo = ValorN; 
                        break;
                    case 2: 
                        v.marca = ValorN; 
                        break;
                    case 3: 
                        v.placa = ValorN; 
                        break;
                    case 4: 
                        v.color = ValorN; 
                        break;
                    case 5: 
                        v.year = stoi(ValorN); 
                        break;
                    case 6: 
                        v.kilometraje = stoi(ValorN); 
                        break;
                    case 7: 
                        bolv = ValorN; 
                        break;
                    case 8: 
                        v.motor = ValorN; 
                        break;
                    case 9: 
                        v.precioRenta = stof(ValorN); 
                        break;
                    case 10: 
                        v.cedula = stoi(ValorN); 
                        break;
                    case 11: 
                        v.fechaEntrega = ValorN; 
                        break;
                }

                archivoTemp << v.modelo << ","
                            << v.marca << ","
                            << v.placa << ","
                            << v.color << ","
                            << v.year << ","
                            << v.kilometraje << ","
                            << bolv << ","
                            << v.motor << ","
                            << v.precioRenta << ","
                            << v.cedula << ","
                            << v.fechaEntrega << endl;
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

void actualizarColumnaClientes(int Nlinea, int ind, const string& ValorN) {
    ifstream Archivo("./bin/Clientes.csv");
    ofstream archivoTemp("temp.csv", ios::out);

    if (Archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        int contador = 1;
        while (getline(Archivo, linea)) {
            if (contador == Nlinea) {
                string bolc;
                stringstream ss(linea);
                Cliente c;
                string rentado_str;
                ss >> c.cedula;
                ss.ignore();
                getline(ss, c.nombre, ',');
                getline(ss, c.apellido, ',');
                getline(ss, c.email, ',');
                ss >> c.nVehiculosRentados;
                ss.ignore();
                getline(cin,c.direccion, ',');
                getline(cin, bolc, ',');
                switch (ind) {
                    case 1: 
                        c.nombre = ValorN; 
                        break;
                    case 2: 
                        c.apellido = ValorN; 
                        break;
                    case 3: 
                        c.direccion = ValorN; 
                        break;
                    case 4: 
                        c.email = ValorN; 
                        break;
                    case 5: 
                        bolc = ValorN; 
                        break;
                    case 6: 
                        c.nVehiculosRentados = stoi(ValorN); 
                        break;
                    case 7: 
                        c.cedula = stoi(ValorN) ; 
                        break;
                }

                archivoTemp << "\"" << c.cedula << "\","
                            << "\"" << c.nombre << "\","
                            << "\"" << c.apellido << "\","
                            << "\"" << c.email << "\","
                            << c.nVehiculosRentados << ","
                            << c.direccion << ","
                            << bolc << ",\n";
            } else {
                archivoTemp << linea << endl;
            }
            contador++;
        }
        Archivo.close();
        archivoTemp.close();

        if (remove("./bin/Clientes.csv") != 0) {
            cout << "Error al eliminar el archivo original." << endl;
        } else if (rename("temp.csv", "./bin/Clientes.csv") != 0) {
            cout << "Error al renombrar el archivo temporal." << endl;
        } else {
            cout << "Columna actualizada" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo Clientes.csv" << endl;
    }
}

void actualizarColumnaRepuestos(int Nlinea, int ind, const string& ValorN) {
    ifstream Archivo("./bin/Repuestos.csv");
    ofstream archivoTemp("temp.csv", ios::out);

    if (Archivo.is_open() && archivoTemp.is_open()) {
        string linea;
        int contador = 1;
        while (getline(Archivo, linea)) {
            if (contador == Nlinea) {
                string bolr;
                stringstream ss(linea);
                Repuesto r;
                string rentado_str;
                getline(cin , r.partModel, ',');
                getline(ss, r.marca, ',');
                getline(ss, r.nombre, ',');
                getline(ss, r.modelo, ',');
                ss >> r.yearCarro;
                ss.ignore();
                ss >> r.precio;
                ss.ignore();
                ss >> r.existencias;
                switch (ind) {
                    case 1: 
                        r.partModel = ValorN; 
                        break;
                    case 2: 
                        r.marca = ValorN; 
                        break;
                    case 3: 
                        r.nombre = ValorN; 
                        break;
                    case 4: 
                        r.modelo = ValorN; 
                        break;
                    case 5: 
                        r.yearCarro = stoi(ValorN); 
                        break;
                    case 6: 
                        r.existencias = stoi(ValorN); 
                        break;
                    case 7: 
                        r.precio = stoi(ValorN) ; 
                        break;
                }

                archivoTemp << "\"" << r.partModel<< "\","
                            << "\"" << r.marca << "\","
                            << "\"" << r.nombre << "\","
                            << "\"" << r.modelo << "\","
                            << r.yearCarro << ","
                            << r.precio << ","
                            << r.existencias << ",\n";
            } else {
                archivoTemp << linea << endl;
            }
            contador++;
        }
        Archivo.close();
        archivoTemp.close();

        if (remove("./bin/Clientes.csv") != 0) {
            cout << "Error al eliminar el archivo original." << endl;
        } else if (rename("temp.csv", "./bin/Clientes.csv") != 0) {
            cout << "Error al renombrar el archivo temporal." << endl;
        } else {
            cout << "Columna actualizada" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo Clientes.csv" << endl;
    }
}

void actualizarFilaVehiculos(int Nlinea) {
    bool SoN;
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
            cout << "Ingrese los nuevos detalles del vehiculo:\n";
            cout << "Modelo: ";
            cin .ignore();
            getline(cin, v.modelo );
            cout << "Marca: ";
            getline(cin, v.marca);
            cout << "Placa: ";
            getline(cin, v.placa);
            cout << "Color: ";
            getline(cin, v.color);
            cout << "Year: "; 
            cin >> v.year;
            cout << "Kilometraje: ";
            cin >> v.kilometraje;
            cout << "Rentado (TRUE para si, FALSE para no): ";
            cin >> TF;
            cin.ignore();
            cout << "Motor: ";
            getline(cin, v.motor);
            cout << "Precio de renta: ";
            cin >> v.precioRenta;
            cout << "Cedula del cliente: ";
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
                        <<  "\"" << v.motor << "\","
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
    cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin>>SoN;
    if(SoN==true){
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
    else {
        cout<<"Operacion cancelada"<<endl;
        remove("temp.csv") != 0;
    }
}


void actualizarFilaClientes(int Nlinea) {
    bool SoN;
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
    cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin>>SoN;
    if(SoN==true){
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
    else {
        cout<<"Operacion cancelada"<<endl;
        remove("temp.csv") != 0;
    }
}


void actualizarFilaRepuestos(int Nlinea) {
    bool SoN;
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
            cout << "Year del vehiculo: "; 
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
    cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin>>SoN;
    if(SoN==true){
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
    else {
        cout<<"Operacion cancelada"<<endl;
        remove("temp.csv") != 0;
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
    bool SoN;
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
    getline(cin, v.modelo);
    cin.ignore();
    cout << "Marca: ";
    getline(cin, v.marca);
    cin.ignore();
    cout << "Placa: ";
    getline(cin, v.placa);
    cin.ignore();
    cout << "Color: ";
    getline(cin, v.color);
    cin.ignore();
    cout << "Year: ";
    cin >> v.year;
    cin.ignore();
    cout << "Kilometraje: ";
    cin >> v.kilometraje;
    cin.ignore();
    cout << "Rentado (TRUE para si, FALSE para no): ";
    cin >> ToF;
    cout << "Motor: ";
    getline(cin, v.motor);
    cin.ignore();
    cout << "Precio de renta: ";
    cin >> v.precioRenta;
    cin.ignore();
    cout << "Cedula del cliente: ";
    cin >> v.cedula;
    cin.ignore();
    cout << "Fecha de entrega(dd/mm/yyyy): ";
    getline(cin, v.fechaEntrega);
    cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin>>SoN;
    if(SoN==true){
    archivo << v.modelo << "," << v.marca << "," << v.placa << "," << v.color << "," << v.year << "," << v.kilometraje << ","
            << ToF << "," << v.motor << "," << v.precioRenta << "," << v.cedula << "," << v.fechaEntrega << "\n";
    archivo.close();
    cout << "Linea insertada en " << nombreArchivo << endl;
    }
    else{
        cout<<"Operacion cancelada"<<endl;
        archivo.close();
    }
}

void insertarNuevaLineaClientes() {
    bool SoN;
    string nombreArchivo= "./bin/Clientes.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Cliente c;
    string ToFa;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    cout << "Ingrese los detalles del cliente:\n";
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, c.nombre);
    cin.ignore();
    cout << "Apellido: ";
    getline(cin,c.apellido);
    cin.ignore();
    cout << "Direccion: "; 
    getline(cin, c.direccion);
    cout << "Cedula: ";
    cin >> c.cedula;
    cout << "Activo (TRUE para si, FALSE para no): ";
    getline(cin,ToFa);
    cout << "email: ";
    getline(cin,c.email);
    cout << "Numero de vehiculos rentados: ";
    cin >> c.nVehiculosRentados;
    cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin>>SoN;
    if(SoN==true){
    archivo << c.cedula << "," << c.nombre << "," << c.apellido << "," << c.email << "," << c.nVehiculosRentados << "," << c.direccion << ","
            << ToFa << "\n";
    archivo.close(); 
    cout << "Linea insertada en " << nombreArchivo << endl;
    }
    else{
        cout<<"Operacion cancelada"<<endl;
        archivo.close();
    }
}

void insertarNuevaLineaRepuestos() {
    bool SoN;
    string nombreArchivo= "./bin/Repuestos.csv";
    ofstream archivo(nombreArchivo, ios::app); 
    Repuesto r;
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    cout << "Ingrese los detalles de los repuestos:\n";
    cout << "Modelo del repuesto: ";
    cin.ignore();
    getline(cin,r.partModel);
    cout << "Marca: ";
    getline(cin,r.marca);
    cout << "Nombre: ";
    getline(cin,r.nombre);
    cout << "Modelo del vehiculo: ";
    getline(cin,r.modelo);
    cin.ignore();
    cout << "Year: ";
    cin >> r.yearCarro;
    cin.ignore();
    cout << "Existencias: ";
    cin >> r.existencias;
    cin.ignore();
    cout << "Precio: ";
    cin >> r.precio;
    cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
    cin>>SoN;
    if(SoN==true){
        archivo << r.partModel << "," << r.marca << "," << r.nombre << "," << r.modelo << "," << r.yearCarro << "," << r.precio << ","
        << r.existencias << "\n";
        archivo.close(); 
        cout << "Linea insertada en " << nombreArchivo << endl;
    }
    else{
        cout<<"Operacion cancelada"<<endl;
        archivo.close();
    }
}

void leerClientes(const string& nombreArchivo, Cliente*& clientes, int& numClientes) {
    ifstream file(nombreArchivo);
    string line;

    if (!file.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << endl;
        return;
    }

    numClientes = 0;
    while (getline(file, line)) {
        numClientes++;
    }
    
    file.clear(); 
    file.seekg(0);

    
    clientes = new Cliente[numClientes];

    getline(file, line);
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
        clientes[i++] = c; 
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
        Vehiculo v;
        getline(ss, v.modelo, ',');
        getline(ss, v.marca, ',');
        getline(ss, v.placa, ',');
        getline(ss, v.color, ',');
        ss >> v.year; ss.ignore();
        ss >> v.kilometraje; ss.ignore();
        ss >> v.rentado; ss.ignore();
        getline(ss, v.motor, ',');
        ss >> v.precioRenta; ss.ignore();
        ss >> v.cedula; ss.ignore();
        getline(ss, v.fechaEntrega);
        vehiculos[i++] = v; 
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
        Repuesto r;
        getline(ss, r.modelo, ',');
        getline(ss, r.marca, ',');
        getline(ss, r.nombre, ',');
        getline(ss, r.partModel, ',');
        ss >> r.yearCarro; ss.ignore();
        ss >> r.existencias; ss.ignore();
        ss >> r.precio; ss.ignore();
                repuestos[i++] = r; 
    }
    file.close();
}

void mostrarCliente(Cliente* clientes, int numClientes, int cedula) {
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].cedula == cedula) {
            cout << "Nombre: " << clientes[i].nombre << endl;
            cout << "Apellido: " << clientes[i].apellido << endl;
            cout << "Direccion: " << clientes[i].direccion << endl;
            cout << "Email: " << clientes[i].email << endl;
            cout << "Activo: " << (clientes[i].activo ? "Si" : "No") << endl;
            cout << "Vehiculos rentados: " << clientes[i].nVehiculosRentados << endl;
            return;
        }
    }
    cerr << "Cliente con cedula " << cedula << " no encontrado" << endl;
}

void mostrarVehiculo(Vehiculo* vehiculos, int numVehiculos, const string& placa) {
    for (int i = 0; i < numVehiculos; ++i) {
        if (vehiculos[i].placa == placa) {
            cout << "Modelo: " << vehiculos[i].modelo << endl;
            cout << "Marca: " << vehiculos[i].marca << endl;
            cout << "Placa: " << vehiculos[i].placa << endl;
            cout << "Color: " << vehiculos[i].color << endl;
            cout << "Year: " << vehiculos[i].year << endl; 
            cout << "Kilometraje: " << vehiculos[i].kilometraje << endl;
            cout << "Rentado: " << (vehiculos[i].rentado ? "Si" : "No") << endl;
            cout << "Motor: " << vehiculos[i].motor << endl;
            cout << "Precio de Renta: " << vehiculos[i].precioRenta << endl;
            cout << "Cedula del Cliente: " << vehiculos[i].cedula << endl;
            cout << "Fecha de Entrega: " << vehiculos[i].fechaEntrega << endl;
            return;
        }
    }
    cerr << "Vehiculo con placa " << placa << " no encontrado." << endl;
}

void mostrarRepuesto(Repuesto* repuestos, int numRepuestos, const string& modelo) {
    for (int i = 0; i < numRepuestos; ++i) {
        if (repuestos[i].modelo == modelo) {
            cout << "Modelo: " << repuestos[i].modelo << endl;
            cout << "Marca: " << repuestos[i].marca << endl;
            cout << "Nombre: " << repuestos[i].nombre << endl;
            cout << "Modelo del Carro: " << repuestos[i].partModel << endl;
            cout << "Year del Carro: " << repuestos[i].yearCarro << endl; 
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
    bool wh=true;
    char confirmar = 0;
    bool cambiosRealizados = false;

    Vehiculo* vehiculos = nullptr;
    int numVehiculos = 0;
    string placaBuscada; 

    Cliente* clientes = nullptr;
    int numClientes = 0; 
    int cedulaBuscada = 0; 

    Repuesto* repuestos = nullptr;
    int numRepuestos = 0;
    string modeloBuscado; 

    leerClientes(nombreArchivoClientes, clientes, numClientes);
    leerRepuestos(nombreArchivoRepuestos, repuestos, numRepuestos);
    leerVehiculos(nombreArchivoVehiculos, vehiculos, numVehiculos);

    do {
        cout << "Que archivo desea gestionar: " << endl;
        cout << "1. Vehiculos" << endl;
        cout << "2. Clientes" << endl;
        cout << "3. Repuestos" << endl;
        cout << "4. Cerrar el programa" <<endl;
        int opcion=0;
        int opcion1=0;
        int opcion11=0;
        int opcion12=0;
        int opcion13=0;
        int opcion2=0;
        int opcion21=0;
        int opcion22=0;
        int opcion23=0;
        int opcion3=0;
        int opcion31=0;
        int opcion32=0;
        int opcion33=0;
        int Nlinea=0;
        int ind=0;
        string ValorN;
        cin >> opcion;
        bool SoN;
        switch (opcion) {
        case 1: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4.Mostrar o buscar datos"<<endl;
            cout<<"5.Regresar"<<endl;
            cout<<"6.Cerrar el programa"<<endl;
            cin>>opcion1;
            switch (opcion1){
                case 1:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Elegir fila a borrar"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion11;
                    switch(opcion11){
                        case 1:
                            cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                borrarLinea(nombreArchivoVehiculos,Nlinea);
                                continue;
                            }
                            else{
                                cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 2:
                            continue;
                        case 3:
                            wh=false;
                            break;}
                continue;
                case 2:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Actualizar una columna de la fila"<<endl;
                    cout<<"2.Actualizar toda una fila"<<endl;
                    cout<<"3.Regresar"<<endl;
                    cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion12;
                    switch(opcion12){
                        case 1:
                            cout << "Ingrese la fila del vehiculo que quiere modificar: "; cin >> Nlinea;
                            cout << "Ingrese el numero de la columna que desea modificar (1-11): "<<endl;
                            cout << "1. Modelo"<<endl;
                            cout << "2. Marca"<<endl;
                            cout << "3. Placa"<<endl;
                            cout << "4. Color"<<endl;
                            cout << "5. Year"<<endl;
                            cout << "6. Kilometraje"<<endl;
                            cout << "7. Rentado (TRUE para si, FALSE para no)"<<endl;
                            cout << "8. Motor"<<endl;
                            cout << "9. Precio de Renta"<<endl;
                            cout << "10. Cedula del Cliente"<<endl;
                            cout << "11. Fecha de Entrega"<<endl;
                            cout << "Ingrese la opcion: "; cin >> ind;
                            cout << "Ingrese el dato actualizado: "; cin >> ValorN;
                            cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                actualizarColumnaVehiculos(Nlinea, ind, ValorN);
                                continue;
                            }
                            else{
                                cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 2:
                            cout<<"Ingrese el numero de fila que quiere modificar: ";
                            cin>>Nlinea;
                            actualizarFilaVehiculos(Nlinea);
                            continue;
                        case 3:
                            continue;
                        case 4:
                            wh=false;
                            break;}
                continue;
                case 3:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Insertar una fila"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion13;
                    switch(opcion13){
                        case 1:
                            insertarNuevaLineaVehiculos();
                            continue;
                        case 2:
                            continue;
                        case 3:
                            wh=false;
                            break;}
                continue;
                case 4:
                cout << "Ingrese la placa del vehiculo a consultar: "; 
                cin >> placaBuscada; 
                mostrarVehiculo(vehiculos, numVehiculos, placaBuscada);
                continue;

            case 5:
                continue;
            case 6:
                wh=false;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                continue; 
        }
        continue;
        case 2: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4.Mostrar o buscar datos"<<endl;
            cout<<"5.Regresar"<<endl;
            cout<<"6.Cerrar el programa"<<endl;
            cin>>opcion2;
            switch (opcion2){
                case 1:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Elegir fila a borrar"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion21;
                    switch(opcion21){
                        case 1:
                            cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                borrarLinea(nombreArchivoClientes,Nlinea);
                                continue;
                            }
                            else{
                                cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            break;
                        case 2:
                            continue;
                        case 3:
                            wh=false;
                            break;
                    }
                continue;
                case 2:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Actualizar una columna de la fila"<<endl;
                    cout<<"2.Actualizar toda una fila"<<endl;
                    cout<<"3.Regresar"<<endl;
                    cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion22;
                    switch(opcion22){
                        case 1:
                            cout << "Ingrese la fila del cliente que quiere modificar: "; cin >> Nlinea;
                            cout << "Ingrese el numero de la columna que desea modificar (1-7): "<<endl;
                            cout << "1. Nombre"<<endl;
                            cout << "2. Apellido"<<endl;
                            cout << "3. Direccion"<<endl;
                            cout << "4. Email"<<endl;
                            cout << "5. Activo (TRUE para si, FALSE para no)"<<endl;
                            cout << "6. Numero de vehiculos rentados"<<endl;
                            cout << "7. Cedula"<<endl;
                            cout << "Ingrese la opcion: "; cin >> ind;
                            cout << "Ingrese el dato actualizado: "; cin >> ValorN;
                            cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                actualizarColumnaClientes(Nlinea, ind, ValorN);
                                continue;
                            }
                            else{
                                cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            break;
                        case 2:
                            cout<<"Ingrese el numero de fila que quiere modificar: ";
                            cin>>Nlinea;
                            actualizarFilaClientes(Nlinea);
                            continue;
                        case 3:
                            continue;
                        case 4:
                            wh=false;
                            break;
                    }
                continue;
                case 3:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Insertar una fila"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion23;
                    switch(opcion23){
                        case 1:
                            insertarNuevaLineaClientes();
                            continue;
                        case 2:
                            continue;
                        case 3:
                            wh=false;
                            break;}
                continue;
                case 4:
                cout << "Ingrese la cedula del cliente a consultar: "; 
                cin >> cedulaBuscada; 
                mostrarCliente(clientes, numClientes, cedulaBuscada);
                continue;

            case 5:
                continue;
            case 6:
                wh=false;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                continue; 
        }
        break;
        case 3: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4.Mostrar o buscar datos"<<endl;
            cout<<"5.Regresar"<<endl;
            cout<<"6.Cerrar el programa"<<endl;
            cin>>opcion3;
            switch (opcion3){
                case 1:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Elegir fila a borrar"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion31;
                    switch(opcion31){
                        case 1:
                            cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                borrarLinea(nombreArchivoRepuestos,Nlinea);
                                continue;
                            }
                            else{
                                cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 3:
                            wh=false;
                            break;}
                break;
                case 2:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Actualizar una columna de la fila"<<endl;
                    cout<<"2.Actualizar toda una fila"<<endl;
                    cout<<"3.Regresar"<<endl;
                    cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion32;
                    switch(opcion32){
                        case 1:
                            cout << "Ingrese la fila del repuestos que quiere modificar: "; cin >> Nlinea;
                            cout << "Ingrese el numero de la columna que desea modificar (1-7): "<<endl;
                            cout << "1. Modelo del repuesto"<<endl;
                            cout << "2. Marca"<<endl;
                            cout << "3. Nombre"<<endl;
                            cout << "4. Modelo del carro"<<endl;
                            cout << "5. Year Carro"<<endl;
                            cout << "6. Existencias"<<endl;
                            cout << "7. Precio"<<endl;
                            cout << "Ingrese la opcion: "; cin >> ind;
                            cout << "Ingrese el dato actualizado: "; cin >> ValorN;
                            cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                actualizarColumnaRepuestos(Nlinea, ind, ValorN);
                                continue;
                            }
                            else{
                                cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 2:
                            cout<<"Ingrese el numero de fila que quiere modificar: ";
                            cin>>Nlinea;
                            actualizarFilaRepuestos(Nlinea);
                        case 3:
                            continue;
                        case 4:
                            wh=false;
                            break;
                    }
                continue;
                case 3:
                    cout<<"Como desea proceder:"<<endl;
                    cout<<"1.Insertar una fila"<<endl;
                    cout<<"2.Regresar"<<endl;
                    cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion33;
                    switch(opcion33){
                        case 1:
                            insertarNuevaLineaRepuestos();
                            continue;
                        case 2:
                            continue;
                        case 3:
                            wh=false;
                            break;
                }
                continue;
                case 4:
                cout << "Ingrese el modelo del repuesto a consultar: "; 
                cin >> modeloBuscado; 
                mostrarRepuesto(repuestos, numRepuestos, modeloBuscado);
                continue;
            case 5:
                continue;
            case 6:
                wh=false;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                continue; 
        }
        continue;   
        case 4:
            wh=false;
            break;  
        default: 
            cout << "Opcion no valida. Intente de nuevo." << endl;
            continue; 
        }
    delete[] vehiculos;
    delete[] clientes;
    delete[] repuestos;
    } while(wh==true);
    getchar();
    return 0;       
}