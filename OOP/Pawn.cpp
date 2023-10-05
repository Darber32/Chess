#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Pawn.h"
#include "Marker.h"

Pawn::Pawn(Color color, int x, int y, sf::Image image)
{
    Set_Type(pawn);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}

void Pawn::Show_Avalible_Positions(Table& table, int& c, Marker** markers_mass)
{
    for (int i = 0; i < c; i++)
        markers_mass[i]->Clear(markers_mass[i]);
    c = 0;
    int i = 0;
    if (color == white)
    {
        if (y > 0)
        {
            if (table.Get_Position((y - size) / size, x / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x, y - size);
                i++;
                c++;
                if (y == 600)
                    if (table.Get_Position((y - 2 * size) / size, x / size) == nullptr)
                    {
                        markers_mass[i]->Set_Position(x, y - 2 * size);
                        i++;
                        c++;
                    }
            }
            if (table.Get_Position((y - size) / size, (x - size) / size) != nullptr)
                if (table.Get_Position((y - size) / size, (x - size) / size)->Get_Color() != color)
                {
                    markers_mass[i]->Set_Position(x - size, y - size);
                    i++;
                    c++;
                }
            if (table.Get_Position((y - size) / size, (x + size) / size) != nullptr)
                if (table.Get_Position((y - size) / size, (x + size) / size)->Get_Color() != color)
                {
                    markers_mass[i]->Set_Position(x + size, y - size);
                    i++;
                    c++;
                }
        }
    }
    else
    {
        if (y < 700)
        {
            if (table.Get_Position((y + size) / size, x / size) == nullptr)
            {
                markers_mass[i]->Set_Position(x, y + size);
                i++;
                c++;
                if (y == 100)
                    if (table.Get_Position((y + 2 * size) / size, x / size) == nullptr)
                    {
                        markers_mass[i]->Set_Position(x, y + 2 * size);
                        i++;
                        c++;
                    }
            }
            if (table.Get_Position((y + size) / size, (x - size) / size) != nullptr)
                if (table.Get_Position((y + size) / size, (x - size) / size)->Get_Color() != color)
                {
                    markers_mass[i]->Set_Position(x - size, y + size);
                    i++;
                    c++;
                }
            if (table.Get_Position((y + size) / size, (x + size) / size) != nullptr)
                if (table.Get_Position((y + size) / size, (x + size) / size)->Get_Color() != color)
                {
                    markers_mass[i]->Set_Position(x + size, y + size);
                    i++;
                    c++;
                }
        }
    }
}