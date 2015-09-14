//
// Created by Alexis Jauregui on 9/10/15.
//

#include "ghost.h"

void ghost::Initialiaze(int i) {
    source.x = 32;
    source.y = 0;
    switch(i){
        case 0:
            texture1.loadFromFile("media/ghost.png");
            startPos.x = 208;
            startPos.y = 200;
            break;
        case 1:
            texture1.loadFromFile("media/blue.png");
            //175
            startPos.x = 90;
            startPos.y = 250;
            break;
        case 2:
            texture1.loadFromFile("media/green.png");
            //240
            startPos.x = 350;
            startPos.y = 250;
            break;
        case 3:
            texture1.loadFromFile("media/pink.png");
            //208
            startPos.x = 208;
            startPos.y = 487;
            break;
        default:
            break;
    }

    sprite1.setTexture(texture1);
    sprite1.setPosition(startPos);

    scared.loadFromFile("media/ghostV.png");

    clock2.restart();
    yo= true;
}

void ghost::Update(sf::RenderWindow *window,score* score1) {

    frameCounter += frameSpeed * clock1.restart().asSeconds();
    if (frameCounter >= switchFrame)
    {
        frameCounter = 0;
        source.x++;
        if (source.x * 32 >= texture1.getSize().x)
            source.x = 0;
    }

    sprite1.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));

    if(score1->go)
    {
        if(yo){
            temp = clock2.getElapsedTime().asSeconds();
            yo = false;

        }

        if(clock2.getElapsedTime().asSeconds()<temp+4){
            sprite1.setTexture(scared);
            fright = true;

        }else{
            yo=true;
            score1->go = false;


        }


    }else{
        sprite1.setTexture(texture1);
        clock2.restart().asSeconds();
        fright = false;
    }

    if(reset){
        sprite1.setPosition({0,0});
        reset = false;
    }

}

void ghost::Render(sf::RenderWindow *window) {
    window->draw(sprite1);

}
