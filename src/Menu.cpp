#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <cmath>



using namespace std;

#include "Menu.h"



int Menu::elegirPersonaje(ArchivoGuardado* save)
{

    Juego j;
    Menu m;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Selección de Personaje");


    // Cargo el sonido

    bufferseleccionKloster.loadFromFile("sounds/kloster.wav");
    sellecionsoundKloster.setBuffer(bufferseleccionKloster);

    bufferseleccionRicky.loadFromFile("sounds/opcionFort.wav");
    sellecionsoundKRicky.setBuffer(bufferseleccionRicky);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("sounds/gtasa1.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    //creando sonido para cuando se cambian las opciones
    sf::SoundBuffer buffer2;
    buffer2.loadFromFile("sounds/gtasa2.wav");
    sf::Sound sound2;
    sound2.setBuffer(buffer2);




    // Cargar las imágenes de fondo
    sf::Texture Carlos, Carla;
    Carlos.loadFromFile("images/fort.png"); // Ajusta la ruta a la imagen de fondo de Carlos
    Carla.loadFromFile("images/OpcionKloster.png");  // Ajusta la ruta a la imagen de fondo de Carla

    sf::Sprite backgroundSprite1(Carlos);
    sf::Sprite backgroundSprite2(Carla);

    // Ajustar la posición y escala de las imágenes de fondo
    backgroundSprite1.setPosition(0, 80);
    //backgroundSprite1.setScale(0.5f, 1.0f); // Escala al 50% del ancho de la ventana

    backgroundSprite2.setPosition(400, 80);  // Ajusta la posición para la mitad derecha de la ventana
    //backgroundSprite2.setScale(0.5f, 1.0f); // Escala al 50% del ancho de la ventana

    // Cargar la fuente
    sf::Font font;
    font.loadFromFile("fonts/letraCOD.ttf");

    // Crear las opciones de selección de personaje
    sf::Text carlosOption("Carlos", font, 50);
    carlosOption.setPosition(128, 500);

    sf::Text carlaOption("Kloster", font, 50);
    carlaOption.setPosition(530, 500);

    int op = 0;

    while (window.isOpen())
    {
        Menu m;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Left)
                {
                    if (op > 0)
                    {
                        op--;
                        sound.play();
                    }
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    if (op < 1)
                    {
                        op++;
                        sound.play();
                    }
                }
                else if (event.key.code == sf::Keyboard::Return)
                {
                    // Aquí puedes manejar la selección de personaje
                    if (op == 0)
                    {
                        // El jugador seleccionó a Carlos
                        sellecionsoundKRicky.play();
                        std::cout << "Has seleccionado a Carlos" << std::endl;

                        ObjetoPersonaje *soldado = new ObjetoPersonaje(0);
                        menusound.stop();
                        return j.run(soldado);

                    }
                    else if (op == 1)
                    {

                        sellecionsoundKloster.play();
                        std::cout << "Has seleccionado a Kloster" << std::endl;
                        ObjetoPersonaje *soldado = new ObjetoPersonaje(1);
                        menusound.stop();
                        return j.run(soldado);
                    }
                    // Logica adicional
                }
            }
        }

        // Actualizar la apariencia de las opciones en función de la selección
        carlosOption.setFillColor(op == 0 ? sf::Color::Red : sf::Color::White);
        carlaOption.setFillColor(op == 1 ? sf::Color::Red : sf::Color::White);

        window.clear();

        // Dibujar los fondos correspondientes a las opciones seleccionadas
        if (op == 0)
        {
            window.draw(backgroundSprite1);
        }
        else if (op == 1)
        {
            window.draw(backgroundSprite2);
        }

        window.draw(carlosOption);
        window.draw(carlaOption);
        window.display();
    }

}

void Menu::acercaDe(sf::RenderWindow& window)
{

    // Cargo la textura y hago el fondo
    sf::Texture textureFondo;
    if (!textureFondo.loadFromFile("images/fondo_intro.png"))
    {
        std::cerr << "Error al cargar la imagen de fondo." << std::endl;

    }








    sf::Sprite spriteFondo(textureFondo);

    sf::Font font;
    if (!font.loadFromFile("fonts/letraCOD.ttf"))
    {
        std::cerr << "Error al cargar la fuente." << std::endl;
    }

    // Cargo textos

    sf::Text titulo("Laboratorio de computacion II", font, 35);
    titulo.setFillColor(sf::Color::White);
    titulo.setPosition(100, 50); // Ajusta la posición según sea necesario

    sf::Text grupo("Grupo: 44", font, 30);
    grupo.setFillColor(sf::Color::White);
    grupo.setPosition(100, 100); // Ajusta la posición según sea necesario

    sf::Text integrantes("Proyecto: Carlos Duty\n\n Integrantes:\n\nSantiago Jesus Canete \nIvan Agustin Leani \nJosias Omar Olave \nGonzalo Garnica\n\nProfesor: Brian Lara ", font, 35);
    integrantes.setFillColor(sf::Color::White);
    integrantes.setPosition(100, 150); // Ajusta la posición según sea necesario

    // Bucle de eventos para la pantalla acercaDe

    bool mostrarAcercaDe = true;
    while (mostrarAcercaDe && window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)   // Volver al menú al presionar Escape
                {
                    mostrarAcercaDe = false;
                }
            }
        }

        window.clear();
        window.draw(spriteFondo);
        window.draw(titulo);
        window.draw(grupo);
        window.draw(integrantes);
        window.display();
    }
}



