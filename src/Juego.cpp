#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

#include "Juego.h"


Juego::Juego()
{

    _fps = 60;
    rutasZombie[0] = "images/zombie1.png";
    rutasZombie[1] = "images/zombie2.png";
    rutasZombie[2] = "images/zombie3.png";
    rutasZombie[3] = "images/zombie4.png";

    bufferjuego.loadFromFile("sounds/principal.mp3");
    juegosound.setBuffer(bufferjuego);

    _enPausa = false;
}

void Juego::mostrarPantallaGameOver(sf::RenderWindow &window) {
    // Crear un texto para mostrar
    sf::Font font;
    if (!font.loadFromFile("fonts/letraCOD.ttf")) {
        // pongo cout para manejar la carga de la fuente
    }

    sf::Text text;
    text.setFont(font);
    text.setString("Game Over");
    text.setCharacterSize(150); // en píxeles
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(window.getSize().x / 2 - text.getLocalBounds().width / 2,
                     window.getSize().y / 2 - text.getLocalBounds().height / 2);

    window.draw(text);
}


void Juego::mostrarPantallaGano(sf::RenderWindow &window) {
    // Crear un texto para mostrar
    sf::Font font;
    if (!font.loadFromFile("fonts/letraCOD.ttf")) {
        // pongo cout para manejar la carga de la fuente
    }

    sf::Text text;
    text.setFont(font);
    text.setString("GANASTE");
    text.setCharacterSize(150); // en píxeles
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);
    text.setPosition(window.getSize().x / 2 - text.getLocalBounds().width / 2,
                     window.getSize().y / 2 - text.getLocalBounds().height / 2);

    window.draw(text);
}

int Juego::getFPS()
{
    return _fps;
}

void Juego::setPausa(bool p)
{
    _enPausa = p;
}


void Juego::mostrarPuntos(sf::RenderWindow& window,ObjetoPersonaje& soldado,int seleccion,Ronda &_ronda) {

        string rutaCarlos = "images/fort.png";
        string rutaCarla = "images/OpcionKloster.png";
        string rutaImagen;
        if(soldado.getSeleccion()==0){
        rutaImagen = rutaCarlos;
        }else if(soldado.getSeleccion()==1){rutaImagen=rutaCarla;}

       // Cargoo la fuente
       sf::Font font;
    if (!font.loadFromFile("fonts/Melted Monster.ttf")) { // era la unica fuente que mostraba la /
        std::cerr << "Error al cargar la fuente." << std::endl;
        return;
    }

    // cargo texturas

    sf::Texture texturePuntos;
if (!texturePuntos.loadFromFile(rutaImagen)) {
    std::cerr << "Error al cargar imagen de puntos." << std::endl;
}

sf::Texture textureBalas;
if (!textureBalas.loadFromFile("images/cartucho.png")) {
    std::cerr << "Error al cargar imagen de balas." << std::endl;
}

sf::Texture textureVida;
if (!textureVida.loadFromFile("images/vida_pixel_.png")) {
    std::cerr << "Error al cargar imagen de vida." << std::endl;
}

sf::Sprite spritePuntos(texturePuntos);
sf::Sprite spriteBalas(textureBalas);
sf::Sprite spriteVida(textureVida);




    // Texto de los puntos
    sf::Text textoPuntos;
    textoPuntos.setFont(font);
    textoPuntos.setString("Puntos: " + std::to_string(soldado.getPuntos()));
    textoPuntos.setCharacterSize(50); // Tamaño de la fuente
    textoPuntos.setFillColor(sf::Color::White);
    textoPuntos.setPosition(50, 50);

    // Texto de las balas
    sf::Text textoBalas;
    textoBalas.setFont(font);
    textoBalas.setString("Balas: " + std::to_string(soldado.getBalasEnCargador()) + "/" + std::to_string(soldado.getBalas()));
    textoBalas.setCharacterSize(50); // Tamaño de la fuente
    textoBalas.setFillColor(sf::Color::White);
    textoBalas.setPosition(50, 100); // Ajuste de la posición

    // Texto de la salud
    sf::Text textoSalud;
    textoSalud.setFont(font);
    textoSalud.setString("Salud: " + std::to_string(soldado.getSaludActual()) + "/100");
    textoSalud.setCharacterSize(50); // Tamaño de la fuente
    textoSalud.setFillColor(sf::Color::White);
    textoSalud.setPosition(50, 150); // Ajuste de la posición

    //Texto Ronda
    sf::Text textoRonda;
    textoRonda.setFont(font);
    textoRonda.setString("Ronda: " + std::to_string(_ronda.getRonda()) + "/10");
    textoRonda.setCharacterSize(50); // Tamaño de la fuente
    textoRonda.setFillColor(sf::Color::Red);
    textoRonda.setPosition(50, 200); // Ajuste de la posición


    // Todo este bloque es para obtener el tamaño de pixeles de cada imagen y ajustarlo a los pixeles que yo quiero

        // Obtiene el tamaño actual de la textura
    sf::Vector2u textureSizePuntos = texturePuntos.getSize();
    sf::Vector2u textureSizeBalas = textureBalas.getSize();
    sf::Vector2u textureSizeVida = textureVida.getSize();

    // Calcula la escala necesaria para ajustar el tamaño de la imagen
    float pixeles = 50.0f;
    float scalePuntos = pixeles / textureSizePuntos.x;
    float scaleBalas = pixeles / textureSizeBalas.x;
    float scaleVida = pixeles / textureSizeVida.x;

    spritePuntos.setScale(scalePuntos, scalePuntos);
    spriteBalas.setScale(scaleBalas, scaleBalas);
    spriteVida.setScale(scaleVida, scaleVida);


    // Dibujo los sprites

    spritePuntos.setPosition(textoPuntos.getGlobalBounds().left + textoPuntos.getGlobalBounds().width + 25, 65);
    spriteBalas.setPosition(textoBalas.getGlobalBounds().left + textoBalas.getGlobalBounds().width + 25, 110);
    spriteVida.setPosition(textoSalud.getGlobalBounds().left + textoSalud.getGlobalBounds().width + 25, 165);


    // Guarda la vista actual
    sf::View vistaActual = window.getView();
    // Restablece la vista de la ventana a la vista por defecto
    window.setView(window.getDefaultView());

    // Dibuja los textos y los sprites
    window.draw(textoPuntos);
    window.draw(spritePuntos);
    window.draw(textoBalas);

    window.draw(spriteBalas);
    window.draw(textoSalud);
    window.draw(spriteVida);
    window.draw(textoRonda);

    // Restablece la vista original
    window.setView(vistaActual);
}


