#ifndef MENUPAUSA_H
#define MENUPAUSA_H



#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#include "ArchivoGuardado.h"
#include "Juego.h"

class Juego; // Declaración adelantada de la clase Juego (no encontraba como resolverlo)

class MenuPausa
{
public:

    MenuPausa(sf::RenderWindow& window,Juego* juego,ObjetoPersonaje*);
    void desplegar();
    void manejarEntrada(sf::Event event);
    void ejecutarAccion(int opcion);
    bool guardarPartida();

private:
    Juego* _juego; // puntero a juego
    ObjetoPersonaje* _soldado;
    sf::RenderWindow& window;
    sf::Font font;
    std::vector<std::string> opciones;
    int opcionSeleccionada;


};

#endif // MENUPAUSA_H
