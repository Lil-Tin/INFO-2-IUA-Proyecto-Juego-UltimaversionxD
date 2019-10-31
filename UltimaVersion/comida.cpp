//
// Created by martin skere on 31/10/2019.
//

#include "comida.h"
#include <SFML/Graphics.hpp>
#include<stdlib.h>
#include<time.h>

using namespace sf;


void comida::constructor() {

    tComida.loadFromFile("IMAGENES/comida.png");
    sComida.setTexture(tComida);

}

void comida::setearposicion() {
    srand(time(NULL));
    posicionX=10+rand()%630;
    posicionY=10+rand()%470;



}

void comida::dibujar(RenderWindow *pantalla) {
    sComida.setPosition(posicionX, posicionY);
    pantalla->draw(sComida);
}

int comida::retornarX() {
    return posicionX;
}

int comida::retornarY() {
    return posicionY;
}