void Juego::mostrarIntro(sf::RenderWindow &window)
{
    sf::Font font;
    if (!font.loadFromFile("fonts/letraCOD.ttf"))
    {

    }

    sf::Text texto;
    texto.setFont(font);
    texto.setCharacterSize(70); // Tamaño del texto
    texto.setFillColor(sf::Color::White);


     std::vector<std::string> lineas ={
        "Luego de la catastrofe ocurrida en la UTN de Pacheco",
        "que derivo en un apocalipsis zombie nuestros heroes,",
        "intentan escapar del patio de la UTN..."

    };

    // Construir el texto concatenando las líneas con saltos de línea
    for (const auto& linea : lineas) {
        texto.setString(texto.getString() + linea + "\n");
    }

    // Establecer un tamaño mínimo para el texto principal
    int tamanoMinimo = 15;

    // Ajustar el tamaño del texto principal sin bajar del tamaño mínimo
    while (texto.getLocalBounds().width > (window.getSize().x - 40) && texto.getCharacterSize() > tamanoMinimo) {
        texto.setCharacterSize(texto.getCharacterSize() - 1);
    }

    // Centrar verticalmente el texto principal en la ventana
    float alturaTotal = texto.getLocalBounds().height;
    float posicionVertical = (window.getSize().y - alturaTotal) / 2;
    texto.setPosition(20, posicionVertical);

    // Configurar el texto del mensaje final
    sf::Text mensajeFinal("Presione cualquier tecla para comenzar", font, 30);
    mensajeFinal.setFillColor(sf::Color::White);

    // Posicionar el mensaje final en la esquina inferior derecha
    mensajeFinal.setPosition(window.getSize().x - mensajeFinal.getLocalBounds().width - 20,
                              window.getSize().y - mensajeFinal.getLocalBounds().height - 20);

    sf::Clock reloj;
    size_t lineaActual = 0;
    size_t letraActual = 0;
    string textoMostrado;
    bool mostrarMensajeFinal = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        if (reloj.getElapsedTime().asSeconds() > 0.1/2)
        {
            if (lineaActual < lineas.size())
            {
                if (letraActual < lineas[lineaActual].length())
                {
                    textoMostrado += lineas[lineaActual][letraActual++];
                }
                else
                {
                    textoMostrado += "\n"; // Agrega un salto de línea al final de cada línea
                    lineaActual++;
                    letraActual = 0;
                }

                texto.setString(textoMostrado);

                // Centrar el texto
                sf::FloatRect textRect = texto.getLocalBounds();
                texto.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
                texto.setPosition(window.getSize().x / 2.0f, window.getSize().y / 2.0f - textRect.height / 2.0f);

                reloj.restart();
            }
            else
            {
                mostrarMensajeFinal = true; // Se ha completado el texto introductorio
            }
        }

        window.clear();
        window.draw(texto);
        if (mostrarMensajeFinal)
        {
            window.draw(mensajeFinal); // Dibuja el mensaje final
        }
        window.display();

        if (mostrarMensajeFinal && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            break; // Salir de la intro si se presiona Enter
        }
    }
}


