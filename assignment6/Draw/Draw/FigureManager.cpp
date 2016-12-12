#include "stdafx.h" 

#include <iostream>

#include "FigureManager.h"

#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::cout; 

void FigureManager::input(std::istream &is)
{
    while (1)
    {
        // Factory Pattern
        // 好处是将所有可能增加的类型的构造放到其中
        // 使得类型扩展时，无需对使用者做任何修改
        // FigureManager作为客户，甚至不依赖于各种类型的构造
        // 不依赖 = 不知道
        // 不知道 = 扩展无需更改
        cout << "intput type("; 
        for (Factories::iterator iter = factories.begin(); 
            iter != factories.end(); ++iter)
        {
            cout << (*iter)->id(); 
            cout << " : "; 
            cout << (*iter)->name();
            cout << ", "; 
        }
        cout << "0 : quit)" << std::endl; 

        int type; 
        is >> type; 

        if (type == 0){
            return; 
        }

        for (Factories::iterator iter = factories.begin(); 
            iter != factories.end(); ++iter)
        {
            if (type == (*iter)->id())
            {
                // 所有的工程都是FigureFactory
                // 无需知道是什么类型
                // 再次：不知道 = 扩展无需更改 = 高扩展性
                Figure *figure = (*iter)->createFigure(); 

                // 对FigureManager来说，所有的绘图类型都是Figure
                // 无需关注各个类型具体如何input
                // 因此，各种类型的Draw，任意扩展都不会影响FigureManager
                figure->input(is); 
                _figures.push_back(figure); 
            }
        }
    }
}

void FigureManager::display(BlackBoard &board)
{
    // 对FigureManager来说，所有的绘图类型都是Figure
    // 无需关注各个类型具体如何Draw
    // 因此，各种类型的Draw，任意扩展都不会影响FigureManager
    for (Figures::iterator iter = _figures.begin(); 
        iter != _figures.end(); ++iter)
    {
        (*iter)->draw(board); 
    }
}


void InitiateFigureManager()
{
	FigureManager::handle().installFactory(new Factory<Circle>("Circle", FigureManager::handle().assignID())); 
	FigureManager::handle().installFactory(new Factory<Line>("Line", FigureManager::handle().assignID())); 
	FigureManager::handle().installFactory(new Factory<Rectangle>("Rectangle", FigureManager::handle().assignID())); 
	FigureManager::handle().installFactory(new Factory<Triangle>("Triangle", FigureManager::handle().assignID())); 
}


