//
// Created by Alexis Jauregui on 9/10/15.
//

#ifndef PACM_GHOST_H
#define PACM_GHOST_H


#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "score.h"

class ghost {
public:
    void Initialiaze(int i);
    void Update(sf::RenderWindow* window,score* score1);
    void Render(sf::RenderWindow* window);

    float frameCounter = 0, switchFrame = 100, frameSpeed = 750;
    sf::Clock clock1;
    sf::Texture texture1;
    sf::Texture scared;
    sf::Sprite sprite1;
    sf::Vector2i source;
    sf::Clock clock2;
    sf::Vector2f startPos;

    bool yo;
    bool fright;
    bool reset;
    float temp;


};


#endif //PACM_GHOST_H
