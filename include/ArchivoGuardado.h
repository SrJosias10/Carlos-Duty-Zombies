#ifndef ARCHIVOGUARDADO_H
#define ARCHIVOGUARDADO_H
#include <cstring>

#include "Guardado.h"
#include "ObjetoPersonaje.h"


class ArchivoGuardado
{
public:
    ArchivoGuardado(const char*);
    ArchivoGuardado();

    int contarRegistros();
    Guardado leerRegistro(int);
    bool grabarRegistro(Guardado&);
    ObjetoPersonaje getObjGuardado(int,Guardado*);

private:

    char _path[30];

};

#endif // ARCHIVOGUARDADO_H
