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

sf::RenderWindow window(sf::VideoMode(800, 800), "Chess!");

void Draw(sf::RectangleShape mass_of_rects[SIZE][SIZE], Table& table, Marker ** markers_mass)
{
    window.clear();
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            window.draw(mass_of_rects[i][j]);
    table.Draw();
    for (int i = 0; i < 32; i++)
        markers_mass[i]->Draw_Figure();
    window.display();
}

int main()
{
    sf::RectangleShape mass_of_rects[SIZE][SIZE];
    sf::Image image, image_mark;
    image.loadFromFile("Figures.png");
    image_mark.loadFromFile("Mark.png");
    Marker ** markers_mass = new Marker * [32];
    for (int i = 0; i < 32; i++)
        markers_mass[i] = new Marker(image_mark);
    Table table(mass_of_rects, image);
    int count_of_markers = 0, figure_i, figure_j;
    Color color = white;
    sf::Vector2u vector;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    for (int i = 0; i < SIZE; i++)
                        for (int j = 0; j < SIZE; j++)
                        {
                            if (table.Get_Position(i, j) != nullptr)
                            {
                                vector = table.Get_Position(i, j)->Get_Coords();
                                int size = table.Get_Position(i, j)->Get_Size();
                                if (event.mouseButton.x >= vector.x and event.mouseButton.x <= vector.x + size and event.mouseButton.y >= vector.y and event.mouseButton.y <= vector.y + size)
                                {
                                    if (color == table.Get_Position(i, j)->Get_Color())
                                    {
                                        table.Get_Position(i, j)->Show_Avalible_Positions(table, count_of_markers, (Figure**) markers_mass);
                                        figure_i = i;
                                        figure_j = j;
                                    }
                                }
                            }
                        }
                    for (int i = 0; i < count_of_markers; i++)
                        if (count_of_markers != 0)
                        {
                            vector = markers_mass[i]->Get_Coords();
                            int size = table.Get_Position(figure_i, figure_j)->Get_Size();
                            if (event.mouseButton.x >= vector.x and event.mouseButton.x <= vector.x + size and event.mouseButton.y >= vector.y and event.mouseButton.y <= vector.y + size)
                            {
                                table.Get_Position(figure_i, figure_j)->Move(vector.x, vector.y, table, table.Get_Position(figure_i, figure_j), markers_mass[i]);
                                for (int i = 0; i < count_of_markers; i++)
                                    markers_mass[i]->Clear(markers_mass[i]);
                                count_of_markers = 0;
                                if (color == white)
                                    color = black;
                                else
                                    color = white;
                            }
                        }
                }
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    for (int i = 0; i < count_of_markers; i++)
                        markers_mass[i]->Clear(markers_mass[i]);
                    count_of_markers = 0;
                }
                    
            }
        }
        Draw(mass_of_rects, table, markers_mass);
    }
    table.~Table();
    return 0;
}