#include "Game.h"
#include <iostream>

Game::Game()
    : window(sf::VideoMode::getDesktopMode(), "Pong Game", sf::Style::Fullscreen),
    ball(10.f),
    barre(10.f, 100.f),
    playerControl(barre, window) {

    if (!font.loadFromFile("arial.ttf")) { // Remplacez par le chemin de votre fichier de police
        std::cerr << "Erreur lors du chargement de la police" << std::endl;
    }



}



void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }

    playerControl.handleInput();
}

void Game::update() {
    ball.update();
    checkCollisions();
}

void Game::render() {
    window.clear();
    window.draw(ball.getShape());
    window.draw(barre.getShape());
    window.draw(stat.getScoreText(font));

    window.display();
}

void Game::checkCollisions() {
    // Collision avec les murs
    if (ball.getShape().getPosition().y <= 0 ||
        ball.getShape().getPosition().y >= window.getSize().y - ball.getShape().getRadius() * 2) {
        ball.bounce();
    }

    // Collision avec la barre
    if (ball.getShape().getGlobalBounds().intersects(barre.getShape().getGlobalBounds())) {
        ball.reverseDirection();
        
    }

    // Réinitialiser la balle si elle sort de l'écran à gauche
    if (ball.getShape().getPosition().x <= 0 || ball.getShape().getPosition().x >= window.getSize().x) {
        ball = Ball(10.f); // Réinitialisation de la balle
        stat.incrementScore();
    }
}
