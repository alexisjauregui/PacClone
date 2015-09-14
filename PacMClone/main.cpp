#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_state.h"
#include "main_state.h"


using namespace std;

game_state coreState;
bool quit_game = false;

int main() {
    cout << "Hello, World!" << endl;

    //Applications variables
    sf::RenderWindow window(sf::VideoMode(448, 567), "Pong");

    coreState.set_window(&window);
    coreState.set_state(new main_state());

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        coreState.Update();
        coreState.Render();
        window.display();

        if(quit_game)
        {
            window.close();
        }

    }

    return 0;
}