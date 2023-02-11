/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** main
*/

#include "main.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

static sf::Clock MA_PUTAIN_DE_CLOCK;

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

void spawn_mobs(Game &game, float time)
{
    static sf::Time elapsed = MA_PUTAIN_DE_CLOCK.getElapsedTime();
    static sf::Time spawn_time = sf::seconds(time);

    elapsed = MA_PUTAIN_DE_CLOCK.getElapsedTime();
    if (elapsed >= spawn_time) {
        game.addMob(Mob());
        MA_PUTAIN_DE_CLOCK.restart();
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
        }

        game.getCharacter().handleShoot(*sfml.last_mouse_pos);

        spawn_mobs(game, 4.0);
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
