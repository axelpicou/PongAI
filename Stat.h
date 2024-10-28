#ifndef STAT_H
#define STAT_H

#include <SFML/Graphics.hpp>

class Stat {
public:
    Stat();
    void incrementScore();
    int getScore() const;
    sf::Text getScoreText(const sf::Font& font) const; // Ajout d'une méthode pour obtenir le texte

private:
    int score;
};

#endif // STAT_H
