#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Marker.h"

Marker::Marker(sf::Image image)
{
    size = 100;
    Set_Type(mark);
    Set_Color(none);
    Set_Position(800, 800);
    Set_Sprite(image, 2);
}

void Marker::Set_Color(Color color)
{
    this->color = color;
}

void Marker::Set_Type(Fig_Number type)
{
    this->type = type;
}

void Marker::Set_Sprite(sf::Image image, int type)
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

void Marker::Set_Position(int x, int y)
{
    this->x = x;
    this->y = y;
    sprite.setPosition(x, y);
}

Fig_Number Marker::Get_Type()
{
    return type;
}
sf::Vector2u Marker::Get_Coords()
{
    sf::Vector2u vector;
    vector.x = x;
    vector.y = y;
    return vector;
}

int Marker::Get_Size()
{
    return size;
}
Color Marker::Get_Color()
{
    return color;
}

void Marker::Draw_Figure()
{
    window.draw(sprite);
}

void Marker::Clear(Marker * markers_mass)
{
    markers_mass->Set_Position(800, 800);
}