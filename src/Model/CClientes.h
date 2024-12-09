#pragma once
#include <string>
using namespace std;

class Cliente {
private:
    string nombre, apellido, email, direccion;
    int cedula, nVehiculosRentados;
    bool rentado;

public:
    Cliente() : nombre(""), apellido(""), email(""), direccion(""), cedula(0), nVehiculosRentados(0), rentado(false) {}
    Cliente(string nombre, string apellido, string email, string direccion, bool rentado, int cedula, int nVehiculosRentados)
        : nombre(nombre), apellido(apellido), email(email), direccion(direccion), rentado(rentado), cedula(cedula), nVehiculosRentados(nVehiculosRentados) {}

    int getCedula() const { return cedula; }
    void setCedula(int cedula) { this->cedula = cedula; }

    string getNombre() const { return nombre; }
    void setNombre(const string& nombre) { this->nombre = nombre; }

    string getApellido() const { return apellido; }
    void setApellido(const string& apellido) { this->apellido = apellido; }

    string getEmail() const { return email; }
    void setEmail(const string& email) { this->email = email; }

    string getDireccion() const { return direccion; }
    void setDireccion(const string& direccion) { this->direccion = direccion; }

    int getnVehiculosRentados() const { return nVehiculosRentados; }
    void setVehiculosRentados(int nVehiculosRentados) { this->nVehiculosRentados = nVehiculosRentados; }

    bool isRentado() const { return rentado; }
    void rentar() { rentado = true; }
    void devolver() { rentado = false; }
};

