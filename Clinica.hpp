#ifndef CLINICA_HPP_INCLUDED
#define CLINICA_HPP_INCLUDED

#include <vector>
#include "Paciente.hpp"
#include "Medico.hpp"

using namespace std;

class Clinica {
private:
    vector<Paciente> pacientes;  // Vector de 100 pacientes
    vector<Medico> medicos;     // Vector de 20 médicos

public:
    Clinica(); // Constructor

    // Método para imprimir información de todos los pacientes
    void printPacientes() const;

    // Método para imprimir información de todos los médicos
    void printMedicos() const;

    // Método para buscar un paciente por número
    Paciente* buscarPaciente(int numPa);

    // Método para buscar un médico por número
    Medico* buscarMedico(int numMe);

    // Método para eliminar un paciente por número
    bool eliminarPaciente(int numPa);

    // Método para modificar un paciente por número
    bool modificarPaciente(int numPa, const Paciente& nuevoPaciente);

    // Método para agregar un nuevo paciente al final del vector
    void agregarPaciente(const Paciente& nuevoPaciente);

    // Método para agregar un nuevo médico al final del vector
    void agregarMedico(const Medico& nuevoMedico);

    // Método para encontrar el último paciente en el vector de pacientes
    Paciente* ultimoPaciente();
};

#endif // CLINICA_HPP_INCLUDED
