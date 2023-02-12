/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
    #define CHARACTER_HPP_
    #include <SFML/Graphics.hpp>
    #include "ProgressBar.hpp"
    #include "class/Mob.hpp"
    #include "class/Hud.hpp"
    #include "class/Projectile.hpp"
    #include "class/Exp.hpp"
    #include <map>

    #define SPEED 0.1f
    #define WINDOWX 800
    #define WINDOWY 800

    #define CHARACTERSIZE 50

class Character {
    public:
        Character() = default;
        Character(float x, float y, sf::Sprite &sprite);

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        void setHealth(float value);
        void setEndurance(float value);
        void setAttack(float value);
        void setLevel(void);

    float getAttack() const;
        float getHealth() const;
        float getEndurance() const;
        sf::Sprite getSprite() const;
        sf::Vector2f getPosition() const;
        float getExp() const;
        void setExp(float value);

        void handleShoot(sf::Vector2f mousePos);
        void handleMobsCollides(std::vector<Mob> &mobs);
        void handleProjectile(sf::RenderWindow& window, std::vector<Mob> &mobs, Hud &hud, std::vector<Exp> &exps);
        void handleCollision(std::vector<Mob> &mobs, Hud &hud, std::vector<Projectile>::iterator &it, std::vector<Exp> &exps);
        void handleXp(sf::RenderWindow &window, std::vector<Exp>& exps, Hud &hud);
        void draw(sf::RenderWindow& window, std::vector<Mob>& _mobs, Hud& _hud, std::vector<Exp>& _exp);
        void animate();

        private:
        std::vector<Projectile> _projectiles;
        sf::Clock _enduranceClock;
        sf::RectangleShape rectangle;
        ProgressBar _healthBar;
        ProgressBar _weaponBar;
        sf::Sprite _sprite;
        float _health;
        float _endurance;
        float _attack;
        float _exp;
        int _kills;
        int _level;
};

#endif /* !CHARACTER_HPP_ */
