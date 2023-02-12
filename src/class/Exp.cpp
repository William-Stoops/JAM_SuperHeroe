//
// Created by Noa Trachez on 11/02/2023.
//

#include "Exp.hpp"
#include <iostream>

Exp::Exp(sf::Vector2f position)
{
    sf::Texture *texture = new sf::Texture();
    (*texture).loadFromFile("assets/chauve_qui_peu.png");
    _bat.setTexture(*texture);
    _bat.setPosition(position);
    _bat.setScale(sf::Vector2f(0.05, 0.05));
    _bat.setOrigin(_bat.getGlobalBounds().width / 2, _bat.getGlobalBounds().height / 2);
    _bat.setRotation(rand() % 360);
    _rotation = rand() % 360;
    _position = position;
    _exp = 10;
}

sf::FloatRect Exp::getRect() const
{
    return _bat.getGlobalBounds();
}

float Exp::getExp() const
{
    return _exp;
}

void Exp::draw(sf::RenderWindow &window)
{
    window.draw(_bat);
}

bool Exp::operator==(const Exp &mob) const
{
    return this->_position == mob._position && this->_rotation == mob._rotation && this->_exp == mob._exp;
}