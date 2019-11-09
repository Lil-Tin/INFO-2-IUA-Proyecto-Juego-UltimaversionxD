//
// Created by martin skere on 5/11/2019.
//

#include "score.h"
#include <iostream>





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
