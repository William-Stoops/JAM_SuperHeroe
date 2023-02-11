/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** Hud
*/

#ifndef HUD_HPP_
    #define HUD_HPP_
    #include <iostream>
    #include <SFML/Graphics.hpp>

class Hud {
    public:
        Hud();

        void setKills(void);

        int getKills() const;

        void drawKills(sf::RenderWindow& window) const;
        void draw(sf::RenderWindow& window) const;

    private:
        int _kills;
};

#endif /* !HUD_HPP_ */
