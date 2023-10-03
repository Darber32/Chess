#pragma once
#include "Figure.h"

class Marker
{
public:
    Marker(sf::Image image);
    void Set_Color(Color color);
    void Set_Type(Fig_Number type);
    void Set_Sprite(sf::Image image, int type);
    void Set_Position(int x, int y);
    Fig_Number Get_Type();
    sf::Vector2u Get_Coords();
    int Get_Size();
    Color Get_Color();
    void Draw_Figure();
    void Clear(Marker* markers_mass);
private:
    int x, y;
    double size;
    Fig_Number type;
    Color color;
    sf::Texture texture;
    sf::Sprite sprite;
};