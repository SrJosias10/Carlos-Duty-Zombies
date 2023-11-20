#include <iostream>

using namespace std;

#include "Guardado.h"

// Getters
int Guardado::getSalud() const
{
    return _salud;
}

int Guardado::getBalasEnCargador() const
{
    return _balasEnCargador;
}

int Guardado::getBalasTotales() const
{
    return _balasTotales;
}

int Guardado::getPuntaje() const
{
    return _puntaje;
}

// Setters
void Guardado::setSalud(int salud)
{
    _salud = salud;
}

void Guardado::setBalasEnCargador(int balasEnCargador)
{
    _balasEnCargador = balasEnCargador;
}

void Guardado::setBalasTotales(int balasTotales)
{
    _balasTotales = balasTotales;
}


void Guardado::setPuntaje(int puntaje)
{
    _puntaje = puntaje;
}


void Guardado::setSeleccion(int s)
{
    _seleccion = s;
}
int Guardado::getSeleccion()
{
    return _seleccion;
}

void Guardado::setRonda(int r)
{
    _ronda = r;

}

int Guardado::getRonda()
{
    return _ronda;
}

void Guardado::setTiempo(int t)
{
    _tiempo = t;
}
int Guardado::getTiempo()
{
    return _tiempo;
}









