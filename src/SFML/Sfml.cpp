/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Sfml
*/

#include "Sfml.hpp"

SFML::SFML() {
    sf::Vector2u size(800, 800);
    sf::VideoMode mode(size.x, size.y);
    this->window = new sf::RenderWindow(mode, "Epitech Jam");
    this->font = new sf::Font;
    this->text = new sf::Text;


    if (!this->font->loadFromFile("assets/oswald.ttf")) exit(84);
    this->text->setFont(*this->font);

    this->rectangle = new sf::RectangleShape(sf::Vector2f(400.0f,200.0f));
    this->rectangle->setFillColor(sf::Color::Transparent);
    this->rectangle->setOutlineThickness(2);
    this->rectangle->setOutlineColor(sf::Color::White);
}
