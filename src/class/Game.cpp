//
// Created by Talleux on 10/02/2023.
//

#include "Game.hpp"

Game::Game()
{
    this->_mobs = std::vector<Mob>();
}

void Game::getMobs()
{
    return this->_mobs;
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
