//
// Created by Alexis Jauregui on 9/17/15.
//

#include "ghostai.h"

void ghostai::Initialize(int level) {
    if(level == 1)
    {
       map = "maps/colmap.txt";
    }else if(level == 2){
        map = "maps/comap2.txt";
    }else{
        map = "maps/colmap.txt";
    }
    std::ifstream openfile(map);

    std::vector<int> tempmap;
    colmap.clear();

    if(openfile.is_open())
    {

        while (!openfile.eof()) {
            std::string string1, value;
            std::getline(openfile,string1);
            std::stringstream stream(string1);

            while(std::getline(stream,value,' ')) {
                if (value.length() > 0) {
                    int a = atoi(value.c_str());
                    tempmap.push_back(a);

                }
            }

            colmap.push_back(tempmap);
            tempmap.clear();
        }
    }
    clock1.restart();
    chase = true;
    seconds = 20;

}

void ghostai::changeDes(puck* puck1, int i) {

    if(clock1.getElapsedTime().asSeconds()>seconds)
    {

        if(chase){
            std::cout<<"change position to chase"<<std::endl;
            seconds = 22;
            chase = false;
        }else{
            std::cout<<"change position to scatter"<<std::endl;
            seconds = 7;
            chase = true;
        }

        clock1.restart();

    }

    if(!chase){
        // Case 0 = red, 1 = blue, 2 = green , 3 = pink .
        switch(i){
            case 0:
                targetPos.x = puck1->pSprite->getPosition().x;
                targetPos.y = puck1->pSprite->getPosition().y;
            case 1:
                if(puck1->velocity->x == 2){
                    targetPos.x = puck1->pSprite->getPosition().x+ 48;
                    targetPos.y = puck1->pSprite->getPosition().y - 32;
                }else if(puck1->velocity->x == -2){
                    targetPos.x = puck1->pSprite->getPosition().x- 48;
                    targetPos.y = puck1->pSprite->getPosition().y- 32 ;
                }else{
                    if(puck1->velocity->y ==2){
                        targetPos.x = puck1->pSprite->getPosition().x -32;
                        targetPos.y = puck1->pSprite->getPosition().y+42;
                    }else{
                        targetPos.x = puck1->pSprite->getPosition().x + 32;
                        targetPos.y = puck1->pSprite->getPosition().y-42 ;
                    }
                }
                break;
            case 2:
                targetPos.x = random();
                targetPos.y = random();

                break;
            case 3:
                if(puck1->velocity->x == 2){
                    targetPos.x = puck1->pSprite->getPosition().x+ 32;
                    targetPos.y = puck1->pSprite->getPosition().y ;
                }else if(puck1->velocity->x == -2){
                    targetPos.x = puck1->pSprite->getPosition().x- 32;
                    targetPos.y = puck1->pSprite->getPosition().y ;
                }else{
                    if(puck1->velocity->y ==2){
                        targetPos.x = puck1->pSprite->getPosition().x;
                        targetPos.y = puck1->pSprite->getPosition().y+32;
                    }else{
                        targetPos.x = puck1->pSprite->getPosition().x;
                        targetPos.y = puck1->pSprite->getPosition().y-32 ;
                    }
                }
                break;
            default:
                break;
        }
    }else{
        switch(i) {
            case 0:
                //top right
                targetPos.x = 400;
                targetPos.y = 10;
                break;
            case 1:
                // Bottom left
                targetPos.x = 100;
                targetPos.y = 500;
                break;
            case 2:
                //bottom right
                targetPos.x = 400;
                targetPos.y = 500;
                break;
            case 3:
                //top left
                targetPos.x = 000;
                targetPos.y = 00;
                break;
            default:
                break;
        }

    }


}

