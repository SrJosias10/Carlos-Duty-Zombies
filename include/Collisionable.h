#pragma once
#include <SFML/Graphics.hpp>

class Collisionable
{
public:
    // Declaración de una función virtual pura llamada getBounds
    // Esta función debe ser implementada por clases derivadas
    virtual sf::FloatRect getBounds() const = 0;

    // Declaración de la función isCollision que verifica colisiones
    bool isCollision(Collisionable& col) const;

    bool isCollision(Collisionable* col) const;
};
