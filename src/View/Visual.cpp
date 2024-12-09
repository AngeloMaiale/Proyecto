#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>
#include <string>
#include <cstdlib>
#include "../Model/CClientes.h"
#include "../Model/CVehiculos.h"
#include "../Model/CRepuestos.h"
#include "../Model/CUsuario.h"
#include "../Controller/FBorrar.cpp"
#include "../Controller/FVehiculos.cpp"
#include "../Controller/FClientes.cpp"
#include "../Controller/Frepuestos.cpp"
#include "../Controller/FUsuario.cpp"
using namespace std;

void Consola() {
    auto obtenerFechaActual = []() {
        time_t t = time(nullptr);
        tm* tmPtr = localtime(&t);
        char buffer[11];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d", tmPtr);
        return string(buffer);
    };

    auto crearCopiaDeSeguridad = [&](const string& nombreArchivo) {
        string fecha = obtenerFechaActual();
        string nombreCopia = "./copiaProyecto/" + fecha + "_" + nombreArchivo;

        filesystem::create_directory("./copiaProyecto");

        ifstream archivoOriginal(nombreArchivo, ios::binary);
        ofstream archivoCopia(nombreCopia, ios::binary);

        if (archivoOriginal && archivoCopia) {
            archivoCopia << archivoOriginal.rdbuf(); 
            cout << "Copia de seguridad creada: " << nombreCopia << endl;
        } else {
            cout << "Error al crear la copia de seguridad." << endl;
        }
    };
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
            cout<<"5.Crear un respaldo"<<endl;
            cout<<"6.Regresar"<<endl;
            cout<<"7.Cerrar el programa"<<endl;
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
                crearCopiaDeSeguridad("nombreArchivoVehiculos.csv"); // Cambia el nombre del archivo según sea necesario
                continue;
            case 6:
                wh = false;
                break;
            case 7:
                continue;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                continue; 
        }
        break;

        continue;
        case 2: 
            cout<<"Que quiere hacer con el archivo:"<<endl;
            cout<<"1.Borrar datos"<<endl;
            cout<<"2.Actualizar datos"<<endl;
            cout<<"3.Insertar datos"<<endl;
            cout<<"4.Mostrar o buscar datos"<<endl;
            cout<<"5.Crear un respaldo"<<endl;
            cout<<"6.Regresar"<<endl;
            cout<<"7.Cerrar el programa"<<endl;
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
                crearCopiaDeSeguridad("nombreArchivoVehiculos.csv"); // Cambia el nombre del archivo según sea necesario
                continue;
            case 6:
                wh = false;
                break;
            case 7:
                continue; 
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
            cout<<"5.Crear un respaldo"<<endl;
            cout<<"6.Regresar"<<endl;
            cout<<"7.Cerrar el programa"<<endl;
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
                crearCopiaDeSeguridad("nombreArchivoVehiculos.csv"); // Cambia el nombre del archivo según sea necesario
                continue;
            case 6:
                wh = false;
                break;
            case 7:
                continue; 
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                continue; 
        }
        break;
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
}