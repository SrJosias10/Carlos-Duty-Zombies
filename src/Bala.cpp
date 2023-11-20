#include "Bala.h"

Bala::Bala(float startX, float startY, sf::Vector2f direction, float rotation)
    : moveDirection(direction), texturePtr(nullptr)
{
    texturePtr = new sf::Texture();
    // Utiliza -> para acceder a loadFromFile
    texturePtr->loadFromFile("images/bala.png");
    // Utiliza *texturePtr para acceder a la textura
    sprite.setTexture(*texturePtr);
    sprite.setScale(0.3f, 0.3f);
    sprite.setPosition(startX, startY);
    moveDirection = direction;
    sprite.setRotation(rotation);
}

Bala::Bala(){

    bufferBala.loadFromFile("sounds/bala.wav");
    balasound.setBuffer(bufferBala);
}

void Bala::move()
{
    //velocidad de la bala
    float bulletSpeed = 15;
    sprite.move(bulletSpeed * moveDirection);

}

void Bala::draw(sf::RenderTarget& target, sf::RenderStates states)const
{

    target.draw(sprite, states);
}

sf::FloatRect Bala::getBounds() const
{
    return sprite.getGlobalBounds();
}

sf::Sound& Bala::getSoundDisparo(){
    return balasound;
}




