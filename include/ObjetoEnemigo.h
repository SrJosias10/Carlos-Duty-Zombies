#pragma once

#include <SFML/Graphics.hpp>
#include "Collisionable.h"
#include <SFML/Audio.hpp>
#include "ObjetoPersonaje.h"


class ObjetoEnemigo: public sf::Drawable , public Collisionable
{

   private:

    ObjetoPersonaje* _jugador;

    sf::Sprite _sprite;
    sf::Texture _texture;
    int _timeSonidoZombie;
    //sonido soldado herido
    sf::SoundBuffer bufferMuerte;
    sf::Sound muertesound;
    //sonido zombie
    sf::SoundBuffer bufferZombie;
    sf::Sound zombiesound;
    //sonido2 zombie
    sf::SoundBuffer bufferZombie2;
    sf::Sound zombiesound2;
    int indiceAleatorio;
    sf::Vector2f LugarNacimiento[2];
    float _frame;
    float _frameAtaque;
    int timerM=20*10;
    int vida;
    float ultima;
    float velocidad;
    bool atacar;



public:
    ObjetoEnemigo(ObjetoPersonaje* jugador, std::string &);
    ObjetoEnemigo();

    void update(std::vector<ObjetoEnemigo*>&);

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void respawn(std::vector<ObjetoEnemigo*>&);

    void golpear();

    sf::FloatRect getBounds() const override;

    sf::Vector2f getPosition() const;

    float getRadius() const;

    // Agregar este método a la clase ObjetoEnemigo en "ObjetoEnemigo.h"
    void move(const sf::Vector2f& offset);

    void morir(){

    }
    bool murio() const;
    void recibioBala();
    void colisionConBala(std::vector<Bala*>&, std::vector<ObjetoEnemigo*>& vZombies);
    int getVida();
    void setVelocidad(float vel);
    void setVida(int v);
    void setAtacar(int a){atacar = a;}


};


