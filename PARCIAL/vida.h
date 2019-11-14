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

        nodo *sig = nullptr;
        int posicionX;
        int posicionY;
    }*cima=new nodo;

    Texture tVida;
    Sprite sVida;
public:
    void constructor();
    void dibujar(RenderWindow *);

    void deletear();
};


#endif //PROYECTOSNAKE_VIDA_H
