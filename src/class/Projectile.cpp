/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Projectile
*/

#include "Projectile.hpp"
#include <cmath>
#include <array>

Projectile::Projectile(sf::Vector2f position, sf::Vector2f target, float damage, int level)
{
    std::array<sf::Color, 8> colors = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta, sf::Color::Cyan, sf::Color::White, sf::Color::Black};

    _projectile.setRadius(5.f);
    _projectile.setFillColor(colors[(level / 2) % 8]);
    _projectile.setOrigin(_projectile.getRadius(), _projectile.getRadius());
    _projectile.setPosition(position);
    sf::Vector2f direction = target - position;
    float magnitude = std::sqrt(std::pow(direction.x, 2) + std::pow(direction.y, 2));
    direction /= magnitude;
    _velocity = direction * _speed;
    _damage = damage;
    _clock.restart();
}

void Projectile::move()
{
    if (_clock.getElapsedTime().asSeconds() < 0.001)
        return;
    _projectile.move(_velocity);
    _clock.restart();
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
