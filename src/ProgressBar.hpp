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
    HUD,
};

static std::map<ProgressBarType, sf::Vector2f> progressBarSize = {
    {HEALTH, sf::Vector2f(50, 5)},
    {WEAPONS, sf::Vector2f(50, 5)},
    {HUD, sf::Vector2f(400, 20)},
};

static std::map<ProgressBarType, std::map<std::string, sf::Color>> progressBarColor = {
    {
        HEALTH, {
            {"fullBar", sf::Color::Black},
            {"bar", sf::Color::Green},
        },
    },
    {
        WEAPONS, {
            {"fullBar", sf::Color::Black},
            {"bar", sf::Color(255, 165, 0)},
        },
    },
    {
        HUD, {
            {"fullBar", sf::Color::Black},
            {"bar", sf::Color::Red},
        },
    },
};

class ProgressBar {
    public:
        ProgressBar() = default;
        ProgressBar(float x, float y, ProgressBarType type) {
            _pos = sf::Vector2f(x, y);
            fullBar.setSize(progressBarSize[type]);
            fullBar.setFillColor(progressBarColor[type]["fullBar"]);
            fullBar.setPosition(_pos);
            bar.setSize(progressBarSize[type]);
            bar.setFillColor(progressBarColor[type]["bar"]);
            bar.setPosition(_pos);
            _type = type;
        }

        sf::Vector2f getPosition() const {
            return _pos;
        }

        sf::Vector2f getSize() const {
            return fullBar.getSize();
        }

        void setPosition(float x, float y) {
            _pos = sf::Vector2f(x, y);
            fullBar.setPosition(x, y);
            bar.setPosition(x, y);
        }

        void setValue(float value) {
            _value = value;
            if (_type == WEAPONS) {
                bar.setSize(sf::Vector2f((value / 10) * fullBar.getSize().x, fullBar.getSize().y));
                return;
            }
            bar.setSize(sf::Vector2f((value / _max) * fullBar.getSize().x, fullBar.getSize().y));
        }

        void draw(sf::RenderWindow &window) const {
            window.draw(fullBar);
            window.draw(bar);
        }

    private:
        sf::RectangleShape fullBar;
        sf::RectangleShape bar;
        sf::Vector2f _pos;
        float _max = 100;
        float _value = 100;
        ProgressBarType _type = HEALTH;
};

#endif /* !PROGRESSBAR_HPP_ */
