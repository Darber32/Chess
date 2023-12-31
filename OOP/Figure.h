#pragma once
#include "Main.h"
#include <SFML/Graphics.hpp>

class Table;

class Figure
{
public:
    Figure();
    void Set_Color(Color color);
    void Set_Type(Fig_Number type);
    void Set_Sprite(sf::Image image, int type);
    void Set_Position(int x, int y);
    Fig_Number Get_Type();
    sf::Vector2u Get_Coords();
    int Get_Size();
    Color Get_Color();
    void Move(int x, int y, Table& table, Figure* figure, int index);
    void Draw_Figure();
    virtual void Show_Avalible_Positions(Table& table, int& c);
protected:
    int x, y;
    double size;
    Fig_Number type;
    Color color;
    sf::Texture texture;
    sf::Sprite sprite;
};