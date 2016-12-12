#ifndef _LINE_H_
#define _LINE_H_

#include "Figure.h"

class Line : public Figure
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
    }

    virtual void draw(BlackBoard &); 

private:
    int _x1, _y1; 
    int _x2, _y2; 
};

#endif // #ifndef _LINE_H_
