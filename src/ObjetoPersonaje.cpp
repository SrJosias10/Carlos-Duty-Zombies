#include <iostream>
#include <cmath>
#include <vector>


using namespace std;

#include "ObjetoPersonaje.h"


/// constructor

ObjetoPersonaje::ObjetoPersonaje()
{
}


ObjetoPersonaje::ObjetoPersonaje(int op)
{
    /// Carga archivos de sonido para la recarga y disparo
    bufferRecarga.loadFromFile("sounds/recarga.wav");
    recargasound.setBuffer(bufferRecarga);

    bufferGatillo.loadFromFile("sounds/gatillo.wav");
    gatilloSound.setBuffer(bufferGatillo);
    gatilloSound.setVolume(50.0f);

    bufferDisparo.loadFromFile("sounds/bala.wav");
    disparoSound.setBuffer(bufferDisparo);


    /// carga la textura dependiedo de la opcion
    std::string rutaTextura;

    ///Riky
    if(op == 0)
    {

        rutaTextura = "images/carlos.png";
        bufferGritoDeGuerra.loadFromFile("sounds/fort.wav");


    }




    /// kloster
    if(op == 1)
    {

        rutaTextura = "images/Kloster.png";
        bufferGritoDeGuerra.loadFromFile("sounds/kloster.wav");

    }


    setSeleccion(op);
    gritoGuerraSound.setBuffer(bufferGritoDeGuerra);

    _texture.loadFromFile(rutaTextura);
    /// Asigna la textura al sprite
    _sprite.setTexture(_texture);


    /// vector para la escala del tamaño del pj
    sf::Vector2f escala(0.9f, 0.9f);
    _sprite.setScale(escala);
    /// Velocidad inicial
    _velocidad = {5,5};
    /// Establece el rectángulo de textura para mostrar la imagen inicial
    _sprite.setTextureRect({0,0,70,70});
    /// Establece el origen del sprite en su centro
    _sprite.setOrigin(_sprite.getGlobalBounds().width/2, _sprite.getGlobalBounds().height/2);
    /// Establece la rotación inicial del sprite a 0 grados
    _sprite.setRotation(0);
    _sprite.setPosition(1200,1000);



    SPACEFULL = false;
    HFULL = false;
    murio = false;
    recargando = false;
    disparo = false;
    _puntos=0;
    _tiempo = 1;
    _ronda = 1;



    _saludBase = 100;
    _saludActual = 100;
    _balasEnCargador = 12;
    _balas = 5;

}








void ObjetoPersonaje::restarBala()
{
    if(_balasEnCargador > 0) _balasEnCargador--;
}

void ObjetoPersonaje::cargarArma()
{

    int rest = 12 - _balasEnCargador;


    if(_balasEnCargador <= 12 && _balasEnCargador >= 0 && _balas >0)
    {
        _balas -= rest;
        _balasEnCargador += rest;
        if(_balas <= 0) _balas = 0;

    }

}

void ObjetoPersonaje::restarVida(int vidaRestada)
{
    if(_saludActual>0)
    {

        _saludActual-=vidaRestada;
    }
}
void ObjetoPersonaje::curar(int vidaCurada)
{
    _saludActual+=vidaCurada;
    if(_saludActual>_saludBase)_saludActual = 100;
}



