//
// Created by Alexis Jauregui on 9/13/15.
//

#include "Lives.h"

void Lives::Initialize() {
    texture.loadFromFile("media/lives.png");
    width = 48;


    this->lives = new sf::Sprite();
    this->lives->setTexture(texture);
    this->lives->setPosition(10,530);
    this->lives->scale(1.5,1.5);
    this->lives->setTextureRect(sf::IntRect(0,0,width,16));


}

void Lives::Update(puck *puck1, ghost *ghost1) {

    if(ghost1->sprite1.getGlobalBounds().intersects(puck1->rectangleShape1.getGlobalBounds())
            and !ghost1->fright)
    {
        width -= 16;
       this->lives->setTextureRect(sf::IntRect(0,0,width,16));
        puck1->pSprite->setPosition({210,295});

    }

    if(ghost1->sprite1.getGlobalBounds().intersects(puck1->rectangleShape1.getGlobalBounds())
        and ghost1->fright)
    {
        ghost1->reset = true;
    }





}

void Lives::Render(sf::RenderWindow* window) {
    window->draw(*this->lives);
}
