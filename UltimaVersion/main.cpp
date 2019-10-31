#include <iostream>
#include "vibora.h"
#include "comida.h"
#include <SFML/Graphics.hpp>
using namespace sf;


int main() {
    RenderWindow pantalla(VideoMode(640,480), "ProyectoSnake");
    pantalla.setFramerateLimit(30);
    pantalla.getSize();

    Texture tFondoDePantalla;
    Sprite sFondoDePantalla;
    tFondoDePantalla.loadFromFile("IMAGENES/fondodepantalla.png");
    sFondoDePantalla.setTexture(tFondoDePantalla);
    vibora jugador;
    bool band=false, comidasa=true;
    int direccion=0, x1, x2, y1, y2; // 1 derecha - 2 arriba - 3 abajo - 0 izquierda
    jugador.constructor();
    comida Comida;
    Comida.constructor();


    while (pantalla.isOpen()) {
        Event e;
        while (pantalla.pollEvent(e)) {
            if (e.type == Event::Closed)
                pantalla.close();
        }

        pantalla.clear();

        if (Keyboard::isKeyPressed(Keyboard::D) && direccion!=1){
            direccion = 0;


        }
        if (Keyboard::isKeyPressed(Keyboard::A) && direccion!=0){
            direccion = 1;

        }
        if (Keyboard::isKeyPressed(Keyboard::W) && direccion!=3){
            direccion = 2;

        }
        if (Keyboard::isKeyPressed(Keyboard::S) && direccion!=2){
            direccion = 3;

        }
        if (Keyboard::isKeyPressed(Keyboard::Space)){
           jugador.crecer();
        }
        /*if (comidasa){
            Comida.setearposicion();
            comidasa = false;
            x1 = Comida.retornarX();
            y1 = Comida.retornarY();
            x2 = x1 - 5;
            x1 = x1 + 5;
            y2 = y1 - 5;
            y1 = y1 + 5;

        }*/


        std::cout<<direccion<<std::endl;
        jugador.moverse(direccion);
        pantalla.draw(sFondoDePantalla);
        Comida.dibujar(&pantalla);

        if (jugador.retornarY()>=y2 && jugador.retornarX()<=y1){
            if(jugador.retornarX()>=x2 && jugador.retornarY()<=x1){
                comidasa = true;
                jugador.crecer();
            }
        }


        jugador.dibujar(&pantalla);
        pantalla.display();





    }
    




    system("pause");

    return 0;
}