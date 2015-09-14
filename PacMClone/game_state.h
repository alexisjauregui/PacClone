//
// Created by Alexis Jauregui on 8/4/15.
//

#ifndef PACM_GAME_STATE_H
#define PACM_GAME_STATE_H

#include <SFML/Graphics.hpp>

class tiny_state
{
public:
    virtual void Initialize(sf::RenderWindow* window)
    {

    }
    virtual void Update(sf::RenderWindow* window)
    {

    }
    virtual void Render(sf::RenderWindow* window)
    {

    }
    virtual void Destroy(sf::RenderWindow* window)
    {

    }
    ~tiny_state();

    sf::Text* text;
};

class game_state
{
public:
    game_state()
    {
    }
    void set_window(sf::RenderWindow* window)
    {
        this->window = window;
    }
    void set_state(tiny_state* state)
    {
        if(this->state != NULL){
            this->state->Destroy(this->window);
        }
        this->state = state;
        if(this->state != NULL){
            this->state->Initialize(this->window);
        }
    }
    void Update(){
        if(this->state != NULL){
            this->state->Update(this->window);
        }
    }
    void Render(){
        if(this->state != NULL){
            this->state->Render(this->window);
        }
    }
    ~game_state(){
        if(this->state != NULL){
            this->state->Render(this->window);
        }
    }

private:
    sf::RenderWindow* window;
    tiny_state* state;

};

extern game_state coreState;
extern bool quit_game;

#endif //PACM_GAME_STATE_H
