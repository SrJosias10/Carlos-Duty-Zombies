#include "Drop.h"
#include <stdlib.h>

Drop::Drop()
{
    _texture.loadFromFile("images/chaleco.png");

    _sprite.setTexture(_texture);

    _sprite.setOrigin(_sprite.getGlobalBounds().width/2 , _sprite.getGlobalBounds().height/2);

    _sprite.setScale(0.7,0.7);
    bufferDrop.loadFromFile("sounds/chaleco.wav");
    Dropsound.setBuffer(bufferDrop);

    bufferMistery.loadFromFile("sounds/ApariciondeCaja.mp3");
    DropMisterysound.setBuffer(bufferMistery);

    aparicionChaleco[0] = sf::Vector2f(440, 508);
    aparicionChaleco[1] = sf::Vector2f(1909, 517);
    aparicionChaleco[2] = sf::Vector2f(398, 1601);
    aparicionChaleco[3] = sf::Vector2f(1925, 1525);

    apareceunavez=true;
    timer=180*10;
}

//Vacio, podriamos agregarle animacion usando un sprite
void Drop::update()
{
}

// Función de dibujo que implementa la interfaz sf::Drawable
void Drop::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    // Dibuja el sprite del chaleco en el objetivo (render target)
    target.draw(_sprite , states);
}

// Función para reubicar el chaleco en una posición aleatoria
void Drop::respawn(int indiceAleatorio){

    // Establece la posición del chaleco en una ubicación aleatoria dentro de la pantalla
    _sprite.setPosition(aparicionChaleco[indiceAleatorio]);

}
void Drop::Reproducir(){Dropsound.play();}
void Drop::ReproducirMisterio(){DropMisterysound.play();}


sf::FloatRect Drop::getBounds() const {
    return _sprite.getGlobalBounds();
}
void Drop::setApareceunavez(bool cambio){apareceunavez=cambio;}
bool Drop::getApareceunavez()const{return apareceunavez;}

void Drop::setAutomaticoTimer(){timer=180*10;}
void Drop::chrono(){timer--;}
int Drop::getTimer()const {return timer;}

void Drop::setDibujar(bool d){dibujar=d;}
bool Drop::getDibujar()const{return dibujar;}
