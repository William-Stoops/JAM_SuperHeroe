//
// Created by Talleux on 10/02/2023.
//

#ifndef JAM_SUPERHEROE_GAME_HPP
    #define JAM_SUPERHEROE_GAME_HPP

    #include "Mob.hpp"
    #include "../ProgressBar.hpp"
    #include "../Character.hpp"
    #include "../SFML/Sfml.hpp"

class Game
{
    public:
        Game() = default;
        Game(SFML sfml);

        std::vector<Mob> getMobs();
        Character &getCharacter();

        void addMob(Mob mob);
        void removeMob(Mob mob);
        void removeMob(int index);

        void draw(sf::RenderWindow &window) const;

    private:
        std::vector<Mob> _mobs;
        ProgressBar _progressBar;
        Character _character;
};


#endif //JAM_SUPERHEROE_GAME_HPP
