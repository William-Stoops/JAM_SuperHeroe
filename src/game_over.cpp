/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** TODO: add description
*/
#include "main.hpp"


int handle_click(SFML sfml, sf::Event event, const char *name)
{
    if (event.type == sf::Event::MouseButtonReleased &&
             event.mouseButton.button == sf::Mouse::Left)
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(*sfml.window);
        if (sfml._sprite[name].getGlobalBounds().contains(mousePos.x,
                                                          mousePos.y))
        {
            return 1;
        }
    }
    return 0;
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
        if (handle_click(sfml, event, "close") == 1)
            sfml.window->close();
       // if (handle_click(sfml, event, "retry") == 1)
            //inserer fonction game ici
        sf::Vector2i mousePos = sf::Mouse::getPosition(*sfml.window);
        if (sfml._sprite["retry"].getGlobalBounds().contains(mousePos.x,
                                                          mousePos.y))
            sfml.window->draw(sfml._sprite["retry2"]);
        else
            sfml.window->draw(sfml._sprite["retry"]);
        if (sfml._sprite["close"].getGlobalBounds().contains(mousePos.x,
                                                             mousePos.y))
            sfml.window->draw(sfml._sprite["close2"]);
        else
            sfml.window->draw(sfml._sprite["close"]);
        sfml.window->display();
    }
}