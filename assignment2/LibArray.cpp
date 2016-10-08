// LibArray.cpp : 定义控制台应用程序的入口点。
//

// 实验内容：
// 1：将C语言版本LibArray用C++封装，注意，原C版本保留一个备份

// 实验目的：
// 1：C++类定义的基本方法

// 实验提交
// 只提交CLibArray.cpp及CLibArray.h
// 文件打包成一个.zip或.rar格式的压缩包，以邮件附件形式发送。邮件主题与压缩包名一致。
// Email：esecpp2016@163.com
// 命名规范：学号+姓名+第几次作业+第几版（注意添加加号“+”）
// 截止时间：10月16日24：00前

#include "stdafx.h"

#include <assert.h>

#include "CLibArray.h"

int _tmain(int argc, _TCHAR* argv[])
{
    CArray array;
    // 不再需要initial，但应该有正确的初始化
    // array_initial(array); 

    //array.recap(10); 
    //assert(array.capacity() == 10); 

    //////////////////////////////////////////////////////////////////////////
    for (int i = 0; i < 20; ++i)
    {
        array.append(i); 
    }
    assert(array.size() == 20); 
    
    for (int i = 0; i < array.size(); ++i)
    {
        assert(array.at(i) == i); 
    }

    //////////////////////////////////////////////////////////////////////////
    CArray array2, array3; 
    // array_initial(array2); 
    // array_initial(array3); 

    array2.copy(array); 
    assert(array.compare(array2) == true); 

    array3.copy(array); 
    assert(array.compare(array3) == true); 

    //////////////////////////////////////////////////////////////////////////
    array2.insert(2, 3); 
    assert(array.compare(array2) == false); 

    //////////////////////////////////////////////////////////////////////////
    array3.at(2) = 5; 
    assert(array.compare(array3) == false); 

    //////////////////////////////////////////////////////////////////////////
    // 不再需要destroy，但应该有正确的内存释放
    // array_destroy(array); 
    // array_destroy(array2); 
    // array_destroy(array3); 

    return 0;
}
