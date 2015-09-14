//
// Created by Alexis Jauregui on 8/7/15.
//

#include "pac_game.h"

void pac_game::Initialize(sf::RenderWindow *window) {
    this->puck1 = new puck();
    this->puck1->initialize(window);
    this->score1 = new score();
    this->score1->Initialize(window);
    this->map1 = new map();
    this->map1->Initialize("maps/map1.txt");
    this->dots1 = new dots();
    this->dots1->Initialize("maps/dots.txt");

    this->red = new ghost();
    this->red->Initialiaze(0);
    this->blue = new ghost();
    this->blue->Initialiaze(1);
    this->green = new ghost();
    this->green->Initialiaze(2);
    this->pink = new ghost();
    this->pink->Initialiaze(3);

    this->lives = new Lives();
    this->lives->Initialize();

    this->font = new sf::Font();
    this->font->loadFromFile("media/DroidSans.ttf");

    this->text1 = new sf::Text("Game Over",*this->font,70);
    this->text1->setOrigin(this->text1->getGlobalBounds().width/2,
                           this->text1->getGlobalBounds().height/2);
    this->text1->setPosition({448/2, 567/2});

    this->text2 = new sf::Text("Press Enter 2 Resume",*this->font,40);
    this->text2->setOrigin(this->text1->getGlobalBounds().width/2,
                           this->text1->getGlobalBounds().height/2);
    this->text2->setPosition({448/2, 567/2});


    paused = false;
    gameover = false;




}

void pac_game::Update(sf::RenderWindow *window) {


    this->score1->Update(window);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        quit_game = true;

    this->map1->Update(window,this->puck1);
    this->dots1->Update(this->puck1,window,this->score1);


    if(!gameover) {
        if (!paused) {
            this->puck1->Update(window);
            this->puck1->wakka->setVolume(100);
            this->red->Update(window, this->score1);
            this->blue->Update(window, this->score1);
            this->green->Update(window, this->score1);
            this->pink->Update(window, this->score1);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and !keyPressed) {
                paused = true;
            }
        }
    }

    this->lives->Update(this->puck1,this->red);
    this->lives->Update(this->puck1,this->blue);
    this->lives->Update(this->puck1,this->pink);
    this->lives->Update(this->puck1,this->green);

// Reset stuff
    if(paused) {
        window->draw(*this->text2);
        this->puck1->wakka->setVolume(0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
            paused = false;
        }
    }

    keyPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);


    if(this->lives->width < 1 ){
        window->draw(*this->text1);
        gameover = true;
        this->puck1->wakka->setVolume(0);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            coreState.set_state(new main_state());

    }


    if(dots1->finish == 246){
        coreState.set_state(new main_state());
    }

}

void pac_game::Render(sf::RenderWindow *window) {
    this->map1->Render(window);
    this->dots1->Render(window);

    window->draw(*this->score1);
    if(!gameover) {
        if (!paused) {
            this->puck1->Render(window);
            this->red->Render(window);
            this->blue->Render(window);
            this->green->Render(window);
            this->pink->Render(window);
        }
    }
    this->lives->Render(window);


}

void pac_game::Destroy(sf::RenderWindow *window) {

    delete(this->puck1);

}
