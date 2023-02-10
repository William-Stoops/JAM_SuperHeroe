/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_
    #include <SFML/Graphics.hpp>
    #include "ProgressBar.hpp"
    #include <map>

    #define SPEED 5
    #define WINDOWX 800
    #define WINDOWY 800

    #define CHARACTERSIZE 50

enum Direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

static std::map<int, Direction> keyMap = {
    {sf::Keyboard::Left, LEFT},
    {sf::Keyboard::Right, RIGHT},
    {sf::Keyboard::Up, UP},
    {sf::Keyboard::Down, DOWN}
};

class Character {
    public:
        Character(float x, float y);

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void updateHealth(float value);
        void move(int key);

        void draw(sf::RenderWindow& window) const;

    private:
        sf::RectangleShape rectangle;
        ProgressBar _healthBar;
        float _health;
};

#endif /* !CHARACTER_HPP_ */
