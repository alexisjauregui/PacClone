//
// Created by Alexis Jauregui on 9/17/15.
//

#ifndef PACM_GHOSTAI_H
#define PACM_GHOSTAI_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "ghost.h"
#include "puck.h"


class ghostai{
public:
    std::vector<std::vector<int>> colmap;
    const char* map;
    void Initialize(int level);
    void changeDes(puck* puck1,int i);
    void Update(ghost* ghost1, int i,sf::RenderWindow* window,puck* puck1);



    sf::RectangleShape intersect[50][50];
    sf::Vector2f targetPos;
    sf::Clock clock1;
    bool chase;
    int seconds;

};


#endif //PACM_GHOSTAI_H
