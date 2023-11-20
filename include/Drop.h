#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Collisionable.h"


class Drop: public sf::Drawable , public Collisionable
{
    sf::Sprite _sprite;
    sf::Texture _texture;
    sf::Vector2f _velocidad;
    /// agarra chaleco
    sf::SoundBuffer bufferDrop;
    sf::Sound Dropsound;
    ///sonido cajita
    sf::SoundBuffer bufferMistery;
    sf::Sound DropMisterysound;

    int indiceAleatorio;
    sf::Vector2f aparicionChaleco[4];
    bool apareceunavez;
    bool dibujar;
    int timer;

public:
    Drop();
    void update();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void respawn(int);
    sf::FloatRect getBounds() const override;
    void Reproducir();
    void ReproducirMisterio();
    void setApareceunavez(bool);
    bool getApareceunavez()const;
    void setAutomaticoTimer();
    void chrono();
    int getTimer()const ;
    void setDibujar(bool);
    bool getDibujar()const;

};