void ObjetoPersonaje::joystick()
{
    bool UP = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
    bool DOWN = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
    bool LEFT = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
    bool RIGHT = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
    bool R = sf::Keyboard::isKeyPressed(sf::Keyboard::R);
    bool SPACE = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);
    bool H = sf::Keyboard::isKeyPressed(sf::Keyboard::H);

    // Detecta las teclas que usamos para mover al personaje ajustando la velocidad y la animación
    if(UP)
    {
        _velocidad.y = -5;
        _sprite.setRotation(-90);
        _sprite.setTextureRect({0+(int)_frame*70,0,70,70});
    }

    if(DOWN)
    {
        _velocidad.y = 5;
        _sprite.setRotation(90);

        _sprite.setTextureRect({0+(int)_frame*70,0,70,70});
    }

    if(LEFT)
    {
        _velocidad.x = -5;
        _sprite.setRotation(180);

        _sprite.setTextureRect({0+(int)_frame*70,0,70,70});
    }

    if(RIGHT)
    {
        _velocidad.x = 5;
        _sprite.setRotation(0);

        _sprite.setTextureRect({0+(int)_frame*70,0,70,70});
    }

    /// movimiento diagonal


    if (UP && LEFT)
    {
        _velocidad.x = -4;
        _velocidad.y = -4;

        _sprite.setRotation(225);

    }

    if (UP && RIGHT)
    {
        _velocidad.x = 4;
        _velocidad.y = -4;

        _sprite.setRotation(315);
    }

    if (DOWN && LEFT)
    {
        _velocidad.x = -4;
        _velocidad.y = 4;

        _sprite.setRotation(135);
    }

    if (DOWN && RIGHT)
    {
        _velocidad.x = 4;
        _velocidad.y = 4;
        _sprite.setRotation(45);
    }

    if (SPACE && !SPACEFULL)
    {

        if(_balasEnCargador > 0)
        {
            if(!recargando)
            {
                setDisparo(true);
                if(getDisparo())_sprite.setTextureRect({0,75,120,70});
                SPACEFULL = true;
                disparoSound.play();
                disparar();
            }
        }
        else
        {
            gatillar();
        }
    }

    if (!SPACE)
    {
        SPACEFULL = false;
        setDisparo(false);
    }


    if (R && !recargando)
    {
        recargasound.play();
        recargaClock.restart();
        recargando = true;
    }

    // Verifica si el tiempo ha alcanzado el límite (1 segundo) para permitir disparos
    if (recargando && recargaClock.getElapsedTime() >= tiempoRecarga)
    {
        recargando = false;
        cargarArma();
    }

    if(H && !HFULL)
    {
        HFULL = true;
        gritoGuerraSound.play();
    }
    if(!H)HFULL = false;

}


