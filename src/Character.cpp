/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(float x, float y, sf::Sprite &sprite)
{
    _healthBar = ProgressBar(x, y + CHARACTERSIZE + 5, HEALTH);
    _weaponBar = ProgressBar(x, y + CHARACTERSIZE + 10, WEAPONS);
    _health = 100;
    _sprite = sprite;
    _sprite.setPosition(x, y);
    sf::Vector2f scale(0.01, 0.01);
    _sprite.setScale(scale);
}

void Character::moveLeft() {
    if (_sprite.getPosition().x < SPEED) return;
    _healthBar.setPosition(_healthBar.getPosition().x - SPEED, _healthBar.getPosition().y);
    _sprite.move(-SPEED, 0);
    _weaponBar.setPosition(_weaponBar.getPosition().x - SPEED, _weaponBar.getPosition().y);
}

void Character::moveRight() {
    if (_sprite.getPosition().x > WINDOWX - (CHARACTERSIZE + SPEED)) return;
    _healthBar.setPosition(_healthBar.getPosition().x + SPEED, _healthBar.getPosition().y);
    _sprite.move(SPEED, 0);
    _weaponBar.setPosition(_weaponBar.getPosition().x + SPEED, _weaponBar.getPosition().y);
}

void Character::moveUp() {
    if (_sprite.getPosition().y < SPEED) return;
    _healthBar.setPosition(_healthBar.getPosition().x, _healthBar.getPosition().y - SPEED);
    _sprite.move(0, -SPEED);
    _weaponBar.setPosition(_weaponBar.getPosition().x, _weaponBar.getPosition().y - SPEED);
}

void Character::moveDown() {
    if (_sprite.getPosition().y > WINDOWY - (CHARACTERSIZE + SPEED)) return;
    _healthBar.setPosition(_healthBar.getPosition().x, _healthBar.getPosition().y + SPEED);
    _sprite.move(0, SPEED);
    _weaponBar.setPosition(_weaponBar.getPosition().x, _weaponBar.getPosition().y + SPEED);
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
    window.draw(_sprite);
    _healthBar.draw(window);
    _weaponBar.draw(window);
}

