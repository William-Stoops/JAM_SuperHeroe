//
// Created by Talleux on 10/02/2023.
//

#include "Mob.hpp"

Mob::Mob()
{
    this->_hp = 100;
    this->_speed = 1;
    this->_damage = 10;
    this->_pos = sf::Vector2f(0,0);
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
