#include "stdafx.h"

#include "Triangle.h"
#include "BlackBoard.h"

void Triangle::draw(BlackBoard &board)
{
	std::cout << "Triangle " 
		<< "(" << _x1 << ", " << _y1 << ") " 
		<< "(" << _x2 << ", " << _y2 << ") " 
		<< "(" << _x3 << ", " << _y3 << ") " 
		<< std::endl;

	board.DrawLine(_x1, _y1, _x2, _y2); 
	board.DrawLine(_x2, _y2, _x3, _y3); 
	board.DrawLine(_x3, _y3, _x1, _y1); 

}