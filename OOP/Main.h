#pragma once
#define SIZE 8
#include <SFML/Graphics.hpp>

extern sf::RenderWindow window;

enum Fig_Number
{
    castle, bishop, queen, king, knight, pawn, mark
};

enum Color
{
    black, white, none
};