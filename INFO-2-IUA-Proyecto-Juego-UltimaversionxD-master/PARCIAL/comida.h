//
// Created by martin skere on 31/10/2019.
//

#ifndef PROYECTOSNAKE_COMIDA_H
#define PROYECTOSNAKE_COMIDA_H
#include <SFML/Graphics.hpp>


using namespace sf;


class comida {
private:
    int posicionX;
    int posicionY;
    Texture tComida;
    Sprite sComida;
public:
    void constructor();
    void dibujar(RenderWindow *);
    void setearposicion();
    Sprite retornarSprite();

};


#endif //PROYECTOSNAKE_COMIDA_H
