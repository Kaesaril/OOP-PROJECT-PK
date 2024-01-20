#include "Persona.hpp"
#include <iostream>
#include <string>

Persona::Persona(string nombre,int edad,string domicilio):nombre(nombre),edad(edad),domicilio(domicilio){}

void Persona::setNombre(string nombre){
 this->nombre=nombre;
}

void Persona::setEdad(int edad){
	this->edad=edad;
}

void Persona::setDomicilio( string domicilio){
	this->domicilio=domicilio;
}

string Persona::getNombre() const{
	return this->nombre;
}

int Persona::getEdad() const{
	return this->edad;
}

string Persona::getDomicilio() const {
    return this->domicilio;
}

void Persona::print() const{
	cout<<"irror"<<endl;
}



