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
        if (event.key.code == sf::Keyboard::Z) keyMap["up"] = true;
        if (event.key.code == sf::Keyboard::S) keyMap["down"] = true;
        if (event.key.code == sf::Keyboard::Q) keyMap["left"] = true;
        if (event.key.code == sf::Keyboard::D) keyMap["right"] = true;
    }
    if (event.type == sf::Event::KeyReleased) {
        if (event.key.code == sf::Keyboard::Z) keyMap["up"] = false;
        if (event.key.code == sf::Keyboard::S) keyMap["down"] = false;
        if (event.key.code == sf::Keyboard::Q) keyMap["left"] = false;
        if (event.key.code == sf::Keyboard::D) keyMap["right"] = false;
    }
}

void spawn_mobs(Game &game, float time, int frags)
{
    static sf::Time elapsed = MA_PUTAIN_DE_CLOCK.getElapsedTime();
    if (time > 1)
        time = time - (frags * 0.032);
    else
        time = 1;
    static sf::Time spawn_time = sf::seconds(time);

    elapsed = MA_PUTAIN_DE_CLOCK.getElapsedTime();
    if (elapsed >= spawn_time) {
        game.addMob(Mob(game.getCharacter().getPosition(), frags));
        MA_PUTAIN_DE_CLOCK.restart();
    }
}

int moveCharacter(Game &game, std::map<std::string, bool> &keyMap)
{
    int last_key = 0;
    if (keyMap["up"]) {game.getCharacter().moveUp(); last_key = 1;}
    if (keyMap["down"]) {game.getCharacter().moveDown(); last_key = 2;}
    if (keyMap["left"]) {game.getCharacter().moveLeft(); last_key = 2;}
    if (keyMap["right"]) {game.getCharacter().moveRight(); last_key = 2;}
    return last_key;
}

int sfmL(SFML &sfml)
{
    int last_key = 0;
    int last_key2 = 0;
    Game game(sfml);
    std::map<std::string, bool> keyMap = {
        {"up", false},
        {"down", false},
        {"left", false},
        {"right", false}
    };

    sf::Clock clock;
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

        if (game.getCharacter().getHealth() <= 0)
            return game.getHud().getKills();

        game.getCharacter().handleShoot(*sfml.last_mouse_pos);
        spawn_mobs(game, 4.0, game.getHud().getKills());
        last_key = moveCharacter(game, keyMap);
        if (last_key != 0)
            last_key2 = last_key;
        sfml.window->clear();
        (*sfml.window).draw(sfml._sprite["background"]);
        game.draw(*sfml.window);
        float elapsedsecond = clock.getElapsedTime().asSeconds();
        if (elapsedsecond > 0.15) {
            game.animate(keyMap, last_key, last_key2);
            clock.restart();
        }
        sfml.window->display();
    }
    return 1;
}

int main(void)
{
    SFML sfmls;
    int game_over = 0;
    int kills = 0;
    srand(time(NULL));

    while (game_over == 0) {
        game_start_loop(sfmls);
        kills = sfmL(sfmls);
        game_over = game_over_loop(sfmls, kills);
    }
    return 0;
}
