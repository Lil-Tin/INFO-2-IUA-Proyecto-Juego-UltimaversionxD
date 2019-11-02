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
//sleep(milliseconds(200));
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
    fondo = aux;


}

int vibora::retornarY() {
    return frente->posicionY;
}

int vibora::retornarX() {
    return frente->posicionY;
}


bool vibora::comio(Sprite sComida) {

    if(sVibora.getGlobalBounds().intersects(sComida.getGlobalBounds())){
        std::cout<<"SI"<<std::endl;
        return  true;
    }

    return  false;
}

bool vibora::choco() {
    Sprite aux = sVibora;
    movimiento *aux2 = fondo;


    while (aux2->sig != NULL) {

        aux.setPosition(aux2->posicionX, aux2->posicionY);


        if (sVibora.getGlobalBounds().intersects(aux.getGlobalBounds())) {
            std::cout << "Choco" << std::endl;
            return true;
        }
        aux2 = aux2 -> sig;
    }

    return  false;

}






