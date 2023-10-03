#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "King.h"

King::King(Color color, int x, int y, sf::Image image)
{
    Set_Type(king);
    Set_Color(color);
    Set_Position(x, y);
    Set_Sprite(image, 1);
}
void King::Show_Avalible_Positions()
{
    return;
}