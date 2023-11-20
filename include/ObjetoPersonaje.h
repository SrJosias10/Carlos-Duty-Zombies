#ifndef OBJETOPERSONAJE_H
#define OBJETOPERSONAJE_H

#include <SFML/Graphics.hpp>

#include "Bala.h"
#include "Collisionable.h"


class ObjetoPersonaje: public sf::Drawable, public Collisionable
{
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

    sf::SoundBuffer bufferRecarga;
    sf::Sound recargasound;
    sf::SoundBuffer bufferGatillo;
    sf::Sound gatilloSound;
    sf::SoundBuffer bufferDisparo;
    sf::Sound disparoSound;

    /// grito al precionar H
    sf::SoundBuffer bufferGritoDeGuerra;
    sf::Sound gritoGuerraSound;

    /// grito al recibir Daño
    sf::SoundBuffer bufferGritoDolor;
    sf::Sound gritoDolorSound;


    sf::Clock recargaClock;
    const sf::Time tiempoRecarga = sf::seconds(1.0f);
    bool recargando = false;
    bool murio;


    sf::Vector2f _velocidad;
    sf::Vector2f _ultimaDireccion;
    float _frame;
    std::vector<Bala*> bullets;
    bool SPACEFULL;
    bool HFULL;
    int timerRecarga;
    bool recarga;
    bool disparo;

    int _saludBase;
    int _saludActual;
    int _balas;
    int _balasEnCargador;
    int _puntos;
    bool _puntosfijo;
    int _ronda;
    float _tiempo;
    void morir();
    int _seleccion;


public:

    ObjetoPersonaje(int s);
    ObjetoPersonaje();

    bool getMurio();
    bool setMurio(bool);
    void update();
    void joystick();
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void golpeado();
    void respawn();
    void setDisparo(bool);
    bool getDisparo()const;
    float getRotation() const;
    int getSalud();
    int getBalas();
    int getBalasEnCargador();
    bool getPuntosFijos()const;
    void setPuntosFijos(bool);








    sf::Vector2f getPosition() const;

    // Función para obtener los límites del personaje (implementación de la interfaz Collisionable)
    sf::FloatRect getBounds() const override;
    ObjetoPersonaje* getPtr();
    std::vector<Bala*>& getBullet();


    void disparar();
    void drawBala(sf::RenderWindow&);
    void updateBullets();
    void restarBala();
    void sumarBalas(int);
    /// suma al acumulador vida
    void curar(int vida);
    void restarVida(int);
    void gatillar();
    void agregarPuntos(int puntos);
    int getSaludActual();
    int getSaludBase();
    int getPuntos();
    void cargarArma();



    /// para el cargado/guardado
    void setBalasEnCargador(int);
    void setSalud(int);
    void setBalas(int);
    void setPuntos(int);
    void setRonda(int);
    int getRonda();
    void setTiempo(float);
    int getTiempo();
    int getSeleccion();
    void setSeleccion(int);
    void agregarBalas(int);



};
#endif // OBJETOPERSONAJE_H


