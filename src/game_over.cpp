/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** TODO: add description
*/
#include "main.hpp"

void game_over_loop(SFML sfml)
{
    while (sfml.window->isOpen())
    {
        sf::Event event{};
        while (sfml.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sfml.window->close();
        }
        sfml.window->clear();
        sfml.window->display();
    }
}