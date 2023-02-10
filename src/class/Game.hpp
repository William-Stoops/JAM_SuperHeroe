//
// Created by Talleux on 10/02/2023.
//

#ifndef JAM_SUPERHEROE_GAME_HPP
    #define JAM_SUPERHEROE_GAME_HPP

    #include "Mob.hpp"
    #include "../ProgressBar.hpp"

class Game
{
    public:
        Game();
        ~Game() = default;

        std::vector<Mob> getMobs();

        void addMob(Mob mob);
        void removeMob(Mob mob);
        void removeMob(int index);

    private:
        std::vector<Mob> _mobs;
        ProgressBar _progressBar;
};


#endif //JAM_SUPERHEROE_GAME_HPP
