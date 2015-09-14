//
// Created by Alexis Jauregui on 9/10/15.
//

#include "map.h"

void map::Initialize(const char* filename) {


    std::ifstream openfile(filename);

    if(openfile.is_open())
    {
        std::string tileLocation;
        openfile >> tileLocation;
        tileText.loadFromFile(tileLocation);
        tiles.setTexture(tileText);
        while (!openfile.eof()) {
            std::string string1, value;
            std::getline(openfile,string1);
            std::stringstream stream(string1);

            while(std::getline(stream,value,' ')) {
                if (value.length() > 0) {
                    std::string xVal = value.substr(0, value.find(','));
                    std::string yVal = value.substr(value.find(',') + 1);

                    int x, y, i, j;

                    for (i = 0; i < xVal.length(); i++) {
                        if (!isdigit(xVal[i]))
                            break;

                    }
                    for (j = 0; j < yVal.length(); j++) {
                        if (!isdigit(yVal[j]))
                            break;
                    }
                    x = (i == xVal.length()) ? atoi(xVal.c_str()) : -1;
                    y = (i == yVal.length()) ? atoi(yVal.c_str()) : -1;
                    tempmap.push_back(sf::Vector2i(x, y));
                }
            }
            if(tempmap.size()>0) {
                map.push_back(tempmap);
                tempmap.clear();
            }
        }
    }

}

void map::Update(sf::RenderWindow *window,puck *puck1) {
    for(int i = 0;i <map.size();i++)
    {
        for(int j = 0; j<map[i].size();j++){
            if(map[i][j].x != -1 and map[i][j].y != -1 ){
                tiles.setPosition(j*16,i*16);
                tiles.setTextureRect(sf::IntRect(map[i][j].x*16,map[i][j].y*16,16,16));
                window->draw(tiles);

                if(tiles.getGlobalBounds().intersects(puck1->rectangleShape1.getGlobalBounds())){
                    puck1->pSprite->move(puck1->velocity->x*-1,puck1->velocity->y*-1);
                    puck1->velocity->x = 0;
                    puck1->velocity->y = 0;
                }
            }
        }
    }

}


void map::Render(sf::RenderWindow *window) {
    window->draw(tiles);
}
