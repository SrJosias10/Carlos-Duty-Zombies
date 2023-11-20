#ifndef ESCENA_H
#define ESCENA_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "ObjetoPersonaje.h"
#include "ObjetoEnemigo.h"
#include "Drop.h"


class Escena
{
    public:

    Escena();

   void dibujarEscena(sf::RenderWindow&, ObjetoPersonaje &soldado,std::vector<ObjetoEnemigo*>&, Drop &municion);



    private:

        sf::Texture _fondo;
        sf::Texture _soldado;
        sf::Sprite _fondoSprite;





};

#endif // ESCENA_H
