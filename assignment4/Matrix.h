#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>

#include "Vector.h"

/// @brief Matrix类
///
/// Matrix类，实现Matrix类赋值、元素访问、乘法、流输出等操作
///
/// @see 
///
class Matrix
{
public:
	/// 定义类型便于其他代码使用
	typedef std::vector<Vector> Data; 

	/// 定义非法矩阵，这里用0 * 0矩阵表示，也可在Matrix中添加一个特殊标志位
	static Matrix INVALID_MATRIX; 
public:
    // Matrix类构造函数.
	/// 默认构造函数要加，否则vector无法resize
	Matrix() { }

	Matrix(const Vector &rhs); 

	Matrix(int row, int col); 

	Matrix(int row, int col, const double data[]); 

	Matrix(int row, int col, const double data); 

	Matrix(const Matrix &rhs) : _data(rhs._data) { }
        
    // Matrix类析构函数
    ~Matrix()
	{
		/// 养成习惯，析构时清空
		_data.clear(); 
	}
 
    // Matrix类接口.
public:
	// Matrix类赋值函数
    const Matrix &operator=(const Matrix &rhs); 
	const Matrix &operator=(const Vector &rhs); 
    
   	int rows() const
	{
		return _data.size(); 
	}

	int cols() const
	{
		if (_data.empty())
		{
			return 0; 
		}

		return _data[0].size(); 
	}

	Matrix trans() const;  

	/// 注意返回值加引用，否则赋值无效
	Vector &operator[](int row)
	{
		return _data[row]; 
	}

	const Vector &operator[](int row) const
	{
		return _data[row]; 
	}

	/// 这里千万不能用引用，因返回的是局部变量
	/// 记得加const
	Matrix operator-() const; 

	Matrix operator*(const Matrix &rhs) const; 
	Matrix operator*(double rhs) const; 

	Matrix operator+(const Matrix &rhs) const; 
	Matrix operator+(double rhs) const 
	{
		return *this + Matrix(rows(), cols(), rhs); 
	}
	
	Matrix operator-(const Matrix &rhs) const
	{
		return *this + (- rhs); 
	}

	Matrix operator-(double rhs) const
	{
		return *this - Matrix(rows(), cols(), rhs); 
	}

	/// 记得加const
	bool operator==(const Matrix &rhs) const;
	bool operator==(const Vector &rhs) const;

	/// 记得加const
	bool operator!=(const Matrix &rhs) const
	{
		return !(*this == rhs); 
	}

	bool operator!=(const Vector &rhs) const
	{
		return !(*this == rhs); 
	}

    
    // Matrix类私有实现方法
private:
           
    // Matrix类私有属性
private:
	/// 所有成员函数应设为私有
	Data _data; 
    
	/// operator<<需加友元声明，否则无法打印，测试代码中没有要求，这里作为一个示例
	friend std::ostream &operator<<(std::ostream &out, const Matrix &rhs); 
}; // class Matrix类定义结束.

/// 定义Matrix流输出操作
std::ostream &operator<<(std::ostream &out, const Matrix &rhs); 

#endif // #ifndef _MATRIX_H_
