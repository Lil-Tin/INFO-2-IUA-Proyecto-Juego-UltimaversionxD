//
// Created by martin skere on 5/11/2019.
//

#ifndef PROYECTOSNAKE_SCORE_H
#define PROYECTOSNAKE_SCORE_H

#include <string>
#include "textos.h"


class score {
private:
    float cronometro , cronometrototal;
    int score=0;
    textos scoreMostrar;
public:
    void gano();
    void tiempo();
    std::string devolverscore();

};


#endif //PROYECTOSNAKE_SCORE_H
