//
// Created by martin skere on 4/11/2019.
//

#include "vida.h"
#include <iostream>

void vida::constructor() {
    tVida.loadFromFile("IMAGENES/corazon.png");
    sVida.setTexture(tVida);


    cima->posicionX=5;
    cima->posicionY=0;
    int i = 1;

    while(i<4) {
        nodo *aux = new nodo;
        aux->posicionY=cima->posicionY;
        aux->posicionX=cima->posicionX+20;

        aux->sig=cima;
        cima = aux;
        i++;
    }


}

void vida::dibujar(RenderWindow *pantalla) {
    nodo *aux = cima;

    while (aux->sig!= nullptr ){
        sVida.setPosition(aux->posicionX , aux->posicionY);
        pantalla->draw(sVida);
        aux = aux->sig;
    }if (aux->sig == nullptr){
        sVida.setPosition(aux->posicionX , aux->posicionY);
        pantalla->draw(sVida);
    }

}

 void vida::deletear() {

    if (!(cima->sig==nullptr)){
    nodo *aux2;
    aux2 = cima;
    cima=cima->sig;
    delete aux2;
    aux2 = nullptr;
}
    else{
        delete cima;
        cima = nullptr;
    }
}


