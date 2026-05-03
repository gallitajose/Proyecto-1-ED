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

class Servicios
{

private:

	string descripcion;
	int prioridad;
	Area* area;


public:

	Servicios(string descripcion, int prioridad, Area* area)
	{
		this->descripcion = descripcion;
		this->prioridad = prioridad;
		this->area = area;
	}

	~Servicios()
	{
	}


	Servicios(const Servicios& Servicioscopia)
	{
		descripcion = Servicioscopia.descripcion;
		prioridad = Servicioscopia.prioridad;
		area = Servicioscopia.area;
	}


	Servicios& operator=(const Servicios& Servicioscopia)
	{
		if (this != &Servicioscopia)
		{
			descripcion = Servicioscopia.descripcion;
			prioridad = Servicioscopia.prioridad;
			area = Servicioscopia.area;
		}


		return *this;
	}



	string getDescripcion() const
	{
		return descripcion;
	}


	int getPrioridad() const
	{
		return prioridad;
	}

	Area* getArea() const
	{
		return area;
	}




	friend ostream& operator <<(ostream& os, const Servicios& servi)
	{

		os << "(Informacion del servicio: " << servi.descripcion << "Prioridad del servicio:" << servi.prioridad << "Area del servicio: " << servi.area->getCodigo();
		return os;

	}







};

