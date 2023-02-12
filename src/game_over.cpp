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

int game_over_loop(SFML sfml, int kills)
{
    sf::Text text;
    sf::Font font;

    if (!font.loadFromFile("assets/oswald.ttf"))
        return 1;
    text.setFont(font);
    text.setString("Demande a ta maman de t'aider, elle saura te guider,\n\t\t\tcar c'est elle ton hero du quotidien");
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Red);
    text.setPosition(180, 0);

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
        if (kills == 0)
            sfml.window->draw(text);
        if (handle_click(sfml, event, "close") == 1) {
            sfml.window->close();
            return 1;
        }
       if (handle_click(sfml, event, "retry") == 1)
            return 0;
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
        sfml.window->draw(sfml._sprite["beercules_over"]);
        sfml.window->display();
    }
    return 1;
}