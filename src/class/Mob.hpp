//
// Created by Talleux on 10/02/2023.
//

#ifndef JAM_SUPERHEROE_MOB_HPP
    #define JAM_SUPERHEROE_MOB_HPP

#include <SFML/Graphics.hpp>

class Mob
{
    public:
        Mob(sf::Vector2f pos = sf::Vector2f(0, 0), sf::Color color = sf::Color::Red);
        ~Mob() = default;

        void setHp(float hp);
        void setSpeed(float speed);
        void setDamage(float damage);
        void setPos(sf::Vector2f pos);
        void setShape(sf::RectangleShape shape);

        float getHp() const;
        float getSpeed() const;
        float getDamage() const;
        sf::Vector2f getPos() const;
        sf::RectangleShape getShape() const;
        sf::FloatRect getRect() const;
        void move(sf::Vector2f pos);

        void draw(sf::RenderWindow &window) const;

        bool operator==(const Mob &mob) const;

    private:
        float _hp;
        float _speed;
        float _damage;
        sf::Vector2f _pos;
        sf::RectangleShape _shape;
};


#endif //JAM_SUPERHEROE_MOB_HPP
