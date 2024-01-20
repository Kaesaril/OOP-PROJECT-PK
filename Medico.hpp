#ifndef MEDICO_HPP_INCLUDED
#define MEDICO_HPP_INCLUDED

#include "Persona.hpp"
#include <string>

class Medico : public Persona {
    int numMe; // Asumo que cada médico tiene un número único
    
public:
    Medico(std::string nombre, int edad, std::string domicilio, int numMe);
    int getNumMe() const;
    void setNumMe(int numMe);
    void print() const;
};

#endif // MEDICO_HPP_INCLUDED

