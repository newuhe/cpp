#include "stdafx.h"

#include "Line.h"
#include "BlackBoard.h"

void Line::draw(BlackBoard &board)
{
	std::cout << "Line " 
		<< "(" << _x1 << ", " << _y1 << ") " 
		<< "(" << _x2 << ", " << _y2 << ") " 
		<< std::endl; 

	board.DrawLine(_x1, _y1, _x2, _y2); 

}