// Función para actualizar la posición y la animación del personaje
void ObjetoPersonaje::update()
{

// Restablece la velocidad a cero al principio
    _velocidad = {0, 0};

    // Si el frame llega a 6, se reinicia a 0 para dar el efecto de animación
    _frame += 0.2;


    // Si el frame llega a 6, se reinicia a 0 para dar el efecto de animación
    if(_frame>=6)
    {
        _frame=0;
    }


    joystick();

    // Si el personaje se queda quieto, el sprite queda quieto y si se dispara el sprite dispara

    if (_velocidad.x == 0 && _velocidad.y == 0)
    {

        if(disparo)
        {
            _sprite.setTextureRect({0,75,120,70});
        }
        else
        {
            _sprite.setTextureRect({0,0,70,70});
        }
    }


    _sprite.move(_velocidad);


    //Condicionales para que no salga de la pantalla

    if (_sprite.getPosition().x - _sprite.getOrigin().x < 420)
    {
        _sprite.setPosition(420+_sprite.getOrigin().x, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y - _sprite.getOrigin().y < 480)
    {
        _sprite.setPosition(_sprite.getPosition().x, 480+_sprite.getOrigin().y);
    }

    if (_sprite.getPosition().x + _sprite.getOrigin().x > 1950)
    {
        _sprite.setPosition(1950 - _sprite.getOrigin().x, _sprite.getPosition().y);
    }

    if (_sprite.getPosition().y + _sprite.getOrigin().y > 1880)
    {
        _sprite.setPosition(_sprite.getPosition().x, 1880 - _sprite.getOrigin().y);
    }
}

// Función de dibujo que implementa la interfaz sf::Drawable
void ObjetoPersonaje::draw(sf::RenderTarget& target, sf::RenderStates states)const
{
    // Dibuja el sprite en el objetivo (render target)
    target.draw(_sprite, states);
}

// Función para reubicar al personaje en la posicion (50 , 360) /// ajusten si lo desean
void ObjetoPersonaje::respawn()
{



}

// Llama a la función respawn para volver a la posición determinada.
void ObjetoPersonaje::golpeado()
{
    if(_saludActual > 0 )
    {
        restarVida(25);
    }
    else if(_saludActual <=0)
    {
        ///  morir();
        setMurio(true);
    }
}
// Función para obtener los límites del personaje (implementación de la interfaz Collisionable)
sf::FloatRect ObjetoPersonaje::getBounds() const
{
    return _sprite.getGlobalBounds();
}

// Función para obtener la posición del personaje (sirve para que el ObjetoEnemigo lo detecte)
sf::Vector2f ObjetoPersonaje::getPosition() const
{
    return _sprite.getPosition();
}

ObjetoPersonaje* ObjetoPersonaje::getPtr()
{

    return this;
}


void ObjetoPersonaje::disparar()
{
    if (getDisparo() && !recargando)
    {
        restarBala();

// Calcula la dirección del disparo basado en la rotación del personaje.
        // Crea una bala y la agrega al vector de balas.
        float characterRotation = getRotation();
        float radians = characterRotation * (3.14159265f / 180);
        sf::Vector2f characterDirection(cos(radians), sin(radians));

        //sf::Vector2f initialPosition = soldado.getPosition() + sf::Vector2f(5.0f, 3.0f); // Ajusta los valores según tu necesidad.

        sf::Vector2f initialPosition = getPosition();

        // Ajusta la posición de la bala dependiendo de la rotación del personaje.
        if (characterRotation == 90.0f)
        {
            initialPosition.x -= 3;
        }
        else if (characterRotation == 180.0f)
        {
            initialPosition.y -=3;
        }
        else if (characterRotation == -90.0f)
        {
            initialPosition.x +=3;
        }
        else if (characterRotation == 0)
        {
            initialPosition.y +=3;
        }

        /// agrega una instancia al vector
        bullets.push_back(new Bala(initialPosition.x, initialPosition.y, characterDirection, getRotation()));

    }
}


void ObjetoPersonaje::updateBullets()
{
    for (size_t i = 0; i < bullets.size(); /* No incrementar i en cada iteración */)
    {
        bullets[i]->move(); // Mover las balas en cada iteración del juego

        // Verificar si la bala está fuera de los límites del mapa
        float bulletX = bullets[i]->sprite.getPosition().x;
        float bulletY = bullets[i]->sprite.getPosition().y;

        if (bulletX < 420 || bulletX > 1900 || bulletY < 500 || bulletY > 1900)
        {
            delete bullets[i]; // Asegúrate de liberar la memoria
            bullets.erase(bullets.begin() + i);
        }
        else
        {
            ++i; // Solo incrementa i si no se elimina la bala
        }
    }
}


std::vector<Bala*>& ObjetoPersonaje::getBullet()
{
    return bullets;
}

bool ObjetoPersonaje::getMurio()
{
    return murio;
}
bool ObjetoPersonaje::setMurio(bool m)
{
    murio = m;
}
void ObjetoPersonaje::gatillar()
{
    gatilloSound.play();
}

void ObjetoPersonaje::setDisparo(bool estado)
{
    disparo = estado;
}
bool ObjetoPersonaje::getDisparo()const
{
    return disparo;
}
float ObjetoPersonaje::getRotation() const
{
    return _sprite.getRotation();
}
int ObjetoPersonaje::getSalud()
{

    return _saludActual;
}
int ObjetoPersonaje::getBalas()
{

    return _balas;
}

int ObjetoPersonaje::getBalasEnCargador()
{

    return _balasEnCargador;
}


int ObjetoPersonaje::getPuntos()
{
    return _puntos;
}

void ObjetoPersonaje::agregarPuntos(int puntos)
{
    _puntos += puntos;
}


int ObjetoPersonaje::getSaludBase()
{
    return _saludBase;
}

int ObjetoPersonaje::getSaludActual()
{
    return _saludActual;
}

void ObjetoPersonaje::setBalasEnCargador(int balas)
{
    _balasEnCargador = balas;
}

void ObjetoPersonaje::setSalud(int salud)
{
    this->_saludActual = salud;
}

void ObjetoPersonaje::setBalas(int balas)
{
    this->_balas = balas;
}
void ObjetoPersonaje::agregarBalas(int b){this->_balas += b;}

void ObjetoPersonaje::setPuntos(int puntos)
{
    this->_puntos = puntos;
}

void ObjetoPersonaje::setRonda(int ronda)
{
    this->_ronda = ronda;
}

int ObjetoPersonaje::getRonda()
{
    return _ronda;
}

void ObjetoPersonaje::setTiempo(float t){

    _tiempo = t;
}

int ObjetoPersonaje::getTiempo(){

return _tiempo;
}
void ObjetoPersonaje::setSeleccion(int s){
    _seleccion = s;
}
int ObjetoPersonaje::getSeleccion(){
    return _seleccion;
}

bool ObjetoPersonaje::getPuntosFijos()const{return _puntosfijo;}
void ObjetoPersonaje::setPuntosFijos(bool estado){_puntosfijo = estado;}




