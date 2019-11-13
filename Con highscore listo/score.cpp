//
// Created by martin skere on 5/11/2019.
//

#include "score.h"
#include <iostream>
#include "textos.h"
#include <string>
#include <fstream>
#include "textos.h"
#include <stdlib.h>
//#include <list>





void score::tiempo() {
    cronometro = cronometro + 0.2;
    cronometrototal = cronometrototal + 0.2;
    std::cout<<cronometro<<std::endl;

}

void score::gano() {
    if (cronometro<=3){
        score = score + 500;

    }
    if (cronometro>3 && cronometro<6 ){
        score = score + 250;

    }
    score = score + 100;

    std::cout<<score<<std::endl;
    cronometro = 0;
}

 std::string score::devolverscore() {
    std::string stringScore;
    stringScore=std::to_string(score);
    return std::to_string(score);
}

void score::highscore() {
    int i=0, x=0;
    std::string r;
    int textoScoreInt=0;
    std::ifstream leerscores,leernombres;


    leerscores.open("textos/highscore.txt",std::ios::in);
    leernombres.open("textos/nombres.txt", std::ios::in);

    if(leerscores.fail() && leernombres.fail()){
        std::cout<<"No se pudo abrir"<<std::endl;
    } else {
        while (!leerscores.eof() && !leernombres.eof()){
            std::getline(leernombres, r);
            nombres.push_front(r);
            leerscores>>textoScoreInt;
            highscores.push_front(textoScoreInt);
            i++;
        }

    }
    cambiarListaHighScore();
    mostrarListaNombres();
    leernombres.close();
    leerscores.close();
}

void score::mostrarListaNombres() {
    std::list<int >::iterator pos;
    pos=highscores.begin();

    while (pos!=highscores.end()){
        std::cout<<*pos<<std::endl;
        pos++;
    }
    highscores.reverse();
}

void score::dibujarhigscore(RenderWindow *pantalla) {
    int i=0, aux1=100, aux2=125;
    std::string auxString;
    textos dibujarhigh;
    std::list<int >::iterator pos;
    pos=highscores.begin();
    while(i<10){
        auxString=std::to_string(*pos);
       dibujarhigh.constructor(aux1,aux2,22,auxString,Color::Red);
        pos++;
        aux2+=30;
        i++;
        dibujarhigh.dibujar(pantalla);
    }
}

void score::cambiarListaHighScore() {
        highscores.push_back(score);
        highscores.sort();
        highscores.pop_front();

}

void score::cambiarArchivos() {
    std::ofstream reescribirScore;
    reescribirScore.open("textos/highscore.txt", std::ios::out);
    std::list<int >::iterator pos;
    pos = highscores.begin();

    if (reescribirScore.fail()) {
        std::cout << "No se pudo abrir" << std::endl;
    } else {

        for (int i = 0; i < 10; i++) {
            reescribirScore<<*pos<<std::endl;
            pos++;
        }
    }            reescribirScore.close();
}



