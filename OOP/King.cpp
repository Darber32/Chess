#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "King.h"

King::King(Color color, int x, int y, sf::Image image)
{
    Set_Type(king);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}
void King::Show_Avalible_Positions(Table& table, int& c)
{
    table.Marker_Clear();
    c = 0;
    int i = 0;
    if (y > 0)
    {
        if (table.Get_Position((y - size) / size, x / size) == nullptr)
        {
            table.Set_Marker_Position(i, x, y - size);
            i++;
            c++;
        }
        else if (table.Get_Position((y - size) / size, x / size)->Get_Color() != color)
        {
            table.Set_Marker_Position(i, x, y - size);
            i++;
            c++;
        }
        if (x > 0)
        {
            if (table.Get_Position((y - size) / size, (x-size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - size, y - size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - size) / size, (x- size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - size, y - size);
                i++;
                c++;
            }
        }
        if (x < width - size)
        {
            if (table.Get_Position((y - size) / size, (x + size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + size, y - size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - size) / size, (x + size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + size, y - size);
                i++;
                c++;
            }
        }
    }
    if (y < height - size)
    {
        if (table.Get_Position((y + size) / size, x / size) == nullptr)
        {
            table.Set_Marker_Position(i, x, y + size);
            i++;
            c++;
        }
        else if (table.Get_Position((y + size) / size, x / size)->Get_Color() != color)
        {
            table.Set_Marker_Position(i, x, y + size);
            i++;
            c++;
        }
        if (x > 0)
        {
            if (table.Get_Position((y + size) / size, (x - size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - size, y + size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + size) / size, (x - size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - size, y + size);
                i++;
                c++;
            }
        }
        if (x < width - size)
        {
            if (table.Get_Position((y + size) / size, (x + size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + size, y + size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + size) / size, (x + size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + size, y + size);
                i++;
                c++;
            }
        }
    }
    if (x > 0)
    {
        if (table.Get_Position(y / size, (x - size) / size) == nullptr)
        {
            table.Set_Marker_Position(i, x - size, y);
            i++;
            c++;
        }
        else if (table.Get_Position(y / size, (x - size) / size)->Get_Color() != color)
        {
            table.Set_Marker_Position(i, x - size, y);
            i++;
            c++;
        }
    }
    if (x < width - size)
    {
        if (table.Get_Position(y / size, (x + size) / size) == nullptr)
        {
            table.Set_Marker_Position(i, x + size, y);
            i++;
            c++;
        }
        else if (table.Get_Position(y / size, (x + size) / size)->Get_Color() != color)
        {
            table.Set_Marker_Position(i, x + size, y);
            i++;
            c++;
        }
    }
}