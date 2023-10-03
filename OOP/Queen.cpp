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
void Queen::Show_Avalible_Positions()
{
    return;
}