//
// Created by Alexis Jauregui on 9/7/15.
//

#ifndef PACM_PUCK_H
#define PACM_PUCK_H


#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


class puck {
public:
    void initialize(sf::RenderWindow* window);
    void Update(sf::RenderWindow* window);
    void Render(sf::RenderWindow* window);

    sf::Sprite* pSprite;
    sf::Vector2f* velocity;
    sf::RectangleShape rectangleShape1;
    sf::Sound* wakka;

private:
    sf::Texture pTexture;
    sf::Vector2i source;
    enum Direction{Down,Left,Right,Up};

    sf::SoundBuffer buffer;

    float frameCounter =0 , switchFrame= 100, frameSpeed = 750;

    sf::Clock* clock1;


};


#endif //PACM_PUCK_H
