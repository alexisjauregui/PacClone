//
// Created by Alexis Jauregui on 8/7/15.
//

#ifndef PACM_PAC_GAME_H
#define PACM_PAC_GAME_H


#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <cctype>
#include "game_state.h"
#include "main_state.h"
#include "puck.h"
#include "score.h"
#include "map.h"
#include "dots.h"
#include "ghost.h"
#include "Lives.h"


class pac_game :public tiny_state {
public:
void Initialize(sf::RenderWindow* window);
void Update(sf::RenderWindow* window);
void Render(sf::RenderWindow* window);
void Destroy(sf::RenderWindow* window);

private:

    score* score1;
    puck* puck1;
    map* map1;
    dots* dots1;
    ghost* red;
    ghost* blue;
    ghost* green;
    ghost* pink;
    Lives* lives;
    sf::Font* font;
    sf::Text* text1;
    sf::Text* text2;
    bool paused;
    bool keyPressed;
    bool gameover;


};


#endif //PACM_PAC_GAME_H
