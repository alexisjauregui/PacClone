//
// Created by Alexis Jauregui on 9/10/15.
//

#ifndef PACM_MAP_H
#define PACM_MAP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "puck.h"


class map {
public:
    void Initialize(const char* filename);
    void Update(sf::RenderWindow* window,puck *puck1);
    void Render(sf::RenderWindow* window);

    std::vector<std::vector<int>>colmap;
    sf::RectangleShape colrect;

private:
    sf::Texture tileText;
    sf::Sprite tiles;


    std::vector<std::vector<sf::Vector2i>>map;
    std::vector<sf::Vector2i> tempmap;



};


#endif //PACM_MAP_H
