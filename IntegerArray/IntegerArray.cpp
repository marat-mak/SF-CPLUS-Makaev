#include"IntegerArray.h"


IntegerArray::IntegerArray() = default;

IntegerArray::IntegerArray(int length) :
	m_length{ length }
{
	if (length <= 0)
	{
		throw BadLength();
	}
	m_data = new int[length] {};
}
	
IntegerArray::IntegerArray(const IntegerArray& other)
{
	this->m_length = other.m_length;
	this->m_data = other.m_data;
}

void IntegerArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

int& IntegerArray::operator[](int index)
{
	if (index < 0) { throw BadRange(); }
	if (index > m_length) { throw BadRange(); }
	return m_data[index];
}

int IntegerArray::getLength() const
{
	return m_length;
}

void IntegerArray::reallocate(int newLength)
{
	erase();
	if (newLength <= 0)
		return;
	m_data = new int[newLength];
	m_length = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (newLength == m_length)
		return;
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* data{ new int[newLength] };
	if (m_length > 0)
	{
		int elementsToCopy{ (newLength > m_length) ? m_length : newLength };
		
		for (int index{ 0 }; index < elementsToCopy; ++index)
			data[index] = m_data[index];
	}

	delete[] m_data;

	m_data = data;
	m_length = newLength;
}
void IntegerArray::insertBefore(int value, int index)
{
	if (index < 0) { throw BadRange(); }
	if (index > m_length) { throw BadRange(); }

	int* data{ new int[m_length + 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	data[index] = value;

	for (int after{ index }; after < m_length; ++after)
		data[after + 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	++m_length;
}

void IntegerArray::remove(int index)
{	
	if (index < 0) { throw BadRange(); }
	if (index > m_length) { throw BadRange(); }

		
	if (m_length == 1)
	{
		erase();
		return;
	}

	int* data{ new int[m_length - 1] };

	for (int before{ 0 }; before < index; ++before)
		data[before] = m_data[before];

	for (int after{ index + 1 }; after < m_length; ++after)
		data[after - 1] = m_data[after];

	delete[] m_data;
	m_data = data;
	--m_length;
}

void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}
void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, m_length);
}

void IntegerArray::search(int value)
{
	for (int index{ 0 }; index < m_length; ++index)
		if (m_data[index] == value)
		{
			cout << "Index of value: " << index << endl;
			return;
		}
	cout << "This value is not in array" << endl;			
}