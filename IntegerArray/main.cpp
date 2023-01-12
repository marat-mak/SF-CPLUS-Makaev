#include"IntegerArray.h"


int main()
{	
    // ��������� ������ �� 10 ���������
    IntegerArray array(10);
    

    // ��������� ������ ������� �� 1 �� 10
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;
    
    // ������� ������ ������� �� 8 ���������
    array.resize(8);

    // ��������� ����� 20 ����� ��������� � �������� 5
    array.insertBefore(20, 5);

    // ������� ������� � �������� 3
    array.remove(3);

    // ��������� 30 � 40 � ����� � ������
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // ������������� ��� �����
    for (int i{ 0 }; i < array.getLength(); ++i)
        cout << array[i] << ' ';

    cout << '\n';

    //����� �� �������
    cout << array.operator[](5) << endl;

    //����� �� ��������
    array.search(20);
	
	try
	{
		IntegerArray i(0);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
    try
    {
        array.remove(20);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        array.operator[](20);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
    try
    {
        array.insertBefore(20, 20);
    }
    catch (exception& e)
    {
        cout << e.what() << endl;
    }
	return 0;
}