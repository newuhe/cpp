#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "Figure.h"

class Triangle : public Figure
{
public:
    virtual void input(std::istream &is)
    {
        std::cout << "X1: "; 
        is >> _x1; 
		std::cout << "Y1: "; 
        is >> _y1; 
		
		std::cout << "X2: "; 
        is >> _x2; 
		std::cout << "Y2: "; 
        is >> _y2; 
		
		std::cout << "X3: "; 
        is >> _x3; 
		std::cout << "Y3: "; 
        is >> _y3; 
    }

    virtual void draw(BlackBoard &board); 

private:
    int _x1, _y1; 
	int _x2, _y2; 
	int _x3, _y3; 
};

#endif // #ifndef _TRIANGLE_H_
