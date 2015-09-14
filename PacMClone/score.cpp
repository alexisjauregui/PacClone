//
// Created by Alexis Jauregui on 9/7/15.
//

#include "score.h"

void score::Initialize(sf::RenderWindow *window) {
    this->font1 = new sf::Font();
    this->setString("Score:"+ std::to_string(number));
    if (!this->font1->loadFromFile("media/DroidSans.ttf"))
    {
        std::cout<<"font not found"<< std::endl;
    }
    this->setPosition(window->getSize().x/2-75,5);
    this->setFont(*font1);
    this->setCharacterSize(16);
    number = 0;

}


void score::Update(sf::RenderWindow *window) {
    this->setString("Score:"+ std::to_string(number));




}

