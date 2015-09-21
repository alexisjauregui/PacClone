//
// Created by Alexis Jauregui on 9/20/15.
//

#include "level2.h"


void level2::Initialize(sf::RenderWindow *window) {
    this->puck1 = new puck();
    this->puck1->initialize(window);
    this->score1 = new score();
    this->score1->Initialize(window);
    this->map1 = new map();
    this->map1->Initialize("maps/map2.txt");
    this->dots1 = new dots();
    this->dots1->Initialize("maps/dots2.txt");

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

    this->ghostai1 = new ghostai();
    this->ghostai1->Initialize(2);

    this->font = new sf::Font();
    this->font->loadFromFile("media/DroidSans.ttf");

    this->text1 = new sf::Text("Game Over",*this->font,70);
    this->text1->setOrigin(this->text1->getGlobalBounds().width/2,
                           this->text1->getGlobalBounds().height/2);
    this->text1->setPosition({448/2, 567/2});

    this->text2 = new sf::Text("Press Enter 2 Resume",*this->font,40);
    this->text2->setOrigin(this->text1->getGlobalBounds().width/2,
                           this->text1->getGlobalBounds().height/2+100);
    this->text2->setPosition({448/2, 567/2});


    paused = false;
    gameover = false;




}

void level2::Update(sf::RenderWindow *window) {


    this->score1->Update(window);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        quit_game = true;

    this->map1->Update(window,this->puck1);
    this->dots1->Update(this->puck1,window,this->score1);


    if(!gameover) {
        if (!paused) {
            this->puck1->Update(window);
            this->puck1->wakka->setVolume(100);
            this->red->Update(window, this->score1, 0);
            if (this->score1->number > 140)
                this->blue->Update(window, this->score1, 1);
            if (this->score1->number > 250)
                this->green->Update(window, this->score1,2);
            if (this->score1->number > 700)
                this->pink->Update(window, this->score1,3);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) and !keyPressed) {
                paused = true;
            }
        }
    }

    this->lives->Update(this->puck1,this->red);
    this->lives->Update(this->puck1,this->blue);
    this->lives->Update(this->puck1,this->pink);
    this->lives->Update(this->puck1,this->green);

    this->ghostai1->Update(this->red,0,window,this->puck1);
    this->ghostai1->Update(this->blue,1,window,this->puck1);
    this->ghostai1->Update(this->pink,2,window,this->puck1);
    this->ghostai1->Update(this->green,3,window,this->puck1);
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
    if(this->puck1->reset){
        std::cout<<"yo"<<std::endl;

        this->red->Initialiaze(0);
        this->blue->Initialiaze(1);
        this->green->Initialiaze(2);
        this->pink->Initialiaze(3);
        this->ghostai1->Initialize(1);
        this->puck1->initialize(window);
        if(!gameover)
            paused = true;
    }

}

void level2::Render(sf::RenderWindow *window) {
    this->map1->Render(window);
    this->dots1->Render(window);

    window->draw(*this->score1);
    if(!gameover) {
        this->lives->Render(window);
        this->red->Render(window);
        this->blue->Render(window);
        this->green->Render(window);
        this->pink->Render(window);
        this->puck1->Render(window);
    }




}

void level2::Destroy(sf::RenderWindow *window) {

    delete(this->puck1);

}
