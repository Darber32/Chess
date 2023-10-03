#pragma once
#include "Figure.h"

class Pawn : public Figure
{
public:
    Pawn(Color color, int x, int y, sf::Image image);
    void Show_Avalible_Positions(Table& table, int& c, Marker** figure_mass);
};