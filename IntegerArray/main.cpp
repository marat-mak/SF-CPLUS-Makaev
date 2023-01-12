#include"IntegerArray.h"


int main()
{	
    // Объявляем массив из 10 элементов
    IntegerArray array(10);
    

    // Заполняем массив числами от 1 до 10
    for (int i{ 0 }; i < 10; ++i)
        array[i] = i + 1;
    
    // Изменим размер массива до 8 элементов
    array.resize(8);

    // Вставляем число 20 перед элементом с индексом 5
    array.insertBefore(20, 5);

    // Удаляем элемент с индексом 3
    array.remove(3);

    // Добавляем 30 и 40 в конец и начало
    array.insertAtEnd(30);
    array.insertAtBeginning(40);

    // Распечатываем все числа
    for (int i{ 0 }; i < array.getLength(); ++i)
        cout << array[i] << ' ';

    cout << '\n';

    //Поиск по индексу
    cout << array.operator[](5) << endl;

    //Поиск по значению
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