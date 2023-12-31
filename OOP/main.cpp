#include <iostream>
#include "Main.h"
#include "Table.h"
#include "Figure.h"
#include "Pawn.h"
#include "Castle.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Marker.h"
#include "Game.h"

int width = 1000;
int height = 1000;
sf::RenderWindow window(sf::VideoMode(width, height), "Chess!");

int main()
{
    Game game;
    game.Start();
    return 0;
}