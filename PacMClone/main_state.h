//
// Created by Alexis Jauregui on 8/4/15.
//

#ifndef PACM_MAIN_STATE_H
#define PACM_MAIN_STATE_H


#include "game_state.h"
#include "pac_game.h"

class main_state: public tiny_state {
public:
    void Initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);
    void Destroy(sf::RenderWindow* window);

private:

    sf::Font* font;
    sf::Text* title;
    sf::Text* quit;
    sf::Text* play;


    sf::Texture* texture;
    sf::Sprite* sprite;

    int selected;
    bool upKey;
    bool downKey;
};


#endif //PACM_MAIN_STATE_H
