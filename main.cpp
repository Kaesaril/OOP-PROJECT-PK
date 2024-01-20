#include <iostream>
#include <limits>
#include "Clinica.hpp"

using namespace std;

int obtenerEntero() {
    int valor;
    while (!(cin >> valor)) {
        cout << "Error. Please, introduce a valid number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return valor;
}

string obtenerCadenaNoVacia(const string& mensaje) {
    string valor;
    do {
        cout << mensaje;
        getline(cin, valor);
    } while (valor.empty());
    return valor;
}

int main() {
    Clinica miClinica;

    int opcion;
    do {
        try {
            cout << "----- MENU -----" << endl;
            cout << "0: List all doctors" << endl;
            cout << "1: List all patients" << endl;
            cout << "2: Search for a doctor by docNum" << endl;
            cout << "3: Search for a patient by patNum" << endl;
            cout << "4: Delete a patient by patNum" << endl;
            cout << "5: Modify a patient by patNum" << endl;
            cout << "6: Add a doctor" << endl;
            cout << "7: Add a patient" << endl;
            cout << "8: Exit" << endl;
            cout << "Enter an option: ";
            opcion = obtenerEntero();

            switch (opcion) {
                case 0:
                    miClinica.printMedicos();
                    break;

                case 1:
                    miClinica.printPacientes();
                    break;

                case 2: {
                    int numMe;
                    cout << "Introduce number of doctor: ";
                    numMe = obtenerEntero();
                    Medico* medicoEncontrado = miClinica.buscarMedico(numMe);
                    if (medicoEncontrado) {
                        medicoEncontrado->print();
                    } else {
                        cout << "Doctor not found." << endl;
                    }
                    break;
                }

                case 3: {
                    int numPa;
                    cout << "Introduce number of patient: ";
                    numPa = obtenerEntero();
                    Paciente* pacienteEncontrado = miClinica.buscarPaciente(numPa);
                    if (pacienteEncontrado) {
                        pacienteEncontrado->print();
                    } else {
                        cout <<"Patient not found."  << endl;
                    }
                    break;
                }

                case 4: {
                    int numPaEliminar;
                    cout << "Introduce number of patient to delete: ";
                    numPaEliminar = obtenerEntero();
                    if (miClinica.eliminarPaciente(numPaEliminar)) {
                        cout << "Patient deleted it" << endl;
                    } else {
                        cout << "Not found" << endl;
                    }
                    break;
                }

                case 5: {
                    int numPaModificar;
                    cout << "Introduce number of patient to search: ";
                    numPaModificar = obtenerEntero();
                    Paciente* pacienteAModificar = miClinica.buscarPaciente(numPaModificar);
                    if (pacienteAModificar) {
			cout<<"Name" <<endl;
                        string nombreNuevo = obtenerCadenaNoVacia("");
                        cout<<"Introduce age "<<endl;
                        int edadNueva = obtenerEntero();
			cout<<"Address"<<endl;
                        string domicilioNuevo = obtenerCadenaNoVacia("");
                        Paciente nuevoPaciente(nombreNuevo, edadNueva, domicilioNuevo, numPaModificar);
                        if (miClinica.modificarPaciente(numPaModificar, nuevoPaciente)) {
                            cout << "Did it" << endl;
                        } else {
                            cout << "Error" << endl;
                        }
                    } else {
                        cout << "Not found" << endl;
                    }
                    break;
                }

                case 6: {
			cout<<"Introduce name "<<endl;
                    string nombreMedico = obtenerCadenaNoVacia("");
                    cout<<"Introduce age"<<endl;
                    int edadMedico = obtenerEntero();
			cout<<"Introduce adrres"<<endl;
                    string domicilioMedico = obtenerCadenaNoVacia("");
                    cout<<"Introduce number of medician"<<endl;
                    int numMe = obtenerEntero();
                    Medico nuevoMedico(nombreMedico, edadMedico, domicilioMedico, numMe);
                    miClinica.agregarMedico(nuevoMedico);
                    cout << "Operation did it." << endl;
                    break;
                }

                case 7: {
                    int numPa;
                    cout << "Number of patient ";
                    numPa = obtenerEntero();
			cout<<"Introduce name "<<endl;
                    string nombrePaciente = obtenerCadenaNoVacia("");
			 cout<<"Introduce age"<<endl;
                    int edadPaciente = obtenerEntero();
			cout<<" Adrress" <<endl;
                    string domicilioPaciente = obtenerCadenaNoVacia("");
                    
                    Paciente nuevoPaciente(nombrePaciente, edadPaciente, domicilioPaciente, numPa);
                    miClinica.agregarPaciente(nuevoPaciente);
                    cout << "Did it" << endl;
                    break;
                }

                case 8:
                    cout << "Exiting the program ..." << endl;
                    break;

                default:
                    throw runtime_error("Invalid option. Please enter a valid option.");
            }
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = -1; // Reiniciar el bucle para que el usuario vuelva a ingresar una opción válida.
        }
    } while (opcion != 8);

    return 0;
}
