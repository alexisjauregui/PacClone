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
            velocity.x = -2;
            velocity.y = 0;
            break;
        case 1:
            texture1.loadFromFile("media/blue.png");
            startPos.x = 175;
            startPos.y = 250;
            velocity.x = 0;
            velocity.y = 0;
            break;
        case 2:
            texture1.loadFromFile("media/green.png");
            //240
            startPos.x = 240;
            startPos.y = 250;
            velocity.x = 0;
            velocity.y = 0;
            break;
        case 3:
            texture1.loadFromFile("media/pink.png");
            //208
            startPos.x = 208;
            startPos.y = 250;
            velocity.x = 0;
            velocity.y = 0;
            break;
        default:
            break;
    }

    sprite1.setTexture(texture1);
    sprite1.setPosition(startPos);
    sprite1.setTextureRect(sf::IntRect(0, 0, 32, 32));

    scared.loadFromFile("media/ghostV.png");


    clock2.restart();
    resetClock = true;
    yo= true;
}

void ghost::Update(sf::RenderWindow *window,score* score1,int i) {

    frameCounter += frameSpeed * clock1.restart().asSeconds();
    if (frameCounter >= switchFrame)
    {
        frameCounter = 0;
        source.x++;
        if (source.x * 32 >= texture1.getSize().x)
            source.x = 0;
    }

    sprite1.setTextureRect(sf::IntRect(source.x * 32, source.y * 32, 32, 32));
    sprite1.move(velocity);

//Power Pellet Mode
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

   switch (i){
       case 0:
           if(sprite1.getPosition().x == 208 and sprite1.getPosition().y == 200 ) {
               velocity.x = -2;
           }
           break;
       case  1:
           if(sprite1.getPosition().x == 175 and sprite1.getPosition().y == 250 ){
               sprite1.setPosition({208,200});
               velocity.x = -2;
           }
           break;
       case 2:
           if(sprite1.getPosition().x == 240 and sprite1.getPosition().y == 250 ){
               sprite1.setPosition({208,200});
               velocity.x = 2;
           }
           break;
       case 3:
           if(sprite1.getPosition().x == 208 and sprite1.getPosition().y == 250 ){
               sprite1.setPosition({207,200});
               velocity.x = -2;
           }
           break;
       default:
           break;
   }


    if(reset) {
        sprite1.setPosition({startPos.x + 1, startPos.y + 1});
        velocity.x = 0;
        velocity.y = 0;
        if (resetClock) {
            clock3.restart();
            resetClock = false;
        }
        if(clock3.getElapsedTime().asSeconds() > 7)
        {
            sprite1.setPosition(startPos);
            resetClock = true;
            reset = false;
        }
    }


}

void ghost::Render(sf::RenderWindow *window) {
    window->draw(sprite1);

}
