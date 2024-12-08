#pragma once
#include <string>
using namespace std;

class Repuesto {
private:
    string modelo, marca, nombre, partModel;
    int yearCarro, existencias;
    float precio;

public:
    Repuesto() : modelo(""), marca(""), nombre(""), partModel(""), yearCarro(0), existencias(0), precio(0.0f) {}
    Repuesto(string modelo, string marca, string nombre, string partModel, 
             int yearCarro, int existencias, float precio) 
        : modelo(modelo), marca(marca), nombre(nombre), partModel(partModel), 
          yearCarro(yearCarro), existencias(existencias), precio(precio) {}

    string getModelo() const { return modelo; }
    void setModelo(const string& modelo) { this->modelo = modelo; }

    string getMarca() const { return marca; }
    void setMarca(const string& marca) { this->marca = marca; }

    string getNombre() const { return nombre; }
    void setNombre(const string& nombre) { this->nombre = nombre; }

    string getPartModel() const { return partModel; }
    void setPartModel(const string& partModel) { this->partModel = partModel; }

    int getYearCarro() const { return yearCarro; }
    void setYearCarro(int yearCarro) { this->yearCarro = yearCarro; }

    int getExistencias() const { return existencias; }
    void setExistencias(int existencias) { this->existencias = existencias; }

    float getPrecio() const { return precio; }
    void setPrecio(float precio) { this->precio = precio; }

    void agregarExistencias(int cantidad) { existencias += cantidad; }
    void venderRepuesto(int cantidad) { if (existencias >= cantidad) existencias -= cantidad; }
};