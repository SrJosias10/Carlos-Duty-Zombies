#include <iostream>

using namespace std;

#include "ArchivoGuardado.h"

ArchivoGuardado::ArchivoGuardado(const char *n)
{
    strcpy(_path, n);
}
ArchivoGuardado::ArchivoGuardado(){
    strcpy(_path,"save.dat");
}



Guardado ArchivoGuardado::leerRegistro(int pos)
{
    Guardado reg;
    FILE *p;
    p=fopen(_path, "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof (Guardado)*pos,0);
    fread(&reg, sizeof (Guardado),1, p);
    fclose(p);
    return reg;
}


int ArchivoGuardado::contarRegistros()
{
    FILE *p;
    p=fopen(_path, "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Guardado);
}


bool ArchivoGuardado::grabarRegistro(Guardado& reg)
{
    FILE *p;
    p=fopen(_path, "wb");
    if(p==NULL) return false;
    bool escribio=fwrite(&reg, sizeof reg,1, p);
    fclose(p);
    return escribio;
}

ObjetoPersonaje ArchivoGuardado::getObjGuardado(int i,Guardado* p)
{

    p[i] = this->leerRegistro(i);

    ObjetoPersonaje pj;


/*
    pj.setBalasEnCargador(p[i].getBalasEnCargador());
    pj.setBalas(p[i].getBalasTotales());
    pj.setPuntos(p[i].getPuntaje());
    pj.setSalud(p[i].getSalud());
    pj.setTiempo(p[i].getTiempo());
*/
    return pj;

}






