//
// Created by Talleux on 10/02/2023.
//

#include "Mob.hpp"
#include <cmath>
#include "iostream"
#include <array>

sf::Vector2f nextPosition(const sf::Vector2f position, sf::Vector2f to, float speed)
{
    sf::Vector2f direction = to - position;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    sf::Vector2f unitDirection = direction / distance;

    sf::Vector2f movement = unitDirection * speed;
    sf::Vector2f nextPosition = position + movement;
    return nextPosition;
}

Mob::Mob(sf::Vector2f pos, int frags)
{
    this->_hp = 10 + (frags * 0.05);
    this->_speed = 0.05 + (frags * 0.001);
    this->_damage = 0.05;
    float enemy_x;
    float enemy_y;


    while (1) {
        enemy_x = -200 + rand() % 1000;
        enemy_y = -200 + rand() % 1000;

        float distance = std::sqrt(std::pow((enemy_x - 400), 2) + std::pow((enemy_y - 400), 2));
        float distance2 = std::sqrt(std::pow((enemy_x - pos.x), 2) + std::pow((enemy_y - pos.y), 2));
        if (distance >= 500 && distance2 >= 400)
            break;
    }

    this->_pos = sf::Vector2f(enemy_x, enemy_y);
    sf::Texture *texture = new sf::Texture();
    (*texture).loadFromFile("assets/villain.png");

    std::array<sf::IntRect, 8> rect =
    {sf::IntRect(3, 6, 38, 42), sf::IntRect(0, 198, 47, 42),
     sf::IntRect(152, 4, 32, 44), sf::IntRect(288, 198, 46, 44),
     sf::IntRect(437, 6, 35, 42), sf::IntRect(148, 198, 30, 42),
     sf::IntRect(292, 193, 39, 47), sf::IntRect(440, 198, 47, 42)};

    sf::Sprite sprite;
    this->_sprite = sprite;
    this->_sprite.setTexture(*texture);
    sf::IntRect rect2 = rect[rand() % 8];
    this->_sprite.setTextureRect(rect2);
    this->_first_left = rect2.left;
    this->_sprite.setPosition(this->_pos);
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

sf::FloatRect Mob::getRect() const
{
    return this->_sprite.getGlobalBounds();
}

bool Mob::operator==(const Mob &mob) const
{
    return this->_hp == mob._hp && this->_speed == mob._speed && this->_damage == mob._damage && this->_pos == mob._pos;
}

void Mob::move(sf::Vector2f position)
{
    sf::Vector2f pos = nextPosition(this->_sprite.getPosition(), position, this->_speed);
    this->_sprite.setPosition(pos.x, pos.y);
    this->_pos = pos;
}

void Mob::animate()
{
    sf::IntRect rect = this->_sprite.getTextureRect();
    rect.left += 50;
    this->_sprite.setTextureRect(rect);

    if (rect.left > _first_left + 140) {
        rect.left = _first_left;
        this->_sprite.setTextureRect(rect);
    }
}

void Mob::draw(sf::RenderWindow &window) const
{
    window.draw(this->_sprite);
}
