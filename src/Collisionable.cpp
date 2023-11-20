#include "Collisionable.h"

bool Collisionable::isCollision(Collisionable& obj) const{

    // Utiliza la funci�n intersects de sf::FloatRect para verificar la intersecci�n de l�mites
    // entre el objeto actual y el objeto pasado como par�metro
    return getBounds().intersects(obj.getBounds());
}

bool Collisionable::isCollision(Collisionable* obj) const{


    return getBounds().intersects(obj->getBounds());
}
