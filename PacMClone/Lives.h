//
// Created by Alexis Jauregui on 9/13/15.
//

#ifndef PACM_LIVES_H
#define PACM_LIVES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "puck.h"
#include "ghost.h"


class Lives {
public:
    void Initialize();
    void Update(puck* puck1,ghost* ghost1);
    void Render(sf::RenderWindow* window);

    sf::Sprite* lives;
    sf::Texture texture;
    int width;


};


#endif //PACM_LIVES_H
