//
// Created by martin skere on 4/11/2019.
//

#ifndef PROYECTOSNAKE_VIDA_H
#define PROYECTOSNAKE_VIDA_H
#include <SFML/Graphics.hpp>

using namespace sf;


class vida {
private:
    struct nodo{
        int vidas; //Va a ser el tamaño
        nodo *sig = NULL;
        int posicionX;
        int posicionY;
    }*cima;

    Texture tVida;
    Sprite sVida;
public:
    void constructor();
    void dibujar(RenderWindow *);



};


#endif //PROYECTOSNAKE_VIDA_H
