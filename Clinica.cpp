#include "Clinica.hpp"
#include <iostream>

using namespace std;

// Constructor por defecto
Clinica::Clinica() {
    // Inicializar el vector de pacientes con 100 pacientes con datos ficticios
    for (int i = 1; i <= 100; ++i) {
        pacientes.push_back(Paciente("PATIENT" + to_string(i), 20 + i, "ADDRESS" + to_string(i), i));
    }

    // Inicializar el vector de médicos con 20 médicos con datos ficticios
    for (int i = 1; i <= 20; ++i) {
        medicos.push_back(Medico("DOCTOR" + to_string(i), 30 + i, "DOCTOR ADDRESS" + to_string(i), 1000 + i));
    }
}

void Clinica::printPacientes() const {
    cout << "Lista de Pacientes:" << endl;
    for (const auto& paciente : pacientes) {
        paciente.print();
    }
}

void Clinica::printMedicos() const {
    cout << "Lista de Médicos:" << endl;
    for (const auto& medico : medicos) {
        medico.print();
    }
}

Paciente* Clinica::buscarPaciente(int numPa) {
    for (auto& paciente : pacientes) {
        if (paciente.getNumPa() == numPa) {
            return &paciente;
        }
    }
    return nullptr;
}

Medico* Clinica::buscarMedico(int numMe) {
    for (auto& medico : medicos) {
        if (medico.getNumMe() == numMe) {
            return &medico;
        }
    }
    return nullptr;
}

bool Clinica::eliminarPaciente(int numPa) {
    for (auto it = pacientes.begin(); it != pacientes.end(); ++it) {
        if (it->getNumPa() == numPa) {
            pacientes.erase(it);
            return true;
        }
    }
    return false;
}

bool Clinica::modificarPaciente(int numPa, const Paciente& nuevoPaciente) {
    for (auto& paciente : pacientes) {
        if (paciente.getNumPa() == numPa) {
            paciente = nuevoPaciente;
            return true;
        }
    }
    return false;
}

void Clinica::agregarPaciente(const Paciente& nuevoPaciente) {
    // Verificate
    for (const auto& paciente : pacientes) {
        if (paciente.getNumPa() == nuevoPaciente.getNumPa()) {
            cout << "This number already exists,please introduce another" << endl;
            return; // add
        }
    }
    pacientes.push_back(nuevoPaciente);
}

void Clinica::agregarMedico(const Medico& nuevoMedico) {
    // Verificate
    for (const auto& medico : medicos) {
        if (medico.getNumMe() == nuevoMedico.getNumMe()) {
            cout << "This number already exists,please introduce another" << endl;
            return; // no add
        }
    }
    medicos.push_back(nuevoMedico);
}



Paciente* Clinica::ultimoPaciente() {
    if (pacientes.empty()) {
        return nullptr;
    }
    return &pacientes.back();
}
