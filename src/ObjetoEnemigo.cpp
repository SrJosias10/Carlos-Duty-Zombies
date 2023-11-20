#include <stdlib.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include "ObjetoEnemigo.h"


ObjetoEnemigo::ObjetoEnemigo(ObjetoPersonaje* jugador, std::string& pathTexture)
    : _jugador(jugador), vida(100)
{
    // Asigna el puntero al jugador

    _texture.loadFromFile(pathTexture);
    _sprite.setTexture(_texture);
    _sprite.setTextureRect({0,0,90,90});
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
    _sprite.setRotation(0);
    indiceAleatorio = rand() % 2;
    LugarNacimiento[0] = sf::Vector2f(840,480);
    LugarNacimiento[1] = sf::Vector2f(1200,1850);
    _sprite.setPosition(LugarNacimiento[indiceAleatorio]);
    _frame=0;
    _frameAtaque=0;
    atacar=false;


    sf::Vector2f escala(0.7f, 0.7f);
    _sprite.setScale(escala);

    bufferMuerte.loadFromFile("sounds/lastimanaRF.wav");
    muertesound.setBuffer(bufferMuerte);

    bufferZombie.loadFromFile("sounds/zombie.wav");
    zombiesound.setBuffer(bufferZombie);

    bufferZombie2.loadFromFile("sounds/zombie2.wav");
    zombiesound2.setBuffer(bufferZombie2);
}

ObjetoEnemigo::ObjetoEnemigo() {};

//Función para actualizar la posición y el comportamiento del ObjetoEnemigo
void ObjetoEnemigo::update(std::vector<ObjetoEnemigo*>& vZombies)
{
    //Variable para transcurrir el tiempo de la reaparicion del grito del zombie
    _timeSonidoZombie--;

    //Si el tiempo de sonido llega a 0 o menos entonces reproducimos un sonido
    //random de 2 y reasignamos un tiempo a la variable timesonidozombie
    if (_timeSonidoZombie < 0)
    {
        _timeSonidoZombie = 60*10;
        std::rand() % 2==0? zombiesound.play() : zombiesound2.play();
    }

    // Calcula la dirección hacia el personaje
    sf::Vector2f direccion = _jugador->getPosition() - _sprite.getPosition();

    // Calcula la distancia entre el ObjetoEnemigo y el personaje

    float distancia = std::sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

    // Normaliza la dirección (la convierte en un vector unitario)
    direccion /= distancia;

    if(vida<=0){
            velocidad = 0;
            zombiesound2.stop();
            zombiesound.stop();
        }

    // Mueve el ObjetoEnemigo hacia el personaje
    _sprite.move(direccion * velocidad);

    // Calcula el ángulo de rotación basado en la dirección
    float angulo = std::atan2(direccion.y, direccion.x) * (180.0f / 3.14159265f);
    ultima = angulo;

    // Establece la rotación del sprite según el ángulo calculado
    if(vida>0)
    {
        _sprite.setRotation(angulo);
    }
    //el frame ajusta la transicion del sprite
    _frame += 0.15;
    _frameAtaque += 0.08;

    // Si el frame llega a 12, se reinicia a 0 para dar el efecto de animación
    if(_frame>=12)
    {
        _frame=0;
    }
    if(_frameAtaque>=6)
    {
        _frameAtaque=0;
    }


    // Establece el rectángulo de textura para la animación
    if(vida>0)
    {
        _sprite.setTextureRect({0+(int)_frame*90,0,90,90});

    }
    else
    {

        _sprite.setTextureRect({0,120,120,114});

        timerM--;
    }
    if(atacar){
        _sprite.setTextureRect({0+(int)_frameAtaque*90,228,90,90});
    }


    for (int i = 0; i < vZombies.size(); i++)
    {
    // Verificar si el zombie está muerto
    if (vZombies[i]->getVida() <= 0)
    {
        continue;  // Saltar al siguiente zombie si está muerto
    }

    for (int j = i + 1; j < vZombies.size(); j++)
    {
        // Verificar si el otro zombie está muerto
        if (vZombies[j]->getVida() <= 0)
        {
            continue;  // Saltar al siguiente zombie si está muerto
        }

        if (vZombies[i]->isCollision(vZombies[j]))
        {
            // Calcular la dirección y distancia entre los dos zombies
            sf::Vector2f direccion = vZombies[i]->getPosition() - vZombies[j]->getPosition();
            float distancia = sqrt(direccion.x * direccion.x + direccion.y * direccion.y);

            // Normalizar el vector de dirección
            if (distancia != 0)
            {
                direccion /= distancia;
            }

            // Calcular la superposición y el vector de separación
            float superposicion = vZombies[i]->getRadius() + vZombies[j]->getRadius() - distancia;
            sf::Vector2f separacion = direccion * superposicion * 0.5f;

            // Mover los zombies para resolver la colisión
            vZombies[i]->move(separacion);
            vZombies[j]->move(-separacion);
        }
    }
}














}

