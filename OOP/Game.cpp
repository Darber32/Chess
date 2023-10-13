#include "Game.h"
#include "Table.h"
#include "Figure.h"

Game::Game()
{
	color = white;
	image.loadFromFile("Figures.png");
	image_mark.loadFromFile("Mark.png");
    table = new Table(mass_of_rects, image, image_mark);
}

Game::~Game()
{
    delete table;
}

void Game::Left_Buttom_Pressed()
{
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            if (table->Get_Position(i, j) != nullptr)
            {
                vector = table->Get_Position(i, j)->Get_Coords();
                int size = table->Get_Position(i, j)->Get_Size();
                if (event.mouseButton.x >= vector.x and event.mouseButton.x <= vector.x + size and event.mouseButton.y >= vector.y and event.mouseButton.y <= vector.y + size)
                {
                    if (color == table->Get_Position(i, j)->Get_Color())
                    {
                        table->Get_Position(i, j)->Show_Avalible_Positions(*table, count_of_markers);
                        figure_i = i;
                        figure_j = j;
                    }
                }
            }
        }
    for (int i = 0; i < count_of_markers; i++)
        if (count_of_markers != 0)
        {
            vector = table->Get_Marker_Coords(i);
            int size = table->Get_Position(figure_i, figure_j)->Get_Size();
            if (event.mouseButton.x >= vector.x and event.mouseButton.x <= vector.x + size and event.mouseButton.y >= vector.y and event.mouseButton.y <= vector.y + size)
            {
                table->Get_Position(figure_i, figure_j)->Move(vector.x, vector.y, *table, table->Get_Position(figure_i, figure_j), i);
                table->Marker_Clear();
                count_of_markers = 0;
                if (color == white)
                    color = black;
                else
                    color = white;
            }
        }
}

void Game::Right_Button_Pressed()
{
    table->Marker_Clear();
    count_of_markers = 0;
}

void Game::Draw()
{
    window.clear();
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            window.draw(mass_of_rects[i][j]);
    table->Draw();
    window.display();
}

void Game::Start()
{
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed)
            {
                Left_Buttom_Pressed();

            }
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                Right_Button_Pressed();
            }
        }
        Draw();
    }
}