bool Menu::desplegar(ArchivoGuardado* save)
{
    Juego j;


    //Seleccion s;

    // Musica de fondo del menu

    bufferMenu.loadFromFile("sounds/menu.mp3");
    menusound.setBuffer(bufferMenu);



    sf::SoundBuffer buffer;
    buffer.loadFromFile("sounds/gtasa1.wav");
    sf::Sound sound;
    sound.setBuffer(buffer);

    //creando sonido para cuando se cambian las opciones
    sf::SoundBuffer buffer2;
    buffer2.loadFromFile("sounds/gtasa2.wav");
    sf::Sound sound2;
    sound2.setBuffer(buffer2);



    // Inicialización de la ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Selección de Personaje");

    menusound.play();
    menusound.setVolume(40.f);

    //Fondo
    sf::Texture textura;
    if (!textura.loadFromFile("images/fondo_pixel_2.png"))
    {
        // Manejar errores de carga de textura
        cout<<"error";
    }

    sf::Sprite image;
    image.setTexture(textura);

    // Ajustar la escala del sprite al tamaño de la ventana
    float ventanaAncho = static_cast<float>(window.getSize().x);
    float ventanaAlto = static_cast<float>(window.getSize().y);

    float escalaX = ventanaAncho / textura.getSize().x;
    float escalaY = ventanaAlto / textura.getSize().y;

    image.setScale(escalaX, escalaY);



    // Creo la fuente
    sf::Font font;
    if (!font.loadFromFile("fonts/letraCOD.ttf"))  //Melted Monster
    {
        // Manejar errores de carga de fuente
        // Puedes agregar un mensaje de error o cerrar la aplicación aquí
    }

    // Opciones
    sf::Text nuevoJuego("Nuevo juego", font, 30);
    nuevoJuego.setPosition(20, 40);

    sf::Text cargarJuego("Cargar Partida", font, 30);
    cargarJuego.setPosition(20, 80);

    sf::Text configuracion("Acerca de", font, 30);
    configuracion.setPosition(20, 120);

    sf::Text salir("Salir", font, 30);
    salir.setPosition(20, 160);

    int op = 0; // Para rastrear la opción seleccionada

    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    // Mover hacia arriba en las opciones
                    if (op > 0)
                    {
                        op--;
                        sound.play();
                    }
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    // Mover hacia abajo en las opciones
                    if (op < 3)   // 3 es el número de opciones
                    {
                        op++;
                        sound.play();
                    }
                }
                else if (event.key.code == sf::Keyboard::Return)
                {
                    // Ejecutar la opción seleccionada al presionar Enter
                    sound2.play();
                    switch (op)
                    {
                    case 0:
                        elegirPersonaje(save);
                        break;
                    case 1:

                        cargarPartida();

                        break;
                    case 2:
                        acercaDe(window);
                        break;
                    case 3:
                        window.close(); // Salir
                        break;
                    }
                }
            }
        }


        // Actualizar la apariencia del menú en función de la opción seleccionada
        nuevoJuego.setFillColor(op == 0 ? sf::Color::Red : sf::Color::White);
        cargarJuego.setFillColor(op == 1 ? sf::Color::Red : sf::Color::White);
        configuracion.setFillColor(op == 2 ? sf::Color::Red : sf::Color::White);
        salir.setFillColor(op == 3 ? sf::Color::Red : sf::Color::White);

        window.clear();


        // Dibujar el fondo
        window.draw(image);
        // Dibujar elementos del menú y otros elementos
        window.draw(nuevoJuego);
        window.draw(cargarJuego);
        window.draw(configuracion);
        window.draw(salir);

        window.display();
    }
}


void Menu::cargarPartida()
{

    Juego j;
    ArchivoGuardado save;

    int cantReg = save.contarRegistros();

    Guardado reg = save.leerRegistro(0);

    /// si eligio a k o f
    ObjetoPersonaje pj(reg.getSeleccion());

    pj.setBalasEnCargador(reg.getBalasEnCargador());
    pj.setBalas(reg.getBalasTotales());
    pj.setPuntos(reg.getPuntaje());
    pj.setSalud(reg.getSalud());
    pj.setRonda(reg.getRonda());
    pj.setTiempo(reg.getTiempo());


    /// corre el juego
    menusound.stop();
    j.run(&pj);

}



