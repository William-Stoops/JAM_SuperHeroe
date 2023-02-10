/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Sfml
*/

#include "Sfml.hpp"
void SFML::addsprite(const char *name, const char *path)
{
    sf::Texture texture;
    sf::Sprite sprite;
    if (!texture.loadFromFile(path))
        return;
    sprite.setTexture(texture);
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
    addsprite("spiderman", "assets/spelunky.png");
}
