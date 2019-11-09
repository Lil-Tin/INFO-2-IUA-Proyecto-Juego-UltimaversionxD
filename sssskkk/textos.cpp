//
// Created by Usuario on 09/11/2019.
//

#include "textos.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
using namespace sf;

void textos::constructor(int posX, int posY, int size , std::string cadenaDeTexto ) {
    if(!font.loadFromFile("font.ttf")){
        std::cout<<"ERROR CARGA DE FUENTE"<<std::endl;
    }

    texto.setFont(font);
    texto.setPosition(posX, posY);
    texto.setCharacterSize(size);
    texto.setFillColor(sf::Color::White);
    texto.setString(cadenaDeTexto);

}
