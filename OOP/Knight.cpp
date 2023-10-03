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
void Knight::Show_Avalible_Positions()
{
    return;
}