#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <filesystem>
#include "../Model/CClientes.h"
#include "../Model/CUsuario.h"
#include "../Model/CVehiculos.h"
#include "../Model/CRepuestos.h"
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
    };
    
    string nombreArchivoUsuario = "./bin/Usuarios.csv"; // Corregido aquí
    string nombreArchivoVehiculos = "./bin/Vehiculos.csv";
    string nombreArchivoClientes = "./bin/Clientes.csv";
    string nombreArchivoRepuestos = "./bin/Repuestos.csv";
    bool wh = true;
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
        std::cout << "Que archivo desea gestionar: " << endl;
        std::cout << "1. Vehiculos" << endl;
        std::cout << "2. Clientes" << endl;
        std::cout << "3. Repuestos" << endl;
        std::cout << "4. Cerrar el programa" <<endl;
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
            std::cout<<"Que quiere hacer con el archivo:"<<endl;
            std::cout<<"1.Borrar datos"<<endl;
            std::cout<<"2.Actualizar datos"<<endl;
            std::cout<<"3.Insertar datos"<<endl;
            std::cout<<"4.Mostrar o buscar datos"<<endl;
            std::cout<<"5.Crear copia de seguridad"<<endl;
            std::cout<<"6.Regresar"<<endl;
            std::cout<<"7.Cerrar el programa"<<endl;
            cin>>opcion1;
            switch (opcion1){
                case 1:
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Elegir fila a borrar"<<endl;
                    std::cout<<"2.Regresar"<<endl;
                    std::cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion11;
                    switch(opcion11){
                        case 1:
                            std::cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            std::cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                borrarLinea(nombreArchivoVehiculos,Nlinea);
                                continue;
                            }
                            else{
                                std::cout<<"Operacion cancelada"<<endl;
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
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Actualizar una columna de la fila"<<endl;
                    std::cout<<"2.Actualizar toda una fila"<<endl;
                    std::cout<<"3.Regresar"<<endl;
                    std::cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion12;
                    switch(opcion12){
                        case 1:
                            std::cout << "Ingrese la fila del vehiculo que quiere modificar: "; cin >> Nlinea;
                            std::cout << "Ingrese el numero de la columna que desea modificar (1-11): "<<endl;
                            std::cout << "1. Modelo"<<endl;
                            std::cout << "2. Marca"<<endl;
                            std::cout << "3. Placa"<<endl;
                            std::cout << "4. Color"<<endl;
                            std::cout << "5. Year"<<endl;
                            std::cout << "6. Kilometraje"<<endl;
                            std::cout << "7. Rentado (TRUE para si, FALSE para no)"<<endl;
                            std::cout << "8. Motor"<<endl;
                            std::cout << "9. Precio de Renta"<<endl;
                            std::cout << "10. Cedula del Cliente"<<endl;
                            std::cout << "11. Fecha de Entrega"<<endl;
                            std::cout << "Ingrese la opcion: "; cin >> ind;
                            std::cout << "Ingrese el dato actualizado: "; cin >> ValorN;
                            std::cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                actualizarColumnaVehiculos(Nlinea, ind, ValorN);
                                continue;
                            }
                            else{
                                std::cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 2:
                            std::cout<<"Ingrese el numero de fila que quiere modificar: ";
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
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Insertar una fila"<<endl;
                    std::cout<<"2.Regresar"<<endl;
                    std::cout<<"3.Cerrar el programa"<<endl;
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
                std::cout << "Ingrese la placa del vehiculo a consultar: "; 
                cin >> placaBuscada; 
                mostrarVehiculo(vehiculos, numVehiculos, placaBuscada);
                continue;
            case 5:
                crearCopiaDeSeguridad(nombreArchivoVehiculos);
                continue; 
            case 6:
                wh = false; 
                break;
            case 7:
                exit(0);
            default:
                std::cout << "Opción no válida. Intente de nuevo." << endl;
                continue; 
        }
        continue;
        case 2: 
            std::cout<<"Que quiere hacer con el archivo:"<<endl;
            std::cout<<"1.Borrar datos"<<endl;
            std::cout<<"2.Actualizar datos"<<endl;
            std::cout<<"3.Insertar datos"<<endl;
            std::cout<<"4.Mostrar o buscar datos"<<endl;
            std::cout<<"5.Crear copia de seguridad"<<endl;
            std::cout<<"6.Regresar"<<endl;
            std::cout<<"7.Cerrar el programa"<<endl;
            cin>>opcion2;
            switch (opcion2){
                case 1:
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Elegir fila a borrar"<<endl;
                    std::cout<<"2.Regresar"<<endl;
                    std::cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion21;
                    switch(opcion21){
                        case 1:
                            std::cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            std::cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                borrarLinea(nombreArchivoClientes,Nlinea);
                                continue;
                            }
                            else{
                                std::cout<<"Operacion cancelada"<<endl;
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
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Actualizar una columna de la fila"<<endl;
                    std::cout<<"2.Actualizar toda una fila"<<endl;
                    std::cout<<"3.Regresar"<<endl;
                    std::cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion22;
                    switch(opcion22){
                        case 1:
                            std::cout << "Ingrese la fila del cliente que quiere modificar: "; cin >> Nlinea;
                            std::cout << "Ingrese el numero de la columna que desea modificar (1-7): "<<endl;
                            std::cout << "1. Nombre"<<endl;
                            std::cout << "2. Apellido"<<endl;
                            std::cout << "3. Direccion"<<endl;
                            std::cout << "4. Email"<<endl;
                            std::cout << "5. Activo (TRUE para si, FALSE para no)"<<endl;
                            std::cout << "6. Numero de vehiculos rentados"<<endl;
                            std::cout << "7. Cedula"<<endl;
                            std::cout << "Ingrese la opcion: "; cin >> ind;
                            std::cout << "Ingrese el dato actualizado: "; cin >> ValorN;
                            std::cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                actualizarColumnaClientes(Nlinea, ind, ValorN);
                                continue;
                            }
                            else{
                                std::cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            break;
                        case 2:
                            std::cout<<"Ingrese el numero de fila que quiere modificar: ";
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
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Insertar una fila"<<endl;
                    std::cout<<"2.Regresar"<<endl;
                    std::cout<<"3.Cerrar el programa"<<endl;
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
                std::cout << "Ingrese la cedula del cliente a consultar: "; 
                cin >> cedulaBuscada; 
                mostrarCliente(clientes, numClientes, cedulaBuscada);
                continue;
            case 5:
                crearCopiaDeSeguridad(nombreArchivoClientes);
                continue; 
            case 6:
                wh = false; 
                break;
            case 7:
                exit(0);
            default:
                std::cout << "Opción no válida. Intente de nuevo." << endl;
                continue; 
        }
        continue;
        case 3: 
            std::cout<<"Que quiere hacer con el archivo:"<<endl;
            std::cout<<"1.Borrar datos"<<endl;
            std::cout<<"2.Actualizar datos"<<endl;
            std::cout<<"3.Insertar datos"<<endl;
            std::cout<<"4.Mostrar o buscar datos"<<endl;
            std::cout<<"5.Crear copia de seguridad"<<endl;
            std::cout<<"6.Regresar"<<endl;
            std::cout<<"7.Cerrar el programa"<<endl;
            cin>>opcion3;
            switch (opcion3){
                case 1:
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Elegir fila a borrar"<<endl;
                    std::cout<<"2.Regresar"<<endl;
                    std::cout<<"3.Cerrar el programa"<<endl;
                    cin>>opcion31;
                    switch(opcion31){
                        case 1:
                            std::cout<<"Que linea desea borrar: ";
                            cin>>Nlinea;
                            std::cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                borrarLinea(nombreArchivoRepuestos,Nlinea);
                                continue;
                            }
                            else{
                                std::cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 3:
                            wh=false;
                            break;}
                break;
                case 2:
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Actualizar una columna de la fila"<<endl;
                    std::cout<<"2.Actualizar toda una fila"<<endl;
                    std::cout<<"3.Regresar"<<endl;
                    std::cout<<"4.Cerrar el programa"<<endl;
                    cin>>opcion32;
                    switch(opcion32){
                        case 1:
                            std::cout << "Ingrese la fila del repuestos que quiere modificar: "; cin >> Nlinea;
                            std::cout << "Ingrese el numero de la columna que desea modificar (1-7): "<<endl;
                            std::cout << "1. Modelo del repuesto"<<endl;
                            std::cout << "2. Marca"<<endl;
                            std::cout << "3. Nombre"<<endl;
                            std::cout << "4. Modelo del carro"<<endl;
                            std::cout << "5. Year Carro"<<endl;
                            std::cout << "6. Existencias"<<endl;
                            std::cout << "7. Precio"<<endl;
                            std::cout << "Ingrese la opcion: "; cin >> ind;
                            std::cout << "Ingrese el dato actualizado: "; cin >> ValorN;
                            std::cout<<"Esta seguro de los cambios que va a realizar? Se va a reemplzar el archivo con uno nuevo con los cambios realizados (1 para si, 0 para no): ";
                            cin>>SoN;
                            if(SoN==true){
                                actualizarColumnaRepuestos(Nlinea, ind, ValorN);
                                continue;
                            }
                            else{
                                std::cout<<"Operacion cancelada"<<endl;
                                continue;
                            }
                            continue;
                        case 2:
                            std::cout<<"Ingrese el numero de fila que quiere modificar: ";
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
                    std::cout<<"Como desea proceder:"<<endl;
                    std::cout<<"1.Insertar una fila"<<endl;
                    std::cout<<"2.Regresar"<<endl;
                    std::cout<<"3.Cerrar el programa"<<endl;
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
                std::cout << "Ingrese el modelo del repuesto a consultar: "; 
                cin >> modeloBuscado; 
                mostrarRepuesto(repuestos, numRepuestos, modeloBuscado);
                continue;
            case 5:
                crearCopiaDeSeguridad(nombreArchivoRepuestos);
                continue; 
            case 6:
                wh = false; 
                break;
            case 7:
                exit(0);
            default:
                std::cout << "Opción no válida. Intente de nuevo." << endl;
                continue; 
        }
        continue;   
        case 4:
            wh=false;
            break;  
        default: 
            std::cout << "Opcion no valida. Intente de nuevo." << endl;
            continue; 
        }
    delete[] vehiculos;
    delete[] clientes;
    delete[] repuestos;
    } while(wh==true);
}