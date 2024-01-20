#ifndef PERSONA_HPP_INCLUDED
#define PERSONA_HPP_INCLUDED

#include <iostream>
#include <string>

using namespace std;

class Persona{

protected:
	string nombre;//name
	int edad;//age
	string domicilio;//address

public:
	Persona(string nombre,int edad,string domicilio);

	void setNombre(string name);
	void setEdad(int edad);
	void setDomicilio(string domicilio);

	string getNombre()const;
	int getEdad()const;
	string getDomicilio()const;

	void virtual print() const;

};

#endif
