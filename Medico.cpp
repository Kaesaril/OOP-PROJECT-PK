#include "Medico.hpp"
#include <iostream>

Medico::Medico(std::string nombre, int edad, std::string domicilio, int numMe)
    : Persona(nombre, edad, domicilio), numMe(numMe) {}

int Medico::getNumMe() const {
    return numMe;
}

void Medico::setNumMe(int numMe) {
    this->numMe = numMe;
}

void Medico::print() const {
    std::cout << "DOCTOR: " << getNombre() << ", AGE: " << getEdad() << ", MedicianNumber: " << numMe << std::endl;
}

