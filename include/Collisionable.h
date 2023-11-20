#pragma once
#include <SFML/Graphics.hpp>

class Collisionable
{
public:
    // Declaraci�n de una funci�n virtual pura llamada getBounds
    // Esta funci�n debe ser implementada por clases derivadas
    virtual sf::FloatRect getBounds() const = 0;

    // Declaraci�n de la funci�n isCollision que verifica colisiones
    bool isCollision(Collisionable& col) const;

    bool isCollision(Collisionable* col) const;
};
