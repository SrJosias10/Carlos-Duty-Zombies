#include "Collisionable.h"

bool Collisionable::isCollision(Collisionable& obj) const{

    // Utiliza la función intersects de sf::FloatRect para verificar la intersección de límites
    // entre el objeto actual y el objeto pasado como parámetro
    return getBounds().intersects(obj.getBounds());
}

bool Collisionable::isCollision(Collisionable* obj) const{


    return getBounds().intersects(obj->getBounds());
}
