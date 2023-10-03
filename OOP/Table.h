#pragma once
#include "Main.h"
#include <SFML/Graphics.hpp>

class Figure;

class Marker;

class Table
{
protected:
    Figure* mass[SIZE][SIZE] = { nullptr };
public:
    Table(sf::RectangleShape mass_of_rects[SIZE][SIZE], sf::Image image);
    ~Table();
    void Take_Position(Figure* figure, int i, int j);
    Figure* Get_Position(int i, int j);
    void Reset_Position(int i, int j);
    void Delete(int i, int j);
    void Draw();
};