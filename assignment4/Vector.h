#ifndef _VECTOR_H_
#define _VECTOR_H_

#include <iostream>
#include <vector>

class Vector
{
public:
	typedef std::vector<double> Data; 

	static Vector INVALID_VECTOR; 

public:

	double &operator[](int idx) { return _data[idx]; }
	double operator[](int idx) const { return _data[idx]; }

	Vector() { }
	Vector(int length, const double data[]);
	Vector(int length, const double data);

	~Vector()
	{
		_data.clear(); 
	}

	//////////////////////////////
	void resize(int length)
	{
		_data.resize(length); 
	}

	int size() const { return _data.size(); }

	//////////////////////////////
	const Vector &operator=(const Vector &rhs); 
	const Vector &operator=(double rhs); 

	Vector operator-() const; 

	Vector operator+(const Vector &rhs) const; 
	Vector operator+(double rhs) const
	{
		return *this + Vector(size(), rhs); 
	}

	Vector operator-(const Vector &rhs) const
	{
		return *this + (-rhs); 
	}
	Vector operator-(double rhs) const
	{
		return *this - Vector(size(), rhs); 
	}

	Vector operator*(double rhs) const; 

	bool operator==(const Vector &rhs) const; 
	bool operator!=(const Vector &rhs) const
	{
		return !(rhs == *this); 
	}

private:
	Data _data; 

	friend std::ostream &operator<<(std::ostream &os, const Vector &vector); 
}; 

std::ostream &operator<<(std::ostream &os, const Vector &vector); 

#endif