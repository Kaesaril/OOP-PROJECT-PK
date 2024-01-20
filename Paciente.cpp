#include "Paciente.hpp"
#include <iostream>

Paciente::Paciente(std::string nombre, int edad, std::string domicilio, int numPa)
    : Persona(nombre, edad, domicilio), numPa(numPa) {}

int Paciente::getNumPa() const {
    return numPa;
}

void Paciente::setNumPa(int numPa) {
    this->numPa = numPa;
}

void Paciente::print() const {
    std::cout << "PATIENT: " << getNombre() << ", AGE: " << getEdad() << ", NUMBER: " << numPa << std::endl;
}
