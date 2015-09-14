//
// Created by Alexis Jauregui on 9/10/15.
//

#ifndef PACM_DOTS_H
#define PACM_DOTS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include "puck.h"
#include "score.h"



class checkdots : public sf::CircleShape
{
public:
    checkdots() {
        this->setRadius(2);
        this->setFillColor(sf::Color(0, 0, 255));

    }
    bool passed = false;

};


class dots {
public:
    std::vector<std::vector<int>> colmap;
    checkdots checkdots1[50][50];
    int finish;
    void Initialize(const char *filename);
    void Update(puck *puck1,sf::RenderWindow *window, score *score1);
    void Render(sf::RenderWindow* window);





};



#endif //PACM_DOTS_H
