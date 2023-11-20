#ifndef RONDA_H
#define RONDA_H

class Ronda
{
    public:

        Ronda();

    int getTiempo() const;
    int getRonda() const;
    int getAparicion() const;
    int getTRonda() const;
    int getTimervidaExacto() const;

    float getVelocidad() const;
    int getAumentavida() const;
    int getTimerZombie() const;
    int getTimervida() const;

    void setTiempo(int);
    void setRonda(int);
    void setAparicion(int);
    void setVelocidad(float);
    void setAumentavida(int);
    void setTimerZombie(int);
    void setTimervida(int);
    void restarTimerZombie();
    void restarTimerVida();
    void sumarTiempo();

    void logicaRonda();

    private:

    int _tiempo;
    int _ronda;
    int _aparicion;
    const int tRonda = 180 * 10;
    bool vecRonda[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    float velocidad;
    int aumentavida;
    int timerZombie;
    int timervida;
    const int timervidaExacto = 4 * 10;

};

#endif // RONDA_H
