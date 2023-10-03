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

Table::Table(sf::RectangleShape mass_of_rects[SIZE][SIZE], sf::Image image)
{
    int index = 0, c = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            mass_of_rects[i][j].setSize(sf::Vector2f(100, 100));
            mass_of_rects[i][j].setPosition(100 * i, 100 * j);
            if (i % 2 == 0)
                if (index % 2 == 0)
                    mass_of_rects[i][j].setFillColor(sf::Color::White);
                else
                    mass_of_rects[i][j].setFillColor(sf::Color(40, 40, 40));
            else
                if (index % 2 == 0)
                    mass_of_rects[i][j].setFillColor(sf::Color(40, 40, 40));
                else
                    mass_of_rects[i][j].setFillColor(sf::Color::White);
            index++;
            if (i == 0)
            {
                if (j == 0 or j == 7)
                    mass[i][j] = new Castle(black, 100 * j, 0, image);
                if (j == 1 or j == 6)
                    mass[i][j] = new Knight(black, 100 * j, 0, image);
                if (j == 2 or j == 5)
                    mass[i][j] = new Bishop(black, 100 * j, 0, image);
                if (j == 3)
                    mass[i][j] = new Queen(black, 100 * j, 0, image);
                if (j == 4)
                    mass[i][j] = new King(black, 100 * j, 0, image);
            }
            if (i == 1)
                mass[i][j] = new Pawn(black, 100 * j, 100, image);
            if (i == 6)
                mass[i][j] = new Pawn(white, 100 * j, 600, image);
            if (i == 7)
            {
                if (j == 0 or j == 7)
                    mass[i][j] = new Castle(white, 100 * j, 700, image);
                if (j == 1 or j == 6)
                    mass[i][j] = new Knight(white, 100 * j, 700, image);
                if (j == 2 or j == 5)
                    mass[i][j] = new Bishop(white, 100 * j, 700, image);
                if (j == 3)
                    mass[i][j] = new Queen(white, 100 * j, 700, image);
                if (j == 4)
                    mass[i][j] = new King(white, 100 * j, 700, image);
            }
            if (i == 0 or i == 1 or i == 6 or i == 7)
                c++;
        }
}

Table::~Table()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (Get_Position(i, j) != nullptr)
                Delete(i, j);
}

void Table::Take_Position(Figure* figure, int i, int j)
{
    mass[i][j] = figure;
}

Figure* Table::Get_Position(int i, int j)
{
    return mass[i][j];
}

void Table::Reset_Position(int i, int j)
{
    mass[i][j] = nullptr;
}

void Table::Delete(int i, int j)
{
        switch (Get_Position(i, j)->Get_Type())
        {
        case pawn:
            delete (Pawn*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        case castle:
            delete (Castle*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        case knight:
            delete (Knight*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        case bishop:
            delete (Bishop*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        case queen:
            delete (Queen*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        case king:
            delete (King*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        case mark:
            delete (Marker*)Get_Position(i, j);
            mass[i][j] = nullptr;
            break;
        }
}

void Table::Draw()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (mass[i][j] != nullptr)
                mass[i][j]->Draw_Figure();
}