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

void Castle::Show_Avalible_Positions()
{
    return;
}