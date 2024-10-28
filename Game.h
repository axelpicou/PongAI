#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Barre.h"
#include "PlayerControl.h"
#include "Stat.h"

class Game {
public:
    Game();
    void run();


private:
    void processEvents();
    void update();
    void render();
    void checkCollisions();

    sf::RenderWindow window;
    Ball ball;
    Barre barre;
    PlayerControl playerControl;
    Stat stat;
    sf::Font font;
};

#endif // GAME_H
