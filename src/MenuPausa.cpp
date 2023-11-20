#include <iostream>
using namespace std;

#include "Juego.h"
#include "MenuPausa.h"



MenuPausa::MenuPausa(sf::RenderWindow& window,Juego* juego, ObjetoPersonaje* soldado) : window(window), _juego(juego), opcionSeleccionada(0),_soldado(soldado)
{
    font.loadFromFile("fonts/letraCOD.ttf");
    opciones = {"Continuar", "Guardar", "Menu Principal"};

}

void MenuPausa::desplegar()
{

    sf::RectangleShape overlay(sf::Vector2f(window.getSize().x, window.getSize().y));
    overlay.setFillColor(sf::Color(0, 0, 0, 75)); // Color negro semitransparente
    window.draw(overlay);


    float centroX = window.getSize().x / 2.0f;
    float centroY = window.getSize().y / 2.0f;
    float espacioInterOpciones = 150.0f;

    for (int i = 0; i < opciones.size(); ++i)
    {
        sf::Text texto(opciones[i], font, 100);  // Ajusta el tamaño de fuente según tu menú principal
        // Calcular la posición X e Y para centrar el texto
        sf::FloatRect textRect = texto.getLocalBounds();
        texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
        texto.setPosition(centroX, centroY + i * espacioInterOpciones - opciones.size() * espacioInterOpciones / 2.0f);

        texto.setFillColor(i == opcionSeleccionada ? sf::Color::Red : sf::Color::White);
        window.draw(texto);
    }


}


void MenuPausa::manejarEntrada(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::Up)
        {
            if (opcionSeleccionada > 0)
            {
                opcionSeleccionada--;
            }
        }
        else if (event.key.code == sf::Keyboard::Down)
        {
            if (opcionSeleccionada < opciones.size() - 1)
            {
                opcionSeleccionada++;
            }
        }
        else if (event.key.code == sf::Keyboard::Return)
        {
            ejecutarAccion(opcionSeleccionada);
        }
    }
}

void MenuPausa::ejecutarAccion(int opcion)
{
    switch (opcion)
    {
    case 0:
        if (_juego)
        {
            _juego->setPausa(false); // Reanuda el juego
        }
        break;
    case 1:
        /// retorna true o false si pudo guardar.
            guardarPartida();

        break;
    case 2:
        // Menu Principal
        window.close();
        break;

    }
}

bool MenuPausa::guardarPartida(){

    ArchivoGuardado save;
    Guardado reg;



    reg.setSalud(_soldado->getSalud());
    reg.setBalasEnCargador(_soldado->getBalasEnCargador());
    reg.setBalasTotales(_soldado->getBalas());
    reg.setPuntaje(_soldado->getPuntos());
    reg.setSeleccion(_soldado->getSeleccion());
    reg.setRonda(_soldado->getRonda());
    reg.setTiempo(_soldado->getTiempo());

/*
    reg._salud = _soldado->getSalud();
    reg._balasEnCargador = _soldado->getBalasEnCargador();
    reg._balasTotales= _soldado->getBalas();
    reg._puntaje=_soldado->getPuntos();
    reg._seleccion=_soldado->getSeleccion();

    */




    return save.grabarRegistro(reg);

}
