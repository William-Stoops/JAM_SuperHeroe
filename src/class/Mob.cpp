//
// Created by Talleux on 10/02/2023.
//

#include "Mob.hpp"

Mob::Mob(sf::Vector2f pos, sf::Color color)
{
    this->_hp = 100;
    this->_speed = 1;
    this->_damage = 10;
    this->_pos = pos;
    this->_shape = sf::RectangleShape(sf::Vector2f(100,100));
    this->_shape.setFillColor(color);
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

bool Mob::operator==(const Mob &mob) const
{
    return this->_hp == mob._hp && this->_speed == mob._speed && this->_damage == mob._damage && this->_pos == mob._pos;
}
