//
// Created by martin skere on 5/11/2019.
//

#ifndef PROYECTOSNAKE_SCORE_H
#define PROYECTOSNAKE_SCORE_H

#include <SFML/Graphics.hpp>
#include <string>
#include "textos.h"
#include <list>

class score {
private:
    float cronometro , cronometrototal;
    int score=0;
    std::list <int >highscores;
    std::list<std::string> nombres;  // no estan implementados.

public:
    void gano();
    void tiempo();
    std::string devolverscore();
    void highscore();
    void dibujarhigscore(RenderWindow *);
    void mostrarListaNombres(); // <--- (mostrar lista de highscore)
    void cambiarListaHighScore(); // <-----(Pone el score actual en la lista, la ordena,
                                 //         y elimina el elemento mas chico)
    void cambiarArchivos();
};


#endif //PROYECTOSNAKE_SCORE_H
