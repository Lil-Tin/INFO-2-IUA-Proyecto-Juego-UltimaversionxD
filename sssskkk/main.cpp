#include <iostream>
#include "vibora.h"
#include "comida.h"
#include <SFML/Graphics.hpp>
#include "vida.h"
#include "score.h"

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

    score Score;
    vida vidas;                //
    vidas.constructor();      //
    vibora jugador;          //Constructores.
    jugador.constructor();  //y aca creamos las variables para las clases
    comida Comida;         //
    Comida.constructor(); //

    int bida=4;
    bool Comer;
    Comer = true;
    int direccion=0; //Variables.

    /*Font font;
    font.loadFromFile("font.ttf");
    Text text;
    text.setFont(font);
    text.setPosition(200, 0);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setString("SCORE:");*/
    //pantalla.draw(text);




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



        Score.tiempo();
        jugador.moverse(direccion);
        pantalla.draw(sFondoDePantalla);
        Comida.dibujar(&pantalla);

        if (bida>=1){
        vidas.dibujar(&pantalla);
        } else {
            break;
        }

        Sprite aux3=Comida.retornarSprite();


        if (jugador.comio(aux3)){
            jugador.crecer();
            Score.gano();
            Comer = true;
        }


        if(jugador.detectarColisionesFondo() || jugador.choco() ){
            bida--;
            vidas.deletear();
            jugador.resetear();
            jugador.constructor();
            direccion = 0;
            Comer = true;

            sleep(milliseconds(1000));

        }

        if(bida>=1){
            jugador.dibujar(&pantalla,direccion);
        }else{
            pantalla.close();
        }
        pantalla.display();

    }

    return 0;
}