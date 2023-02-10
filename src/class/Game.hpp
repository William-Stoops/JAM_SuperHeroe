//
// Created by Talleux on 10/02/2023.
//

#ifndef JAM_SUPERHEROE_GAME_HPP
#define JAM_SUPERHEROE_GAME_HPP


class Game
{
    public:
        Game();
        ~Game() = default;

        void getMobs();

        void addMob(Mob mob);
        void removeMob(Mob mob);
        void removeMob(int index);

    private:
        std::vector<Mob> _mobs;
};


#endif //JAM_SUPERHEROE_GAME_HPP
