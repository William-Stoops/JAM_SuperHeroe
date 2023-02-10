/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** ProgressBar
*/

#ifndef PROGRESSBAR_HPP_
    #define PROGRESSBAR_HPP_
    #include <SFML/Graphics.hpp>
    #include <map>

enum ProgressBarType {
    HEALTH,
    WEAPONS,
};

static std::map<ProgressBarType, sf::Vector2f> progressBarSize = {
    {HEALTH, sf::Vector2f(50, 10)},
    {WEAPONS, sf::Vector2f(50, 50)},
};

static std::map<ProgressBarType, sf::Color> progressBarColor = {
    {HEALTH, sf::Color::Green},
    {WEAPONS, sf::Color::Blue},
};

class ProgressBar {
    public:
        ProgressBar() = default;
        ProgressBar(float x, float y, ProgressBarType type) {
            bar.setSize(progressBarSize[type]);
            bar.setFillColor(progressBarColor[type]);
            bar.setPosition(x, y);
            _pos = sf::Vector2f(x, y);
        }

        sf::Vector2f getPosition() const {
            return _pos;
        }

        void setPosition(float x, float y) {
            _pos = sf::Vector2f(x, y);
            bar.setPosition(x, y);
        }

        void draw(sf::RenderWindow &window) const {
            window.draw(bar);
        }

    private:
        sf::RectangleShape bar;
        sf::Vector2f _pos;
        float _max = 100;
        float _value = 100;
};

#endif /* !PROGRESSBAR_HPP_ */
