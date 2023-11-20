#ifndef BALA_H
#define BALA_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Collisionable.h"

class Bala : public sf::Drawable , public Collisionable
{
public:
    Bala();
    // Constructor que inicializa una bala en una posici�n con una direcci�n
    Bala(float startX, float startY, sf::Vector2f direction, float rotation);
    // M�todo para mover la bala
    void move();
    sf::Sprite sprite;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::FloatRect getBounds() const override;

    sf::Sound& getSoundDisparo();


private:
    // Almacena la direcci�n de movimiento de la bala
    sf::Vector2f moveDirection;
    sf::Texture* texturePtr;

    sf::SoundBuffer bufferBala;

    sf::Sound balasound;
};
#endif
