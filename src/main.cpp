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

sf::Vector2f get_shoot_vector(sf::Vector2f *last_mouse_pos, sf::Vector2f center, double speed)
{
    sf::Vector2f shoot_vector;

    double angle = atan((last_mouse_pos->y - center.y) / (last_mouse_pos->x - center.x));

    shoot_vector.x = cos(angle) * speed;
    shoot_vector.y = sin(angle) * speed;

    return shoot_vector;
}

void detectInput(sf::Event event, std::map<std::string, bool> &keyMap)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) keyMap["up"] = true;
        if (event.key.code == sf::Keyboard::Down) keyMap["down"] = true;
        if (event.key.code == sf::Keyboard::Left) keyMap["left"] = true;
        if (event.key.code == sf::Keyboard::Right) keyMap["right"] = true;
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Up) keyMap["up"] = false;
        if (event.key.code == sf::Keyboard::Down) keyMap["down"] = false;
        if (event.key.code == sf::Keyboard::Left) keyMap["left"] = false;
        if (event.key.code == sf::Keyboard::Right) keyMap["right"] = false;
    }
}

void moveCharacter(Game &game, std::map<std::string, bool> &keyMap)
{
    if (keyMap["up"]) game.getCharacter().moveUp();
    if (keyMap["down"]) game.getCharacter().moveDown();
    if (keyMap["left"]) game.getCharacter().moveLeft();
    if (keyMap["right"]) game.getCharacter().moveRight();
}

void sfml(void)
{
    SFML sfml;
    Game game(sfml);
    std::map<std::string, bool> keyMap = {
        {"up", false},
        {"down", false},
        {"left", false},
        {"right", false}
    };

    while (sfml.window->isOpen()) {
        sf::Event event{};
        while (sfml.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                sfml.window->close();
            detectInput(event, keyMap);
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
        moveCharacter(game, keyMap);
        sfml.window->clear();
        (*sfml.window).draw(sfml._sprite["background"]);
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
