/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** main
*/

#include "main.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

void nextPosition(sf::Vector2f &position, sf::Vector2f to, float speed)
{
    sf::Vector2f direction = to - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f unitDirection = direction / distance;

    sf::Vector2f movement = unitDirection * speed;
    position += movement;
}

void detectInput(int keyCode, Character &character)
{
    if (keyMap.find(keyCode) != keyMap.end())
        character.move(keyCode);
}

void sfml(void)
{
    SFML sfml;
    Character character(100, 100, sfml._sprite["spiderman"]);

    while (sfml.window->isOpen())
    {
        sf::Event event{};
        while (sfml.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                sfml.window->close();
            if (event.type == sf::Event::KeyPressed)
                detectInput(event.key.code, character);
        }
        sfml.window->clear();
        character.draw(*sfml.window);
        sfml.window->display();
    }
}

int main(void)
{
    sfml();
    return 0;
}
