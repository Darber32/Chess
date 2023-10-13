#pragma once
#include "Figure.h"

class Queen : public Figure
{
public:
    Queen(Color color, int x, int y, sf::Image image);
    void Show_Avalible_Positions(Table& table, int& c);
};