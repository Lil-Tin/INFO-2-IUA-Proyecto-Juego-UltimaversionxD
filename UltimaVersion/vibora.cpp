//
// Created by mauri on 26/10/2019.
//
#include <SFML/Graphics.hpp>
#include "vibora.h"
#include <iostream>
#include "comida.h"
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

void vibora::dibujar(RenderWindow* pantalla , int direccion) {

    movimiento *aux1 = fondo;
    do {
        switch (direccion) {// 0 derecha - 2 arriba - 3 abajo - 1 izquierda
            case 0:

                sVibora.setPosition(aux1->posicionX , aux1->posicionY);
                pantalla->draw(sVibora);
                aux1 = aux1->sig;


                break;
            case 1:
                sVibora.setPosition(aux1->posicionX, aux1->posicionY);
                pantalla->draw(sVibora);
                aux1 = aux1->sig;


                break;
            case 2:
                sVibora.setPosition(aux1->posicionX, aux1->posicionY);
                pantalla->draw(sVibora);
                aux1 = aux1->sig;

                break;
            case 3:
                sVibora.setPosition(aux1->posicionX, aux1->posicionY);
                pantalla->draw(sVibora);
                aux1 = aux1->sig;
                break;
        }
    }while(aux1->sig!=NULL);

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
            aux->posicionX=aux->posicionX+20;

            break;
        case 1:
            aux->posicionX=aux->posicionX-20;

            break;
        case 2:
            aux->posicionY=aux->posicionY-20;

            break;
        case 3:
            aux->posicionY=aux->posicionY+20;

            break;
    }
    aux = fondo ;
    fondo = fondo->sig;
    delete aux;
    frente = frente->sig;






}

void vibora::crecer() {
    movimiento *aux = new movimiento;
    aux->sig= fondo;
    aux->posicionX=900;
    aux->posicionY=900;
    fondo = aux;


}



bool vibora::comio(Sprite sComida) {

    if(sVibora.getGlobalBounds().intersects(sComida.getGlobalBounds())){
        return  true;
    }

    return  false;
}

bool vibora::choco() {
    Sprite aux = sVibora;
    Sprite aux3 = sVibora;
    movimiento *aux2 = fondo;
do  {
    aux3.setPosition(frente->posicionX,frente->posicionY);
    aux.setPosition(aux2->posicionX, aux2->posicionY);
        if (aux.getGlobalBounds().intersects(aux3.getGlobalBounds())) {
            return true;
        }
    aux2 = aux2 -> sig;
    } while (aux2->sig != NULL);
    return  false;

}

bool vibora::detectarColisionesFondo() {
        if(frente->posicionX<17 || frente->posicionX>621-10 || frente->posicionY<64-10 || frente->posicionY>461-10){
            return true;
        }
        else{
            return false;
        }
    }

void vibora::resetear() {

    while (fondo->sig!=NULL){
        movimiento *aux = fondo;
        fondo = fondo->sig;
        delete aux;
    } if (fondo->sig==NULL){
        delete fondo;
        delete frente;

    }


}





