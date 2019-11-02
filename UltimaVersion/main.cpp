#include <iostream>
#include "vibora.h"
#include "comida.h"
#include <SFML/Graphics.hpp>
using namespace sf;


int main() {
    srand(time(NULL));
    RenderWindow pantalla(VideoMode(640,480), "ProyectoSnake");
    pantalla.setFramerateLimit(15);
    pantalla.getSize();

    Texture tFondoDePantalla;
    Sprite sFondoDePantalla;
    tFondoDePantalla.loadFromFile("IMAGENES/fondodepantalla.png");
    sFondoDePantalla.setTexture(tFondoDePantalla);

    vibora jugador;
    jugador.constructor();
    comida Comida;          //Constructores.
    Comida.constructor();
     //Retorna el sprite y una funcion del SFML va a armar la colision.

    bool Comer=true;
    int direccion=0; //Variables.





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
        if (Comer){
            Comida.setearposicion();
            Comer = false;
        }



        std::cout<<direccion<<std::endl;
        jugador.moverse(direccion);
        pantalla.draw(sFondoDePantalla);
        Comida.dibujar(&pantalla);
        Sprite aux3=Comida.retornarSprite();

        if (jugador.comio(aux3)){
            jugador.crecer();
            Comer = true;
        }

        if (jugador.choco()){
            std::cout<<"NOse jaja"<<std::endl;
        }

        if(jugador.detectarColisionesFondo()==true){
           std::cout<<"FUERAFUERAFUERAFUERA"<<std::endl;
        }

        jugador.dibujar(&pantalla,direccion);
        pantalla.display();

    }

    return 0;
}