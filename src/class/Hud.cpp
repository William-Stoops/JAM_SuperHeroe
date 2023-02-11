/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Hud
*/

#include "Hud.hpp"

Hud::Hud()
{
    _kills = 0;
}

void Hud::setKills(void)
{
    _kills += 1;
}

int Hud::getKills() const
{
    return _kills;
}

void Hud::drawKills(sf::RenderWindow &window) const
{
    sf::Font font;
    sf::Text text;
    std::string kills = std::to_string(_kills);

    if (!font.loadFromFile("assets/oswald.ttf"))
        return;
    text.setFont(font);
    text.setString("Kills : " + kills);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(window.getSize().x - text.getGlobalBounds().width - 30, 15);
    window.draw(text);
}

void Hud::draw(sf::RenderWindow &window) const
{
    drawKills(window);
}
