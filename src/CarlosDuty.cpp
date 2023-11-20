#include <iostream>

#include "CarlosDuty.h"
#include "Menu.h"
#include "ArchivoGuardado.h"

using namespace std;

int main()
{

    Menu menu;
    ArchivoGuardado save("save.dat");

   while(menu.desplegar(&save)){
}

    return 0;
}


