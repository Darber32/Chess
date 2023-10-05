#pragma once
#include "Figure.h"

class Castle : public Figure
{
public:
    Castle(Color color, int x, int y, sf::Image image);
    void Show_Avalible_Positions(Table& table, int& c, Figure** markers_mass);
};
