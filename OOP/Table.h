#pragma once
#include "Main.h"
#include <SFML/Graphics.hpp>

class Figure;

class Marker;

class Table
{
protected:
    Figure* mass[SIZE][SIZE] = { nullptr };
    Marker* marker_mass[32] = {nullptr};
public:
    Table(sf::RectangleShape mass_of_rects[SIZE][SIZE], sf::Image image, sf::Image image_2);
    ~Table();
    void Take_Position(Figure* figure, int i, int j);
    Figure* Get_Position(int i, int j);
    void Reset_Position(int i, int j);
    void Delete(int i, int j);
    void Set_Marker_Position(int i, int x, int y);
    sf::Vector2u Get_Marker_Coords(int i);
    void Marker_Clear();
    void Draw();
};