void ghostai::Update(ghost *ghost1, int i, sf::RenderWindow* window,puck* puck1) {

    changeDes(puck1,i);

    for(int i = 0; i< colmap.size();i++) {
        for (int j = 0; j < colmap[i].size(); j++) {
            if (colmap[i][j] == 2)
            {
                int top, left;
                top = i * 16;
                left = j * 16;

                intersect[i][j].setPosition(left+8, top+8);
                intersect[i][j].setSize({1, 1});
                intersect[i][j].setFillColor(sf::Color::Red);
                //window->draw(intersect[i][j]);

                if (ghost1->sprite1.getGlobalBounds().intersects(intersect[i][j].getGlobalBounds()))
                {
                    intersect[i][j].setFillColor(sf::Color::Blue);

                    ghost1->sprite1.move(left-ghost1->sprite1.getPosition().x-8,top-ghost1->sprite1.getPosition().y-8);
                    //Left WAll
                    if(colmap[i][j-1]== 1)
                    {
                        // top and left corner
                        if(colmap[i-1][j]== 1)
                        {

                            if(ghost1->velocity.x==-2){
                                ghost1->sprite1.move(0,16);
                                ghost1->velocity.x = 0;
                                ghost1->velocity.y = 2;
                            }else {
                                ghost1->sprite1.move(16, 0);
                                ghost1->velocity.x = 2;
                                ghost1->velocity.y = 0;
                            }
                            //left only
                        }
                        //if bottom left
                        else if(colmap[i+1][j]== 1)
                        {
                            if(ghost1->velocity.x==-2){
                                ghost1->sprite1.move(0,-16);
                                ghost1->velocity.x = 0;
                                ghost1->velocity.y = -2;
                            }else {
                                ghost1->sprite1.move(16, 0);
                                ghost1->velocity.x = 2;
                                ghost1->velocity.y = 0;
                            }
                            // three direction left wall
                        }else{
                            if(ghost1->velocity.y == 0)
                            {
                                // decide up or down
                                if(targetPos.y<ghost1->sprite1.getPosition().y){
                                    ghost1->sprite1.move(0,-16);
                                    ghost1->velocity.x = 0;
                                    ghost1->velocity.y = -2;
                                }else{
                                    ghost1->sprite1.move(0,16);
                                    ghost1->velocity.x = 0;
                                    ghost1->velocity.y = 2;
                                }
                            }else if(ghost1->velocity.y == 2){
                                //down or right
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                {
                                    ghost1->sprite1.move(16, 0);
                                    ghost1->velocity.x = 2;
                                    ghost1->velocity.y = 0;

                                }else{
                                    ghost1->sprite1.move(0,16);
                                }


                            }else{
                                // up or right
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                {
                                    ghost1->sprite1.move(16, 0);
                                    ghost1->velocity.x = 2;
                                    ghost1->velocity.y = 0;

                                }else{
                                    ghost1->sprite1.move(0,-16);
                                }

                            }

                        }



                    }
                    //Right Wall
                    else if(colmap[i][j+1]== 1)
                    {
                        if(colmap[i-1][j]== 1)
                        {

                            if(ghost1->velocity.x== 2){
                                ghost1->sprite1.move(0,16);
                                ghost1->velocity.x = 0;
                                ghost1->velocity.y = 2;
                            }else {
                                ghost1->sprite1.move(-16, 0);
                                ghost1->velocity.x = -2;
                                ghost1->velocity.y = 0;
                            }

                        }
                        else if(colmap[i+1][j]== 1)
                        {

                            if(ghost1->velocity.x==2){
                                ghost1->sprite1.move(0,-16);
                                ghost1->velocity.x = 0;
                                ghost1->velocity.y = -2;
                            }else {
                                ghost1->sprite1.move(-16, 0);
                                ghost1->velocity.x = -2;
                                ghost1->velocity.y = 0;
                            }
                        }else{
                            //threeway right wall

                            if(ghost1->velocity.y == 0)
                            {
                                // decide up or down
                                if(targetPos.y<ghost1->sprite1.getPosition().y){
                                    ghost1->sprite1.move(0,-16);
                                    ghost1->velocity.x = 0;
                                    ghost1->velocity.y = -2;
                                }else{
                                    ghost1->sprite1.move(0,16);
                                    ghost1->velocity.x = 0;
                                    ghost1->velocity.y = 2;
                                }
                            }else if(ghost1->velocity.y == 2){
                                //down or left
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                {
                                    ghost1->sprite1.move(-16, 0);
                                    ghost1->velocity.x = -2;
                                    ghost1->velocity.y = 0;

                                }else{
                                    ghost1->sprite1.move(0,16);
                                }


                            }else{
                                // up or right
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                {
                                    ghost1->sprite1.move(-16, 0);
                                    ghost1->velocity.x = -2;
                                    ghost1->velocity.y = 0;

                                }else{
                                    ghost1->sprite1.move(0,-16);
                                }

                            }
                        }

                    //No Right or left wall
                    }else
                    {
                        //bottom is a wall
                        if(colmap[i+1][j]==1)
                        {
                            //left or right
                            if(ghost1->velocity.y == 2)
                            {
                                if(targetPos.x<ghost1->sprite1.getPosition().x){
                                    //left
                                    ghost1->sprite1.move(-16,0);
                                    ghost1->velocity.x = -2;
                                    ghost1->velocity.y = 0;
                                }else{
                                    //right
                                    ghost1->sprite1.move(16,0);
                                    ghost1->velocity.x = 2;
                                    ghost1->velocity.y = 0;
                                }
                            }else{
                                if(ghost1->velocity.x == 2)
                                {
                                    // top or right
                                    if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                       std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                    {
                                     //right
                                     ghost1->sprite1.move(16,0);

                                    }else{
                                       // top
                                       ghost1->sprite1.move(0, -16);
                                        ghost1->velocity.x =0;
                                        ghost1->velocity.y = -2;

                                    }
                                }else{
                                    // top or left
                                    if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                       std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                    {
                                        //left
                                        ghost1->sprite1.move(-16,0);

                                    }else{
                                        // top
                                        ghost1->sprite1.move(0, -16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = -2;

                                    }

                                }
                            }

                        //top is wall
                        }else if(colmap[i-1][j] == 1)
                        {
                            if(ghost1->velocity.y == -2)
                            {
                                if(targetPos.x<ghost1->sprite1.getPosition().x){
                                    ghost1->sprite1.move(-16,0);
                                    ghost1->velocity.x = -2;
                                    ghost1->velocity.y = 0;
                                }else{
                                    ghost1->sprite1.move(16,0);
                                    ghost1->velocity.x = 2;
                                    ghost1->velocity.y = 0;
                                }
                            }else{
                                if(ghost1->velocity.x == 2)
                                {
                                    // bottom or right
                                    if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                       std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                    {
                                        //right
                                        ghost1->sprite1.move(16,0);

                                    }else{
                                        // bottom
                                        ghost1->sprite1.move(0, 16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = 2;

                                    }

                                }else{
                                    // bottom or left;
                                    if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                       std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                    {
                                        //left
                                        ghost1->sprite1.move(-16,0);

                                    }else{
                                        // bottom
                                        ghost1->sprite1.move(0,16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = 2;

                                    }

                                }
                            }

                        //Four Way intersection
                        }else
                        {
                            if(ghost1->velocity.y == 2){
                               //if down: left right or down
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                {
                                    // left or right
                                    if(targetPos.x<ghost1->sprite1.getPosition().x){
                                        ghost1->sprite1.move(-16,0);
                                        ghost1->velocity.x = -2;
                                        ghost1->velocity.y = 0;
                                    }else{
                                        ghost1->sprite1.move(16,0);
                                        ghost1->velocity.x = 2;
                                        ghost1->velocity.y = 0;
                                    }
                                }else{
                                    // keep going down
                                    ghost1->sprite1.move(0,16);
                                }

                            // up: left right or up
                            }else if(ghost1->velocity.y == -2){
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y))
                                { // left or right
                                    if(targetPos.x<ghost1->sprite1.getPosition().x){
                                        ghost1->sprite1.move(-16,0);
                                        ghost1->velocity.x = -2;
                                        ghost1->velocity.y = 0;
                                    }else{
                                        ghost1->sprite1.move(16,0);
                                        ghost1->velocity.x = 2;
                                        ghost1->velocity.y = 0;
                                    }
                                }else{
                                    // keep going up
                                    ghost1->sprite1.move(0,-16);
                                }

                            // right: up down or right
                            }else if(ghost1->velocity.x == 2){
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y)){
                                    //right
                                    ghost1->sprite1.move(16,0);
                                }else{
                                    // up or down
                                    if(targetPos.y<ghost1->sprite1.getPosition().y){
                                        ghost1->sprite1.move(0,-16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = -2;
                                    }else{
                                        ghost1->sprite1.move(0,16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = 2;
                                    }

                                }

                            } else if(ghost1->velocity.x == -2){
                                if(std::fabs(ghost1->sprite1.getPosition().x-targetPos.x)>
                                   std::fabs(ghost1->sprite1.getPosition().y-targetPos.y)){
                                    //left
                                    ghost1->sprite1.move(-16,0);
                                }else{
                                    // up or down
                                    if(targetPos.y<ghost1->sprite1.getPosition().y){
                                        ghost1->sprite1.move(0,-16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = -2;
                                    }else{
                                        ghost1->sprite1.move(0,16);
                                        ghost1->velocity.x = 0;
                                        ghost1->velocity.y = 2;
                                    }

                                }
                            }



                        }

                    }


                }

            }
        }
    }

}

