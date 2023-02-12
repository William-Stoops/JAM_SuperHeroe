/*
** EPITECH PROJECT, 2023
** JAM_SuperHeroe
** File description:
** main
*/

#ifndef MAIN_HPP_
    #define MAIN_HPP_

    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>
    #include <unistd.h>
    #include <string>
    #include <iostream>
    #include <limits.h>
    #include <list>
    #include <sys/utsname.h>
    #include "SFML/Sfml.hpp"
    #include "class/Game.hpp"
    #include <sstream>
    #include <map>

int game_over_loop(SFML sfml, int kills);
void game_start_loop(SFML sfml);
SFML sfml(void);

#endif /* !MAIN_HPP_ */
