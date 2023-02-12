/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** TODO: add description
*/
#include "main.hpp"


int handle_start_click(SFML sfml, sf::Event event, const char *name)
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

void game_start_loop(SFML sfml)
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
        sfml.window->draw(sfml._sprite["start"]);
        sfml.window->draw(sfml._sprite["Play"]);
        sfml.window->draw(sfml._sprite["Leaderboard"]);
        sfml.window->draw(sfml._sprite["Logo"]);
        if (handle_start_click(sfml, event, "Play") == 1)
            break;
        //if (handle_start_click(sfml, event, "Leaderboard") == 1)
            //inserer fonction leaderboard ici
        sf::Vector2i mousePos = sf::Mouse::getPosition(*sfml.window);
        if (sfml._sprite["Play"].getGlobalBounds().contains(mousePos.x,
                                                          mousePos.y))
            sfml.window->draw(sfml._sprite["Play2"]);
        else
            sfml.window->draw(sfml._sprite["Play"]);
        if (sfml._sprite["Leaderboard"].getGlobalBounds().contains(mousePos.x,
                                                             mousePos.y))
            sfml.window->draw(sfml._sprite["Leaderboard2"]);
        else
            sfml.window->draw(sfml._sprite["Leaderboard"]);
        sfml.window->display();
    }
}