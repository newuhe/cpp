// Draw.cpp : 定义控制台应用程序的入口点。
//作业提交：

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "BlackBoard.h"
#include "FigureManager.h"

// 第五次作业提交时间：11月27日24:00点前
// 这是本次作业的测试代码，主要让同学们熟悉继承的用法
// 本次作业目的：实现一个绘图系统，用户输入相关图形(圆，线段，长方形)的参数，一次性画出所有输入图形
// 建议先实现一个类Figure，其他的图形都由Figure派生出。
// 此外，还需要实现FigureManager.h(cpp)，它提供图形参数输入的界面和控制，具体要求见FigureManager.cpp
// BlackBoard.h(cpp)不需要修改。它是一个实现绘图环境的类，
// 最终提交FigureManager.h(cpp),Figure.h(cpp),Circle.h(cpp),Line.h(cpp),Rectangle.h(cpp)，文件名固定

// 作业所有文件打包成.zip或.rar压缩包，以邮件附件形式，发送到邮箱 esecpp2016@163.com。邮件主题与压缩包名一致
// 压缩包命名规范：学号+姓名+第几次作业+第几版；比如：141180000+杰克+第五次作业+第一版（注意添加加号“+”），作业将以最后一次提交的为准




// 提供绘图环境的对象
BlackBoard board; 

// 可忽略
void ReshapeCallback(int width, int height)
{
	board.UpdateWindowSize(width, height); 
}

// 窗口用于处理键盘输入的回调函数入口，这里只处理了一件事，按q退出程序，可忽略
// 注意，这里的键盘输入是窗口的键盘输入，而不是命令行的
void KeyboardCallback(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		exit(0);
		break; 
	}

}

// 窗口用于绘制的回调函数入口，最终会调用FigureManager的display函数
// 本次作业无需改动DisplayCallback，绘制图形应在FigureManager中完成。
void DisplayCallback()
{
	board.Clear(); 

	FigureManager::handle().display(board); 

	board.Flush(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	// 如果你的实现需要一些必要的初始化，可放在这个函数中，main函数会调用
	// 如果没有，则忽略
	InitiateFigureManager(); 

	// 这里可切换输入方式：
	// 1、从test.txt文件输入，以方便调试时键盘输入费时。
	// 2、从命令行输入，以帮助在没有完全编写好代码时，无法用test.txt测试

#if 1
	std::ifstream in("test.txt");  
	if (! in.is_open())  
	{ 
		std::cout << "Error opening file"; 
		exit (1); 
	}  
	FigureManager::handle().input(in); 
#else
	FigureManager::handle().input(std::cin); 
#endif

	// 以下代码用于初始化窗口等、可忽略
	board.InitCommandLine(&argc, (char **)argv); 
	board.InitWindowSize(800, 800); 

	board.InitDisplayCallback(DisplayCallback); 
	board.InitKeyboardCallback(KeyboardCallback); 
	board.InitReshapeCallback(ReshapeCallback); 

	board.Show(); 

	return 0;
}

