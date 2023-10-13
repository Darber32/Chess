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

Table::Table(sf::RectangleShape mass_of_rects[SIZE][SIZE], sf::Image image, sf::Image image_2)
{
    int index = 0, c = 0;
    int w = width / 8, h = height / 8;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            mass_of_rects[i][j].setSize(sf::Vector2f(w, h));
            mass_of_rects[i][j].setPosition(w * i, h * j);
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
                    mass[i][j] = new Castle(black, h * j, 0, image);
                if (j == 1 or j == 6)
                    mass[i][j] = new Knight(black, h * j, 0, image);
                if (j == 2 or j == 5)
                    mass[i][j] = new Bishop(black, h * j, 0, image);
                if (j == 3)
                    mass[i][j] = new Queen(black, h * j, 0, image);
                if (j == 4)
                    mass[i][j] = new King(black, h * j, 0, image);
            }
            if (i == 1)
                mass[i][j] = new Pawn(black, h * j, w, image);
            if (i == 6)
                mass[i][j] = new Pawn(white, h * j, w * 6, image);
            if (i == 7)
            {
                if (j == 0 or j == 7)
                    mass[i][j] = new Castle(white, h * j, w * 7, image);
                if (j == 1 or j == 6)
                    mass[i][j] = new Knight(white, h * j, w * 7, image);
                if (j == 2 or j == 5)
                    mass[i][j] = new Bishop(white, h * j, w * 7, image);
                if (j == 3)
                    mass[i][j] = new Queen(white, h * j, w * 7, image);
                if (j == 4)
                    mass[i][j] = new King(white, h * j, w * 7, image);
            }
            if (i == 0 or i == 1 or i == 6 or i == 7)
                c++;
        }
    for (int i = 0; i < 32; i++)
        marker_mass[i] = new Marker(image_2);
}

Table::~Table()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (Get_Position(i, j) != nullptr)
                Delete(i, j);
    for (int i = 0; i < 32; i++)
        delete marker_mass[i];
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

void Table::Set_Marker_Position(int i, int x, int y)
{
    marker_mass[i]->Set_Position(x, y);
}

sf::Vector2u Table::Get_Marker_Coords(int i)
{
    return marker_mass[i]->Get_Coords();
}

void Table::Marker_Clear()
{
    for (int i = 0; i < 32; i++)
        marker_mass[i]->Clear(marker_mass[i]);
}

void Table::Draw()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (mass[i][j] != nullptr)
                mass[i][j]->Draw_Figure();
    for (int i = 0; i < 32; i++)
        marker_mass[i]->Draw_Figure();
}