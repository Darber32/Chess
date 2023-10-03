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
void Bishop::Show_Avalible_Positions()
{
    return;
}