//
// Created by martin skere on 31/10/2019.
//

#include "comida.h"
#include <SFML/Graphics.hpp>
#include<stdlib.h>


using namespace sf;


void comida::constructor() {

    tComida.loadFromFile("IMAGENES/comida.png");
    sComida.setTexture(tComida);

}

void comida::setearposicion() {

    posicionX=rand()%(616-30)+32;
    posicionY=rand()% (456-86)+55;

}

void comida::dibujar(RenderWindow *pantalla) {
    sComida.setPosition(posicionX, posicionY);
    pantalla->draw(sComida);
}


Sprite comida::retornarSprite() {
    return sComida;
}

