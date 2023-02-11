/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Character
*/

#include "Character.hpp"

Character::Character(float x, float y, sf::Sprite &sprite)
{
    _sprite = sprite;
    _sprite.setPosition(x, y);
    _sprite.setTextureRect({756, 378, 40, 54});
    sf::FloatRect rect = _sprite.getGlobalBounds();
    _healthBar = ProgressBar(x, y + rect.height + 5, HEALTH);
    _weaponBar = ProgressBar(x, y + rect.height + 10, WEAPONS);
    _health = 100;
    _endurance = 100;
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

void Character::setHealth(float value) {
    _health += value;
    _healthBar.setValue(_health);
}

void Character::setEndurance(float value) {
    if (value < 0)
        value = 0;
    _endurance = value;
    _weaponBar.setValue(_endurance);
}

void Character::setAttack(float value) {
    _attack = value;
}

float Character::getAttack() const {
    return _attack;
}

float Character::getHealth() const {
    return _health;
}

float Character::getEndurance() const {
    return _endurance;
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

void Character::handleShoot(sf::Vector2f mousePos) {
    if (_endurance <= 0) return;
    sf::FloatRect rect = _sprite.getGlobalBounds();
    sf::Vector2f center = sf::Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2);
    _projectiles.push_back(Projectile(center, mousePos, _attack));
    this->setEndurance(this->getEndurance() - 10);
}

void Character::handleCollision(std::vector<Mob> &mobs, Hud &hud, Projectile *it) {
    for (auto &mob : mobs) {
        if (it->getRect().intersects(mob.getRect())) {
            mob.setHp(mob.getHp() - it->getDamage());
            if (mob.getHp() <= 0) {
              mobs.erase(std::remove(mobs.begin(), mobs.end(), mob), mobs.end());
              hud.setKills();
            }
        }
    }
}

void Character::handleProjectile(sf::RenderWindow &window, std::vector<Mob> &mobs, Hud &hud) {
    for (auto it = _projectiles.begin(); it != _projectiles.end();) {
        if (it->isOutOfWindow(window)) {
            it = _projectiles.erase(it);
            continue;
        }
        it->draw(window);
        it->move();
        handleCollision(mobs, hud, &(*it));
        it++;
    }
}

void Character::draw(sf::RenderWindow& window, std::vector<Mob>& _mobs, Hud& _hud) {
    this->handleProjectile(window, _mobs, _hud);
    window.draw(_sprite);
    _healthBar.draw(window);
    _weaponBar.draw(window);
}
