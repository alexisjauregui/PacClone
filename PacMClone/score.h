//
// Created by Alexis Jauregui on 9/7/15.
//

#ifndef PACM_SCORE_H
#define PACM_SCORE_H


#include <SFML/Graphics.hpp>
#include <iostream>

class score: public sf::Text {

public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    int number;
    bool go;
private:
    sf::Font* font1;


};


#endif //PACM_SCORE_H
