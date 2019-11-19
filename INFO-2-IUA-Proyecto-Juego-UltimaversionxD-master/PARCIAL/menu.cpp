//
// Created by Usuario on 10/11/2019.
//

#include "menu.h"
#include "textos.h"
using namespace sf;
void menu::constructor() {
    tFondo.loadFromFile("IMAGENES/fondoDePantallaMenu.jpg");
    sFondo.setTexture(tFondo);
    sFondo.setPosition(0,0);
    play.constructor(220,150,86,"play",Color::Red);
    lose.constructor(75,35,34,"Perdiste\nTOP 10",Color::Red);
}

void menu::inicio(RenderWindow *pantalla) {
    pantalla->draw(sFondo);
    play.dibujar(pantalla);
}

void menu::perdio(RenderWindow *pantalla) {
    pantalla->draw(sFondo);
    lose.dibujar(pantalla);

}

