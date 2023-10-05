#include "Main.h"
#include "Figure.h"
#include "Table.h"
#include "Marker.h"

Marker::Marker(sf::Image image)
{
    Set_Type(mark);
    Set_Color(none);
    Set_Position(800, 800);
    Set_Sprite(image, 2);
}