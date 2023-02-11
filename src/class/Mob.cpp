//
// Created by Talleux on 10/02/2023.
//

#include "Mob.hpp"
#include <cmath>
#include "iostream"

sf::Vector2f nextPosition(const sf::Vector2f position, sf::Vector2f to, float speed)
{
    sf::Vector2f direction = to - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f unitDirection = direction / distance;

    sf::Vector2f movement = unitDirection * speed;
    sf::Vector2f nextPosition = position + movement;
    return nextPosition;
}

Mob::Mob(sf::Vector2f pos, sf::Color color)
{
    this->_hp = 100;
    this->_speed = 1;
    this->_damage = 0.1;
    float enemy_x;
    float enemy_y;

    while (1) {
        int min_distance = 300;
        enemy_x = rand() % 2 ? pos.x + rand() % min_distance : pos.x - rand() % min_distance;
        enemy_y = rand() % 2 ? pos.y + rand() % min_distance : pos.y - rand() % min_distance;

        float distance = std::sqrt(std::pow((enemy_x - pos.x), 2) + std::pow((enemy_y - pos.y), 2));
        if (distance >= min_distance)
            break;
    }
    this->_pos = sf::Vector2f(enemy_x, enemy_y);
    this->_shape = sf::RectangleShape(sf::Vector2f(100,100));
    this->_shape.setFillColor(color);
    this->_shape.setPosition(this->_pos);
}

void Mob::setHp(float hp)
{
    this->_hp = hp;
}

void Mob::setSpeed(float speed)
{
    this->_speed = speed;
}

void Mob::setDamage(float damage)
{
    this->_damage = damage;
}

void Mob::setPos(sf::Vector2f pos)
{
    this->_pos = pos;
}

void Mob::setShape(sf::RectangleShape shape)
{
    this->_shape = shape;
}

float Mob::getHp() const
{
    return this->_hp;
}

float Mob::getSpeed() const
{
    return this->_speed;
}

float Mob::getDamage() const
{
    return this->_damage;
}

sf::Vector2f Mob::getPos() const
{
    return this->_pos;
}

sf::RectangleShape Mob::getShape() const
{
    return this->_shape;
}

sf::FloatRect Mob::getRect() const
{
    return this->_shape.getGlobalBounds();
}

bool Mob::operator==(const Mob &mob) const
{
    return this->_hp == mob._hp && this->_speed == mob._speed && this->_damage == mob._damage && this->_pos == mob._pos;
}

void Mob::move(sf::Vector2f position)
{
    sf::Vector2f pos = nextPosition(this->_shape.getPosition(), position, 0.1);
    this->_shape.setPosition(pos.x, pos.y);
    this->_pos = pos;
}

void Mob::draw(sf::RenderWindow &window) const
{
    window.draw(this->_shape);
}
