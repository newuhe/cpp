#include "stdafx.h"

#include "Circle.h"
#include "BlackBoard.h"

void Circle::draw(BlackBoard &board)
{
	std::cout << "Circle (" << _x << ", " << _y << ") " << _radius << std::endl; 

	board.DrawCircle(_x, _y, _radius); 

}