//
// Created by Usuario on 10/11/2019.
//

#ifndef PROYECTOSNAKE_MENU_H
#define PROYECTOSNAKE_MENU_H

#include <SFML/Graphics.hpp>
#include "textos.h"
#include <string>
#include <iostream>

using namespace sf;
class menu {
private:
    Texture tFondo;
    Sprite sFondo;
    textos play;
    textos lose;
public:
    void constructor();
    void inicio(RenderWindow *pantalla);
    void perdio(RenderWindow *pantalla);
};


#endif //PROYECTOSNAKE_MENU_H
