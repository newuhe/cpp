#include "stdafx.h"

#include "Vector.h"


Vector Vector::INVALID_VECTOR; 

Vector::Vector(int length, const double data[])
{
	_data.resize(length); 
	for (int idx = 0; idx < length; ++idx)
	{
		_data[idx] = data[idx]; 
	}
}

Vector::Vector(int length, const double data)
{
	_data.resize(length); 
	for (int idx = 0; idx < length; ++idx)
	{
		_data[idx] = data; 
	}
}

const Vector &Vector::operator=(const Vector &rhs)
{
	_data = rhs._data; 

	return *this; 
}

const Vector &Vector::operator=(double rhs)
{
	for (int idx = 0; idx < size(); ++idx)
	{
		_data[idx] = rhs; 
	}

	return *this; 
}


Vector Vector::operator-() const
{
	Vector result(*this); 
	for (Data::size_type idx = 0; idx < _data.size(); ++idx)
	{
		result[idx] = -_data[idx]; 
	}

	return result; 
}

Vector Vector::operator+(const Vector &rhs) const
{
	if (size() != rhs.size())
	{
		return INVALID_VECTOR; 
	}

	Vector result(*this); 
	for (Data::size_type idx = 0; idx < _data.size(); ++idx)
	{
		result[idx] = _data[idx] + rhs[idx]; 
	}

	return result; 
}

Vector Vector::operator*(double rhs) const
{
	Vector temp = *this; 

	for (int idx = 0; idx < size(); ++idx)
	{
		temp[idx] *= rhs; 
	}

	return temp; 
}

bool Vector::operator==(const Vector &rhs) const
{
	if (rhs.size() != size())
	{
		return false; 
	}

	for (int idx = 0; idx < size(); ++idx)
	{
		if (rhs[idx] != _data[idx])
		{
			return false;
		}
	}

	return true; 
}

std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
	std::cout << "vector (1 X " << vector.size() << "): " << std::endl; 
	for (int idx = 0; idx < vector.size(); ++idx)
	{
		os << vector[idx] << " "; 
	}

	return os; 
}

////////////////////////////////////////////////////////////////////////////////////////