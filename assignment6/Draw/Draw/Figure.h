#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <string>

class BlackBoard; 

/// @brief [类的概要描述]
///
/// [描述你的类.]
///
/// @see 
///
class Figure
{
public:
    // Figure类析构函数
    virtual ~Figure() { }
 
    // Figure类接口.
public:
    // 所有Figure派生类都会提供这两个接口，
    // 从而使使用者（FigureManager）可无需依赖
    // 于不同的绘图类型的实现
    // 不依赖 = 不知道
    // 不知道 = 扩展无需更改
    virtual void draw(BlackBoard &) = 0; 
    virtual void input(std::istream &is) = 0; 

}; // class Figure类定义结束.

// Factory Pattern
class FigureFactory
{
public:
    FigureFactory(const std::string &name, int id) 
        : _name(name), _id(id) { }

    int id() { return _id; } 
    const std::string &name() { return _name; }

    virtual Figure *createFigure() = 0; 
    virtual ~FigureFactory() { }
private:
    std::string _name; 
    int _id; 
};

// 用于实现编译器多态
// 从而简化对工程类的构造
template<class T>
class Factory : public FigureFactory
{
public:
    Factory(const std::string name, int id) 
        : FigureFactory(name, id) { }

    virtual Figure *createFigure()
    {
        return new T; 
    }
};


#endif // #ifndef _FIGURE_H_
