#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Figure.h"

class Rectangle : public Figure
{
public:
    virtual void input(std::istream &is)
    {
        std::cout << "Left: "; 
        is >> _left; 
		std::cout << "Top: "; 
        is >> _top; 
		
		std::cout << "Right: "; 
        is >> _right; 
		std::cout << "Bottom: "; 
        is >> _bottom; 
    }

    virtual void draw(BlackBoard &); 

private:
    int _left, _top, _right, _bottom; 
};

#endif // #ifndef _RECTANGLE_H_
