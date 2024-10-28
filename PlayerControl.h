#ifndef PLAYERCONTROL_H
#define PLAYERCONTROL_H

#include "Barre.h"

class PlayerControl {
public:
    PlayerControl(Barre& barre, const sf::RenderWindow& window);
    void handleInput();

private:
    Barre& barre;

    const sf::RenderWindow& window;
};

#endif // PLAYERCONTROL_H
