#ifndef BARRE_H
#define BARRE_H

#include <SFML/Graphics.hpp>

class Barre {
public:
    Barre(float width, float height);
    void move(float offset);
    sf::RectangleShape getShape() const;

private:
    sf::RectangleShape shape;
};

#endif // BARRE_H
