/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** main
*/

#include "main.hpp"

void detectInput(int keyCode, Character &character)
{
    if (keyMap.find(keyCode) != keyMap.end())
        character.move(keyCode);
}

void sfml(void)
{
    SFML sfml;
    Character character(100, 100);

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
