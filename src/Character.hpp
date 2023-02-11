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
    #include "class/Mob.hpp"
    #include "class/Hud.hpp"
    #include "class/Projectile.hpp"
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
        Character() = default;
        Character(float x, float y, sf::Sprite &sprite);

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();
        void move(int key);

        void setHealth(float value);
        void setEndurance(float value);
        void setAttack(float value);

        float getAttack() const;
        float getHealth() const;
        float getEndurance() const;
        sf::Sprite getSprite() const;

        void handleShoot(sf::Vector2f mousePos);
        void handleProjectile(sf::RenderWindow& window, std::vector<Mob> &mobs, Hud &hud);
        void handleCollision(std::vector<Mob> &mobs, Hud &hud, Projectile *projectile);
        void draw(sf::RenderWindow& window, std::vector<Mob> &mobs, Hud &hud);

    private:
        std::vector<Projectile> _projectiles;
        sf::RectangleShape rectangle;
        ProgressBar _healthBar;
        ProgressBar _weaponBar;
        sf::Sprite _sprite;
        float _health;
        float _endurance;
        float _attack;
        int _kills;
};

#endif /* !CHARACTER_HPP_ */
