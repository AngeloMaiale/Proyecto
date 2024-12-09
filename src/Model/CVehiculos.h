#pragma once
#include <string>
using namespace std;

class Vehiculo {
private:
    string modelo, marca, placa, color, fechaEntrega, motor;
    int year, kilometraje, cedula;
    bool rentado;
    float precioRenta;

public:
    Vehiculo() : modelo(""), marca(""), placa(""), color(""), fechaEntrega(""), motor(""), year(0), kilometraje(0), cedula(0), rentado(false), precioRenta(0.0f) {}
    Vehiculo(string modelo, string marca, string placa, string color, string fechaEntrega, 
             string motor, int year, int kilometraje, int cedula, bool rentado, float precioRenta) 
        : modelo(modelo), marca(marca), placa(placa), color(color), fechaEntrega(fechaEntrega), 
          motor(motor), year(year), kilometraje(kilometraje), cedula(cedula), 
          rentado(rentado), precioRenta(precioRenta) {}

    string getModelo() const { return modelo; }
    void setModelo(const string& modelo) { this->modelo = modelo; }

    string getMarca() const { return marca; }
    void setMarca(const string& marca) { this->marca = marca; }

    string getPlaca() const { return placa; }
    void setPlaca(const string& placa) { this->placa = placa; }

    string getColor() const { return color; }
    void setColor(const string& color) { this->color = color; }

    string getFechaEntrega() const { return fechaEntrega; }
    void setFechaEntrega(const string& fechaEntrega) { this->fechaEntrega = fechaEntrega; }

    string getMotor() const { return motor; }
    void setMotor(const string& motor) { this->motor = motor; }
    
    int getYear() const { return year; }
    void setYear(int year) { this->year = year; }

    int getKilometraje() const { return kilometraje; }
    void setKilometraje(int kilometraje) { this->kilometraje = kilometraje; }

    int getCedula() const { return cedula; }
    void setCedula(int cedula) { this->cedula = cedula; }

    bool isRentado() const { return rentado; }
    void rentar() { rentado = true; }
    void devolver() { rentado = false; }

    float getPrecioRenta() const { return precioRenta; }
    void setPrecioRenta(float precioRenta) { this->precioRenta = precioRenta; }
};

