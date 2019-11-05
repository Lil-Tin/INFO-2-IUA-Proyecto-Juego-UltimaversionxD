//
// Created by Matias on 26/10/2019.
//

#ifndef PRUEBA1_VIBORA_H
#define PRUEBA1_VIBORA_H
#include <SFML/Graphics.hpp>

using namespace sf;

class vibora {
private:
    Sprite sVibora;
    Texture tVibora;




     struct movimiento{
         float posicionX;   //Para la "telestransportacion de la vibora".
         float posicionY;
         movimiento *sig;
        }*frente, *fondo;

public:
    void constructor( );
    void dibujar(RenderWindow *,int);
    void moverse(int);
    void crecer( );

    bool comio(Sprite);
    bool choco();

    void resetear();

    bool detectarColisionesFondo();

};


#endif //PRUEBA1_VIBORA_H
