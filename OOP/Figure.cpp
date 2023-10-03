#include "Main.h"
#include "Table.h"
#include "Figure.h"
#include "Marker.h"
#include <SFML/Graphics.hpp>

Figure::Figure()
{
    size = 100;
}

void Figure::Set_Color(Color color)
{
    this->color = color;
}

void Figure::Set_Type(Fig_Number type)
{
    this->type = type;
}

void Figure::Set_Sprite(sf::Image image, int type)
{
    texture.loadFromImage(image);
    sf::Vector2u vector = texture.getSize();
    sprite.setTexture(texture);
    switch (type)
    {
    case 1:
        sprite.setTextureRect(sf::IntRect(vector.x / 6 * this->type, vector.y / 2 * color, vector.x / 6, vector.y / 2));
        sprite.setScale(size / (vector.x / 6), size / (vector.y / 2));
        break;
    case 2:
        sprite.setScale(size / vector.x, size / vector.y);
        break;
    }

}

void Figure::Set_Position(int x, int y)
{
    this->x = x;
    this->y = y;
    sprite.setPosition(x, y);
}

Fig_Number Figure::Get_Type()
{
    return type;
}
sf::Vector2u Figure::Get_Coords()
{
    sf::Vector2u vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

int Figure::Get_Size()
{
    return size;
}
Color Figure::Get_Color()
{
    return color;
}
void Figure::Move(int x, int y, Table& table, Figure* figure, Marker* marker)
{
    sf::Vector2u vector = figure->Get_Coords();
    int i = vector.y / size, j = vector.x / size;
    table.Reset_Position(i, j);
    vector = marker->Get_Coords();
    i = vector.y / size;
    j = vector.x / size;
    if (table.Get_Position(i, j) != nullptr)
        table.Delete(i, j);
    Set_Position(x, y);
    /*vector = figure->Get_Coords();
    i = vector.y / size;
    j = vector.x / size;*/
    table.Take_Position(figure, i, j);
}
void Figure::Draw_Figure()
{
    window.draw(sprite);
}
void Figure::Show_Avalible_Positions(Table& table, int& c, Marker** markers_mass)
{
    return;

}