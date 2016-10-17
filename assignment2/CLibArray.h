#ifndef __CLIBARRAY__
#define __CLIBARRAY__


class CArray
{
public:
	CArray(); 
	~CArray(); 

	inline int capacity()
	{
		return _capacity; 
	}

	inline int size()
	{
		return _size; 
	}

	void recap(int capacity); 

	inline int &at(int index)
	{
		return _buff[index]; 
	}

	void append(int element); 
	void insert(int index, int element); 

	void copy(CArray &rhs); 
	bool compare(CArray &rhs); 

private:
	void _check_capacity(int minimal); 

	int *_buff; 
	int _size; 
	int _capacity; 
} ;
#endif