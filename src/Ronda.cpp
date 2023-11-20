#include <iostream>

using namespace std;

#include "Ronda.h"

Ronda::Ronda() : timervidaExacto(4*10),timervida(timervidaExacto),tRonda(180*10)
{


    _tiempo=1;
    _ronda=1;
    _aparicion=60*10;
    velocidad = 1;
    aumentavida=100;
    timerZombie = 60*10;

}


int Ronda::getTiempo() const
{
    return _tiempo;
}

int Ronda::getRonda() const
{
    return _ronda;
}

int Ronda::getAparicion() const
{
    return _aparicion;
}

float Ronda::getVelocidad() const
{
    return velocidad;
}

int Ronda::getAumentavida() const
{
    return aumentavida;
}

int Ronda::getTimerZombie() const
{
    return timerZombie;
}

int Ronda::getTimervida() const
{
    return timervida;
}

void Ronda::setTiempo(int tiempo)
{
    _tiempo = tiempo;
}

void Ronda::setRonda(int ronda)
{
    _ronda = ronda;
}

void Ronda::setAparicion(int aparicion)
{
    _aparicion = aparicion;
}

void Ronda::setVelocidad(float vel)
{
    velocidad = vel;
}

void Ronda::setAumentavida(int vida)
{
    aumentavida = vida;
}

void Ronda::setTimerZombie(int timer)
{
    timerZombie = timer;
}

void Ronda::setTimervida(int timer)
{
    timervida = timer;
}

int Ronda::getTRonda() const
{
    return tRonda;
}

int Ronda::getTimervidaExacto() const
{
    return timervidaExacto;
}

void Ronda::restarTimerZombie()
{
    timerZombie--;
}
void Ronda::restarTimerVida()
{
    timervida--;
}

void Ronda::sumarTiempo(){
    _tiempo++;
}


void Ronda::logicaRonda()
{

    if(_tiempo>tRonda && vecRonda[1])
    {
        _ronda = 2;
        vecRonda[1]=false;
    }
    if(_tiempo>tRonda*2 && vecRonda[2])
    {
        _ronda = 3;
        vecRonda[2] = false;
        velocidad=3;
        aumentavida = 125;
    }
    if(_tiempo>tRonda*3 && vecRonda[3])
    {
        _ronda = 4;
        vecRonda[3] = false;
        _aparicion = 40*10;

    }
    if(_tiempo>tRonda*4 && vecRonda[4])
    {
        _ronda = 5;
        vecRonda[4] = false;
    }
    if(_tiempo>tRonda*5 && vecRonda[5])
    {
        _ronda = 6;
        vecRonda[5] = false;
        velocidad = 4;
        aumentavida = 150;

    }
    if(_tiempo>tRonda*6 && vecRonda[6])
    {
        _ronda = 7;
        vecRonda[6] = false;
        _aparicion = 20*10;
    }
    if(_tiempo>tRonda*7 && vecRonda[7])
    {
        _ronda = 8;
        vecRonda[7] = false;
    }
    if(_tiempo>tRonda*8 && vecRonda[8])
    {
        _ronda = 9;
        vecRonda[8] = false;
        aumentavida = 175;
    }
    if(_tiempo>tRonda*9 && vecRonda[9])
    {
        _ronda = 10;
        vecRonda[9] = false;
        velocidad = 5;
    }
}

