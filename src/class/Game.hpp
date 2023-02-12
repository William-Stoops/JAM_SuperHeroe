//
// Created by Talleux on 10/02/2023.
//

#ifndef JAM_SUPERHEROE_GAME_HPP
    #define JAM_SUPERHEROE_GAME_HPP

    #include "Mob.hpp"
    #include "../ProgressBar.hpp"
    #include "../Character.hpp"
    #include "../SFML/Sfml.hpp"
    #include "Hud.hpp"
    #include "Exp.hpp"
    #include "../Character.hpp"

class Game
{
    public:
        Game() = default;
        Game(SFML sfml);

        std::vector<Mob> &getMobs();
        Character &getCharacter();

        //void animate();
        void animate(std::map<std::string, bool> &keyMap);
        void addMob(Mob mob);
        void removeMob(Mob mob);
        void removeMob(int index);
        void addExp(Exp exp);
        void removeExp(Exp exp);
        Hud &getHud();

        void draw(sf::RenderWindow &window);

    private:
        std::vector<Mob> _mobs;
        std::vector<Exp> _exp;
        ProgressBar _progressBar;
        Character _character;
        Hud _hud;
};


#endif //JAM_SUPERHEROE_GAME_HPP//
