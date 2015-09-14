//
// Created by Alexis Jauregui on 8/4/15.
//

#include "main_state.h"
void main_state::Initialize(sf::RenderWindow* window)
{

    this->selected = 0;

    this->font= new sf::Font();
    this->font->loadFromFile("media/PacFont.ttf");

    this->title = new sf::Text("Pac-Dude",*this->font,40U);
    this->title->setOrigin(this->title->getGlobalBounds().width/2,this->title->getGlobalBounds().height/2);
    this->title->setPosition(window->getSize().x/2,window->getSize().y/8);


    this->quit = new sf::Text("Quit",*this->font,30U);
    this->quit->setOrigin(this->quit->getGlobalBounds().width/2,this->quit->getGlobalBounds().height/2);
    this->quit->setPosition(window->getSize().x/2,window->getSize().y*.80);

    this->play = new sf::Text("Play",*this->font,30U);
    this->play->setOrigin(this->play->getGlobalBounds().width/2,this->play->getGlobalBounds().height/2);
    this->play->setPosition(window->getSize().x/2,window->getSize().y*.70);


    this->texture = new sf::Texture();
    this->texture->loadFromFile("media/cover.png");

    this->sprite = new sf::Sprite();
    this->sprite->setTexture(*this->texture);
    this->sprite->setOrigin(this->sprite->getGlobalBounds().width/2,this->sprite->getGlobalBounds().height/2);
    this->sprite->setColor(sf::Color(255, 255, 255, 200));
    this->sprite->setScale(.75,.75);
    this->sprite->setPosition(window->getSize().x/2,window->getSize().y/2);
}

void main_state::Update(sf::RenderWindow* window)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) and !this->upKey){
        this->selected -= 1;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) and !this->downKey){
        this->selected += 1;
    }
    if(selected < 0){
        this->selected = 1;
    }
    if(selected > 1){
        this->selected = 0;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return)){
        switch (this->selected) {
            case 0:
                coreState.set_state(new pac_game());
                break;
            case 1:
                quit_game = true;
                break;
        }
    }

    this->upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
    this->downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);


}
void main_state::Render(sf::RenderWindow* window){


    this->title->setColor(sf::Color::Yellow);
    this->quit->setColor(sf::Color::White);
    this->play->setColor(sf::Color::White);


    switch (this->selected) {
        case 0:
            this->play->setColor(sf::Color::Red);
            break;
        case 1:
            this->quit->setColor(sf::Color::Red);
            break;

    }

    window->draw(*this->sprite);
    window->draw(*this->title);
    window->draw(*this->quit);
    window->draw(*this->play);


}
void main_state::Destroy(sf::RenderWindow* window){

    delete this->font;
    delete this->title;
    delete this->quit;
    delete this->play;
    delete this->sprite;


}