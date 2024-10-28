#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball {
public:
    Ball(float radius);
    void update();
    void bounce();
    void reverseDirection();
    sf::CircleShape getShape() const;

private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
};

#endif // BALL_H
