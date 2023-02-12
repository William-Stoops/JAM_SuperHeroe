//
// Created by Talleux on 10/02/2023.
//

#include "Game.hpp"

static std::map<int, float> levelMap =
{
    {1, 100},
    {2, 150},
    {3, 200},
    {4, 250},
    {5, 300},
    {6, 350},
    {7, 400},
    {8, 450},
    {9, 500},
    {10, 550},
    {11, 600},
    {12, 650},
    {13, 700},
    {14, 750},
    {15, 800},
    {16, 850},
    {17, 900},
    {18, 950},
    {19, 1000},
    {20, 1050},
};

Game::Game(SFML sfml)
{
    sf::Vector2f pos(100, 100);
    this->_progressBar = ProgressBar(0, 0, HUD);
    this->_character = Character(pos.x, pos.y, sfml._sprite["spiderman"]);
    this->_hud = Hud();
    this->_mobs = std::vector<Mob>();
    float x = (sfml.window->getSize().x - this->_progressBar.getSize().x) / 2;
    this->_progressBar.setPosition(x, 35);
}

Hud &Game::getHud()
{
    return this->_hud;
}

std::vector<Mob> &Game::getMobs()
{
    return this->_mobs;
}

Character &Game::getCharacter()
{
    return this->_character;
}

void Game::addMob(Mob mob)
{
    this->_mobs.push_back(mob);
}

void Game::removeMob(Mob mob)
{
    this->_mobs.erase(std::remove(this->_mobs.begin(), this->_mobs.end(), mob), this->_mobs.end());
}

void Game::removeMob(int index)
{
    this->_mobs.erase(this->_mobs.begin() + index);
}

void Game::draw(sf::RenderWindow &window)
{
    this->_character.draw(window, this->_mobs, this->_hud, this->_exp);
    for (auto &mob : this->_mobs) {
        mob.move(this->_character.getSprite().getPosition());
        mob.draw(window);
    }

    float exp = this->_character.getExp();

    if (exp >= levelMap[this->_character.getLevel()]) {
        this->_character.setLevel();
        this->_character.setExp(0.0);
        this->_progressBar.setMax(levelMap[this->_character.getLevel()]);
    }

    this->_progressBar.setValue(exp);
    this->_progressBar.draw(window);
    this->_hud.draw(window);
}

void Game::animate(std::map<std::string, bool> &keyMap)
{
    for (auto &mob : this->_mobs) {
        mob.animate();
    }
    if (keyMap["up"] || keyMap["down"] || keyMap["left"] || keyMap["right"])
        _character.animate();
    else
        _character.unanimate();
}
