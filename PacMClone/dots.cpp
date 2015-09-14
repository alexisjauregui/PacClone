//
// Created by Alexis Jauregui on 9/10/15.
//

#include "dots.h"



void dots::Initialize(const char *filename) {

    std::ifstream openfile(filename);

    std::vector<int> tempmap;
    colmap.clear();
    finish = 0;

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

}

void dots::Update(puck *puck1, sf::RenderWindow *window,score *score1) {
    for(int i = 0; i< colmap.size();i++)
    {
        for(int j = 0; j < colmap[i].size();j++)
        {
            if(colmap[i][j] ==0)
            {
                int top, left;
                top = i*16;
                left = j*16;

                checkdots1[i][j].setPosition(left+5,top+8);

                if(puck1->pSprite->getGlobalBounds().intersects(checkdots1[i][j].getGlobalBounds())){
                    if(checkdots1[i][j].passed == false)
                    {
                        score1->number += 10;
                        finish++;
                    }

                    checkdots1[i][j].passed = true;
                    checkdots1[i][j].setFillColor(sf::Color(0,0,0,0));
                }

            }

            if(colmap[i][j] ==2)
            {
                int top, left;
                top = i*16;
                left = j*16;
                checkdots1[i][j].setPosition(left,top+2);
                checkdots1[i][j].setRadius(7);

                if(puck1->pSprite->getGlobalBounds().intersects(checkdots1[i][j].getGlobalBounds())){
                    if(checkdots1[i][j].passed == false)
                    {
                        score1->number += 10;
                        finish++;
                        score1->go =true;
                    }

                    checkdots1[i][j].passed = true;
                    checkdots1[i][j].setFillColor(sf::Color(0,0,0,0));

                }
            }
        }
    }



}

void dots::Render(sf::RenderWindow *window) {
    for(int i = 0; i< colmap.size();i++)
    {
        for(int j = 0; j < colmap[i].size();j++)
        {
            if(colmap[i][j] ==0) {
                window->draw(checkdots1[i][j]);
            }
            if(colmap[i][j] ==2) {
                window->draw(checkdots1[i][j]);
            }
        }
    }
}
