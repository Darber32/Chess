#pragma once
#include "Figure.h"

class Knight : public Figure
{
public:
    Knight(Color color, int x, int y, sf::Image image);
    void Show_Avalible_Positions();
};