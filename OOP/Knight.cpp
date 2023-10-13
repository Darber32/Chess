#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Knight.h"

Knight::Knight(Color color, int x, int y, sf::Image image)
{
    Set_Type(knight);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}
void Knight::Show_Avalible_Positions(Table& table, int& c)
{
    table.Marker_Clear();
    c = 0;
    int i = 0;
    if (y > size)
    {
        if (x > 0)
        {
            if (table.Get_Position((y - 2 * size) / size, (x - size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - size, y - 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - 2 * size) / size, (x - size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - size, y - 2 * size);
                i++;
                c++;
            }
        }
        if (x < width - size)
        {
            if (table.Get_Position((y - 2 * size) / size, (x + size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + size, y - 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - 2 * size) / size, (x + size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + size, y - 2 * size);
                i++;
                c++;
            }
        }
    }
    if (y < height - 2 * size)
    {
        if (x > 0)
        {
            if (table.Get_Position((y + 2 * size) / size, (x - size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - size, y + 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + 2 * size) / size, (x - size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - size, y + 2 * size);
                i++;
                c++;
            }
        }
        if (x < width - size)
        {
            if (table.Get_Position((y + 2 * size) / size, (x + size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + size, y + 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + 2 * size) / size, (x + size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + size, y + 2 * size);
                i++;
                c++;
            }
        }
    }
    if (x > size)
    {
        if (y > 0)
        {
            if (table.Get_Position((y - size) / size, (x - 2 * size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - 2 * size, y - size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - size) / size, (x - 2 * size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - 2 * size, y - size);
                i++;
                c++;
            }
        }
        if (y < height - size)
        {
            if (table.Get_Position((y + size) / size, (x - 2 * size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - 2 * size, y + size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + size) / size, (x - 2 * size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - 2 * size, y + size);
                i++;
                c++;
            }
        }
    }
    if (x < width - 2 * size)
    {
        if (y > 0)
        {
            if (table.Get_Position((y - size) / size, (x + 2 * size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + 2 * size, y - size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - size) / size, (x + 2 * size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + 2 * size, y - size);
                i++;
                c++;
            }
        }
        if (y < height - size)
        {
            if (table.Get_Position((y + size) / size, (x + 2 * size) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + 2 * size, y + size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + size) / size, (x + 2 * size) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + 2 * size, y + size);
                i++;
                c++;
            }
        }
    }
}