#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Castle.h"

Castle::Castle(Color color, int x, int y, sf::Image image)
{
    Set_Type(castle);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}

void Castle::Show_Avalible_Positions(Table& table, int& c)
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
            if (table.Get_Position((y - offset) / size, x / size) == nullptr)
            {
                table.Set_Marker_Position(i, x, y - offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y - offset) / size, x / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x, y - offset);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
    flag = true;
    offset = size;
    while (flag)
    {
        if (y + offset >= height)
            flag = false;
        if (flag)
        {
            if (table.Get_Position((y + offset) / size, x / size) == nullptr)
            {
                table.Set_Marker_Position(i, x, y + offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y + offset) / size, x / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x, y + offset);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
    flag = true;
    offset = size;
    while (flag)
    {
        if (x + offset >= width)
            flag = false;
        if (flag)
        {
            if (table.Get_Position(y / size, (x + offset) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x + offset, y);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position(y / size, (x + offset) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x + offset, y);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
    flag = true;
    offset = size;
    while (flag)
    {
        if (x - offset <= -size)
            flag = false;
        if (flag)
        {
            if (table.Get_Position(y / size, (x - offset) / size) == nullptr)
            {
                table.Set_Marker_Position(i, x - offset, y);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position(y / size, (x - offset) / size)->Get_Color() != color)
            {
                table.Set_Marker_Position(i, x - offset, y);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
}