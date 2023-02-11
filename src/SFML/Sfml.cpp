/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Sfml
*/

#include "Sfml.hpp"
void SFML::addsprite(const char *name, const char *path)
{
    sf::Texture *texture = new sf::Texture;
    sf::Sprite sprite;

    if (!(*texture).loadFromFile(path))
        return;
    sprite.setTexture(*texture);
    sprite.setPosition(0, 0);
    std::string str(name);
    _sprite[str] = sprite;
}

SFML::SFML() {
    sf::Vector2u size(800, 800);
    sf::VideoMode mode(size.x, size.y);
    this->window = new sf::RenderWindow(mode, "Epitech Jam");
    this->font = new sf::Font;
    this->text = new sf::Text;
    this->last_mouse_pos = new sf::Vector2f(0,0);


    if (!this->font->loadFromFile("assets/oswald.ttf")) exit(84);
    this->text->setFont(*this->font);

    this->rectangle = new sf::RectangleShape(sf::Vector2f(400.0f,200.0f));
    this->rectangle->setFillColor(sf::Color::Transparent);
    this->rectangle->setOutlineThickness(2);
    this->rectangle->setOutlineColor(sf::Color::White);
    addsprite("spiderman", "./assets/spelunky.png");
    addsprite("game_over", "./assets/game over.png");
    addsprite("retry", "./assets/buttons.png");
    sf::IntRect retry_rect(2036, 208, 200, 200);
    _sprite["retry"].setScale(0.5,0.5);
    _sprite["retry"].setPosition(75, 450);
    _sprite["retry"].setTextureRect(retry_rect);
    sf::FloatRect retry_bounds = _sprite["retry"].getLocalBounds();
    _sprite["retry"].setOrigin(retry_bounds.width / 2.f, retry_bounds.height / 2.f);
    addsprite("close", "./assets/buttons.png");
    sf::IntRect close_rect(819, 834, 200, 200);
    _sprite["close"].setScale(0.5,0.5);
    _sprite["close"].setPosition(625, 450);
    _sprite["close"].setTextureRect(close_rect);
}
