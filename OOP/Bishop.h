#pragma once
#include "Figure.h"

class Bishop : public Figure
{
public:
    Bishop(Color color, int x, int y, sf::Image image);
    void Show_Avalible_Positions(Table& table, int& c, Figure** markers_mass);
};