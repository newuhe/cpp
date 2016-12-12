#include "stdafx.h"

#include "Rectangle.h"
#include "BlackBoard.h"

void Rectangle::draw(BlackBoard &board)
{
	std:: cout << "Rectangle " 
		<< "(" << _left << ", " << _top << ") " 
		<< "(" << _right << ", " << _bottom << ") " 
		<< std::endl; 

	board.DrawLine(_left, _top, _left, _bottom); 
	board.DrawLine(_left, _bottom, _right, _bottom); 
	board.DrawLine(_right, _bottom, _right, _top); 
	board.DrawLine(_right, _top, _left, _top); 

}