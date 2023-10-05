#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Queen.h"

Queen::Queen(Color color, int x, int y, sf::Image image)
{
    Set_Type(queen);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}
void Queen::Show_Avalible_Positions(Table& table, int& c, Figure** markers_mass)
{
    for (int i = 0; i < c; i++)
        markers_mass[i]->Clear(markers_mass[i]);
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
                markers_mass[i]->Set_Position(x - offset, y - offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y - offset) / size, (x - offset) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - offset, y - offset);
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
            if (x + offset >= 800)
                flag = false;
            if (table.Get_Position((y - offset) / size, (x + offset) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + offset, y - offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y - offset) / size, (x + offset) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + offset, y - offset);
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
        if (y + offset >= 800)
            flag = false;
        if (flag)
        {
            if (x + offset >= 800)
                flag = false;
            if (table.Get_Position((y + offset) / size, (x + offset) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + offset, y + offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y + offset) / size, (x + offset) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + offset, y + offset);
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
        if (y + offset >= 800)
            flag = false;
        if (flag)
        {
            if (x - offset <= -size)
                flag = false;
            if (table.Get_Position((y + offset) / size, (x - offset) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x - offset, y + offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y + offset) / size, (x - offset) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - offset, y + offset);
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
        if (y - offset <= -size)
            flag = false;
        if (flag)
        {
            if (table.Get_Position((y - offset) / size, x / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x, y - offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y - offset) / size, x / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x, y - offset);
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
        if (y + offset >= 800)
            flag = false;
        if (flag)
        {
            if (table.Get_Position((y + offset) / size, x / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x, y + offset);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position((y + offset) / size, x / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x, y + offset);
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
        if (x + offset >= 800)
            flag = false;
        if (flag)
        {
            if (table.Get_Position(y / size, (x + offset) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + offset, y);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position(y / size, (x + offset) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + offset, y);
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
                markers_mass[i]->Set_Position(x - offset, y);
                i++;
                c++;
                offset += size;
            }
            else if (table.Get_Position(y / size, (x - offset) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - offset, y);
                i++;
                c++;
                flag = false;
            }
            else
                flag = false;
        }
    }
}