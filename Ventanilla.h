#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class Ventanilla{
private:
	string nombre;
	string codigoTiqueteActual;
	int atendidos;

public:
	Ventanilla(string nombre) {
		this->nombre = nombre;
		this->codigoTiqueteActual = "";
		this->atendidos = 0;
	}
	Ventanilla(const Ventanilla& ventanillaCopia) {
		nombre = ventanillaCopia.nombre;
		codigoTiqueteActual = ventanillaCopia.codigoTiqueteActual;
		atendidos = ventanillaCopia.atendidos;
	}
	~Ventanilla() {

	}
	Ventanilla& operator=(const Ventanilla& ventanillaCopia) {
		if (this != &ventanillaCopia){
			nombre = ventanillaCopia.nombre;
			codigoTiqueteActual = ventanillaCopia.codigoTiqueteActual;
			atendidos = ventanillaCopia.atendidos;
		}
		return *this;
	}
	string getNombre() const{
		return nombre;
	}
	string getCodigoTiqueteActual() const {
		return codigoTiqueteActual;
	}
	int getTiquetesAtendidos() const{
		return atendidos;
	}
	void setTiqueteActual(string codigoTiqueteActual) {
		this->codigoTiqueteActual = codigoTiqueteActual;
	}
	void liberarVentanilla() {
		codigoTiqueteActual = "";
	}
	void registrarAtencion() {
		atendidos++;
	}
	friend ostream& operator<<(ostream& os, const Ventanilla& v) {
		os << "(Tquete actual: " << v.codigoTiqueteActual << ", nombre: " << v.nombre << ", atendidos: " << v.atendidos << ")";
		return os;
	}

};
