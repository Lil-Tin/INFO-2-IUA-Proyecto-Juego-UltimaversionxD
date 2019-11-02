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

    posicionX=rand()%(616-22)+22;
    posicionY=rand()% (456-60)+69;

}

void comida::dibujar(RenderWindow *pantalla) {
    sComida.setPosition(posicionX, posicionY);
    pantalla->draw(sComida);
}

int comida::retornarX() {
    return posicionX;
}

Sprite comida::retornarSprite() {
    return sComida;
}

