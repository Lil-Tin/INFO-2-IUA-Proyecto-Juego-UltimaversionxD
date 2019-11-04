//
// Created by martin skere on 4/11/2019.
//

#include "vida.h"
#include <iostream>

void vida::constructor() {
    tVida.loadFromFile("IMAGENES/corazon.png");
    sVida.setTexture(tVida);
    nodo *cima = new nodo;
    cima->vidas=1;
    cima->posicionX=20;
    cima->posicionY=-30;
    int i = 2;
    while(i!=5) {
        nodo *aux = new nodo;
        aux->posicionY=cima->posicionY;
        aux->posicionX=cima->posicionX+50;
        aux->vidas=i;
        aux->sig=cima;
        cima = aux;
        i++;

    }
    std::cout<<"Anduvo?"<<std::endl;


}

void vida::dibujar(RenderWindow *pantalla) {
    nodo *aux = cima;

    while (aux->sig!= NULL ){
        sVida.setPosition(aux->posicionX , aux->posicionY);
        pantalla->draw(sVida);
        aux = aux->sig;
    }if (aux->sig == NULL){
        sVida.setPosition(aux->posicionX , aux->posicionY);
        pantalla->draw(sVida);
    }

}
