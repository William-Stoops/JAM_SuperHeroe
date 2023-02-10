/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Sfml
*/

#ifndef SFML_HPP_
    #define SFML_HPP_
    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>
    #include <list>
    #include <cstring>
    #include <iostream>
    #include <cstdarg>
    #include <map>

class SFML {
    public:
        SFML();
        ~SFML() = default;

        void addsprite(std::string &name, std::string &path);

        sf::RenderWindow *window;
        sf::Font *font;
        sf::Text *text;
        sf::RectangleShape *rectangle;
        std::map<std::string,sf::Sprite> _sprite;
};

#endif /* !SFML_HPP_ */
