/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(float x, float y)
{
    rectangle.setSize(sf::Vector2f(50, 50));
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(x, y);
    _healthBar = ProgressBar(x, y + CHARACTERSIZE + 5, HEALTH);
    _weaponBar = ProgressBar(x, y + CHARACTERSIZE + 10, WEAPONS);
    _health = 100;
}

void Character::moveLeft() {
    if (rectangle.getPosition().x < SPEED) return;
    _healthBar.setPosition(_healthBar.getPosition().x - SPEED, _healthBar.getPosition().y);
    _weaponBar.setPosition(_weaponBar.getPosition().x - SPEED, _weaponBar.getPosition().y);
    rectangle.move(-SPEED, 0);
}

void Character::moveRight() {
    if (rectangle.getPosition().x > WINDOWX - (CHARACTERSIZE + SPEED)) return;
    _healthBar.setPosition(_healthBar.getPosition().x + SPEED, _healthBar.getPosition().y);
    _weaponBar.setPosition(_weaponBar.getPosition().x + SPEED, _weaponBar.getPosition().y);
    rectangle.move(SPEED, 0);
}

void Character::moveUp() {
    if (rectangle.getPosition().y < SPEED) return;
    _healthBar.setPosition(_healthBar.getPosition().x, _healthBar.getPosition().y - SPEED);
    _weaponBar.setPosition(_weaponBar.getPosition().x, _weaponBar.getPosition().y - SPEED);
    rectangle.move(0, -SPEED);
}

void Character::moveDown() {
    float maxSize = _healthBar.getSize().y + _weaponBar.getSize().y + 5;
    if (rectangle.getPosition().y > WINDOWY - (CHARACTERSIZE + SPEED + maxSize)) return;
    _healthBar.setPosition(_healthBar.getPosition().x, _healthBar.getPosition().y + SPEED);
    _weaponBar.setPosition(_weaponBar.getPosition().x, _weaponBar.getPosition().y + SPEED);
    rectangle.move(0, SPEED);
}

void Character::updateHealth(float value) {
    _health += value;
    _healthBar.setValue(_health);
}

void Character::updateEndurance(float value) {
    _endurance += value;
    _weaponBar.setValue(_endurance);
}

void Character::move(int key) {
    void (Character::*moveFunctions[])(void) = {
        &Character::moveLeft,
        &Character::moveRight,
        &Character::moveUp,
        &Character::moveDown
    };
    auto it = keyMap.find(key);
    if (it != keyMap.end())
        (this->*moveFunctions[it->second])();
}

void Character::draw(sf::RenderWindow& window) const {
    window.draw(rectangle);
    _healthBar.draw(window);
    _weaponBar.draw(window);
}

