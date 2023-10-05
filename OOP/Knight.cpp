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
void Knight::Show_Avalible_Positions(Table& table, int& c, Figure** markers_mass)
{
    for (int i = 0; i < c; i++)
        markers_mass[i]->Clear(markers_mass[i]);
    c = 0;
    int i = 0;
    if (y > 100)
    {
        if (x > 0)
        {
            if (table.Get_Position((y - 2 * size) / size, (x - size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x - size, y - 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - 2 * size) / size, (x - size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - size, y - 2 * size);
                i++;
                c++;
            }
        }
        if (x < 700)
        {
            if (table.Get_Position((y - 2 * size) / size, (x + size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + size, y - 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - 2 * size) / size, (x + size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + size, y - 2 * size);
                i++;
                c++;
            }
        }
    }
    if (y < 600)
    {
        if (x > 0)
        {
            if (table.Get_Position((y + 2 * size) / size, (x - size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x - size, y + 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + 2 * size) / size, (x - size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - size, y + 2 * size);
                i++;
                c++;
            }
        }
        if (x < 700)
        {
            if (table.Get_Position((y + 2 * size) / size, (x + size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + size, y + 2 * size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + 2 * size) / size, (x + size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + size, y + 2 * size);
                i++;
                c++;
            }
        }
    }
    if (x > 100)
    {
        if (y > 0)
        {
            if (table.Get_Position((y - size) / size, (x - 2 * size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x - 2 * size, y - size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - size) / size, (x - 2 * size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - 2 * size, y - size);
                i++;
                c++;
            }
        }
        if (y < 700)
        {
            if (table.Get_Position((y + size) / size, (x - 2 * size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x - 2 * size, y + size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + size) / size, (x - 2 * size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x - 2 * size, y + size);
                i++;
                c++;
            }
        }
    }
    if (x < 600)
    {
        if (y > 0)
        {
            if (table.Get_Position((y - size) / size, (x + 2 * size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + 2 * size, y - size);
                i++;
                c++;
            }
            else if (table.Get_Position((y - size) / size, (x + 2 * size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + 2 * size, y - size);
                i++;
                c++;
            }
        }
        if (y < 700)
        {
            if (table.Get_Position((y + size) / size, (x + 2 * size) / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x + 2 * size, y + size);
                i++;
                c++;
            }
            else if (table.Get_Position((y + size) / size, (x + 2 * size) / size)->Get_Color() != color)
            {
                markers_mass[i]->Set_Position(x + 2 * size, y + size);
                i++;
                c++;
            }
        }
    }
}