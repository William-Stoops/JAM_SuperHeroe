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
    _attack = 10;
}

sf::Sprite Character::getSprite() const
{
    return _sprite;
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
    if (_sprite.getPosition().y > WINDOWY - (CHARACTERSIZE + SPEED + 10 + _healthBar.getSize().y + _weaponBar.getSize().y)) return;
    _healthBar.setPosition(_healthBar.getPosition().x, _healthBar.getPosition().y + SPEED);
    _sprite.move(0, SPEED);
    _weaponBar.setPosition(_weaponBar.getPosition().x, _weaponBar.getPosition().y + SPEED);
}

void Character::setHealth(float value) {
    _health = value;
    _healthBar.setValue(_health);
}

void Character::setEndurance(float value) {
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;
    _endurance = value;
    _weaponBar.setValue(_endurance);
}

sf::Vector2f Character::getPosition() const {
    return _sprite.getPosition();
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

void Character::handleShoot(sf::Vector2f mousePos) {
    if (_endurance <= 10) return;
    sf::FloatRect rect = _sprite.getGlobalBounds();
    sf::Vector2f center = sf::Vector2f(rect.left + rect.width / 2, rect.top + rect.height / 2);
    _projectiles.push_back(Projectile(center, mousePos, _attack));
    this->setEndurance(this->getEndurance() - 10);
}

void Character::handleCollision(std::vector<Mob> &mobs, Hud &hud, std::vector<Projectile>::iterator &it) {
    for (auto &mob : mobs) {
        if (it->getRect().intersects(mob.getRect())) {
            mob.setHp(mob.getHp() - it->getDamage());
            if (mob.getHp() <= 0) {
              mobs.erase(std::remove(mobs.begin(), mobs.end(), mob), mobs.end());
              hud.setKills();
            }
            it = _projectiles.erase(it);
            return;
        }
    }
    ++it;
}

void Character::handleProjectile(sf::RenderWindow &window, std::vector<Mob> &mobs, Hud &hud) {
    for (auto it = _projectiles.begin(); it != _projectiles.end();) {
        if (it->isOutOfWindow(window)) {
            it = _projectiles.erase(it);
            continue;
        }
        it->draw(window);
        it->move();
        handleCollision(mobs, hud, it);
    }
}

void Character::handleMobsCollides(std::vector<Mob> &mobs) {
    for (auto &mob : mobs) {
        if (mob.getRect().intersects(_sprite.getGlobalBounds())) {
            this->setHealth(this->getHealth() - mob.getDamage());
            if (_health <= 0) {
                _health = 0;
            }
            _healthBar.setValue(_health);
        }
    }
}

void Character::draw(sf::RenderWindow& window, std::vector<Mob>& _mobs, Hud& _hud) {
    setEndurance(_enduranceClock.getElapsedTime().asSeconds() * 10);
    if (_enduranceClock.getElapsedTime().asSeconds() >= 1.0f) {
      _enduranceClock.restart();
    }
    this->handleMobsCollides(_mobs);
    this->handleProjectile(window, _mobs, _hud);
    window.draw(_sprite);
    _healthBar.draw(window);
    _weaponBar.draw(window);
}

void Character::animate()
{
    _sprite.setTextureRect(sf::IntRect(_sprite.getTextureRect().left - 67 ,
                                       378,40,54));
    if (_sprite.getTextureRect().left < 420)
        _sprite.setTextureRect({756, 378, 40, 54});
}
