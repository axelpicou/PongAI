#include "Ball.h"

Ball::Ball(float radius) {
    shape.setRadius(radius);
    shape.setFillColor(sf::Color::White);
    shape.setPosition(400, 300);
    velocity = sf::Vector2f(-0.05f, -0.05f);
}

void Ball::update() {
    shape.move(velocity);
}

void Ball::bounce() {
    velocity.y = -velocity.y;
}

void Ball::reverseDirection() {
    velocity.x = -velocity.x;
}

sf::CircleShape Ball::getShape() const {
    return shape;
}
