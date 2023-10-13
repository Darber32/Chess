#pragma once
#include "Main.h"
#include <SFML/Graphics.hpp>

class Table;

class Game
{
protected:
	sf::Event event;
	sf::RectangleShape mass_of_rects[SIZE][SIZE];
	sf::Image image, image_mark;
	Table * table;
	int count_of_markers = 0, figure_i, figure_j;
	Color color;
	sf::Vector2u vector;
public:
	Game();
	~Game();
	void Left_Buttom_Pressed();
	void Right_Button_Pressed();
	void Draw();
	void Start();
};