#ifndef PACIENTE_HPP_INCLUDED
#define PACIENTE_HPP_INCLUDED

#include "Persona.hpp"
#include <string>

class Paciente : public Persona {
    int numPa; // Asumo que cada paciente tiene un número único
    
public:
    Paciente(std::string nombre, int edad, std::string domicilio, int numPa);
    int getNumPa() const;
    void setNumPa(int numPa);
    void virtual print() const;
};

#endif // PACIENTE_HPP_INCLUDED

