#ifndef MENU_H
#define MENU_H

#include "Juego.h"
#include "MenuPausa.h"

class Menu
{
public:

    bool desplegar(ArchivoGuardado*);
    int elegirPersonaje(ArchivoGuardado*);
    void acercaDe(sf::RenderWindow& window);
    void  cargarPartida();

private:
     Juego* _juego; // puntero a juego


    sf::SoundBuffer bufferseleccionKloster;
    sf::Sound sellecionsoundKloster;
    sf::SoundBuffer bufferseleccionRicky;
    sf::Sound sellecionsoundKRicky;

    sf::SoundBuffer bufferMenu;
    sf::Sound menusound;





};

#endif // MENU_H
