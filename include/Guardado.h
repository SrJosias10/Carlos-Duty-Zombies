#ifndef GUARDADO_H
#define GUARDADO_H



class Guardado
{



public:


    int getSalud() const;

    int getBalasEnCargador() const;

    int getBalasTotales() const;


    int getPuntaje() const;

    void setSalud(int salud);

    void setBalasEnCargador(int balasEnCargador);

    void setBalasTotales(int balasTotales);


    void setPuntaje(int puntaje);

    int getSeleccion();
    void setSeleccion(int);

    void setRonda(int);

    int getRonda();

    void setTiempo(int t);
    int getTiempo();



private:


  int _seleccion;
    int _salud;
    int _balasEnCargador;
    int _balasTotales;

    int _puntaje;
    int _ronda;
    int _tiempo;




};

#endif // GUARDADO_H
