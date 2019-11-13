//
// Created by martin skere on 5/11/2019.
//

#include "score.h"
#include <iostream>
#include "textos.h"
#include <string>
#include <fstream>
#include "textos.h"





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
    std::ifstream leerscores,leernombres;

    std::string texto;
    leerscores.open("textos/highscore.txt",std::ios::in);
    leernombres.open("textos/nombres.txt", std::ios::in);

    if(leerscores.fail() && leernombres.fail()){
        std::cout<<"No se pudo abrir"<<std::endl;
    } else {
        while (!leerscores.eof() && !leernombres.eof()){
            std::getline(leernombres, r);
            nombres.put(r, i);
            std::getline(leerscores, texto);
            x = std::stoi(texto);
            highscores.put(x, i);
            i++;
            std::cout<<"se pudo"<<std::endl;
        }

    }
    std::cout<<"se pudo 2"<<std::endl;

    i=0, x=0;
    int aux=0, aux2=0;

    while(i!=highscores.size() ){
        x=highscores.get(i);
        std::cout<<"entro al while"<<std::endl;
        if(score>=x){
            std::cout<<"entro al if"<<std::endl;
            highscores.put(score, i);
            std::cout<<highscores.get(i)<<std::endl;
            aux=i+1;
            while(aux<=highscores.size()){
                std::cout<<"entro al while del if"<<std::endl;
                aux2=highscores.get(aux);
                highscores.put(x, aux);
                x=aux2;
                std::cout<<highscores.get(aux)<<std::endl;
                aux=aux+1;
            } if (aux>10){
                highscores.remove(aux);
                break;
            }
            i=i+100;

        }

        std::cout<<"listo"<<std::endl;
        i=i+1;

    }

    aux=200, aux2=100;
    i=0;
    std::string str="";
    textos dibujahigh;


}

void score::dibujarhigscore(RenderWindow *pantalla) {
    int i=0, aux=220, aux2=150;
    std::string str;
    textos dibujahigh;

    while(i!=highscores.size()){
        str=std::to_string(score);
        dibujahigh.constructor(aux, aux2, 24, str, Color::Red);
        dibujahigh.dibujar(pantalla);
        aux2=aux2-30;
    }

}





