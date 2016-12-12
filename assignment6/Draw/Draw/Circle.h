#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Figure.h"

class Circle : public Figure
{
public:
    virtual void input(std::istream &is)
    {
		std::cout << "Center X: "; 
        is >> _x; 
		
		std::cout << "Center Y: "; 
        is >> _y; 
		
		std::cout << "Radius: "; 
        is >> _radius; 
    }

    virtual void draw(BlackBoard &); 

private:
    int _radius, _x, _y; 
};


#endif // #ifndef _CIRCLE_H_
