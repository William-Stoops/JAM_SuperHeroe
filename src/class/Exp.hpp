//
// Created by Noa Trachez on 11/02/2023.
//

#ifndef EXP_HPP
#define EXP_HPP

#include <SFML/Graphics.hpp>

class Exp
{
    public:
        Exp(sf::Vector2f position);

        sf::FloatRect getRect() const;

        void draw(sf::RenderWindow &window);
        bool operator==(const Exp &mob) const;
        float getExp() const;

    private:
        sf::Sprite _bat;
        sf::Texture _texture;
        sf::Vector2f _position;
        float _rotation;
        float _exp;
};

#endif //EXP_HPP
