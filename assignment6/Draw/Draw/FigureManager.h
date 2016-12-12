#ifndef _FIGUREMANAGER_H_
#define _FIGUREMANAGER_H_

#include <iostream>
#include <vector>

class BlackBoard; 
class Figure; 
class FigureFactory; 
/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class FigureManager
{
    typedef std::vector<Figure *> Figures; 
    typedef std::vector<FigureFactory *> Factories; 

public:
	static FigureManager &handle()
	{
		static FigureManager manager; 
		return manager; 
	}

    
    // FigureManager类析构函数
    virtual ~FigureManager() { }
 
    // FigureManager类接口.
public:
	void input(std::istream &is); 
    void display(BlackBoard &board); 
    void installFactory(FigureFactory *factory)
    {
        factories.push_back(factory); 
    }

    int assignID()
    {
        return ++_lastID; 
    }
    // FigureManager类protected成员函数.
protected:
	    
    // FigureManager类protected型成员变量.
protected:
	// FigureManager类构造函数.
	FigureManager() : _lastID(0) { }

     ///< 描述你的成员变量，如没有，请删除此行. 
    Figures _figures; 
    Factories factories; 

    int _lastID; 

}; // class FigureManager类定义结束.

void InitiateFigureManager(); 

#endif // #ifndef _FIGUREMANAGER_H_
