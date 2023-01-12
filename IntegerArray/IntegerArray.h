#pragma once
#include<iostream>
#include"bad_length.h"
#include"bad_range.h"

class IntegerArray
{
private:
	int m_length{};
	int* m_data{};
public:
	IntegerArray();

	IntegerArray(int length);

	IntegerArray(const IntegerArray& other);

	~IntegerArray()
	{
		delete[] m_data;
	}

	void erase();

	int& operator[](int index);

	int getLength() const;

	void reallocate(int newLength);

	void resize(int newLength);

	void insertBefore(int value, int index);

	void remove(int index);

	void insertAtBeginning(int value);

	void insertAtEnd(int value);

	void search(int value);
};