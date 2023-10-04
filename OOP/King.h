#pragma once
#include "Figure.h"

class King : public Figure
{
public:
    King(Color color, int x, int y, sf::Image image);
    void Show_Avalible_Positions(Table& table, int& c, Marker** markers_mass);
};