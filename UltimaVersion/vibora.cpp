//
// Created by mauri on 26/10/2019.
//
#include <SFML/Graphics.hpp>
#include "vibora.h"
#include <iostream>
using namespace sf;

void vibora::constructor() {
    frente = new movimiento;
    frente->posicionX=320;
    frente->posicionY=240;
    frente->sig=NULL;
    fondo = new movimiento;
    fondo->sig = frente;
    fondo->posicionX=310;
    fondo->posicionY=240;
    tVibora.loadFromFile("IMAGENES/SNAKE.png");
    sVibora.setTexture(tVibora);


}

void vibora::dibujar(RenderWindow* pantalla) {

    movimiento *aux1 = fondo;

    do{
        sVibora.setPosition(aux1->posicionX, aux1->posicionY);
        pantalla->draw(sVibora);
        aux1 = aux1->sig;

    }while (aux1->sig!=NULL);


    if (aux1->sig==NULL) {
        sVibora.setPosition(aux1->posicionX, aux1->posicionY);
        pantalla->draw(sVibora);

        }

}

void vibora::moverse( int direccion) {
    movimiento *aux = new movimiento;
    aux->sig=NULL;
    aux->posicionX= frente->posicionX;
    aux->posicionY=frente->posicionY;
    frente->sig = aux;

    switch (direccion){
        case 0:
            aux->posicionX=aux->posicionX+10;

            break;
        case 1:
            aux->posicionX=aux->posicionX-10;

            break;
        case 2:
            aux->posicionY=aux->posicionY-10;

            break;
        case 3:
            aux->posicionY=aux->posicionY+10;

            break;
    }
    fondo = fondo->sig;
    frente = frente->sig;






}

void vibora::crecer() {
    movimiento *aux = new movimiento;
    aux->sig= fondo;
    fondo = aux;


}

int vibora::retornarY() {
    return frente->posicionY;
}

int vibora::retornarX() {
    return frente->posicionY;
}




