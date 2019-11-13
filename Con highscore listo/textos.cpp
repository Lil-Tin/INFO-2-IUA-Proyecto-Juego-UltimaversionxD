//
// Created by Usuario on 09/11/2019.
//

#include "textos.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

void textos::constructor(int posX, int posY, int size , std::string cadenaDeTexto, Color colorTexto) {
    if(!font.loadFromFile("Galaxy Girl Slant.otf")){
        std::cout<<"ERROR CARGA DE FUENTE"<<std::endl;
    }
    texto.setFont(font);
    texto.setPosition(posX, posY);
    texto.setCharacterSize(size);
    texto.setString(cadenaDeTexto);
    texto.setColor(colorTexto);
}

void textos::dibujar(RenderWindow * pantalla) {
    pantalla->draw(texto);
}