// Función de dibujo que implementa la interfaz sf::Drawable
void ObjetoEnemigo::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    // Dibuja el sprite del ObjetoEnemigo en el objetivo (render target)
    target.draw(_sprite, states);
}

// Función para reubicar al ObjetoEnemigo en una posición específica
void ObjetoEnemigo::respawn(std::vector<ObjetoEnemigo*>& _vEnemigos)
{
    std::srand(std::time(nullptr));

    int randomX, randomY;
    bool colision = false;

    do
    {
        colision = false;  // Inicializamos la bandera de colisión
        randomX = std::rand() % 1080;
        randomY = std::rand() % 720;

        // Verificamos colisiones con otros ObjetoEnemigos (usando punteros)
        for (const ObjetoEnemigo* otroEnemigo : _vEnemigos)
        {
            if (this != otroEnemigo)
            {
                // Calculamos la distancia entre este objeto y el otro objeto
                float distance = std::sqrt(
                                     std::pow(randomX - otroEnemigo->_sprite.getPosition().x, 2) +
                                     std::pow(randomY - otroEnemigo->_sprite.getPosition().y, 2)
                                 );

                // Si la distancia es menor que 50, hay colisión
                if (distance < 50)
                {
                    colision = true;
                    break;
                }
            }
        }

        if (!colision)
        {
            // Establecemos la posición solo si no hay colisión
            _sprite.setPosition(randomX, randomY);
        }
    }
    while (colision);
}

void ObjetoEnemigo::golpear()
{
    muertesound.play();
}

// Función para obtener los límites del ObjetoEnemigo (implementación de la interfaz Collisionable)
sf::FloatRect ObjetoEnemigo::getBounds() const
{

    // Devuelve los límites globales del sprite
    return _sprite.getGlobalBounds();
}

sf::Vector2f ObjetoEnemigo::getPosition() const
{
    return _sprite.getPosition();
}

float ObjetoEnemigo::getRadius() const
{
    // Suponiendo que el ObjetoEnemigo es circular, puedes usar la mitad del ancho del sprite como radio
    return _sprite.getGlobalBounds().width / 2.0f;
}

void ObjetoEnemigo::move(const sf::Vector2f& offset)
{
    _sprite.move(offset);
}

bool ObjetoEnemigo::murio() const
{
    if(vida<=0 && timerM<=0)return true;
    return false;
}
void ObjetoEnemigo::recibioBala()
{
    vida-=25;

}

void ObjetoEnemigo::colisionConBala(std::vector<Bala*>& bullets, std::vector<ObjetoEnemigo*>& vZombies)
{

    //Collisiona disparo con zombie

    for (auto itZombie = vZombies.begin(); itZombie != vZombies.end();)
    {
        auto zombie = *itZombie;
        auto itBullet = bullets.begin();

        while (itBullet != bullets.end())
        {
            auto bullet = *itBullet;

            if (zombie->isCollision(bullet))
            {
                // Si hay colisión, incrementa el contador de golpes del zombie
                zombie->recibioBala();

                // Libera la memoria de la bala y elimínala del vector
                delete bullet;
                itBullet = bullets.erase(itBullet);
            }
            else
            {
                ++itBullet;
            }
        }

        // Verifica si el zombie debe ser eliminado
        if (zombie->murio())
        {
            _sprite.setRotation(ultima);
            if(timerM <= 0)
            {
                delete zombie;

                itZombie = vZombies.erase(itZombie);
            }

        }
        else
        {
            ++itZombie;
        }

    }

}

int ObjetoEnemigo::getVida()
{
    return vida;
}
void ObjetoEnemigo::setVelocidad(float vel)
{
    velocidad=vel;
}
void ObjetoEnemigo::setVida(int v)
{
    vida = v;
}






