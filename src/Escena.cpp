#include <iostream>

using namespace std;

#include "Escena.h"


Escena::Escena(){

    _fondo.loadFromFile("images/mapa.png");
    _fondoSprite.setTexture(_fondo);
}


/*
//Fuente
    sf::Font font;
    font.loadFromFile("fonts/letraCOD.ttf");
    sf::Text text, textVida;

    text.setFont(font);
    textVida.setFont(font);


    sf::SoundBuffer buffer;
    buffer.loadFromFile("municion.wav");


    sf::Sound municionsound;
    municionsound.setBuffer(buffer);

    //Chaleco
    sf::SoundBuffer bufferChaleco;
    bufferChaleco.loadFromFile("chaleco.wav");

    sf::Sound chalecosound;
    chalecosound.setBuffer(bufferChaleco);


    Puntos Municion;
    Municion.respawn();

    Chaleco chaleco;
    chaleco.respawn();



     if(soldado.isCollision(Municion))
        {
            //Cuando se colisiona, la municion vuelve a reaparecer en un lugar random
            Municion.respawn();
            municion++;
            //Se reproduce un sonido (municion)
            municionsound.play();
        }

        //Collisiona con el chaleco

        if(timerchaleco == 0 && soldado.isCollision(chaleco))
        {
            //Ponemos en cuanto tiempo queremos que reaparezca el chaleco
            timerchaleco = 80*10;
            //Cuando se colisiona el chaleco reaparece en un tiempo determinado
            chaleco.respawn();
            //Se reproduce un sonido (chaleco)
            chalecosound.play();
            vidas++;
        }


         //Transforma el entero en letra
        textVida.setPosition({0, 50});
        text.setString("Municion " + std::to_string(municion));
        textVida.setString("Escudo " + std::to_string(vidas));


*/




void Escena::dibujarEscena(sf::RenderWindow &window, ObjetoPersonaje &soldado,std::vector<ObjetoEnemigo*>& vZombies, Drop &municion)
{


    /// dibuja el background , re duro
    window.draw(_fondoSprite);


    /// dibuja a todos los z en el vector
    for(ObjetoEnemigo* zombie : vZombies)
    {
        window.draw(*zombie);
    }


    /// dibuja al soldado
    window.draw(soldado);
    ///dibuja la municion
    if(municion.getDibujar()){
    window.draw(municion);
    }


    /// dibuja las balas
    for (Bala* balaPtr : soldado.getBullet())
    {
        window.draw(*balaPtr);
    }


}




