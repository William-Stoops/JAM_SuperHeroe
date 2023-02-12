//
// Created by Talleux on 10/02/2023.
//

#ifndef JAM_SUPERHEROE_MOB_HPP
    #define JAM_SUPERHEROE_MOB_HPP

#include <SFML/Graphics.hpp>

class Mob
{
    public:
        Mob(sf::Vector2f pos, int frags);
        ~Mob() = default;

        void setHp(float hp);
        void setSpeed(float speed);
        void setDamage(float damage);
        void setPos(sf::Vector2f pos);

        float getHp() const;
        float getSpeed() const;
        float getDamage() const;
        sf::Vector2f getPos() const;
        sf::FloatRect getRect() const;
        void move(sf::Vector2f pos);
        int getLevel() const;
        void animate();

        void draw(sf::RenderWindow &window) const;

        bool operator==(const Mob &mob) const;

    private:
        float _hp;
        float _speed;
        float _damage;
        sf::Vector2f _pos;
        sf::Sprite _sprite;
        int _first_left;
};


#endif //JAM_SUPERHEROE_MOB_HPP
