/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Projectile
*/

#include "Projectile.hpp"
#include <iostream>

Projectile::Projectile(sf::Vector2f position, sf::Vector2f target, float damage)
{
    _projectile.setRadius(5.f);
    _projectile.setFillColor(sf::Color::Red);
    _projectile.setOrigin(_projectile.getRadius(), _projectile.getRadius());
    _projectile.setPosition(position);
    sf::Vector2f direction = target - position;
    float magnitude = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
    direction /= magnitude;
    _velocity = direction * _speed;
    _damage = damage;
}

void Projectile::move()
{
    _projectile.move(_velocity);
}

void Projectile::draw(sf::RenderWindow &window)
{
    move();
    window.draw(_projectile);
}

sf::FloatRect Projectile::getRect() const
{
    return _projectile.getGlobalBounds();
}

float Projectile::getDamage() const
{
    return _damage;
}

bool Projectile::isOutOfWindow(sf::RenderWindow &window)
{
    sf::Vector2f position = _projectile.getPosition();
    return (position.x < 0 || position.x > window.getSize().x ||
            position.y < 0 || position.y > window.getSize().y);
}
