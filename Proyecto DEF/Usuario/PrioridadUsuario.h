#pragma once
#include<string>
#include <time.h>
#include<iostream>
#include <iomanip>
#include <ctime>
#include <chrono>



using std::ctime;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::ostream;

class PrioridadUsuario
{


private:

	string Datos;
	int Prioridad;


public: 

	PrioridadUsuario(string Datos, int Prioridad)
	{

		this->Datos = Datos;
		this->Prioridad = Prioridad;

	}

	~PrioridadUsuario()
	{
	}

	//Estas 2 estructuras sirven para hacer copias y asignaciones del usuario en el que se va a trabajar 
	//Esto es para la generacion de los distintos usuarios con los que se trabajara
	PrioridadUsuario(const PrioridadUsuario& Prioridadcopia) 
	{
		Datos = Prioridadcopia.Datos;
		Prioridad = Prioridadcopia.Prioridad;
	}

	//Esta estructura es para evitar que se reasignen datos a la informacion del usuario al que se le hizo una copia
	PrioridadUsuario& operator=(const PrioridadUsuario& Prioridadcopia)
	{
		if (this != &Prioridadcopia)
		{
			Datos = Prioridadcopia.Datos;
			Prioridad = Prioridadcopia.Prioridad;
		}


		return *this;
	}
	//*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-**-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-

	string getDatos() 
	{
		return Datos;
	}


	int getPrioridad()
	{
		return Prioridad;
	}


	bool operator<(const PrioridadUsuario& prioridad) const 
	{
		return Prioridad < prioridad.Prioridad;
	}


	friend ostream& operator <<(ostream& os, const PrioridadUsuario& prioridadusuario)
	{

		os << "(Tipo de usuario: " << prioridadusuario.Datos << "Prioridad del usuario:" << prioridadusuario.Prioridad;
		return os;

	}
};

