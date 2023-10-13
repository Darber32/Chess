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

void Pawn::Show_Avalible_Positions(Table& table, int& c)
{
    table.Marker_Clear();
    c = 0;
    int i = 0;
    if (color == white)
    {
        if (y > 0)
        {
            if (table.Get_Position((y - size) / size, x / size) == nullptr)
            {
                table.Set_Marker_Position(i, x, y - size);
                i++;
                c++;
                if (y == height - 2 * size)
                    if (table.Get_Position((y - 2 * size) / size, x / size) == nullptr)
                    {
                        table.Set_Marker_Position(i, x, y - 2 * size);
                        i++;
                        c++;
                    }
            }
            if (table.Get_Position((y - size) / size, (x - size) / size) != nullptr)
                if (table.Get_Position((y - size) / size, (x - size) / size)->Get_Color() != color)
                {
                    table.Set_Marker_Position(i, x - size, y - size);
                    i++;
                    c++;
                }
            if (table.Get_Position((y - size) / size, (x + size) / size) != nullptr)
                if (table.Get_Position((y - size) / size, (x + size) / size)->Get_Color() != color)
                {
                    table.Set_Marker_Position(i, x + size, y - size);
                    i++;
                    c++;
                }
        }
    }
    else
    {
        if (y < height - size)
        {
            if (table.Get_Position((y + size) / size, x / size) == nullptr)
            {
                table.Set_Marker_Position(i, x, y + size);
                i++;
                c++;
                if (y == size)
                    if (table.Get_Position((y + 2 * size) / size, x / size) == nullptr)
                    {
                        table.Set_Marker_Position(i, x, y + 2 * size);
                        i++;
                        c++;
                    }
            }
            if (table.Get_Position((y + size) / size, (x - size) / size) != nullptr)
                if (table.Get_Position((y + size) / size, (x - size) / size)->Get_Color() != color)
                {
                    table.Set_Marker_Position(i, x - size, y + size);
                    i++;
                    c++;
                }
            if (table.Get_Position((y + size) / size, (x + size) / size) != nullptr)
                if (table.Get_Position((y + size) / size, (x + size) / size)->Get_Color() != color)
                {
                    table.Set_Marker_Position(i, x + size, y + size);
                    i++;
                    c++;
                }
        }
    }
}