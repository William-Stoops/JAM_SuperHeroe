/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** main
*/

#include "main.hpp"

void display(sf::RenderWindow *window)
{
    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Red);
    sf::RectangleShape shape2(sf::Vector2f(100, 100));

    shape2.setPosition(sf::Vector2f(100, 100));
    shape2.setFillColor(sf::Color::Magenta);
    window->draw(shape);
    window->draw(shape2);
}

void sfml(void)
{
    SFML sfml;
    while (sfml.window->isOpen())
    {
        sf::Event event{};
        while (sfml.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sfml.window->close();
        }
        sfml.window->clear();
        display(sfml.window);
        sfml.window->display();
    }
}

int main(int ac, char **av)
{
    sfml();
    return 0;
}
