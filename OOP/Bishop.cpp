#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Bishop.h"

Bishop::Bishop(Color color, int x, int y, sf::Image image)
{
    Set_Type(bishop);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}
void Bishop::Show_Avalible_Positions(Table& table, int& c)
{
    table.Marker_Clear();
    c = 0;
    int i = 0, offset = size;
    bool flag = true;
    while (flag)
    {
        if (y - offset <= -size)
            flag = false;
        if (flag)
        {
            if (x - offset <= -size)
                flag = false;
            if (table.Get_Position((y - offset) / size, (x - offset) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - offset, y - offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y - offset) / size, (x - offset) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - offset, y - offset);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
    offset = size;
    flag = true;
    while (flag)
    {
        if (y - offset <= -size)
            flag = false;
        if (flag)
        {
            if (x + offset >= width)
                flag = false;
            if (table.Get_Position((y - offset) / size, (x + offset) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + offset, y - offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y - offset) / size, (x + offset) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + offset, y - offset);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
    offset = size;
    flag = true;
    while (flag)
    {
        if (y + offset >= height)
            flag = false;
        if (flag)
        {
            if (x + offset >= width)
                flag = false;
            if (table.Get_Position((y + offset) / size, (x + offset) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + offset, y + offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y + offset) / size, (x + offset) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + offset, y + offset);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
    offset = size;
    flag = true;
    while (flag)
    {
        if (y + offset >= height)
            flag = false;
        if (flag)
        {
            if (x - offset <= -size)
                flag = false;
            if (table.Get_Position((y + offset) / size, (x - offset) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - offset, y + offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y + offset) / size, (x - offset) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - offset, y + offset);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
}