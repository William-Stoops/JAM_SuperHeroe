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

sf::Vector2f get_shoot_vector(sf::Vector2f *last_mouse_pos, sf::Vector2f center, double speed)
{
    sf::Vector2f shoot_vector;

    double angle = atan((last_mouse_pos->y - center.y) / (last_mouse_pos->x - center.x));

    shoot_vector.x = cos(angle) * speed;
    shoot_vector.y = sin(angle) * speed;

    return shoot_vector;
}

void sfml(void)
{
    SFML sfml;
    Game game(sfml);

    while (sfml.window->isOpen())
    {
        sf::Event event{};
        while (sfml.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                sfml.window->close();
            if (event.type == sf::Event::KeyPressed)
                detectInput(event.key.code, game.getCharacter());
            if (event.type == sf::Event::MouseMoved) {
                sfml.last_mouse_pos->x = event.mouseMove.x;
                sfml.last_mouse_pos->y = event.mouseMove.y;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    game.getCharacter().handleShoot(*sfml.last_mouse_pos);
                }
            }
        }
        //std::cout << get_shoot_vector(sfml.last_mouse_pos, (sf::Vector2f) {(800 / 2), (800 / 2)}, 1).x << " " << get_shoot_vector(sfml.last_mouse_pos, (sf::Vector2f) {(800 / 2), (800 / 2)}, 1).y << std::endl;
        sfml.window->clear();
        game.draw(*sfml.window);
        sfml.window->display();
    }
}

int main(void)
{
    srand(time(NULL));
    sfml();
    return 0;
}