int Juego::run(ObjetoPersonaje* soldado)
{


    std::srand((unsigned)std::time(0));

    ///Inicializacion de la ventana , pantalla completa

    sf::RenderWindow window(sf::VideoMode::getFullscreenModes()[0], "Carlos Duty", sf::Style::Fullscreen);
    window.setMouseCursorVisible(false);
    /// nuestro juego corra a un FPS fijo
    window.setFramerateLimit(getFPS());
    sf::View view(sf::FloatRect(0, 0, window.getSize().x-400, window.getSize().y-200));

    mostrarIntro(window);
    window.setView(view);
    Drop municion;
    _ronda.setRonda(soldado->getRonda());
    _ronda.setTiempo(soldado->getTiempo());
    MenuPausa mp(window,this,soldado);


    //Audio principal
    juegosound.play();
    juegosound.setVolume(30.f);

    //Game Loop (Update del juego)
    while (window.isOpen())
    {

        //ReadInput (Actualizar los datos de los perifericos de entrada)

        //Leer cola de mensajes

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Si el juego está pausado, maneja la entrada para el menú de pausa
            if (_enPausa)
            {
                mp.manejarEntrada(event);
            }


            // Comprobar si se presiona una tecla para pausar
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    setPausa(!_enPausa); // Cambiar el estado de pausa

                }
            }

        }

        if(!_enPausa)
        {
            municion.chrono();
            if(municion.getTimer()==25*10){
                municion.ReproducirMisterio();
            }
            if(municion.getTimer()<=0){
                int indiceAleatorioDrop = rand() % 4;
                if(municion.getApareceunavez()){
                municion.respawn(indiceAleatorioDrop);
                municion.setApareceunavez(false);
                }
                municion.setDibujar(true);
            }
            if(soldado->isCollision(municion) && municion.getTimer()<=0){

                municion.setDibujar(false);
                municion.Reproducir();
                soldado->setSalud(100);
                soldado->agregarBalas(36);
                municion.setAutomaticoTimer();
                municion.setApareceunavez(true);
            }

            //Tiempo de la partida
            if(_ronda.getTiempo()>0)
            {
                _ronda.sumarTiempo();
            }

            _ronda.logicaRonda();
            soldado->setRonda(_ronda.getRonda());
            soldado->setTiempo(_ronda.getTiempo());


            if(_ronda.getTimerZombie() > 0)
            {
                _ronda.restarTimerZombie();
            }
            if (_ronda.getTimerZombie() == 0)
            {

                int indiceAleatorio = rand() % 4;
                ObjetoEnemigo* e = new ObjetoEnemigo(soldado, rutasZombie[indiceAleatorio]);
                vZombies.push_back(e);

                // Reiniciar el temporizador
                _ronda.setTimerZombie(_ronda.getAparicion());
                soldado->setPuntosFijos(true);
                e->setVelocidad(_ronda.getVelocidad());
                e->setVida(_ronda.getAumentavida());
            }

            ///Update (actualiza los datos del juego) y ve si hay alguna colision

            soldado->update();
            soldado->updateBullets();

            for(ObjetoEnemigo* zombie : vZombies)
            {

                zombie->update(vZombies);
                zombie->colisionConBala(soldado->getBullet(),vZombies);
                if(zombie->getVida()<=0 && soldado->getPuntosFijos())
                {
                    soldado->agregarPuntos(1);
                    soldado->setPuntosFijos(false);
                }

            }
            for(ObjetoEnemigo *zombie: vZombies)
            {

                if(soldado->isCollision(*zombie) && zombie->getVida()>0)
                {
                  _ronda.restarTimerVida();
                  zombie->setAtacar(1);

                    //Se reproduce sonido de grito de nuestro personaje
                    if(_ronda.getTimervida()<=0){
                    zombie->golpear();
                    soldado->restarVida(20);
                        _ronda.setTimervida(_ronda.getTimervidaExacto());
                    }
                }else{
                zombie->setAtacar(0);
                }
            }

            window.clear();

            /// centra la vista de la camara en el soldado
            view.setCenter(soldado->getPosition());
            window.setView(view);

            /// dibuja entorno , zombies , soldado , etc
            _escena.dibujarEscena(window,*soldado,vZombies,municion);
            mostrarPuntos(window,*soldado,0,_ronda);

            window.display();

        }
        else
        {
            sf::View vistaActual = window.getView();
            window.setView(window.getDefaultView());
            mp.desplegar();
            window.setView(vistaActual);
            window.display();
        }

        ///Gano
        if (_ronda.getTiempo() > _ronda.getTRonda()*10)
        {
            window.setView(window.getDefaultView());
            window.clear();
            mostrarPantallaGano(window);
            window.display();
            sf::sleep(sf::seconds(3));
            window.close();
        }

        ///Perdio
        if(soldado->getSalud()<=0)
        {
            window.setView(window.getDefaultView());
            window.clear();
            mostrarPantallaGameOver(window);
            window.display();
            sf::sleep(sf::seconds(3));
            window.close();
        }

        if (juegosound.getStatus() == sf::SoundSource::Stopped)
        {
            juegosound.play();
        }


    }
    return 0;
}
