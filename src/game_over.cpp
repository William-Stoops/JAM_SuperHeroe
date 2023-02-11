/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** TODO: add description
*/
#include "main.hpp"


void handle_retry_close(SFML sfml, sf::Event event)
{
    if (event.type == sf::Event::MouseButtonReleased &&
             event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*sfml.window);
        if (sfml._sprite["retry"].getGlobalBounds().contains(mousePos.x,
                                                             mousePos.y))
        {
            printf("retry");
        }
        if (sfml._sprite["close"].getGlobalBounds().contains(mousePos.x,
                                                             mousePos.y))
        {
            sfml.window->close();
        }
    }
}

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
        sfml.window->draw(sfml._sprite["game_over"]);
        sfml.window->draw(sfml._sprite["retry"]);
        sfml.window->draw(sfml._sprite["close"]);
        sfml.window->display();
    }
}