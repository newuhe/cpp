// Draw.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include "BlackBoard.h"
#include "FigureManager.h"

BlackBoard board; 

void ReshapeCallback(int width, int height)
{
	board.UpdateWindowSize(width, height); 
}

void KeyboardCallback(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
		exit(0);
		break; 
	}

}

void DisplayCallback()
{
	board.Clear(); 

	FigureManager::handle().display(board); 

	board.Flush(); 
}

int _tmain(int argc, _TCHAR* argv[])
{
	InitiateFigureManager(); 

	// 这里可切换输入方式：
	// 1、从test.txt文件输入，以方便调试时键盘输入费时。
	// 2、从命令行输入，以帮助在没有完全编写好代码时，无法用test.txt测试
#if 0
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

	board.InitCommandLine(&argc, (char **)argv); 
	board.InitWindowSize(800, 800); 

	board.InitDisplayCallback(DisplayCallback); 
	board.InitKeyboardCallback(KeyboardCallback); 
	board.InitReshapeCallback(ReshapeCallback); 

	board.Show(); 

	return 0;
}

