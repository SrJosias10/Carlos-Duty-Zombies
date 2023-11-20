#ifndef JUEGO_H
#define JUEGO_H
#include <vector>

#include "ObjetoPersonaje.h"
#include "ObjetoEnemigo.h"
#include "Escena.h"
#include "MenuPausa.h"
#include "Ronda.h"
#include "Bala.h"
#include "Drop.h"





class Juego
{
public:
    Juego();
    int run(ObjetoPersonaje* soldado);
    void setPausa (bool);
    void mostrarIntro(sf::RenderWindow &window);
    void mostrarPuntos(sf::RenderWindow& window, ObjetoPersonaje& soldado,int seleccion,Ronda&);
    void mostrarPantallaGameOver(sf::RenderWindow &window);
    void mostrarPantallaGano(sf::RenderWindow &window);


private:

    Escena _escena;
    Ronda _ronda;

    sf::SoundBuffer bufferjuego;
    sf::Sound juegosound;

    bool _enPausa;
    int getFPS();
    int _fps;
    std::string rutasZombie[4];
    std::vector<ObjetoEnemigo*> vZombies;


};

#endif // JUEGO_H
