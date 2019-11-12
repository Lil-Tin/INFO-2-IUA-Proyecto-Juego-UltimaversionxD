//
// Created by martin skere on 5/11/2019.
//

#ifndef PROYECTOSNAKE_SCORE_H
#define PROYECTOSNAKE_SCORE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "textos.h"
#include "LinkedList.h"


class score {
private:
    float cronometro , cronometrototal;
    int score=0;
    textos scoreMostrar;
    LinkedList<int> highscores;
    LinkedList<std::string> nombres;
public:
    void gano();
    void tiempo();
    std::string devolverscore();
    void highscore();
    void dibujarhigscore(RenderWindow *);

};


#endif //PROYECTOSNAKE_SCORE_H
