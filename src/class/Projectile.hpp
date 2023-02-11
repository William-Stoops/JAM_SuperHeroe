/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Projectile
*/

#ifndef PROJECTILE_HPP_
    #define PROJECTILE_HPP_
    #include <SFML/Graphics.hpp>
    #include <cmath>

class Projectile
{
    public:
        Projectile(sf::Vector2f position, sf::Vector2f target, float damage);

        sf::FloatRect getRect() const;
        float getDamage() const;

        void move();
        void draw(sf::RenderWindow &window);
        bool isOutOfWindow(sf::RenderWindow &window);

private:
    float _speed = 1.f;
    sf::CircleShape _projectile;
    sf::Vector2f _velocity;
    float _damage;
};

#endif /* !PROJECTILE_HPP_ */
