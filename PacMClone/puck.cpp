//
// Created by Alexis Jauregui on 9/7/15.
//

#include "puck.h"

void puck::initialize(sf::RenderWindow *window) {
    source.x= 32;
    source.y =Left;
    this->clock1 = new sf::Clock();

    if(!pTexture.loadFromFile("media/puck3.png"))
        std::cout<<"Image not found for player"<<std::endl;

    this->pSprite = new sf::Sprite();
    this->pSprite->setTexture(pTexture);
    this->pSprite->setPosition(210,295);

    this->velocity = new sf::Vector2f({-3,0});

    rectangleShape1.setPosition(this->pSprite->getPosition().x+12,
                                this->pSprite->getPosition().y+12);
    rectangleShape1.setSize({8,8});
    rectangleShape1.setFillColor(sf::Color::Red);

    if (!buffer.loadFromFile("media/pacman_chomp.wav"))
        std::cout<<"nope"<<std::endl;
    this->wakka = new sf::Sound();
    this->wakka->setBuffer(buffer);
    this->wakka->play();
    this->wakka->setLoop(true);
    this->pSprite->setTextureRect(sf::IntRect(0,0,32,32));
    reset = false;
}

void puck::Update(sf::RenderWindow *window) {

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        source.y = Down;
        this->velocity->x = 0;
        this->velocity->y = -3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        source.y = Up;
        this->velocity->x = 0;
        this->velocity->y = 3;

    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        source.y = Left;
        this->velocity->y = 0;
        this->velocity->x = -3;
    }
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        source.y = Right;
        this->velocity->y = 0;
        this->velocity->x = 3;
    }

    this->pSprite->move({velocity->x,velocity->y});
    if(this->velocity->x != 0 && this->velocity->y !=0){

    }
    frameCounter += frameSpeed * this->clock1->restart().asSeconds();
    if(frameCounter>=switchFrame)
    {
        frameCounter = 0;
        source.x++;
        if(source.x * 32 >= pTexture.getSize().x)
            source.x=0;

    }


    if(this->velocity->x == 0 and this->velocity->y==0){
        this->wakka->setLoop(false);
    }else{
        if(!this->wakka->getLoop()){
            this->wakka->setLoop(true);
            this->wakka->play();
        }

    }
    this->pSprite->setTextureRect(sf::IntRect(source.x * 32,source.y * 32,32,32));
    rectangleShape1.setPosition(this->pSprite->getPosition().x+12,
                                this->pSprite->getPosition().y+12);

    if(this->pSprite->getPosition().x < 0){
        this->pSprite->setPosition(411,this->pSprite->getPosition().y);
    }
    if(this->pSprite->getPosition().x > 448){
        this->pSprite->setPosition(0,this->pSprite->getPosition().y);
    }
 }




void puck::Render(sf::RenderWindow *window) {
    window->draw(*this->pSprite);
    //window->draw(rectangleShape1);

}
